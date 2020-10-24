#include "CartelControlador.h"


CartelControlador::CartelControlador(SDL_Renderer* renderizador) {
    this->cartel = new Cartel();
    this->vista_cartel = new CartelVista(renderizador);
}

void CartelControlador::desactivarInput(){
    this->cartel->setEsperaInput(false);
}

void CartelControlador::retrocederCartel() {
    this->cartel->retrocederCartel();
}


bool CartelControlador::actualizar(SDL_Event* evento, bool usar_numero, JuegoSonido* cSonido) {
    if(this->cartel->continuar(evento)){
        Uint8 *keystates = const_cast<Uint8 *>(SDL_GetKeyboardState(NULL));

        if (keystates[SDL_SCANCODE_SPACE]){
            keystates[SDL_SCANCODE_SPACE] = false;
            cSonido->mute();
        }

        else if (keystates[SDL_SCANCODE_LCTRL]){
            keystates[SDL_SCANCODE_LCTRL] = false;
            loguearDebug(LOG_CAMBIAR_AUDIO_SFX);
            cSonido->muteSFX();
        }

        if(usar_numero){
            this->vista_cartel->actualizar(this->cartel->getCartel(), this->cartel->getNumeroActual());
        }

        else{
            this->vista_cartel->actualizar(this->cartel->getCartel());
        }

        return true;
    }

    return false;
}

void CartelControlador::cambiar() {
    this->vista_cartel->actualizar( (size_t)this->cartel->cambiar());
}

bool CartelControlador::iniciarNivel(SDL_Event* evento, bool actualizar_cartel, JuegoSonido* cSonido) {

    if(actualizar_cartel){
        this->cambiar();
    }
    this->cartel->iniciarNumero();
    bool continuar = true;

    for(size_t i = 0; i < CANTIDAD_CARTELES_NROS && continuar; i += 1) {
        auto tiempo_inicial = std::chrono::system_clock::now();
        auto tiempo_final = std::chrono::system_clock::now();

        while( (tiempo_final - tiempo_inicial) < TIMEOUT_NUMERO_NIVEL
               && continuar ){
            SDL_WaitEventTimeout(evento, MILISEG_TIMEOUT_EVENTOS);
            continuar = this->actualizar(evento, true, cSonido);
            tiempo_final = std::chrono::system_clock::now();
        }

        this->cartel->proximoNumero();
    }

    return continuar;
}

void CartelControlador::setIniciarJuego() {
    this->cartel->setCartel(CANTIDAD_CARTELES_PRE_JUEGO - 1);
}

void CartelControlador::actualizarJugadoresConectados(std::string mensaje) {
    this->vista_cartel->actualizarJugadoresConectados(mensaje);
}

void CartelControlador::setNivel(int nivel){
    this->cartel->setCartel(nivel + CANTIDAD_CARTELES_PRE_JUEGO);
}

void CartelControlador::resetearCarteles(){
    this->cartel->setCartel(-1);
}

CartelControlador::~CartelControlador() {
    delete(this->cartel);
    delete(this->vista_cartel);
}


void CartelControlador::actualizarCartelMuertosConectados(char* m1, char* m2){
    this->vista_cartel->actualizarCartelMuertosConectados(m1, m2);
}

void CartelControlador::mostrarJuegoGanado(int cantidad_ganadores){
    this->vista_cartel->mostrarJuegoGanado(cantidad_ganadores);

}


