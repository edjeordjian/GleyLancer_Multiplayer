#include "MenuLog.h"

MenuLog::MenuLog(){
    this->actual = MENU_VALIDAR_1;
}

int MenuLog::actualizar(JuegoSonido *cSonido) {
    Uint8* keystates = const_cast<Uint8 *>(SDL_GetKeyboardState(NULL));

    if( keystates[SDL_SCANCODE_DOWN] || keystates[SDL_SCANCODE_TAB]) {
        cSonido->playOpcionMenuAbajo();

        keystates[SDL_SCANCODE_DOWN] = false;
        keystates[SDL_SCANCODE_TAB] = false;
        if (this->actual == MENU_VALIDAR_ULT ){
            this->actual = MENU_VALIDAR_1;

        } else{
            this->actual += 1;
        }
    }

    else if( keystates[SDL_SCANCODE_UP] ){
        cSonido->playOpcionMenuArriba();

        keystates[SDL_SCANCODE_UP] = false;
        if (this->actual == MENU_VALIDAR_1 ){
            this->actual = MENU_VALIDAR_ULT;

        } else{
            this->actual -= 1;
        }
    }

    else if( keystates[SDL_SCANCODE_RETURN] && this->actual == MENU_VALIDAR_ULT){
        keystates[SDL_SCANCODE_RETURN] = false;
        this->actual = MENU_INICIAR;
        cSonido->playOpcionMenuSeleccionar();
    }

    else if(keystates[SDL_SCANCODE_ESCAPE]){
        keystates[SDL_SCANCODE_ESCAPE] = false;
        this->actual = MENU_SALIR;
    }

    else if(keystates[SDL_SCANCODE_0]){
        keystates[SDL_SCANCODE_0] = false;
        configurar(this->actual, "0");
        cSonido->playTeclaLogin();

    } else if(keystates[SDL_SCANCODE_1]){
        keystates[SDL_SCANCODE_1] = false;
        configurar(this->actual, "1");
        cSonido->playTeclaLogin();

    } else if(keystates[SDL_SCANCODE_2]){
        keystates[SDL_SCANCODE_2] = false;
        configurar(this->actual, "2");
        cSonido->playTeclaLogin();

    } else if(keystates[SDL_SCANCODE_3]){
        keystates[SDL_SCANCODE_3] = false;
        configurar(this->actual, "3");
        cSonido->playTeclaLogin();

    } else if(keystates[SDL_SCANCODE_4]){
        keystates[SDL_SCANCODE_4] = false;
        configurar(this->actual, "4");
        cSonido->playTeclaLogin();

    } else if(keystates[SDL_SCANCODE_5]){
        keystates[SDL_SCANCODE_5] = false;
        configurar(this->actual, "5");
        cSonido->playTeclaLogin();

    } else if(keystates[SDL_SCANCODE_6]){
        keystates[SDL_SCANCODE_6] = false;
        configurar(this->actual, "6");
        cSonido->playTeclaLogin();

    } else if(keystates[SDL_SCANCODE_7]){
        keystates[SDL_SCANCODE_7] = false;
        configurar(this->actual, "7");
        cSonido->playTeclaLogin();

    } else if(keystates[SDL_SCANCODE_8]){
        keystates[SDL_SCANCODE_8] = false;
        configurar(this->actual, "8");
        cSonido->playTeclaLogin();

    } else if(keystates[SDL_SCANCODE_9]){
        keystates[SDL_SCANCODE_9] = false;
        configurar(this->actual, "9");
        cSonido->playTeclaLogin();

    } else if(keystates[SDL_SCANCODE_BACKSPACE]) {
        keystates[SDL_SCANCODE_BACKSPACE] = false;
        configurar(this->actual, BACKSPACE);
        cSonido->playTeclaLogin();
    }

    else if((keystates[SDL_SCANCODE_A]) && !( keystates[SDL_SCANCODE_LSHIFT] || keystates[SDL_SCANCODE_RSHIFT] ) ) {
        keystates[SDL_SCANCODE_A] = false;
        configurar(this->actual, "a");
        cSonido->playTeclaLogin();

    } else if((keystates[SDL_SCANCODE_B]) && !( keystates[SDL_SCANCODE_LSHIFT] || keystates[SDL_SCANCODE_RSHIFT] ) ) {
        keystates[SDL_SCANCODE_B] = false;
        configurar(this->actual, "b");
        cSonido->playTeclaLogin();

    } else if((keystates[SDL_SCANCODE_C]) && !( keystates[SDL_SCANCODE_LSHIFT] || keystates[SDL_SCANCODE_RSHIFT] ) ) {
        keystates[SDL_SCANCODE_C] = false;
        configurar(this->actual, "c");
        cSonido->playTeclaLogin();

    } else if((keystates[SDL_SCANCODE_D]) && !( keystates[SDL_SCANCODE_LSHIFT] || keystates[SDL_SCANCODE_RSHIFT] ) ) {
        keystates[SDL_SCANCODE_D] = false;
        configurar(this->actual, "d");
        cSonido->playTeclaLogin();

    } else if((keystates[SDL_SCANCODE_E]) && !( keystates[SDL_SCANCODE_LSHIFT] || keystates[SDL_SCANCODE_RSHIFT] ) ) {
        keystates[SDL_SCANCODE_E] = false;
        configurar(this->actual, "e");
        cSonido->playTeclaLogin();

    } else if((keystates[SDL_SCANCODE_F]) && !( keystates[SDL_SCANCODE_LSHIFT] || keystates[SDL_SCANCODE_RSHIFT] ) ) {
        keystates[SDL_SCANCODE_F] = false;
        configurar(this->actual, "f");
        cSonido->playTeclaLogin();

    } else if((keystates[SDL_SCANCODE_G]) && !( keystates[SDL_SCANCODE_LSHIFT] || keystates[SDL_SCANCODE_RSHIFT] ) ) {
        keystates[SDL_SCANCODE_G] = false;
        configurar(this->actual, "g");
        cSonido->playTeclaLogin();

    } else if((keystates[SDL_SCANCODE_H]) && !( keystates[SDL_SCANCODE_LSHIFT] || keystates[SDL_SCANCODE_RSHIFT] ) ) {
        keystates[SDL_SCANCODE_H] = false;
        configurar(this->actual, "h");
        cSonido->playTeclaLogin();

    } else if((keystates[SDL_SCANCODE_I]) && !( keystates[SDL_SCANCODE_LSHIFT] || keystates[SDL_SCANCODE_RSHIFT] ) ) {
        keystates[SDL_SCANCODE_I] = false;
        configurar(this->actual, "i");
        cSonido->playTeclaLogin();

    } else if((keystates[SDL_SCANCODE_J]) && !( keystates[SDL_SCANCODE_LSHIFT] || keystates[SDL_SCANCODE_RSHIFT] ) ) {
        keystates[SDL_SCANCODE_J] = false;
        configurar(this->actual, "j");
        cSonido->playTeclaLogin();

    } else if((keystates[SDL_SCANCODE_K]) && !( keystates[SDL_SCANCODE_LSHIFT] || keystates[SDL_SCANCODE_RSHIFT] ) ) {
        keystates[SDL_SCANCODE_K] = false;
        configurar(this->actual, "k");
        cSonido->playTeclaLogin();

    } else if((keystates[SDL_SCANCODE_L]) && !( keystates[SDL_SCANCODE_LSHIFT] || keystates[SDL_SCANCODE_RSHIFT] ) ) {
        keystates[SDL_SCANCODE_L] = false;
        configurar(this->actual, "l");
        cSonido->playTeclaLogin();

    } else if((keystates[SDL_SCANCODE_M]) && !( keystates[SDL_SCANCODE_LSHIFT] || keystates[SDL_SCANCODE_RSHIFT] ) ) {
        keystates[SDL_SCANCODE_M] = false;
        configurar(this->actual, "m");
        cSonido->playTeclaLogin();

    } else if((keystates[SDL_SCANCODE_N]) && !( keystates[SDL_SCANCODE_LSHIFT] || keystates[SDL_SCANCODE_RSHIFT] ) ) {
        keystates[SDL_SCANCODE_N] = false;
        configurar(this->actual, "n");
        cSonido->playTeclaLogin();

    } else if((keystates[SDL_SCANCODE_O]) && !( keystates[SDL_SCANCODE_LSHIFT] || keystates[SDL_SCANCODE_RSHIFT] ) ) {
        keystates[SDL_SCANCODE_O] = false;
        configurar(this->actual, "o");
        cSonido->playTeclaLogin();

    } else if((keystates[SDL_SCANCODE_P]) && !( keystates[SDL_SCANCODE_LSHIFT] || keystates[SDL_SCANCODE_RSHIFT] ) ) {
        keystates[SDL_SCANCODE_P] = false;
        configurar(this->actual, "p");
        cSonido->playTeclaLogin();

    } else if((keystates[SDL_SCANCODE_Q]) && !( keystates[SDL_SCANCODE_LSHIFT] || keystates[SDL_SCANCODE_RSHIFT] ) ) {
        keystates[SDL_SCANCODE_Q] = false;
        configurar(this->actual, "q");
        cSonido->playTeclaLogin();

    } else if((keystates[SDL_SCANCODE_R]) && !( keystates[SDL_SCANCODE_LSHIFT] || keystates[SDL_SCANCODE_RSHIFT] ) ) {
        keystates[SDL_SCANCODE_R] = false;
        configurar(this->actual, "r");
        cSonido->playTeclaLogin();

    } else if((keystates[SDL_SCANCODE_S]) && !( keystates[SDL_SCANCODE_LSHIFT] || keystates[SDL_SCANCODE_RSHIFT] ) ) {
        keystates[SDL_SCANCODE_S] = false;
        configurar(this->actual, "s");
        cSonido->playTeclaLogin();

    } else if((keystates[SDL_SCANCODE_T]) && !( keystates[SDL_SCANCODE_LSHIFT] || keystates[SDL_SCANCODE_RSHIFT] ) ) {
        keystates[SDL_SCANCODE_T] = false;
        configurar(this->actual, "t");
        cSonido->playTeclaLogin();

    } else if((keystates[SDL_SCANCODE_U]) && !( keystates[SDL_SCANCODE_LSHIFT] || keystates[SDL_SCANCODE_RSHIFT] ) ) {
        keystates[SDL_SCANCODE_U] = false;
        configurar(this->actual, "u");
        cSonido->playTeclaLogin();

    } else if((keystates[SDL_SCANCODE_V]) && !( keystates[SDL_SCANCODE_LSHIFT] || keystates[SDL_SCANCODE_RSHIFT] ) ) {
        keystates[SDL_SCANCODE_V] = false;
        configurar(this->actual, "v");
        cSonido->playTeclaLogin();

    } else if((keystates[SDL_SCANCODE_W]) && !( keystates[SDL_SCANCODE_LSHIFT] || keystates[SDL_SCANCODE_RSHIFT] ) ) {
        keystates[SDL_SCANCODE_W] = false;
        configurar(this->actual, "w");
        cSonido->playTeclaLogin();

    } else if((keystates[SDL_SCANCODE_X]) && !( keystates[SDL_SCANCODE_LSHIFT] || keystates[SDL_SCANCODE_RSHIFT] ) ) {
        keystates[SDL_SCANCODE_X] = false;
        configurar(this->actual, "x");
        cSonido->playTeclaLogin();

    } else if((keystates[SDL_SCANCODE_Y]) && !( keystates[SDL_SCANCODE_LSHIFT] || keystates[SDL_SCANCODE_RSHIFT] ) ) {
        keystates[SDL_SCANCODE_Y] = false;
        configurar(this->actual, "y");
        cSonido->playTeclaLogin();

    } else if((keystates[SDL_SCANCODE_Z]) && !( keystates[SDL_SCANCODE_LSHIFT] || keystates[SDL_SCANCODE_RSHIFT] ) ) {
        keystates[SDL_SCANCODE_Z] = false;
        configurar(this->actual, "z");
        cSonido->playTeclaLogin();
    }
    else if(keystates[SDL_SCANCODE_A] &&
            ( keystates[SDL_SCANCODE_LSHIFT] || keystates[SDL_SCANCODE_RSHIFT] ) ){
        keystates[SDL_SCANCODE_A] = false;
        configurar(this->actual, "A");
        cSonido->playTeclaLogin();

    } else if(keystates[SDL_SCANCODE_B] &&
              ( keystates[SDL_SCANCODE_LSHIFT] || keystates[SDL_SCANCODE_RSHIFT] ) ){
        keystates[SDL_SCANCODE_B] = false;
        configurar(this->actual, "B");
        cSonido->playTeclaLogin();

    } else if(keystates[SDL_SCANCODE_C] &&
              ( keystates[SDL_SCANCODE_LSHIFT] || keystates[SDL_SCANCODE_RSHIFT] ) ){
        keystates[SDL_SCANCODE_C] = false;
        configurar(this->actual, "C");
        cSonido->playTeclaLogin();

    } else if(keystates[SDL_SCANCODE_D] &&
              ( keystates[SDL_SCANCODE_LSHIFT] || keystates[SDL_SCANCODE_RSHIFT] ) ){
        keystates[SDL_SCANCODE_D] = false;
        configurar(this->actual, "D");
        cSonido->playTeclaLogin();

    } else if(keystates[SDL_SCANCODE_E] &&
              ( keystates[SDL_SCANCODE_LSHIFT] || keystates[SDL_SCANCODE_RSHIFT] ) ){
        keystates[SDL_SCANCODE_E] = false;
        configurar(this->actual, "E");
        cSonido->playTeclaLogin();

    } else if(keystates[SDL_SCANCODE_F] &&
              ( keystates[SDL_SCANCODE_LSHIFT] || keystates[SDL_SCANCODE_RSHIFT] ) ){
        keystates[SDL_SCANCODE_F] = false;
        configurar(this->actual, "F");
        cSonido->playTeclaLogin();

    } else if(keystates[SDL_SCANCODE_G] &&
              ( keystates[SDL_SCANCODE_LSHIFT] || keystates[SDL_SCANCODE_RSHIFT] ) ){
        keystates[SDL_SCANCODE_G] = false;
        configurar(this->actual, "G");
        cSonido->playTeclaLogin();

    } else if(keystates[SDL_SCANCODE_H] &&
              ( keystates[SDL_SCANCODE_LSHIFT] || keystates[SDL_SCANCODE_RSHIFT] ) ){
        keystates[SDL_SCANCODE_H] = false;
        configurar(this->actual, "H");
        cSonido->playTeclaLogin();

    } else if(keystates[SDL_SCANCODE_I] &&
              ( keystates[SDL_SCANCODE_LSHIFT] || keystates[SDL_SCANCODE_RSHIFT] ) ){
        keystates[SDL_SCANCODE_I] = false;
        configurar(this->actual, "I");
        cSonido->playTeclaLogin();

    } else if(keystates[SDL_SCANCODE_J] &&
              ( keystates[SDL_SCANCODE_LSHIFT] || keystates[SDL_SCANCODE_RSHIFT] ) ){
        keystates[SDL_SCANCODE_J] = false;
        configurar(this->actual, "J");
        cSonido->playTeclaLogin();

    } else if(keystates[SDL_SCANCODE_K] &&
              ( keystates[SDL_SCANCODE_LSHIFT] || keystates[SDL_SCANCODE_RSHIFT] ) ){
        keystates[SDL_SCANCODE_K] = false;
        configurar(this->actual, "K");
        cSonido->playTeclaLogin();

    } else if(keystates[SDL_SCANCODE_L] &&
              ( keystates[SDL_SCANCODE_LSHIFT] || keystates[SDL_SCANCODE_RSHIFT] ) ){
        keystates[SDL_SCANCODE_L] = false;
        configurar(this->actual, "L");
        cSonido->playTeclaLogin();

    } else if(keystates[SDL_SCANCODE_M] &&
              ( keystates[SDL_SCANCODE_LSHIFT] || keystates[SDL_SCANCODE_RSHIFT] ) ){
        keystates[SDL_SCANCODE_M] = false;
        configurar(this->actual, "M");
        cSonido->playTeclaLogin();

    } else if(keystates[SDL_SCANCODE_N] &&
              ( keystates[SDL_SCANCODE_LSHIFT] || keystates[SDL_SCANCODE_RSHIFT] ) ){
        keystates[SDL_SCANCODE_N] = false;
        configurar(this->actual, "N");
        cSonido->playTeclaLogin();

    } else if(keystates[SDL_SCANCODE_O] &&
              ( keystates[SDL_SCANCODE_LSHIFT] || keystates[SDL_SCANCODE_RSHIFT] ) ){
        keystates[SDL_SCANCODE_O] = false;
        configurar(this->actual, "O");
        cSonido->playTeclaLogin();

    } else if(keystates[SDL_SCANCODE_P] &&
              ( keystates[SDL_SCANCODE_LSHIFT] || keystates[SDL_SCANCODE_RSHIFT] ) ){
        keystates[SDL_SCANCODE_P] = false;
        configurar(this->actual, "P");
        cSonido->playTeclaLogin();

    } else if(keystates[SDL_SCANCODE_Q] &&
              ( keystates[SDL_SCANCODE_LSHIFT] || keystates[SDL_SCANCODE_RSHIFT] ) ){
        keystates[SDL_SCANCODE_Q] = false;
        configurar(this->actual, "Q");
        cSonido->playTeclaLogin();

    } else if(keystates[SDL_SCANCODE_R] &&
              ( keystates[SDL_SCANCODE_LSHIFT] || keystates[SDL_SCANCODE_RSHIFT] ) ){
        keystates[SDL_SCANCODE_R] = false;
        configurar(this->actual, "R");
        cSonido->playTeclaLogin();

    } else if(keystates[SDL_SCANCODE_S] &&
              ( keystates[SDL_SCANCODE_LSHIFT] || keystates[SDL_SCANCODE_RSHIFT] ) ){
        keystates[SDL_SCANCODE_S] = false;
        configurar(this->actual, "S");
        cSonido->playTeclaLogin();

    } else if(keystates[SDL_SCANCODE_T] &&
              ( keystates[SDL_SCANCODE_LSHIFT] || keystates[SDL_SCANCODE_RSHIFT] ) ){
        keystates[SDL_SCANCODE_T] = false;
        configurar(this->actual, "T");
        cSonido->playTeclaLogin();

    } else if(keystates[SDL_SCANCODE_U] &&
              ( keystates[SDL_SCANCODE_LSHIFT] || keystates[SDL_SCANCODE_RSHIFT] ) ){
        keystates[SDL_SCANCODE_U] = false;
        configurar(this->actual, "U");
        cSonido->playTeclaLogin();

    } else if(keystates[SDL_SCANCODE_V] &&
              ( keystates[SDL_SCANCODE_LSHIFT] || keystates[SDL_SCANCODE_RSHIFT] ) ){
        keystates[SDL_SCANCODE_V] = false;
        configurar(this->actual, "V");
        cSonido->playTeclaLogin();

    } else if(keystates[SDL_SCANCODE_W] &&
              ( keystates[SDL_SCANCODE_LSHIFT] || keystates[SDL_SCANCODE_RSHIFT] ) ){
        keystates[SDL_SCANCODE_W] = false;
        configurar(this->actual, "W");
        cSonido->playTeclaLogin();

    } else if(keystates[SDL_SCANCODE_X] &&
              ( keystates[SDL_SCANCODE_LSHIFT] || keystates[SDL_SCANCODE_RSHIFT] ) ){
        keystates[SDL_SCANCODE_X] = false;
        configurar(this->actual, "X");
        cSonido->playTeclaLogin();

    } else if(keystates[SDL_SCANCODE_Y] &&
              ( keystates[SDL_SCANCODE_LSHIFT] || keystates[SDL_SCANCODE_RSHIFT] ) ){
        keystates[SDL_SCANCODE_Y] = false;
        configurar(this->actual, "Y");
        cSonido->playTeclaLogin();

    } else if(keystates[SDL_SCANCODE_Z] &&
              ( keystates[SDL_SCANCODE_LSHIFT] || keystates[SDL_SCANCODE_RSHIFT] ) ){
        keystates[SDL_SCANCODE_Z] = false;
        configurar(this->actual, "Z");
        cSonido->playTeclaLogin();
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

void MenuLog::configurar(int caso, std::string valor){
    if(caso == MENU_VALIDAR_1) {
        if (valor == BACKSPACE) {
            setUsuario(getUsuario(), true);

        } else {
            if(strlen(getUsuario()) == MAX_LEN_USUARIO)
                return;

            setUsuario(getUsuario() + valor, false);
        }

    }

    else if(caso == MENU_VALIDAR_2){
        if(valor == BACKSPACE){
            setPass(getPass(), true);

        } else{
            if(strlen(getPass()) == MAX_LEN_PASS)
                return;

            setPass(getPass() + valor, false);
        }

    }
}

bool MenuLog::estaActivo() {
    return !( (this->actual == MENU_INICIAR) ||
              (this->actual == MENU_SALIR)
            );
}

bool MenuLog::estaIniciado(){
    return this->actual == MENU_INICIAR;
}

bool MenuLog::estaCancelado(SDL_Event *evento) {
    return (evento->type == SDL_QUIT || (this->actual == MENU_SALIR));
}

void MenuLog::reestablecer() {
    this->actual = MENU_VALIDAR_1;
}

MenuLog::~MenuLog() {
}
