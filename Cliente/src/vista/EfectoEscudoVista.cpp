#include "EfectoEscudoVista.h"

EfectoEscudoVista::EfectoEscudoVista(SDL_Texture *textura) {
    this->textura_escudo=textura;
    this->rectangulo_posicion.x=0;
    this->rectangulo_posicion.y=0;
    this->rectangulo_posicion.w=0;
    this->rectangulo_posicion.h=0;
    this->ancho = ANCHO_ESCUDO_PERSONAJE;
    this->alto = ALTO_ESCUDO_PERSONAJE;
    this->contador = 0;
}

void EfectoEscudoVista::actualizar(int pos_x, int pos_y) {

    if (this->contador > MAX_CONTADOR_ESCUDO ){
        this->contador = 0;
    }

    int correccionX;
    int correccionY;
    int aux;

    if (this->contador < MAX_CONTADOR_ESCUDO / 2) {
        aux = ((this->contador / CONST_CORREGIR_POS_ESCUDO_2) % CONST_CORREGIR_POS_ESCUDO_1);
        this->ancho = (int)ANCHO_ESCUDO_PERSONAJE + 2*aux;
        this->alto = (int)ALTO_ESCUDO_PERSONAJE + 2*aux;
        correccionX = CORRECCION_X_ESCUDO - aux;
        correccionY = CORRECCION_Y_ESCUDO - aux;

    } else {
        aux = CONST_CORREGIR_POS_ESCUDO_1 - (((this->contador - MAX_CONTADOR_ESCUDO / 2) / CONST_CORREGIR_POS_ESCUDO_2) % CONST_CORREGIR_POS_ESCUDO_1);
        this->ancho = (int)ANCHO_ESCUDO_PERSONAJE + 2*aux;
        this->alto = (int)ALTO_ESCUDO_PERSONAJE + 2*aux;
        correccionX = CORRECCION_X_ESCUDO - aux;
        correccionY = CORRECCION_Y_ESCUDO - aux;
    }

    this->rectangulo_posicion.x= pos_x + correccionX;
    this->rectangulo_posicion.y= pos_y + correccionY;

    this->rectangulo_posicion.w=this->ancho;
    this->rectangulo_posicion.h=this->alto;

    this->contador++;

}

SDL_Texture* EfectoEscudoVista::getTextura() {
    return this->textura_escudo;
}

void EfectoEscudoVista::setTextura(SDL_Texture *nueva_textura) {
    this->textura_escudo=nueva_textura;
}

SDL_Rect* EfectoEscudoVista::getRectangulo(){
    return &this->rectangulo_posicion;
}

EfectoEscudoVista::~EfectoEscudoVista() {
}

