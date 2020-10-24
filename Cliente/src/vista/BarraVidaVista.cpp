#include "BarraVidaVista.h"

BarraVidaVista::BarraVidaVista(SDL_Texture* textura_barra_personaje, SDL_Texture* textura_barra_test, int x, int y) {

    this->textura_barra_personaje = textura_barra_personaje;
    this->textura_barra_test = textura_barra_test;

    this->textura_actual = this->textura_barra_personaje;

    this->rectangulo_barra_completa=new SDL_Rect;
    this->barra_vida=new SDL_Rect;

    initRect(this->rectangulo_barra_completa,x,y,ANCHO_BARRA_VIDA,ALTO_BARRA_VIDA);
    initRect(this->barra_vida,0,0,ANCHO_BARRA_VIDA,ALTO_BARRA_VIDA);
}

SDL_Texture* BarraVidaVista::getTextura(){
    return this->textura_actual;
}

SDL_Rect* BarraVidaVista::getBarraVida() {
    return this->barra_vida;
}

SDL_Rect* BarraVidaVista::getRectCompleto(){
    return this->rectangulo_barra_completa;
}

void BarraVidaVista::actualizar(int energia, bool modo_test) {
    this->barra_vida->w=(int)((float)energia * CONST_CONVERTIR_BARRA);
    this->rectangulo_barra_completa->w=(int)((float)energia * CONST_CONVERTIR_BARRA);
    if (modo_test){
        this->textura_actual = this->textura_barra_test;
    } else {
        this->textura_actual = this->textura_barra_personaje;
    }
}

BarraVidaVista::~BarraVidaVista(){
    delete(this->rectangulo_barra_completa);
    delete(this->barra_vida);
}


