#include "EnemigoVista.h"

EnemigoVista::EnemigoVista(){
    this->contador_daniado = 0;
}

SDL_Rect* EnemigoVista::getPosicion(){
    return &this->posicion;
}

SDL_Texture* EnemigoVista::getTextura() {
    return this->textura_actual;
}


SDL_Rect* EnemigoVista::getSpriteActual(){
    return &this->sprite_actual;
}


void EnemigoVista::actualizar(int pos_x, int pos_y, int direccion, bool herido){
    this->posicion.x = pos_x;
    this->posicion.y = pos_y;
    if (herido){
        this->contador_daniado = 9;
    }

    if (this->contador_daniado % 2) this->textura_actual = this->texturas[POS_VISTA_ENEMIGO_TIPO_1_Y_2_DANIADO + (unsigned long)direccion];
    else this->textura_actual = this->texturas[(unsigned long)direccion];

    if (this->contador_daniado > 0){
        this->contador_daniado--;
    }
}

EnemigoVista::~EnemigoVista() {

}

