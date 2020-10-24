#include "ControladorCliente.h"

ControladorCliente::ControladorCliente(int argc, const char* argv[]) {
    CargadorDeConfiguracion cargador;
    cargador.cargar(argc, argv);

    this->setAtributosDefault();
    this->cliente_modelo = new Cliente();
    this->juego_controlador = new JuegoControlador();

}

ControladorCliente::~ControladorCliente() {
    this->borrarConexion();
    delete (this->cliente_modelo);
    delete (this->juego_controlador);

}

void ControladorCliente::reiniciar() {
    SDL_ShowSimpleMessageBox(SDL_MESSAGEBOX_ERROR, MSJ_FIN,
                             MSJ_ACLARACION_FIN, NULL);
    loguearError(MSJ_ACLARACION_FIN);

    this->borrarConexion();
    delete (this->cliente_modelo);
    this->juego_controlador->reiniciar();

    //reinicio los atributos
    this->cliente_modelo = new Cliente();
    this->setAtributosDefault();
}

void ControladorCliente::setAtributosDefault() {
    this->timeout = 0;
    this->cola_inputs = nullptr;
    this->cola_mensajes = nullptr;
    this->hilo_envr = nullptr;
    this->hilo_recv = nullptr;
    this->listo = false;
    this->continuar = true;
}

void ControladorCliente::borrarConexion(){
    this->desconectarse();

    if(this->hilo_recv){
        delete(this->hilo_recv);
        this->hilo_recv=nullptr;
    }
    if(this->hilo_envr){
        delete(this->hilo_envr);
        this->hilo_envr=nullptr;
    }
    if(this->cola_mensajes){
        delete(this->cola_mensajes);
        this->cola_mensajes=nullptr;
    }
    if(this->cola_inputs){
        delete(this->cola_inputs);
        this->cola_inputs=nullptr;
    }
}

bool ControladorCliente::iniciar() {
    std::string respuesta = TIMEOUT;
    bool conectado = false;
    this->juego_controlador->iniciar();
    char* mensaje_ventana;
    const char* puerto_alternativo;

    // Menú + nombre y pass
    while(!conectado || respuesta != MSJ_DATOS_VALIDOS){
        this->juego_controlador->resetearCartel();
        // Antes de que se conecte (menú)
        while (!conectado) {
            SDL_WaitEventTimeout(&this->evento, MILISEG_TIMEOUT_EVENTOS);
            mensaje_ventana = MSJ_CARTEL_CONEXION;
            this->juego_controlador->actualizarMenu();

            if (this->juego_controlador->juegoCancelado(&this->evento)) {
                setFin(true);
                return false;

            } else if (this->juego_controlador->inicioElJuego()) {
                try {
                    loguearInfo(LOG_INTENTAR_CONEXION);
                    loguearInfo(LOG_IP + std::string(getIPServidor()));
                    loguearInfo(LOG_PUERTO + std::string(getPuertoServidor()));

                    this->juego_controlador->desactivarInput();
                    this->juego_controlador->cambiarCartel();

                    this->cliente_modelo->conectarse(getIPServidorCte(), getPuertoServidor());

                    loguearInfo(LOG_MSJ_FD + std::to_string(this->cliente_modelo->getFd()));

                    puerto_alternativo = (char *) std::to_string((((std::atoi(getPuertoServidor()) + FIX_PUERTO_SUCIO) % 6000) + 1025)).c_str();

                    if( this->cliente_modelo->getFd() <0 ){

                        for (int i = 0; i<CANTIDAD_REINTENTOS_RECONEXION; ++i) {

                            loguearInfo(LOG_INTENTO_CONEXION_PUERTO + std::string(puerto_alternativo));
                            this->cliente_modelo->conectarse(getIPServidorCte(), puerto_alternativo);

                            if( this->cliente_modelo->getFd() != -1 )
                                break;

                            puerto_alternativo = (char *) std::to_string((((std::atoi(puerto_alternativo) + FIX_PUERTO_SUCIO) % 6000) + 1025)).c_str();
                        }

                        if( this->cliente_modelo->getFd() < 0 ) {
                            mensaje_ventana = MSJ_SIN_CONEXION;
                            //se utiliza
                            throw EXCEPCION_ERROR_CONEXION;
                        }
                    }

                    this->cola_mensajes = new ColaProtegida<std::string>();
                    this->cola_inputs = new ColaProtegida<uint16_t>();
                    this->hilo_recv = new HiloRecibir(this->cola_mensajes, this);
                    this->hilo_envr = new HiloEnviar(this->cola_inputs, this);

                    this->hilo_recv->ejecutar();
                    this->hilo_envr->ejecutar();

                    loguearInfo(LOG_CONEXION_EXITOSA);
                    conectado = true;

                } catch (char* &error) {
                    loguearError(mensaje_ventana);
                    this->juego_controlador->reestablecerMenu();
                    this->juego_controlador->actualizarMenu();
                    SDL_ShowSimpleMessageBox(SDL_MESSAGEBOX_ERROR, TITULO_CARTEL_CONEXION,
                                             mensaje_ventana, NULL);
                    this->juego_controlador->retrocederCartel();
                }
            }
        }

        this->juego_controlador->cerrarMenuPrincipal();

        // Después de que se conecté (carteles)
        while (respuesta != MSJ_DATOS_VALIDOS) {
            SDL_WaitEventTimeout(&this->evento, MILISEG_TIMEOUT_EVENTOS);

            if (this->juego_controlador->juegoCancelado(&this->evento)) {
                setFin(true);
                return false;
            }

            if ( ( this->juego_controlador->actualizarMenuLog() == -1) ) {
                setFin(true);
                return false;
            }

            if (!this->listo && this->juego_controlador->menuLogEstaIniciado()) {
                if( (strlen(getUsuario()) > 0 ) && ( strlen(getPass()) > 0) ){
                    alistarse();
                }

                else{
                    SDL_ShowSimpleMessageBox(SDL_MESSAGEBOX_ERROR, TITULO_CREDENCIALES,
                                             MSJ_USR_PASS_MAL, NULL);
                    this->juego_controlador->menuLogReestablecer();
                }
            }

            else{
                respuesta = this->cola_mensajes->desencolar(MSJ_COLA_VACIA);
            }

            if (respuesta != std::string(MSJ_COLA_VACIA)) {
                //loguearInfo(respuesta);

                if (respuesta == MSJ_DATOS_INVALIDOS) {
                    this->rechazarConexiones(TITULO_CREDENCIALES,MSJ_SV_REJECTED);
                    conectado = false;
                    break;
                }

                else if (respuesta == MSJ_DATOS_VALIDOS_PARTIDA_LLENA) {
                    this->rechazarConexiones(TITULO_CREDENCIALES,MSJ_SV_VALIDO_PARTIDA_LLENA);
                    conectado = false;
                    break;
                }

                else if (respuesta == MSJ_CLIENTE_YA_CONECTADO) {
                    this->rechazarConexiones(TITULO_CREDENCIALES,MSJ_SV_REJECTED_YA_CONECTADO);
                    conectado = false;
                    break;
                }

                else if (respuesta == MSJ_SERVER_LLENO) {
                    this->rechazarConexiones(TITULO_CARTEL_CONEXION, MSJ_SV_LLENO);
                    conectado = false;
                    break;
                }

                else if (respuesta == MSJ_SERVER_FIN_PARTIDA) {
                    this->rechazarConexiones(TITULO_CARTEL_CONEXION, MSJ_SV_FIN_PARTIDA);
                    conectado = false;
                    break;
                }

                else if( std::strcmp(DESCONECTADO, respuesta.c_str()) == 0 ){
                    return false;
                }
            }

        }
    }

    // Esperando jugadores
    this->juego_controlador->cambiarCartel();

    while(respuesta != MSJ_INICIO_JUEGO){
        SDL_WaitEventTimeout(&this->evento, MILISEG_TIMEOUT_EVENTOS);
        if ( !this->juego_controlador->actualizarCartel(&this->evento) ) {
            setFin(true);
            return false;
        }

        respuesta = this->cola_mensajes->desencolar(MSJ_COLA_VACIA);

        if (respuesta != std::string(MSJ_COLA_VACIA)) {
            if (respuesta.find(MSJ_JUGADOR_CONECTADO) != std::string::npos) {
                this->juego_controlador->actualizarJugadoresConectados(respuesta);
            }
            else if (std::strcmp(DESCONECTADO, respuesta.c_str()) == 0) {
                return false;
            }
        }
    }

    std::string nro  = this->cola_mensajes->desencolarBloqueante();
    this->nro_cliente = (Uint16) atoi(nro.c_str());

    loguearInfo(LOG_NRO_JUGADOR + std::to_string(this->nro_cliente));
    loguearInfo(std::string(LOG_MSJ_NOMBRE_VALIDADO)  +  getUsuario());
    loguearInfo(std::string(LOG_MSJ_PASSWORD_VALIDADO)  +  getPass());

    this->juego_controlador->iniciarVista();
    this->juego_controlador->setNumeroPersonaje((int)this->nro_cliente);

    // cartel stage
    this->juego_controlador->cartelIniciarJuego();
    this->juego_controlador->actualizarJugadoresConectados("");

    this->juego_controlador->actualizarNivel(this->cola_mensajes->desencolarBloqueante().c_str());
    this->cola_inputs->encolar(TECLA_LISTO);

    return true;
}

void ControladorCliente::alistarse() {
    //Primero se envia el nombre del usuario
    enviarStr(getUsuario());
    this->cola_inputs->encolar(TECLA_FIN_NOMBRE);

    //Segundo se envia su password
    enviarStr(getPass());
    this->cola_inputs->encolar(TECLA_FIN_PASS);

    this->listo = true;
}

void ControladorCliente::actualizar() {
    std::string mensaje = this->cola_mensajes->desencolar(MSJ_COLA_VACIA);

    if (mensaje == MSJ_CERRAR_CLIENTE ||
    !this->juego_controlador->actualizar(&this->evento, this->cola_inputs) ||
    !this->continuar) {
        this->desconectarse();
        setFin(true);
        this->timeout = 0;
        return;
    }

    else if (mensaje == PRE_NIVEL_INICIAR) {
        std::this_thread::sleep_for(std::chrono::milliseconds(500));
        this->continuar = this->juego_controlador->iniciarNivel(&this->evento, true);
        this->cola_inputs->encolar(TECLA_LISTO);
        this->timeout = 0;
        return;
    }

    else if (mensaje == PRE_NIVEL_REINICIAR) {
        std::this_thread::sleep_for(std::chrono::milliseconds(500));
        this->continuar = this->juego_controlador->iniciarNivel(&this->evento, false);
        this->cola_inputs->encolar(TECLA_LISTO);
        this->timeout = 0;
        return;

    }

   else if (mensaje == PRE_NIVEL_FINALIZAR) {
        std::this_thread::sleep_for(std::chrono::milliseconds(500));
        this->juego_controlador->finalizarNivel();
        this->juego_controlador->avanzarCartelNivel();
        this->timeout = 0;
        return;
    }

   else if (mensaje == PRE_CONGRATULATIONS) {
       //Recibo la cantidad de jugadores en el equipo
        mensaje = this->cola_mensajes->desencolarBloqueante();
        std::this_thread::sleep_for(std::chrono::milliseconds(500));
        this->juego_controlador->juegoGanado(atoi(mensaje.c_str()));
        this->timeout = 0;
        return;
   }

    else if (mensaje == MSJ_PING){
        this->cola_inputs->encolar(TECLA_PING_RECIBIDO);
        this->timeout = 0;
        return;
    }

    else if (mensaje == PRE_GAME_OVER) {
        std::this_thread::sleep_for(std::chrono::milliseconds(500));
        this->juego_controlador->mostrarGameOver();
        this->timeout = 0;
        return;
    }

    else if(mensaje == MSJ_VIVOS_DESCONECTADOS){
        this->juego_controlador->actualizarCartelMuertosConectados(MSJ_MUERTOS_CONECTADOS_1,
                                                                   MSJ_MUERTOS_CONECTADOS_2);
        this->timeout = 0;
        return;
    }

    else if(mensaje != MSJ_COLA_VACIA){
        this->juego_controlador->actualizarVista(mensaje);
        this->juego_controlador->actualizarCartelMuertosConectados((char *)"",
                                                                   (char *)"");
        this->timeout = 0;
        return;
    }

    else{
        this->timeout += 1;
        // ACA NO VA RETURN
    }

    // Sirve para verificar desconexión SI NO ESTOY CLAVADO EN UN CARTEL COMO EL DE PUNTAJES
    if (((unsigned) this->timeout > TIMEOUT_RECEPCION_SV)) {
        //TODO ENTREGA: Dejo esto conectado porque sino se cierra el cliente al debuggear y detener el servidor
        //this->desconectarse();
        return;
    }
}

std::string ControladorCliente::recibir() {
    if (this->cliente_modelo->estaActivo()) {
        char recv_msg[4096]{0};
        int bytes_recv = this->cliente_modelo->recibir(recv_msg);

        std::string answer = "";

        if (bytes_recv > 0) {
            recv_msg[bytes_recv] = '\0';
            answer = std::string(recv_msg);
            return answer;
        }
        this->desconectarse();
        return DESCONECTADO;
    }

    loguearError(LOG_ERROR_RECIBIR);
    return DESCONECTADO;
}

long int ControladorCliente::enviar(uint16_t input) {
    if (this->cliente_modelo->estaActivo()) {
        long int bytes_sent = this->cliente_modelo->enviar(&input);
        std::string answer = "";

        if (bytes_sent <= 0) {
            this->desconectarse();
        }
        return bytes_sent;
    }

    //loguearError(LOG_ERROR_ENVIAR);
    return -1;
}

bool ControladorCliente::estaActivo() {
    return this->cliente_modelo->estaActivo();
}

void ControladorCliente::desconectarse() {
    this->cliente_modelo->desconectarse();
}

void ControladorCliente::enviarStr(std::string str) {
    for(std::string::size_type i = 0; i < str.size(); ++i) {
        this->cola_inputs->encolar( mapeo_letras[ str[i] ] );
    }
}

void ControladorCliente::rechazarConexiones(char *titulo, char *msj) {
    SDL_ShowSimpleMessageBox(SDL_MESSAGEBOX_ERROR, titulo,
                             msj, NULL);
    this->borrarConexion();
    this->listo = false;
    this->juego_controlador->recrearMenu();
    setUsuario("", false);
    setPass("", false);
}
