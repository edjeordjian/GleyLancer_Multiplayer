#include "ItemVista.h"

ItemVista::ItemVista(int pos_x, int pos_y, int tipo, CargadorTexturasItems* cargador){

    this->texturas = cargador->getTexturas();

    //Agarro siempre la misma textura, a futuro con mas texturas segun la direccion del disparo cambiar
    this->textura_actual = this->texturas[(size_t)tipo];
    this->cargarRectangulos(pos_x,pos_y);

}

void ItemVista::cargarRectangulos(int pos_x, int pos_y){
    initRect(&this->posicion, pos_x, pos_y, ANCHO_ITEM, ALTO_ITEM);
    initRect(&this->sprite_actual, 0, 0, ANCHO_ITEM, ALTO_ITEM);
}

SDL_Rect* ItemVista::getPosicion(){
    return &this->posicion;
}

SDL_Texture* ItemVista::getTextura(){
    return this->textura_actual;
}

SDL_Rect* ItemVista::getSpriteActual(){
    return &this->sprite_actual;
}


void ItemVista::actualizar(int pos_x, int pos_y){
    this->posicion.x = pos_x;
    this->posicion.y = pos_y;

}

ItemVista::~ItemVista(){

}
