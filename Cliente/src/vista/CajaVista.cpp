#include "CajaVista.h"

CajaVista::CajaVista(int pos_x, int pos_y, CargadorTexturasCajas* cargador){

    this->texturas = cargador->getTexturas();

    //Agarro siempre la misma textura, a futuro con mas texturas segun la direccion del disparo cambiar
    this->textura_actual = this->texturas[0];
    this->cargarRectangulos(pos_x,pos_y);

}

void CajaVista::cargarRectangulos(int pos_x, int pos_y){
    initRect(&this->posicion, pos_x, pos_y, ANCHO_CAJA, ALTO_CAJA);
    initRect(&this->sprite_actual, 0, 0, ANCHO_CAJA, ALTO_CAJA);
}

SDL_Rect* CajaVista::getPosicion(){
    return &this->posicion;
}

SDL_Texture* CajaVista::getTextura(){
    return this->textura_actual;
}

SDL_Rect* CajaVista::getSpriteActual(){
    return &this->sprite_actual;
}

void CajaVista::actualizar(int pos_x, int pos_y){
    this->posicion.x = pos_x;
    this->posicion.y = pos_y;
    this->textura_actual = this->texturas[0];

}

CajaVista::~CajaVista(){

}
