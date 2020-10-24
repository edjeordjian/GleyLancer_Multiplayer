#include "MenuJuego.h"
#include "../vista/JuegoSonido.h"

MenuJuego::MenuJuego(){
    this->actual = MENU_OPCION_1;
    this->activo = true;
}

int MenuJuego::inicializar() {
    return this->actual;
}

int MenuJuego::actualizar(JuegoSonido* cSonido) {
    Uint8 *keystates = const_cast<Uint8 *>(SDL_GetKeyboardState(NULL));

    if( keystates[SDL_SCANCODE_DOWN] ){
        keystates[SDL_SCANCODE_DOWN] = false;

        if (this->actual == MENU_OPCION_ULT ){
            this->actual = MENU_OPCION_1;

        } else{
            this->actual += 1;
        }
        cSonido->playOpcionMenuAbajo();
    }

    else if( keystates[SDL_SCANCODE_UP] ){
        keystates[SDL_SCANCODE_UP] = false;

        if ( this->actual == MENU_OPCION_1 ){
            this->actual = MENU_OPCION_ULT;

        } else{
            this->actual -= 1;
        }
        cSonido->playOpcionMenuArriba();
    }

    else if( keystates[SDL_SCANCODE_RETURN] ){
        keystates[SDL_SCANCODE_RETURN] = false;

        if(this->actual == MENU_OPCION_1){
            this->activo = false;
            this->actual = MENU_INICIAR;
        }

        else {
            this->activo = false;
            this->actual = MENU_SALIR;
        }
        cSonido->playOpcionMenuSeleccionar();
    }

    else if(keystates[SDL_SCANCODE_ESCAPE]){
      keystates[SDL_SCANCODE_ESCAPE] = false;
      this->activo = false;
      this->actual = MENU_SALIR;
    }

    else if (keystates[SDL_SCANCODE_LCTRL]){
        keystates[SDL_SCANCODE_LCTRL] = false;
        loguearDebug(LOG_CAMBIAR_AUDIO_SFX);
        cSonido->muteSFX();
    }

    else if (keystates[SDL_SCANCODE_SPACE]){
        keystates[SDL_SCANCODE_SPACE] = false;
        loguearDebug(LOG_CAMBIAR_AUDIO);
        cSonido->mute();
    }

    return this->actual;
}

bool MenuJuego::estaActivo() {
    return this->activo;
}

bool MenuJuego::estaIniciado() {
    return this->actual == MENU_INICIAR;
}

bool MenuJuego::estaCancelado(SDL_Event *evento) {
    return (evento->type == SDL_QUIT || this->actual == MENU_SALIR);
}

void MenuJuego::reestablecer() {
    this->activo = true;
    this->actual = MENU_OPCION_1;
}

MenuJuego::~MenuJuego() {
}
