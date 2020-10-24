#include "Cartel.h"

Cartel::Cartel() {
    this->cartel_actual = -1;
    this->numero_actual = 0;
    this->espera_input = true;
}

void Cartel::retrocederCartel() {
    this->cartel_actual--;
}

void Cartel::setEsperaInput(bool espera){
    this->espera_input = espera;
}

size_t Cartel::getCartel(){
    return (size_t)this->cartel_actual;
}

void Cartel::setCartel(int nro_cartel){
    this->cartel_actual = nro_cartel;
}

bool Cartel::continuar(SDL_Event* evento) {
    /*
     * Usar keystates sólo funciona en la medida en que todos los eventos
     * hayan sido previamente procesados. Si todavía queda algo encolado,
     * entonces es estado del teclado que se obtiene es "viejo" (previo a
     * que hubiera eventos sin procesar).
     *
     * tl;dr: si no parece funcionar, probablemente falte un poll event o
     * SDL_WaitEventTimeout, o algo que atrape eventos.
     * */
    Uint8 *keystates = const_cast<Uint8 *>(SDL_GetKeyboardState(NULL));

    if (keystates[SDL_SCANCODE_ESCAPE]) {
        keystates[SDL_SCANCODE_ESCAPE] = false;
        return false;
    }

    return evento->type != SDL_QUIT;
}

int Cartel::cambiar(){
    return ++this->cartel_actual;
}

size_t Cartel::getNumeroActual() {
    return (size_t) this->numero_actual;
}

void Cartel::proximoNumero() {
    if(this->numero_actual + 1 < CANTIDAD_CARTELES_NROS) {
        this->numero_actual += 1;
    }
}

void Cartel::iniciarNumero() {
    this->numero_actual = 0;
}

Cartel::~Cartel() {
}