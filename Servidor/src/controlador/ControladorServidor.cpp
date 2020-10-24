#include "ControladorServidor.h"

ControladorServidor::ControladorServidor(int argc, char* argv[]) {
    CargadorDeConfiguracion cargador;
    cargador.cargar(argc, argv);

    this->servidor = new Servidor();
    this->controlador_juego = nullptr;
    this->hilo_aceptador = nullptr;
    this->clientes.reserve(CANT_CONEXIONES_MAX);
    this->fps = 0;
    this->nivel_principio = true;
    this->contador_timeout_desconexion = 0;
    this->contador_timeout_inicio = 0;
}

ControladorServidor::~ControladorServidor() {
    this->enviarATodos(MSJ_CERRAR_CLIENTE);
    this->mutex.lock();
    for(auto &c: this->clientes){
        delete(c);
    }
    this->mutex.unlock();
    if (this->hilo_aceptador) {
        delete(this->hilo_aceptador);
    }
    this->mutex.lock();
    delete(this->servidor);
    this->mutex.unlock();
    delete(this->controlador_juego);
}

void ControladorServidor::inicializar() {
    this->servidor->inicializar();
    loguearInfo(MSJ_INICIO_SV);
    this->hilo_aceptador = new HiloAceptador(&this->clientes, &this->mutex, this->servidor, &this->cola_inputs_recibidos);
    this->aceptarClientes();
    this->controlador_juego = new ControladorJuego((int)this->clientes.size());

    this->enviarATodos(PRE_NIVEL_NUM + SEPARADOR + std::to_string(this->controlador_juego->getNumeroNivel()));

    for (auto &cliente: this->clientes){
        this->controlador_juego->setNombreJugador(cliente->getNroCliente(), cliente->getUsuario());
    }

    this->enviarATodos(PRE_NIVEL_REINICIAR);
    
    if(this->controlador_juego->estanTodosLosJugadoresDesconectados()){	
        enviarATodos(std::string(MSJ_VIVOS_DESCONECTADOS));	
    }
    
    //Vacio el buffer de inputs
    std::this_thread::sleep_for(std::chrono::milliseconds(1500));
    while(this->cola_inputs_recibidos.desencolar(COLA_VACIA) != COLA_VACIA){
        std::this_thread::sleep_for(std::chrono::milliseconds(MILISEG_TIMEOUT_EVENTOS));
    }
}

bool ControladorServidor::estaActivo(){
    int jugadores_desconectados = 0;
    std::unique_lock<std::mutex> lock(this->mutex);
    for(auto &c: this->clientes){
        if(c->getFD() == FD_DEFECTO){
            ++jugadores_desconectados;
        }
    }

    // timeout desconexión inicia en 0 porque al principio el sv no se tiene que cerrar
    // Las condiciones para que se ciere son:
    if (jugadores_desconectados == (int)this->clientes.size()
     || this->controlador_juego->estanTodosLosJugadoresDesconectados()){
        // Si se activa una condición de cierre, aumento el tiempo de timeout
        // tiempo actual - tiempo inicio timeout = hace cuánto que el sv entró en estado para cerrarse
        this->contador_timeout_desconexion = SDL_GetTicks() - this->contador_timeout_inicio;
    } else {
        // Referencia: la iteración anterior, o bien, la última iteración donde no había
        // condición para cerrar el sv.
        this->contador_timeout_inicio = SDL_GetTicks();
        this->contador_timeout_desconexion = 0;
    }

    if(this->contador_timeout_desconexion >= TIMEOUT_PARA_GAMEOVER_DESCONECTADOS){
        for (auto & cliente : this->clientes){
            if(cliente->getFD() != FD_DEFECTO){
                cliente->enviarMensaje(this->controlador_juego->getPuntajesFinNivel());
                cliente->enviarMensaje(PRE_GAME_OVER);
            }
         }

        // Mensajes de game over
        this->esperarTiempo(SEGUNDOS_GAME_OVER);
       
        for (auto & cliente : this->clientes){
            if(cliente->getFD() != FD_DEFECTO){
                cliente->enviarMensaje(MSJ_CERRAR_CLIENTE);
            }
        }

        this->esperarTiempo(SEGUNDOS_CERRAR_CLIENTES);
       
       return false;
    }
    
    if( this->controlador_juego->juegoGanado()
       || this->controlador_juego->juegoPerdido()) {

        for (auto & cliente : this->clientes){
            if(cliente->getFD() != FD_DEFECTO){
                cliente->enviarMensaje(MSJ_CERRAR_CLIENTE);
            }
        }
        
        std::this_thread::sleep_for(std::chrono::milliseconds(500));
        this->actualizarInputs();
        loguearInfo(LOG_SERVIDOR_CERRADO_JUEGO_FINALIZADO);
        return false;
    }

    return true;
}

void ControladorServidor::aceptarClientes() {
    this->hilo_aceptador->ejecutar();

    int cantidad_listos = 0;
    int diferencia_listo = 0;
    while (cantidad_listos < (int)getCantidadUsuarios() ) {

        diferencia_listo = this->recibirInfoCliente();
        cantidad_listos += diferencia_listo;
        if(diferencia_listo != 0){
            this->enviarATodos(std::to_string(cantidad_listos) + MSJ_JUGADOR_CONECTADO);
        }

        diferencia_listo = this->borrarClientesDesconectados();
        cantidad_listos -= diferencia_listo;
        if(diferencia_listo != 0){
            this->enviarATodos(std::to_string(cantidad_listos) + MSJ_JUGADOR_CONECTADO);
        }

        /**
         * Este sleep es para arreglar una condicion de carrera producido entre este hilo y el hilo recv
         * (de alguno de los clientes).
         *
         * El error se produce (puede producirse) en el caso de que un cliente se desconecte y el hilo recv
         * intente tomar el mutex para bloquearlo (lock) y cerrar el fd. El problema es que en este ciclo
         * while puede suceder que el intervalo de tiempo del unlock() y el lock() que se encuentra en la
         * linea siguiente al sleep puede ser tan corto que el hilo recv no llegue a enterarse de que puede
         * tomar el mutex para bloquearlo y cerrar el fd (Tanto este hilo como el hilo recv compiten por el
         * lock del mutex una vez este lo desbloquea pero pasaba que en muchos casos era este hilo el que ganaba
         * la carrera por tomar el mutex).
         *
         * Por lo tanto si se deja este espacio de tiempo (sleep), en el que el mutex esta desbloquado, se logra que
         * el hilo recv pueda tomar el mutex, bloquearlo para cerrar su fd correctamente y luego liberarlo.
         **/
        std::this_thread::sleep_for(std::chrono::milliseconds(MILISEG_LOCK_CERRAR_FD));

    }

    loguearInfo(LOG_MSJ_CANT_JUGADORES_LISTOS + std::to_string(cantidad_listos));

    ///Borra todos los clientes conectados que no estan listos
    this->mutex.lock();
    this->borrarClientesNoListos();
    this->mutex.unlock();

    /// Le envio a los clientes un mensaje para que esperen recibirListo su numero de jugador
    this->enviarATodos(MSJ_CLIENTE_LISTO);

    /// Si no se puedo enviar el mensaje a algun cliente es porque se cayo la conexion luego de logearse
    /// no lo elimino de la lista sino que lo dejo disponible para reconectarse
    this->actualizarDesconectados();

    this->mutex.lock();

    /// Se manda al cliente su numero de jugador
    for (size_t i = 0; i < (size_t)cantidad_listos; ++i) {

        this->clientes[i]->asignarNroCliente(i);

        if(this->clientes[i]->estaListo()){
            this->clientes[i]->enviarMensaje(std::to_string(i));
        }

        loguearInfo( LOG_MSJ_MANDAR_NUMERO_USUARIO + this->clientes[i]->getUsuario() + ": " + std::to_string(i));
    }
    this->mutex.unlock();
}

int ControladorServidor::recibirInfoCliente(){
    unsigned short cantidad_listos = 0;
    long unsigned i;
    std::string letra;

    Uint16 mensaje = 0;     /// Variable que representa el mensaje codificado
    Uint16 aux_id;          /// Variable auxiliar entre 0 y CANT_CONEXIONES_MAX usada para decodificar el msj
    Uint16 msj_real;        /// Numero que representa al msj real mandado por el cliente

    mensaje = this->cola_inputs_recibidos.desencolar(COLA_VACIA);

    while(mensaje != COLA_VACIA ){
        aux_id = mensaje % CANT_CONEXIONES_MAX;
        i = 0;
        this->mutex.lock();
        while( i < this->clientes.size() ){

            if ( (this->clientes[i]->getNroCliente() % CANT_CONEXIONES_MAX) == ( int ) aux_id ){

                msj_real = (Uint16) (mensaje - aux_id) / CANT_CONEXIONES_MAX;

                if(msj_real == TECLA_FIN_PASS) {
                    this->validarInfoCliente(i, &cantidad_listos);
                }

                else if(msj_real == TECLA_FIN_NOMBRE){
                    clientes[i]->setNombreCompleto(true);
                }

                else{
                    letra = mapeo_nro_letra[msj_real];
                    clientes[i]->agregarCaracter(letra);
                }
                break;
            }
            i++;
        }
        this->mutex.unlock();
        mensaje = this->cola_inputs_recibidos.desencolar(COLA_VACIA);
    }

    return cantidad_listos;
}

void ControladorServidor::validarInfoCliente(long unsigned n_cliente, unsigned short *cantidad_listos) {
    bool no_esta = false;
    auto itr = this->clientes.begin();
    while(itr != this->clientes.end() and
          (this->clientes[n_cliente]->getUsuario() != (*itr)->getUsuario() or
           this->clientes[n_cliente]->getPassword() != (*itr)->getPassword() or
           this->clientes[n_cliente]->getNroCliente() == (*itr)->getNroCliente() or
           !(*itr)->estaListo())
            ){
        ++itr;
    }

    if(itr == this->clientes.end()){
        no_esta = true;
    }

    if (this->esValidoCliente(clientes[n_cliente]) and no_esta) {
        this->clientes[n_cliente]->enviarMensaje(MSJ_DATOS_VALIDOS);
        clientes[n_cliente]->setListo(true);
        (*cantidad_listos)++;
        loguearDebug(LOG_MSJ_CLIENTE_LISTO_1 + std::to_string( clientes[n_cliente]->getFD()) + LOG_MSJ_CLIENTE_LISTO_2);
    }

    else {
        if (no_esta) {
            this->clientes[n_cliente]->enviarMensaje(MSJ_DATOS_INVALIDOS);
            loguearInfo(LOG_CLIENTE_VALIDO + this->clientes[n_cliente]->getUsuario());
        } else {
            this->clientes[n_cliente]->enviarMensaje(MSJ_CLIENTE_YA_CONECTADO);
            loguearInfo(LOG_CLIENTE_YA_CONECTADO_1 + this->clientes[n_cliente]->getUsuario() + LOG_CLIENTE_YA_CONECTADO_2);
        }
        std::this_thread::sleep_for(std::chrono::milliseconds(200));
        delete (clientes[n_cliente]);
        this->clientes.erase(this->clientes.begin() + (int)n_cliente);
        loguearInfo(LOG_CLIENTE_INVALIDO_BORRADO);
    }

    loguearInfo( LOG_CLIENTE_VALIDADO + clientes[n_cliente]->getUsuario() );
}

int ControladorServidor::borrarClientesDesconectados(){
    int diferencia = 0;

    this->mutex.lock();
    for(long unsigned i=0; i < this->clientes.size();){

        if (this->clientes[i]->getFD() == FD_DEFECTO){   /// Si el jugador se desconecto

            if (this->clientes[i]->estaListo()){         /// Si estaba listo
                diferencia += 1;
            }

            delete(this->clientes[i]);
            this->clientes.erase(this->clientes.begin() + (int)i);
            loguearDebug(LOG_UN_CLIENTE_DESCONECTADO);
        } else{
            ++i;
        }
    }
    this->mutex.unlock();
    return diferencia;
}

int ControladorServidor::actualizarDesconectados(){
    int diferencia = 0;

    this->mutex.lock();
    for (auto & cliente : this->clientes) {
        if (cliente->getFD() == FD_DEFECTO){
            cliente->setListo(false);
            diferencia += 1;
        }
    }
    this->mutex.unlock();
    return diferencia;
}


void ControladorServidor::actualizar(){
    Uint32 startclock = SDL_GetTicks();
    size_t cant_listos = 0;
    size_t cant_desconectados = 0;

    this->mutex.lock();
    auto itr = this->clientes.begin();
    while(itr != this->clientes.end()){
        if ((*itr)->estaListo() and (*itr)->getFD() != FD_DEFECTO){
            ++cant_listos;
        }
        if ((*itr)->getFD() == FD_DEFECTO){
            ++cant_desconectados;
        }
        ++itr;
    }

    // Solo para borrar cuando el sv está lleno.
    if (cant_listos == getCantidadUsuarios() and cant_listos < this->clientes.size()){
        this->borrarClientesNoListos();
    }

    this->actualizarInputs();
    this->mutex.unlock();

    this->controlador_juego->actualizarJuego();
    this->controlador_juego->actualizarPuntajeJuego();

    if (this->controlador_juego->nivelEmpezado() && (cant_desconectados < getCantidadUsuarios())) {
        if (this->controlador_juego->hayJugadorVivo()) {
            this->enviarEstados();
        }
        else{
            this->controlador_juego->reiniciarNivel();
            
            if(this->controlador_juego->estanTodosLosJugadoresDesconectados()){	
                enviarATodos(std::string(MSJ_VIVOS_DESCONECTADOS));	
            }

            if (this->controlador_juego->juegoPerdido()) {
                this->hilo_aceptador->setJuegoFinalizado(true);
                this->enviarATodos(this->controlador_juego->getPuntajesFinNivel());
                this->enviarATodos(PRE_GAME_OVER);
                this->esperarTiempoConLock(SEGUNDOS_GAME_OVER);
                this->mensajesGameOver();
                this->esperarTiempoConLock(SEGUNDOS_CERRAR_CLIENTES);
                return;
            }
            this->enviarATodos(PRE_NIVEL_REINICIAR);
        }
    }

    if (this->controlador_juego->juegoGanado()) {
        this->hilo_aceptador->setJuegoFinalizado(true);
        this->enviarATodos(this->controlador_juego->getPuntajesFinNivel());
        this->enviarATodos(PRE_NIVEL_FINALIZAR);
        this->esperarTiempoConLock(SEGUNDOS_FIN_NIVEL);

        this->enviarATodos(PRE_CONGRATULATIONS);
        this->enviarATodos(std::to_string(getCantidadUsuarios()));
        this->esperarTiempoConLock(SEGUNDOS_CONGRATULATIONS);

        this->enviarATodos(MSJ_CERRAR_CLIENTE);
        // Esperamos unos milisegundos antes de cerrar el server para que el cliente no crea que se perdión conexión con el servidor
        this->esperarTiempoConLock(SEGUNDOS_CERRAR_CLIENTES);
        return;
    }

    if (this->controlador_juego->nivelFinalizado()) {
        this->enviarATodos(this->controlador_juego->getPuntajesFinNivel());
        this->enviarATodos(PRE_NIVEL_FINALIZAR);
        this->esperarTiempoConLock(SEGUNDOS_FIN_NIVEL);
        this->enviarATodos(PRE_NIVEL_INICIAR);
        	
        if(this->controlador_juego->estanTodosLosJugadoresDesconectados()){	
            enviarATodos(std::string(MSJ_VIVOS_DESCONECTADOS));	
        }
        
    }

    // Para evitar condición de desconexión en el cliente si todos los jugadores que tienen vidas están desconectados
    if(this->controlador_juego->estanTodosLosJugadoresDesconectados()){
        enviarATodos(std::string(MSJ_PING));
    }

    /// Se Limita las actualizaciones por segundo a 60
    Uint32 deltaclock = SDL_GetTicks() - startclock;
    if (deltaclock < MILISEG_TIMEOUT_EVENTOS) {
        std::this_thread::sleep_for(std::chrono::milliseconds(MILISEG_TIMEOUT_EVENTOS - deltaclock));
    }

    this->fps++;
    if(SDL_GetTicks() % 1000 < startclock % 1000 ){
        /// descomentar para ver por consola la cantidad de FPS
        //std::cout << "FPS: " << this->fps << std::endl;
        this->fps = 0;
    }
}

void ControladorServidor::actualizarInputs(){
    uint16_t input = this->cola_inputs_recibidos.desencolar(COLA_VACIA);

    while(input != COLA_VACIA) {

        if (input / CANT_CONEXIONES_MAX == 0) {
            this->actualizarInputDesconexion(input);

        } else if (input / CANT_CONEXIONES_MAX == TECLA_PING_RECIBIDO) {
            this->actualizarInputPing(input);

        } else if (input > (TECLA_JUEGO_MAX * CANT_CONEXIONES_MAX)) {
            this->actualizarInputInfoCliente(input);

        } else {
            this->controlador_juego->actualizarEstadoJuego(input);
        }

        input = this->cola_inputs_recibidos.desencolar(COLA_VACIA);
    }
}

void ControladorServidor::actualizarInputDesconexion(uint16_t input){
    auto itr = this->clientes.begin();
    while (itr != this->clientes.end() and ((*itr)->getNroCliente() != input % CANT_CONEXIONES_MAX)) {
        ++itr;
    }
    if (itr == this->clientes.end()) {
        return;
    }

    (*itr)->setListo(false);
    loguearInfo( LOG_CLIENTE_DESCONECTADO + (*itr)->getUsuario() );
    this->controlador_juego->desconectarPersonaje((*itr)->getNroCliente());
}

void ControladorServidor::actualizarInputPing(uint16_t input){
    auto itr = this->clientes.begin();
    while (itr != this->clientes.end() and ((*itr)->getNroCliente() != input % CANT_CONEXIONES_MAX)) {
        ++itr;
    }
    if (itr == this->clientes.end()) {
        return;
    }
    (*itr)->setPingRecibido(true);
}

void ControladorServidor::actualizarInputInfoCliente(uint16_t input){
    auto itr = this->clientes.begin();
    while (itr != this->clientes.end() and ((*itr)->getNroCliente() != input % CANT_CONEXIONES_MAX)) {
        ++itr;
    }
    if (itr == this->clientes.end()) {
        return;
    }

    if (input / CANT_CONEXIONES_MAX == TECLA_FIN_PASS) {
        this->validarInputInfoCliente(&itr);

    }else if (input / CANT_CONEXIONES_MAX == TECLA_FIN_NOMBRE){
        (*itr)->setNombreCompleto(true);

    } else {
        std::string letra = mapeo_nro_letra[input / CANT_CONEXIONES_MAX];
        (*itr)->agregarCaracter(letra);
    }
}

void ControladorServidor::validarInputInfoCliente(std::vector<Cliente*>::iterator* itr) {
    bool ya_esta_conectado = false;
    auto itr2 = this->clientes.begin();

    while (itr2 != this->clientes.end()) {

        if ((*itr2)->getUsuario() == (**itr)->getUsuario() and (*itr2)->getPassword() == (**itr)->getPassword()){

            if ((*itr2)->getFD() != FD_DEFECTO){

                if ((*itr2)->getNroCliente() != (**itr)->getNroCliente()){
                    ya_esta_conectado = true;
                }

            } else {
                loguearInfo( LOG_CLIENTE_VALIDADO + (*itr2)->getUsuario() );
                break;
            }
        }
        ++itr2;
    }

    if (itr2 == this->clientes.end()) {
        if (ya_esta_conectado) {
            (**itr)->enviarMensaje(MSJ_CLIENTE_YA_CONECTADO);

        } else if (esUsuarioValido((**itr)->getUsuario(), (**itr)->getPassword())) {
            (**itr)->enviarMensaje(MSJ_DATOS_VALIDOS_PARTIDA_LLENA);

        } else {
            (**itr)->enviarMensaje(MSJ_DATOS_INVALIDOS);
        }

        std::this_thread::sleep_for(std::chrono::milliseconds(200));
        delete ((**itr));
        this->clientes.erase((*itr)++);
        loguearInfo(LOG_CLIENTE_INVALIDO_BORRADO);
        return;

    } else {
        (**itr)->enviarMensaje(MSJ_DATOS_VALIDOS);
        (**itr)->enviarMensaje(MSJ_CLIENTE_LISTO);
        (**itr)->asignarNroCliente((size_t)(*itr2)->getNroCliente());
        (**itr)->enviarMensaje(std::to_string((**itr)->getNroCliente()));
        (**itr)->enviarMensaje(PRE_NIVEL_NUM + SEPARADOR + std::to_string(this->controlador_juego->getNumeroNivel()));
        (**itr)->setListo(true);
        loguearDebug(LOG_CLIENTE_RECONECTADO);
        loguearDebug(LOG_MSJ_CLIENTE_LISTO_1 + std::to_string((**itr)->getFD()) + LOG_MSJ_CLIENTE_LISTO_2);
        delete ((*itr2));
        this->clientes.erase(itr2++);
        (**itr)->actualizarPingInicial();
        return;
    }
}


void ControladorServidor::enviarEstados(){
    std::string mensaje_estado_personajes = this->controlador_juego->getEstadoPersonajes();
    std::string mensaje_estado_enemigos = this->controlador_juego->getEstadoEnemigos();
    std::string mensaje_estado_proyectiles = this->controlador_juego->getEstadoProyectiles();
    std::string mensaje_estado_puntaje = this->controlador_juego->getEstadoPuntaje();
    std::string mensaje_estado_efecto = this->controlador_juego->getEstadoEfectos();
    std::string mensaje_estado_cajas = this->controlador_juego->getEstadoCajas();
    std::string mensaje_estado_items = this->controlador_juego->getEstadoItems();
    std::string mensaje_estado_fondo = this->controlador_juego->getEstadoFondo();


    this->mutex.lock();
    for (auto & cliente : this->clientes){
        if(cliente->getFD() != FD_DEFECTO && cliente->estaListo()){
            if (this->nivel_principio) {
                cliente->actualizarPingInicial();
            }

            else if (cliente->pingRecibido()){
                cliente->enviarMensaje(mensaje_estado_personajes);
                cliente->enviarMensaje(mensaje_estado_enemigos);
                cliente->enviarMensaje(mensaje_estado_proyectiles);
                cliente->enviarMensaje(mensaje_estado_puntaje);
                cliente->enviarMensaje(mensaje_estado_efecto);
                cliente->enviarMensaje(mensaje_estado_cajas);
                cliente->enviarMensaje(mensaje_estado_items);
                cliente->enviarMensaje(mensaje_estado_fondo);
                cliente->enviarMensaje(MSJ_PING);
                cliente->setPingRecibido(false);
            }

            //TODO ENTREGA: Cambiar UINT_MAX por MS_PING_DESCONECTADO para la entrega
            //else if (cliente->getPing() > MS_PING_DESCONECTADO) {   /// <- ENTREGA
            else if (cliente->getPing() > UINT_MAX) {             /// <- PARA DEBUG
                cliente->desconectar();
                this->controlador_juego->desconectarPersonaje(cliente->getNroCliente());
            }
        }
    }
    this->mutex.unlock();

    if(this->nivel_principio){
        this->nivel_principio = false;
    }
}

void ControladorServidor::enviarATodos(std::string mensaje){
    this->mutex.lock();
    for (auto & cliente : this->clientes){
        if(cliente->getFD() != FD_DEFECTO && cliente->estaListo()){
            cliente->enviarMensaje(mensaje);
        }
    }
    this->mutex.unlock();
}

void ControladorServidor::borrarClientesNoListos(){

    for (size_t i = 0; i < this->clientes.size(); ++i) {

        if (!(this->clientes[i]->estaListo() and this->clientes[i]->getFD() > FD_DEFECTO) and
            !esUsuarioValido(this->clientes[i]->getUsuario(), this->clientes[i]->getPassword())) {

            this->clientes[i]->enviarMensaje(MSJ_SERVER_LLENO);
            std::this_thread::sleep_for(std::chrono::milliseconds(200));
            delete(this->clientes[i]);
            this->clientes.erase(this->clientes.begin() + (int)i);
            loguearDebug(LOG_CLIENTE_DE_MAS_BORRADO);
            --i;
        }
    }
}

bool ControladorServidor::esValidoCliente(Cliente *cliente){
    bool infoValida = esUsuarioValido(cliente->getUsuario(), cliente->getPassword());
    if(infoValida){
        for(auto &c: this->clientes){
            if ((c->getUsuario() == cliente->getUsuario() ) && (c->getFD() != FD_DEFECTO) ){
                return true;
            }
        }
    }
    return false;
}

void ControladorServidor::mensajesGameOver() {
    this->mutex.lock();
    for (auto & cliente : this->clientes){
        if(cliente->getFD() != FD_DEFECTO){
            cliente->enviarMensaje(MSJ_CERRAR_CLIENTE);
        }
    }
    this->mutex.unlock();
}

// El cliente debe recibir (por ejemplo) un ping para
// verificar que el servidor sigue levantado.
void ControladorServidor::esperarTiempo(const unsigned int milisegs) {
    Uint32 inicio_t = SDL_GetTicks();
    Uint32 fin_t = SDL_GetTicks() - inicio_t;
    while (fin_t < milisegs) {
        std::this_thread::sleep_for(std::chrono::milliseconds(MILISEG_MINI_SLEEP));
        for (auto & cliente : this->clientes){
            if(cliente->getFD() != FD_DEFECTO){
                cliente->enviarMensaje(MSJ_PING);
            }
        }
        fin_t = SDL_GetTicks() - inicio_t;
    }
}

void ControladorServidor::esperarTiempoConLock(const unsigned int milisegs) {
    this->mutex.lock();
    esperarTiempo(milisegs);
    this->mutex.unlock();
}
