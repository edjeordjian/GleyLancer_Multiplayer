#include "JuegoVista.h"
#include "EfectoExplosionPersonajeVista.h"
#include "EfectoExplosionEnemigoVista.h"
#include "EfectoExplosionJefeVista.h"
#include "EfectoExplosionCajaVista.h"

JuegoVista::JuegoVista() {

    /* Crear una ventana.
       El solo hecho de crearla ya la muestra en pantalla.
     */
    this->ventana = SDL_CreateWindow(
            NOMBRE_JUEGO,
            X_VENTANA,
            Y_VENTANA,
            ANCHO_VENTANA,
            ALTO_VENTANA,
            STATE_VENTANA
    );

    cargarIcono(RUTA_ICONO, this->ventana);

    this->renderizador = SDL_CreateRenderer(this->ventana, -1, SDL_RENDERER_ACCELERATED);
    this->cargador_enemigos = new CargadorTexturasEnemigos(this->renderizador);
    this->cargador_personajes = new CargadorTexturasPersonajes(this->renderizador);
    this->cargador_proyectiles = new CargadorTexturasProyectiles(this->renderizador);
    this->cargador_cajas = new CargadorTexturasCajas(this->renderizador);
    this->cargador_items = new CargadorTexturasItems(this->renderizador);

    this->nivel = new NivelVista(this->renderizador);

    //SDL_SetRenderDrawColor(this->renderizador, COLOR_BLANCO.r, COLOR_BLANCO.g, COLOR_BLANCO.b, COLOR_BLANCO.a);
    this->puntaje_vista = new PuntajeVista(this->renderizador);

    //Los vectores de enemigos_vista y personajes_vista arrancan vacios, instanciados de forma implicita en el stack

    this->fps = 0;
    this->t_anterior_frame = SDL_GetTicks();

    this->cargador_efectos = new CargadorTexturasEfectos(this->renderizador);

    this->controlador_sonido = nullptr;
    this->n_personaje = 255; //numero invalido

    this->cola_dj = new ColaProtegida<uint16_t>();
    this->dj = std::thread(&JuegoVista::actualizarSonidos, this);
}

JuegoVista::~JuegoVista() {
    this->cola_dj->encolar(DJ_DIE);
    this->dj.join();
    delete(this->cola_dj);

    delete (this->cargador_efectos);

    delete(this->controlador_sonido);

    for (auto &personaje: this->personajes_vista){
        delete(personaje);
    }

    for (auto itr = this->enemigos_vista_map.begin(); itr != this->enemigos_vista_map.end(); ++itr) {
        for (auto &enemigo: *((*itr).second)) {
            delete(enemigo);
        }
        delete((*itr).second);
    }

    for (auto itr = this->proyectiles_vista_map.begin(); itr != this->proyectiles_vista_map.end(); ++itr) {
        for (auto &proyectil: *((*itr).second)){
            delete(proyectil);
        }
        delete((*itr).second);
    }

    for (auto &efecto: this->efectos){
        delete(efecto);
    }

    for (auto &caja: this->cajas) {
        delete(caja);
    }

    for (auto itr = this->items_vista_map.begin(); itr != this->items_vista_map.end(); ++itr) {
        for (auto &item: *((*itr).second)){
            delete(item);
        }
        delete((*itr).second);
    }

    delete (this->nivel);
    delete (this->puntaje_vista);
    delete (this->cargador_enemigos);
    delete (this->cargador_personajes);
    delete (this->cargador_proyectiles);
    delete (this->cargador_cajas);
    delete (this->cargador_items);

    this->destruir();
}

void JuegoVista::actualizarSonidos(){
    int n_sonido = -1;

    while(n_sonido != DJ_DIE){
        n_sonido = this->cola_dj->desencolar(DJ_NO_TRACK);

        if(n_sonido == DJ_NO_TRACK){
            std::this_thread::sleep_for(std::chrono::milliseconds(250));
        }

        else if(n_sonido == DJ_TRACK_NIVEL){
            this->controlador_sonido->playNivel(this->nivel->getNroNivel());
        }

        else if(n_sonido == DJ_TRACK_JEFE_1){
            this->controlador_sonido->playJefe1();
        }

        else if(n_sonido == DJ_TRACK_JEFE_2){
            this->controlador_sonido->playJefe2();
        }

        else if(n_sonido == DJ_TRACK_JEFE_3){
            this->controlador_sonido->playJefe3();
        }

        else if(n_sonido == DJ_TRACK_MENU){
            this->controlador_sonido->playMenu();
        }

        else if(n_sonido == DJ_STOP_STAGE){
            this->controlador_sonido->stopMusicaStages();
        }
    }
}

void JuegoVista::reiniciar() {
    for (auto &personaje: this->personajes_vista){
        delete(personaje);
    }
    for (auto itr = this->enemigos_vista_map.begin(); itr != this->enemigos_vista_map.end(); ++itr) {

        for (auto &enemigo: *((*itr).second)) {
            delete(enemigo);
        }
        (*itr).second->clear();
    }
    this->personajes_vista.clear();
    this->enemigos_vista_map.clear();
    this->puntaje_vista->reiniciar();
    delete (this->nivel);

    this->nivel = new NivelVista(this->renderizador);

}

void JuegoVista::mostrarGameOver() {
    this->controlador_sonido->stopMusicaNivel();
    this->controlador_sonido->playMusicaGameOver();
    this->puntaje_vista->mostrarGameOver();
}

void JuegoVista::destruir() {
    SDL_DestroyRenderer(this->renderizador);
    SDL_DestroyWindow(this->ventana);
}

void JuegoVista::iniciar() {
    /* El clear va DESPUÉS del fondo. */
    SDL_RenderClear(this->renderizador);
}

void JuegoVista::setNumeroPersonaje(int nro_personaje) {
    this->n_personaje = nro_personaje;
}

void JuegoVista::dibujar() {
    /*
                            ::::ACLARACION:::::
    Para los rectagulos tener en cuenta de que la posicion X e Y esta ubicadO en la
    esquina superior izquierda de los mismos.

     */
    SDL_RenderClear(this->renderizador);
    this->nivel->mostrarFondo(this->renderizador);

    this->puntaje_vista->mostrarPuntaje();

    for (auto i = this->proyectiles_vista_map.begin();
         i != this->proyectiles_vista_map.end(); ++i) {
        for (auto proyectil = i->second->begin(); proyectil != i->second->end(); ++proyectil) {
            // Rectángulo para debug
            //SDL_RenderDrawRect(this->renderizador, (*enemigo)->getPosicion());
            SDL_RenderCopy(this->renderizador,
                           (*proyectil)->getTexturaLuz(),
                           NULL,
                           (*proyectil)->getRectLuz()
            );
            SDL_RenderCopy(this->renderizador,
                           (*proyectil)->getTextura(),
                           NULL,
                           (*proyectil)->getPosicion()
            );
        }
    }

    auto itr_per_aux = this->personajes_vista.end();
    for (auto itr_personaje = this->personajes_vista.begin(); itr_personaje != this->personajes_vista.end(); ++itr_personaje) {
        if ((*itr_personaje)->getNumeroPersonaje() == this->n_personaje) {
            itr_per_aux = itr_personaje;
            continue;
        }
        (*itr_personaje)->mostrarEfectoVelocidad(this->renderizador);
        SDL_RenderCopy(this->renderizador,
                       (*itr_personaje)->getTextura(),
                       (*itr_personaje)->getSpriteActual(),
                       (*itr_personaje)->getPosicion()
        );
        (*itr_personaje)->mostrarEfectoEscudo(this->renderizador);
    }
    //Dibujo el personaje propio adelante de los demas
    if ( itr_per_aux != this->personajes_vista.end()) {
        (*itr_per_aux)->mostrarEfectoVelocidad(this->renderizador);
        SDL_RenderCopy(this->renderizador,
                       (*itr_per_aux)->getTextura(),
                       (*itr_per_aux)->getSpriteActual(),
                       (*itr_per_aux)->getPosicion()
        );
        (*itr_per_aux)->mostrarEfectoEscudo(this->renderizador);
    }

    for (std::map<std::string, std::vector<EnemigoVista*>*>::iterator i = this->enemigos_vista_map.begin();
         i != this->enemigos_vista_map.end(); ++i){

        for(std::vector<EnemigoVista*>::iterator enemigo = i->second->begin(); enemigo != i->second->end(); ++enemigo ){
            // Rectángulo para debug
            //SDL_RenderDrawRect(this->renderizador, (*enemigo)->getPosicion());
            SDL_RenderCopy(this->renderizador,
                           (*enemigo)->getTextura(),
                           (*enemigo)->getSpriteActual(),
                           (*enemigo)->getPosicion()
            );
        }
    }

    for(auto &caja: this->cajas) {
        SDL_RenderCopy(this->renderizador,
                       caja->getTextura(),
                       caja->getSpriteActual(),
                       caja->getPosicion()
        );
    }

    for (auto i = this->items_vista_map.begin();
         i != this->items_vista_map.end(); ++i) {
        for (auto item = i->second->begin(); item != i->second->end(); ++item) {
            SDL_RenderCopy(this->renderizador,
                           (*item)->getTextura(),
                           NULL,
                           (*item)->getPosicion()
            );
        }
    }

    for(unsigned long i = 0; i < this->efectos.size(); i++){
        if(this->efectos[i]->estaActivo())
            SDL_RenderCopy(this->renderizador,
                           this->efectos[i]->getTextura(),
                           NULL,
                           this->efectos[i]->getRectangulo()
            );
        else{
            this->efectos.erase(this->efectos.begin() + (int)i);
        }
    }

    SDL_RenderPresent(this->renderizador);
    this->fps++;

    if(!this->controlador_sonido->musicaSonando()){
       this->cola_dj->encolar(DJ_TRACK_NIVEL);
    }

}

void JuegoVista::crearVistaPersonajes(int cantidad){
    for (int j=0; j<cantidad; ++j){
        this->personajes_vista.push_back(new PersonajeVista(X_PERSONAJE_DEFAULT, Y_PERSONAJE_DEFAULT, (int)this->personajes_vista.size(), this->cargador_personajes));
    }
}

void JuegoVista::eliminarVistaPersonajes(int cantidad){
    for (int j=0; j < cantidad; ++j){
        delete(this->personajes_vista[this->personajes_vista.size() - 1]);
        this->personajes_vista.erase(this->personajes_vista.begin() + (int)(this->personajes_vista.size() - 1));
    }
}

void JuegoVista::decodificarEstadoPersonajes(std::string estado) {
    /* Mensaje estado:
     * Posicion_personaje cantidad_personajes Nro_personaje_visible_1 x_personaje_visible_1 y_personaje_visible_1
     * dir_personaje_visible_1 ... x_personaje_visible_n y_personaje_visible_n dir_personaje_visible_n
     */
    std::vector<int> posicion = parserRespuestaPersonajePosicion(estado);
    //El vector "posicion" va a ser una lista de todos los parametros numericos del estado de personajes visibles,
    //es decir: [cantidad_personajes, nro_personaje, x1, y1, dir1, ... , xn, yn, dirn]
    int n_personajes = posicion[0];

    /// Si se agregan parametros al estado del personaje incrementar esta variable
    long unsigned n_parametros_personaje = 9;

    if(n_personajes >= (int)this->personajes_vista.size()){
        this->crearVistaPersonajes(n_personajes - (int)this->personajes_vista.size());
    } else {
        this->eliminarVistaPersonajes((int)this->personajes_vista.size() - n_personajes);
    }
    for (long unsigned i=0; i < (long unsigned)n_personajes; ++i){
        /// Para acceder a cada uno de los parametros de estado multiplico i por la cantidad de parametros de estado
        /// (actualmente 9: nro_personaje, pos_x, pos_y, dir, disparando, daniado, modo test, propulsion, agarro_item)

        //Verifico que el numero del personaje_vista sea igual al numero del personaje que recibi
        if (this->personajes_vista[i]->getNumeroPersonaje() != posicion[i*n_parametros_personaje + 1]) {
            this->personajes_vista[i]->actualizarTexturas(posicion[i*n_parametros_personaje + 1], this->cargador_personajes);
        }

        //If propulsiono y no estaba propulsionando
        if (posicion[i*n_parametros_personaje + 8] && !this->personajes_vista[i]->estaPropulsionando()){
            this->controlador_sonido->playPropulsionPersonaje();
        }
        //Actualizo las posiciones y direccion de cada personaje
        this->personajes_vista[i]->actualizar(posicion[i*n_parametros_personaje + 2],
                                              posicion[i*n_parametros_personaje + 3],
                                              posicion[i*n_parametros_personaje + 4],
                                              posicion[i*n_parametros_personaje + 5],
                                              posicion[i*n_parametros_personaje + 6],
                                              posicion[i*n_parametros_personaje + 7],
                                              posicion[i*n_parametros_personaje + 8]);
        if (posicion[i*n_parametros_personaje + 6]){ //If (daniado)
            this->controlador_sonido->playImpactoPersonaje();
        }
        if (posicion[i*n_parametros_personaje + 9]) { //If (agarro_item)
            this->controlador_sonido->playAgarrarItem();
        }
    }
}

void JuegoVista::crearVistaEnemigos(std::string tipo, int cantidad){
    if(this->enemigos_vista_map.find(tipo) == this->enemigos_vista_map.end()){
        this->enemigos_vista_map[tipo] = new std::vector<EnemigoVista*>();

    }
    for (int i=0; i < cantidad; ++i){
        if ( tipo == getTipoEnemigo1() )
        {
            this->enemigos_vista_map.at(tipo)->push_back(
                    new Enemigo1Vista(0, 0, this->cargador_enemigos));
        }
        else if( tipo == getTipoEnemigo2() )
        {
            this->enemigos_vista_map.at(tipo)->push_back(
                    new Enemigo2Vista(0, 0, this->cargador_enemigos));
        }
        else if ( tipo == TIPO_JEFE_1 ){
            this->cola_dj->encolar(DJ_TRACK_JEFE_1);

            this->enemigos_vista_map.at(tipo)->push_back(
                    new Jefe1Vista(0, 0, this->cargador_enemigos));
        }
        else if ( tipo == TIPO_JEFE_2 ){
            this->cola_dj->encolar(DJ_TRACK_JEFE_2);

            this->enemigos_vista_map.at(tipo)->push_back(
                    new Jefe2Vista(0, 0, this->cargador_enemigos));
        }
        else if ( tipo == TIPO_JEFE_3 ){
            this->cola_dj->encolar(DJ_TRACK_JEFE_3);

            this->enemigos_vista_map.at(tipo)->push_back(
                    new Jefe3Vista(0, 0, this->cargador_enemigos));
        }
    }

}

void JuegoVista::actualizarVistaEnemigos(std::string tipo, int cantidad, std::stringstream* stream_estado){
    int x, y, d;
    bool daniado;
    std::string aux;
    for (int j=0; j < cantidad; ++j){
        (*stream_estado) >> aux; //x enemigo
        x = (int)std::stof(aux);
        (*stream_estado) >> aux; //y enemigo
        y = (int)std::stof(aux);
        (*stream_estado) >> aux; //y enemigo
        d = (int)std::stof(aux);
        (*stream_estado) >> aux; //daniado enemigo
        daniado = (bool) std::stoi(aux);

        (*(this->enemigos_vista_map[tipo]))[(long unsigned)j]->actualizar(x,y,d, daniado);

        if (daniado){
            this->controlador_sonido->playImpactoEnemigo();
        }
    }
}

void JuegoVista::decodificarEstadoEnemigos(std::string estado){

    int cantidad_clase_i;
    std::string clase_i;
    std::string aux;  // palabras extraidas del estados

    std::vector<std::string>::iterator pos_tipo_enemigo;
    std::vector<std::string> tipos_enemigos_vista_actual;

    std::stringstream stream_estado(estado); // stream de las palabras de estado
    stream_estado >> aux; //leo el PRE_ENEMIGO, no sirve de nada pero lo tengo que sacar
    stream_estado >> aux; // leo cantidad de clases de cada enemigo
    int cantidad_clases = atoi(aux.c_str()); // convierto a entero la cantidad de clases

    //Obtengo los tipos de los enemigos actualmente en la vista dibujados
    for (std::map<std::string, std::vector<EnemigoVista*>*>::iterator i = this->enemigos_vista_map.begin();
         i != this->enemigos_vista_map.end(); ++i) {

        tipos_enemigos_vista_actual.push_back(i->first);
    }

    for(int i = 0; i < cantidad_clases; i++){

        stream_estado >> aux; //Clase
        clase_i = aux;

        stream_estado >> aux; //cantidad enemigos de esa clase
        cantidad_clase_i = (int)std::stof(aux);

        //Ajusto las cantidades de enemigos de esa clase en mi map de enemigos vista
        pos_tipo_enemigo = std::find(tipos_enemigos_vista_actual.begin(), tipos_enemigos_vista_actual.end(), clase_i);
        if (pos_tipo_enemigo != tipos_enemigos_vista_actual.end()) {
            tipos_enemigos_vista_actual.erase(pos_tipo_enemigo);
            cantidad_clase_i -= (int) (this->enemigos_vista_map[clase_i]->size());
            if (cantidad_clase_i >= 0) {
                this->crearVistaEnemigos(clase_i, cantidad_clase_i);
            } else {
                this->eliminarVistaEnemigos(clase_i, -1*cantidad_clase_i);
            }
        } else {
            this->crearVistaEnemigos(clase_i, cantidad_clase_i);
        }
        //Recupero el valor de cantidad_clase_i leido
        cantidad_clase_i = (int)std::stof(aux);

        //Actualizo las posiciones de los enemigos de esa clase
        this->actualizarVistaEnemigos(clase_i, cantidad_clase_i, &stream_estado);
    }

    //Elimino los enemigos de clases no recibidas
    for(auto &tipo: tipos_enemigos_vista_actual){
        cantidad_clase_i = (int) this->enemigos_vista_map[tipo]->size();
        this->eliminarVistaEnemigos(tipo, cantidad_clase_i);
    }
}

void JuegoVista::eliminarVistaEnemigos(std::string tipo, int cantidad){
    for (int j=0; j < cantidad; ++j){
        //Borro los enemigos vista que esten de mas en la ventana
        delete((*(this->enemigos_vista_map[tipo]))[this->enemigos_vista_map[tipo]->size() -1]);
        this->enemigos_vista_map[tipo]->erase(this->enemigos_vista_map[tipo]->begin() + (int)(this->enemigos_vista_map[tipo]->size() - 1) );
    }
}

void JuegoVista::crearVistaProyectiles(int nro_jugador, int cantidad) {
    if (this->proyectiles_vista_map.find(nro_jugador) == this->proyectiles_vista_map.end()) {
        this->proyectiles_vista_map[nro_jugador] = new std::vector<ProyectilVista *>();
    }
    for (int i = 0; i < cantidad; ++i) {
        //map.at() lanza excepcion en caso de que no exista la clave
        this->proyectiles_vista_map.at(nro_jugador)->push_back(
                new ProyectilVista(0, 0, nro_jugador, this->cargador_proyectiles));

        //this->controlador_sonido->playDisparo();
    }
}

void JuegoVista::actualizarVistaProyectiles(int nro_jugador, int cantidad, std::stringstream *stream_estado) {
    int x, y, es_nuevo;
    std::string aux;
    for (int j = 0; j < cantidad; ++j) {
        (*stream_estado) >> aux; //x proyectil
        x = (int) std::stof(aux);
        (*stream_estado) >> aux; //y proyectil
        y = (int) std::stof(aux);
        (*stream_estado) >> aux; //es nuevo
        es_nuevo = (int) std::stof(aux);
        if(es_nuevo == 1){
            this->controlador_sonido->playDisparo();
        }
        (*(this->proyectiles_vista_map[nro_jugador]))[(long unsigned) j]->actualizar(x, y, 0);
    }
}

void JuegoVista::decodificarEstadoProyectiles(std::string estado) {
    int cantidad_tipo_nro_jugador_i;
    int tipo_nro_jugador;
    std::string aux;  // palabras extraidas del estados
    std::vector<int>::iterator pos_tipo_proyectil;
    std::vector<int> tipos_proyectiles_vista_actual;    //cada int representa al numero de jugador
    std::stringstream stream_estado(estado); // stream de las palabras de estado
    stream_estado >> aux; //leo el PRE_PROYECTIL, no sirve de nada pero lo tengo que sacar
    stream_estado >> aux; // leo cantidad de tipos de proyectiles (1 por cada personaje que disparó)
    int cantidad_tipos_proyectiles = atoi(aux.c_str()); // convierto a entero la cantidad de cantidad_tipos_proyectiles
    //Obtengo los cantidad_tipos_proyectiles actualmente en la vista dibujados
    for (auto i = this->proyectiles_vista_map.begin(); i != this->proyectiles_vista_map.end(); ++i) {
        tipos_proyectiles_vista_actual.push_back(i->first);
    }
    for (int i = 0; i < cantidad_tipos_proyectiles; i++) {
        stream_estado >> aux; //Clase de proyectil (numero de jugador)
        tipo_nro_jugador = atoi(aux.c_str());
        stream_estado >> aux; //cantidad proyectiles de ese tipo (del jugador)
        cantidad_tipo_nro_jugador_i = (int) std::stof(aux);
        //Ajusto las cantidades de proyectiles de esa clase en mi map de proyectiles vista
        pos_tipo_proyectil = std::find(tipos_proyectiles_vista_actual.begin(), tipos_proyectiles_vista_actual.end(),
                                       tipo_nro_jugador);
        if (pos_tipo_proyectil != tipos_proyectiles_vista_actual.end()) {
            tipos_proyectiles_vista_actual.erase(pos_tipo_proyectil);
            cantidad_tipo_nro_jugador_i -= (int) (this->proyectiles_vista_map[tipo_nro_jugador]->size());
            if (cantidad_tipo_nro_jugador_i >= 0) {
                this->crearVistaProyectiles(tipo_nro_jugador, cantidad_tipo_nro_jugador_i);
            } else {
                this->eliminarVistaProyectiles(tipo_nro_jugador, -1 * cantidad_tipo_nro_jugador_i);
            }
        } else {
            this->crearVistaProyectiles(tipo_nro_jugador, cantidad_tipo_nro_jugador_i);
        }
        //Recupero el valor de cantidad_tipo_nro_jugador_i leido
        cantidad_tipo_nro_jugador_i = (int) std::stof(aux);
        //Actualizo las posiciones de los proyectiles de ese tipo
        this->actualizarVistaProyectiles(tipo_nro_jugador, cantidad_tipo_nro_jugador_i, &stream_estado);
    }
    //Elimino los enemigos de clases no recibidas
    for (auto &tipo: tipos_proyectiles_vista_actual) {
        cantidad_tipo_nro_jugador_i = (int) this->proyectiles_vista_map[tipo]->size();
        this->eliminarVistaProyectiles(tipo, cantidad_tipo_nro_jugador_i);
    }

}

void JuegoVista::eliminarVistaProyectiles(int nro_jugador, int cantidad) {
    for (int j = 0; j < cantidad; ++j) {
        //Borro los proyectiles vista que esten de mas en la ventana
        delete ((*(this->proyectiles_vista_map[nro_jugador]))[this->proyectiles_vista_map[nro_jugador]->size() - 1]);
        this->proyectiles_vista_map[nro_jugador]->erase(this->proyectiles_vista_map[nro_jugador]->begin() +
                                                        (int) (this->proyectiles_vista_map[nro_jugador]->size() - 1));
    }
}

void JuegoVista::crearVistaCajas(int cantidad){
    for (int j=0; j<cantidad; ++j){
        this->cajas.push_back(new CajaVista(X_PERSONAJE_DEFAULT, Y_PERSONAJE_DEFAULT, this->cargador_cajas));
    }
}

void JuegoVista::actualizarVistaCajas(int cantidad, std::stringstream *stream_estado) {
    int x, y;
    std::string aux;
    for (long unsigned j = 0; j < (long unsigned)cantidad; ++j) {
        (*stream_estado) >> aux; //x proyectil
        x = (int) std::stof(aux);
        (*stream_estado) >> aux; //y proyectil
        y = (int) std::stof(aux);
        this->cajas[j]->actualizar(x, y);
    }
}

void JuegoVista::decodificarEstadoCajas(std::string estado) {
    std::string aux;  // palabras extraidas del estado
    std::stringstream stream_estado(estado); // stream de las palabras de estado
    stream_estado >> aux; //leo el PRE_CAJAS, no sirve de nada pero lo tengo que sacar
    stream_estado >> aux; // leo cantidad de cajas en la ventana
    int cantidad_cajas = atoi(aux.c_str()); // convierto a entero la cantidad de cajas
    //Obtengo los cantidad de cajas actualmente en la vista dibujadas
    int cantidad_cajas_anterior = (int) this->cajas.size();
    if (cantidad_cajas - cantidad_cajas_anterior >= 0){
        this->crearVistaCajas(cantidad_cajas - cantidad_cajas_anterior);
    } else {
        this->eliminarVistaCajas(cantidad_cajas_anterior - cantidad_cajas);
    }

    this->actualizarVistaCajas(cantidad_cajas, &stream_estado);
}

void JuegoVista::eliminarVistaCajas(int cantidad){
    for (int j=0; j < cantidad; ++j){
        delete(this->cajas[this->cajas.size() - 1]);
        this->cajas.erase(this->cajas.begin() + (int)(this->cajas.size() - 1));
    }
}

void JuegoVista::crearVistaItems(int tipo, int cantidad){
    if (this->items_vista_map.find(tipo) == this->items_vista_map.end()) {
        this->items_vista_map[tipo] = new std::vector<ItemVista *>();
    }
    for (int i = 0; i < cantidad; ++i) {
        //map.at() lanza excepcion en caso de que no exista la clave
        this->items_vista_map.at(tipo)->push_back(
                new ItemVista(0, 0, tipo, this->cargador_items));
    }
}

void JuegoVista::actualizarVistaItems(int tipo, int cantidad, std::stringstream *stream_estado) {
    int x, y;
    std::string aux;
    for (int j = 0; j < cantidad; ++j) {
        (*stream_estado) >> aux; //x item
        x = (int) std::stof(aux);
        (*stream_estado) >> aux; //y item
        y = (int) std::stof(aux);
        (*(this->items_vista_map[tipo]))[(long unsigned) j]->actualizar(x, y);
    }
}

void JuegoVista::decodificarEstadoItems(std::string estado) {

    int cantidad_tipo_i;
    int tipo_i;
    std::string aux;  // palabras extraidas del estados
    std::vector<int>::iterator pos_tipo_item;
    std::vector<int> tipos_items_vista_actual;    //cada int representa al tipo del item
    std::stringstream stream_estado(estado);     // stream de las palabras de estado
    stream_estado >> aux; //leo el PRE_ITEMS, no sirve de nada pero lo tengo que sacar
    stream_estado >> aux; // leo cantidad de tipos de items
    int cantidad_tipos_items = atoi(aux.c_str()); // convierto a entero la cantidad de cantidad_tipos_items
    //Obtengo los cantidad_tipos_items actualmente en la vista dibujados
    for (auto i = this->items_vista_map.begin(); i != this->items_vista_map.end(); ++i) {
        tipos_items_vista_actual.push_back(i->first);
    }
    for (int i = 0; i < cantidad_tipos_items; i++) {
        stream_estado >> aux; //Tipo del item
        tipo_i = atoi(aux.c_str());
        stream_estado >> aux; //cantidad items de ese tipo
        cantidad_tipo_i = (int) std::stof(aux);
        //Ajusto las cantidades de items de esa clase en mi map de items vista
        pos_tipo_item = std::find(tipos_items_vista_actual.begin(), tipos_items_vista_actual.end(), tipo_i);
        if (pos_tipo_item != tipos_items_vista_actual.end()) {
            tipos_items_vista_actual.erase(pos_tipo_item);
            cantidad_tipo_i -= (int) (this->items_vista_map[tipo_i]->size());
            if (cantidad_tipo_i >= 0) {
                this->crearVistaItems(tipo_i, cantidad_tipo_i);
            } else {
                this->eliminarVistaItems(tipo_i, -1 * cantidad_tipo_i);
            }
        } else {
            this->crearVistaItems(tipo_i, cantidad_tipo_i);
        }
        //Recupero el valor de cantidad_tipo_i leido
        cantidad_tipo_i = (int) std::stof(aux);
        //Actualizo las posiciones de los items de ese tipo
        this->actualizarVistaItems(tipo_i, cantidad_tipo_i, &stream_estado);
    }
    //Elimino los enemigos de clases no recibidas
    for (auto &tipo: tipos_items_vista_actual) {
        cantidad_tipo_i = (int) this->items_vista_map[tipo]->size();
        this->eliminarVistaItems(tipo, cantidad_tipo_i);
    }

}

void JuegoVista::eliminarVistaItems(int tipo, int cantidad){
    for (int j = 0; j < cantidad; ++j) {
        //Borro los items vista que esten de mas en la ventana
        delete ((*(this->items_vista_map[tipo]))[this->items_vista_map[tipo]->size() - 1]);
        this->items_vista_map[tipo]->erase(this->items_vista_map[tipo]->begin() +
                                                        (int) (this->items_vista_map[tipo]->size() - 1));
    }
}


void JuegoVista::decodificarEstadoEfectos(std::string estado) {
    std::string aux;  // palabras extraidas del estados
    std::stringstream stream_estado(estado); // stream de las palabras de estado
    stream_estado >> aux; //leo el PRE_EFECTO, no sirve de nada pero lo tengo que sacar
    stream_estado >> aux; // leo cantidad tipos efectos que  voy a crear
    int cantidad_tipos = atoi(aux.c_str()); // convierto a entero la cantidad de tipos

    for (int c = 0; c < cantidad_tipos; c++) {
        stream_estado >> aux;                               // leo el tipo efecto que voy a crear
        if(aux == PRE_EFECTO_PERSONAJE){
            stream_estado >> aux;                           // leo cantidad de efectos a crear de personaje
            int cantidad_efectos = atoi(aux.c_str());       // convierto a entero la cantidad de clases
            for (int i = 0; i < cantidad_efectos; i++) {
                stream_estado >> aux;
                int pos_x = atoi(aux.c_str());
                stream_estado >> aux;
                int pos_y = atoi(aux.c_str());
                this->efectos.push_back(new EfectoExplosionPersonajeVista(pos_x, pos_y, this->cargador_efectos ));

                loguearInfo(LOG_PERSONAJE_MUERE);
                this->controlador_sonido->playExplosion();
            }
        }
        else if (aux == PRE_EFECTO_ENEMIGO){
            stream_estado >> aux;
            int cantidad_efectos = atoi(aux.c_str());
            for (int i = 0; i < cantidad_efectos; i++) {
                stream_estado >> aux;
                int pos_x = atoi(aux.c_str());
                stream_estado >> aux;
                int pos_y = atoi(aux.c_str());
                this->efectos.push_back(new EfectoExplosionEnemigoVista(pos_x, pos_y, this->cargador_efectos));
                loguearInfo(LOG_ENEMIGO_MUERE);
                this->controlador_sonido->playExplosion();
            }
        }
        else if (aux == PRE_EFECTO_JEFE){
            stream_estado >> aux;
            int cantidad_efectos = atoi(aux.c_str());
            for (int i = 0; i < cantidad_efectos; i++) {
                stream_estado >> aux;
                int pos_x = atoi(aux.c_str());
                stream_estado >> aux;
                int pos_y = atoi(aux.c_str());
                int nro_nivel = this->nivel->getNroNivel();
                this->efectos.push_back(new EfectoExplosionJefeVista(pos_x, pos_y,nro_nivel, this->cargador_efectos));
                loguearInfo(LOG_JEFE_MUERE);
                this->controlador_sonido->playExplosion();
            }
        }
        else if (aux == PRE_EFECTO_CAJA){
            stream_estado >> aux;
            int cantidad_efectos = atoi(aux.c_str());
            for (int i = 0; i < cantidad_efectos; i++) {
                stream_estado >> aux;
                int pos_x = atoi(aux.c_str());
                stream_estado >> aux;
                int pos_y = atoi(aux.c_str());
                this->efectos.push_back(new EfectoExplosionCajaVista(pos_x, pos_y,this->cargador_efectos));
                this->controlador_sonido->playExplosion();
            }
        }
    }
}

void JuegoVista::actualizarTablaPuntajes(std::string estado ){
    // setear puntajes (los textos ya creados, pero con str vacío)

    std::string aux;  // palabras extraidas del estados
    std::stringstream stream_estado(estado); // stream de las palabras de estado
    stream_estado >> aux; //leo el PRE_TABLAS_PUNTAJE, no sirve de nada pero lo tengo que sacar
    stream_estado >> aux; // leo cantidad de personajes

    unsigned int cantidad_personajes = (unsigned int) atoi(aux.c_str()); // cantidad de personajes

    // Estructura de tabla puntajes: 5 títulos y después
    // 5 valores por cada personaje.
    for (unsigned int i = CANT_TITULOS_TABLA_PUNTAJES;
         i < cantidad_personajes * CANT_TITULOS_TABLA_PUNTAJES + CANT_TITULOS_TABLA_PUNTAJES;
         i += 1){
        stream_estado >> aux;
        this->puntaje_vista->setTextoTablaPuntajes(i, aux.c_str());
    }

}

void JuegoVista::actualizar(std::string estado) {

    if (parserTipoRespuesta(estado) == PRE_POSICION_JUGADOR) {
        this->decodificarEstadoPersonajes(estado);
    }

    else if (parserTipoRespuesta(estado) == PRE_POSICION_ENEMIGO) {
        this->decodificarEstadoEnemigos(estado);
    }

    else if (parserTipoRespuesta(estado) == PRE_POSICION_PROYECTILES) {
        this->decodificarEstadoProyectiles(estado);
    }

    else if (parserTipoRespuesta(estado) == PRE_PUNTAJES_VIDAS) {
        this->puntaje_vista->actualizarPuntajes(estado);
    }

    else if (parserTipoRespuesta(estado) == PRE_EFECTOS) {
        this->decodificarEstadoEfectos(estado);
    }

    else if (parserTipoRespuesta(estado) == PRE_CAJAS) {
        this->decodificarEstadoCajas(estado);
    }

    else if (parserTipoRespuesta(estado) == PRE_ITEMS) {
        this->decodificarEstadoItems(estado);
    }

    else if (parserTipoRespuesta(estado) == PRE_TABLAS_PUNTAJE){
        this->actualizarTablaPuntajes(estado);
    }

    /// Agrego este comentario para avisar que estoy dibujando SOLO en el caso de recibir una actualizacion del fondo
    /// (que se recibe siempre)

    if (parserTipoRespuesta(estado) == PRE_POSICION_VENTANA) {
        int posicion = parserRespuestaVentanaPosicion(estado);
        this->nivel->actualizarPosicionFondo(posicion);

        Uint32 deltaclock = SDL_GetTicks() - this->t_anterior_frame;
        if (deltaclock < MILISEG_MIN_FPS) {
            std::this_thread::sleep_for(std::chrono::milliseconds(MILISEG_MIN_FPS - deltaclock));
            //SDL_Delay(MILISEG_MIN_FPS - deltaclock);
        }

        this->dibujar();

        if(SDL_GetTicks() % 1000 < this->t_anterior_frame % 1000 ){
            //std::cout << "FPS: " << this->fps << std::endl;
            this->fps = 0;
        }

        this->t_anterior_frame = SDL_GetTicks();

    }
}

void JuegoVista::avanzarNivel() {
    for (auto &efecto: this->efectos){
        delete(efecto);
    }
    this->efectos.clear();

    this->nivel->avanzarNivel();
    this->controlador_sonido->stopMusicaNivel();
    this->controlador_sonido->playMusicaFinNivel();
    this->puntaje_vista->mostrarTablaPuntaje();

}

SDL_Renderer *JuegoVista::getRenderizador() {
    return this->renderizador;
}

void JuegoVista::setNivel(int nro_nivel){
    for (int i = 0; i < nro_nivel; ++i){
        this->nivel->avanzarNivel();
        this->puntaje_vista->avanzarCartelNivel();
    }

}

void JuegoVista::setControladorSonido(JuegoSonido *juego_sonido) {
    this->controlador_sonido = juego_sonido;
}

void JuegoVista::reiniciarMusica() {
    this->controlador_sonido->stopMusicaNivel();
    this->cola_dj->encolar(DJ_TRACK_MENU);
}

void JuegoVista::avanzarCartelNivel() {
    puntaje_vista->avanzarCartelNivel();
}

void JuegoVista::pararMusicaNivel() {
    this->cola_dj->encolar(DJ_STOP_STAGE);
}
