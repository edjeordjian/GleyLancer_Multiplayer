#include "JuegoControlador.h"
#include <SDL2/SDL.h>

JuegoControlador::JuegoControlador() {
    SDL_Init(SDL_INIT_EVERYTHING);
    TTF_Init();
    this->vista = new JuegoVista();
    SDL_RenderSetLogicalSize(this->vista->getRenderizador(), ANCHO_VENTANA, ALTO_VENTANA);
    SDL_SetHint(SDL_HINT_RENDER_SCALE_QUALITY, "nearest");
    SDL_SetHint(SDL_HINT_RENDER_LOGICAL_SIZE_MODE, "letterbox");

    this->controlador_sonido = new JuegoSonido();
    this->tecla_mute = false;
    this->tecla_mute_sfx = false;
    this->tecla_test = false;

    this->vista->setControladorSonido(this->controlador_sonido);

    this->menu = new MenuJuegoControlador(this->vista->getRenderizador());
    this->menu_log = nullptr;
    this->cartel_controlador = new CartelControlador(this->vista->getRenderizador());
    this->tecla_movimiento = TECLA_NINGUNA;
    this->tecla_disparo = TECLA_NO_DISPARAR;
    this->tecla_propulsion = false;

    this->cola_actualizaciones_vista = new ColaProtegida<std::string>();
    this->hilo_dibujador = new HiloDibujador(this->cola_actualizaciones_vista, this->vista);
    this->hilo_dibujador->ejecutar();
}

JuegoControlador::~JuegoControlador() {
    delete(this->hilo_dibujador);
    delete(this->cartel_controlador);
    if (this->menu) {
        delete(this->menu);
    }
    if (this->menu_log) {
        delete(this->menu_log);
    }
    delete(this->cola_actualizaciones_vista);

    delete(this->vista);
    TTF_Quit();
    SDL_Quit();
}

void JuegoControlador::reiniciar() {
    delete(this->hilo_dibujador);
    delete(this->cola_actualizaciones_vista);

    this->vista->reiniciar();

    this->resetearCartel();

    if (this->menu) {
        delete(this->menu);
    }
    if (this->menu_log) {
        delete(this->menu_log);
    }

    this->menu_log = nullptr;

    this->menu = new MenuJuegoControlador(this->vista->getRenderizador());

    this->cola_actualizaciones_vista = new ColaProtegida<std::string>();
    this->hilo_dibujador = new HiloDibujador(this->cola_actualizaciones_vista, this->vista);
    this->hilo_dibujador->ejecutar();
    this->vista->reiniciarMusica();
}

bool JuegoControlador::iniciar() {
    this->menu->iniciar();
    this->vista->iniciar();
    //this->vista->actualizar(this->juego->getEstadoPersonaje());
    return true;
}

void JuegoControlador::cartelIniciarJuego(){
    this->cartel_controlador->setIniciarJuego();
}

bool JuegoControlador::actualizarMenu() {
    if (!this->controlador_sonido->musicaSonando()){
        this->controlador_sonido->playMenu();
    }

    return this->menu->actualizar(this->controlador_sonido);
}

bool JuegoControlador::inicioElJuego() {
    return this->menu->estaIniciado();
}

bool JuegoControlador::juegoCancelado(SDL_Event *evento) {
     if (this->menu) {
         return this->menu->estaCancelado(evento);
     }
     else {
         return this->menu_log->estaCancelado(evento);
     }
}

bool JuegoControlador::actualizar(SDL_Event* evento, ColaProtegida<uint16_t>* cola_inputs) {

    SDL_PollEvent(evento);
    const Uint8 *keystates = SDL_GetKeyboardState(NULL);

    if (evento->type == SDL_QUIT or keystates[SDL_SCANCODE_ESCAPE]) {
        loguearInfo(LOG_JUEGO_CERRADO_POR_USER);
        return false;
    }

    if (keystates[SDL_SCANCODE_UP] and keystates[SDL_SCANCODE_LEFT]) {
        if (this->tecla_movimiento != TECLAS_ARRIBA_IZQUIERDA) {
            cola_inputs->encolar(TECLAS_ARRIBA_IZQUIERDA);
            loguearDebug(LOG_MOV_SUP_IZQ);
            this->tecla_movimiento = TECLAS_ARRIBA_IZQUIERDA;
        }

    } else if (keystates[SDL_SCANCODE_UP] and keystates[SDL_SCANCODE_RIGHT]) {
        if (this->tecla_movimiento != TECLAS_ARRIBA_DERECHA) {
            cola_inputs->encolar(TECLAS_ARRIBA_DERECHA);
            loguearDebug(LOG_MOV_SUP_DER);
            this->tecla_movimiento = TECLAS_ARRIBA_DERECHA;
        }

    } else if (keystates[SDL_SCANCODE_DOWN] and keystates[SDL_SCANCODE_LEFT]) {
        if (this->tecla_movimiento != TECLAS_ABAJO_IZQUIERDA) {
            cola_inputs->encolar(TECLAS_ABAJO_IZQUIERDA);
            loguearDebug(LOG_MOV_ABA_IZQ);
            this->tecla_movimiento = TECLAS_ABAJO_IZQUIERDA;
        }

    } else if (keystates[SDL_SCANCODE_DOWN] and keystates[SDL_SCANCODE_RIGHT]) {
        if (this->tecla_movimiento != TECLAS_ABAJO_DERECHA) {
            cola_inputs->encolar(TECLAS_ABAJO_DERECHA);
            loguearDebug(LOG_MOV_ABA_DER);
            this->tecla_movimiento = TECLAS_ABAJO_DERECHA;
        }

    } else if (keystates[SDL_SCANCODE_UP]) {
        if (this->tecla_movimiento != TECLA_ARRIBA) {
            cola_inputs->encolar(TECLA_ARRIBA);
            loguearDebug(LOG_MOV_ARRIBA);
            this->tecla_movimiento = TECLA_ARRIBA;
        }

    } else if (keystates[SDL_SCANCODE_LEFT]) {
        if (this->tecla_movimiento != TECLA_IZQUIERDA) {
            cola_inputs->encolar(TECLA_IZQUIERDA);
            loguearDebug(LOG_MOV_IZQ);
            this->tecla_movimiento = TECLA_IZQUIERDA;
        }

    } else if (keystates[SDL_SCANCODE_DOWN]) {
        if (this->tecla_movimiento != TECLA_ABAJO) {
            cola_inputs->encolar(TECLA_ABAJO);
            loguearDebug(LOG_MOV_ABAJO);
            this->tecla_movimiento = TECLA_ABAJO;
        }

    } else if (keystates[SDL_SCANCODE_RIGHT]) {
        if (this->tecla_movimiento != TECLA_DERECHA) {
            cola_inputs->encolar(TECLA_DERECHA);
            loguearDebug(LOG_MOV_DER);
            this->tecla_movimiento = TECLA_DERECHA;
        }

    } else if (this->tecla_movimiento != TECLA_NINGUNA) {
        cola_inputs->encolar(TECLA_NINGUNA);
        this->tecla_movimiento = TECLA_NINGUNA;

    }

    if (keystates[SDL_SCANCODE_S]) {
        if (this->tecla_disparo != TECLA_DISPARAR) {
            cola_inputs->encolar(TECLA_DISPARAR);
            loguearDebug(LOG_DISPARAR);
            this->tecla_disparo = TECLA_DISPARAR;
        }
    } else {
        if (this->tecla_disparo != TECLA_NO_DISPARAR) {
            cola_inputs->encolar(TECLA_NO_DISPARAR);
            loguearDebug(LOG_NO_DISPARAR);
            this->tecla_disparo = TECLA_NO_DISPARAR;
        }
    }

    if (keystates[SDL_SCANCODE_A]) {
        if (!this->tecla_propulsion){
            cola_inputs->encolar(TECLA_PROPULSION);
            loguearDebug(LOG_TECLA_PROPULSION);
            this->tecla_propulsion = true;
        }
    } else if (this->tecla_propulsion) {
        this->tecla_propulsion = false;
    }

    if (keystates[SDL_SCANCODE_LCTRL]){
        if (!this->tecla_mute_sfx){
            this->controlador_sonido->muteSFX();
            loguearDebug(LOG_CAMBIAR_AUDIO_SFX);
            this->tecla_mute_sfx = true;
        }
    } else{
        this->tecla_mute_sfx = false;
    }

    if (keystates[SDL_SCANCODE_SPACE]){
        if (!this->tecla_mute){
            this->controlador_sonido->mute();
            loguearDebug(LOG_CAMBIAR_AUDIO);
            this->tecla_mute = true;
        }
    } else{
        this->tecla_mute = false;
    }

    if(keystates[SDL_SCANCODE_T]){
        if (!this->tecla_test) {
            loguearDebug(LOG_CAMBIAR_MODO_JUEGO);
            cola_inputs->encolar(TECLA_TEST);
            this->tecla_test = true;
        }
    }
    else {
        this->tecla_test = false;
    }

    return   (evento->type != SDL_QUIT)
          && !(keystates[SDL_SCANCODE_ESCAPE]);
}

void JuegoControlador::desactivarInput(){
    this->cartel_controlador->desactivarInput();
}

bool JuegoControlador::iniciarNivel(SDL_Event* evento, bool actualizar_cartel){
    this->controlador_sonido->stopMusicaNivel();
    this->controlador_sonido->playMusicaStages();
    bool retorno = this->cartel_controlador->iniciarNivel(evento, actualizar_cartel, controlador_sonido);
    this->vista->pararMusicaNivel();
    return retorno;
}

void JuegoControlador::finalizarNivel(){
    this->vista->avanzarNivel();
}

void JuegoControlador::juegoGanado(int cantidad_ganadores){
    this->controlador_sonido->stopMusicaNivel();
    this->controlador_sonido->playMusicaFinNivel();
    this->cartel_controlador->mostrarJuegoGanado(cantidad_ganadores);
}

void JuegoControlador::mostrarGameOver() {
    this->vista->mostrarGameOver();
}

void JuegoControlador::actualizarVista(std::string estado){
    this->cola_actualizaciones_vista->encolar(estado);
}

void JuegoControlador::setNumeroPersonaje(int nro_personaje){
    this->vista->setNumeroPersonaje(nro_personaje);
}

void JuegoControlador::menuLogReestablecer() {
    this->menu_log->reestablecer();
}

void JuegoControlador::reestablecerMenu() {
    this->menu->reestablecer();
}

bool JuegoControlador::actualizarCartel(SDL_Event* evento) {
    return this->cartel_controlador->actualizar(evento, false, this->controlador_sonido);
}

void JuegoControlador::retrocederCartel() {
    this->cartel_controlador->retrocederCartel();
}

void JuegoControlador::resetearCartel() {
    this->cartel_controlador->resetearCarteles();
}

void JuegoControlador::cambiarCartel() {
    this->cartel_controlador->cambiar();
}

int JuegoControlador::actualizarMenuLog() {
    return this->menu_log->actualizar(this->controlador_sonido);
}

bool JuegoControlador::menuLogEstaIniciado() {
    return this->menu_log->estaIniciado();
}

void JuegoControlador::actualizarJugadoresConectados(std::string mensaje) {
    this->cartel_controlador->actualizarJugadoresConectados(mensaje);
}

void JuegoControlador::iniciarVista() {
    this->vista->iniciar();
    this->controlador_sonido->stopMenu();
}

//Setea los carteles de nivel y el nivel a dibujar a partir de un mensaje de la forma "PRE_NIVEL_NUM n", con n el numero de nivel (entre 0 y 2)
void JuegoControlador::actualizarNivel(std::string estado_nivel){
    //std::cout << estado_nivel << std::endl;
    std::stringstream str(estado_nivel);
    std::string aux;
    str >> aux;
    if (aux == PRE_NIVEL_NUM){
        str >> aux;
        int nivel = (int)strtol(aux.c_str(), NULL, 10);
        //Se setea el cartel anterior al de "Stage nro_nivel" ya que luego se recibe el mensaje "PRE_NIVEL_INICIAR" que avanza de cartel
        this->cartel_controlador->setNivel(nivel);
        this->vista->setNivel(nivel);
    }
}


void JuegoControlador::cerrarMenuPrincipal() {
    delete (this->menu);
    this->menu = nullptr;
    this->menu_log = new MenuLogControlador(this->vista->getRenderizador());
}

void JuegoControlador::recrearMenu() {
    delete(this->menu_log);
    this->menu_log = nullptr;
    this->menu = new MenuJuegoControlador(this->vista->getRenderizador());
}

void JuegoControlador::actualizarCartelMuertosConectados(char* m1, char* m2) {
    this->cartel_controlador->actualizarCartelMuertosConectados(m1, m2);
}

void JuegoControlador::avanzarCartelNivel() {
    vista->avanzarCartelNivel();
}