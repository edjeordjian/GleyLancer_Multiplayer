#include "Ventana.h"

Ventana::Ventana(float incremento) {
    this->posicion_x_fondo = ANCHO_FONDO/2;
    this->incremento_ventana = incremento;
    initRect(&this->marco_ventana, 0, 0, ANCHO_VENTANA,ALTO_VENTANA);
    this->llego_al_final = false;
}

Ventana::~Ventana() {

}

/*Este metodo detecta y corrige al personaje para que
 su imagen no se escape por el borde de la ventana de la vista*/
void Ventana::corregirColisionBorde(Personaje *personaje) {

    SDL_Rect posicionPersonaje;
    SDL_Rect interseccion;

    initRect(&posicionPersonaje,
            (int) personaje->getPosicionVentana().getX(),
            (int) personaje->getPosicionVentana().getY(),
            ANCHO_PERSONAJE,
            ALTO_PERSONAJE);


    if ( ! SDL_IntersectRect(&posicionPersonaje,&marco_ventana,&interseccion) ){
        return;
    }

    if ( interseccion.w < posicionPersonaje.w) {

        if (interseccion.x == posicionPersonaje.x) {
            personaje->actualizarColision(POS_DERECHA);

        } else {
            personaje->actualizarColision(POS_IZQUIERDA);
        }
    }


    if ( interseccion.h < posicionPersonaje.h ) {
        if (interseccion.y == posicionPersonaje.y) {
            personaje->actualizarColision(POS_ABAJO);
        } else {
           personaje->actualizarColision(POS_ARRIBA);
        }
    }
}

void Ventana::actualizarPosicionVista(IChocable* chocable){
    Posicion pos_ventana;
    SDL_Rect interseccion;
    SDL_Rect posicion_chocable;

    pos_ventana.setX(chocable->getPosX() - this->posicion_x_fondo);
    pos_ventana.setY(chocable->getPosY());

    chocable->setPosicionVentana(pos_ventana);

    initRect(&posicion_chocable,
             (int) chocable->getPosicionVentana().getX(),
             (int) chocable->getPosicionVentana().getY(),
             chocable->getAncho(),
             chocable->getAlto());

    chocable->setEstaEnVentana(SDL_IntersectRect(&posicion_chocable, &marco_ventana, &interseccion));

}

bool  Ventana::actualizar(){
    if (this->posicion_x_fondo < (ANCHO_FONDO - ANCHO_VENTANA) ){
        this->llego_al_final = false;
        this->posicion_x_fondo += this->incremento_ventana;
        return true;
    }
    this->llego_al_final = true;
    return false;
}

bool Ventana::llegoAlFinal(){
    return this->llego_al_final;
}

double Ventana::getX() {
    return this->posicion_x_fondo;
}
