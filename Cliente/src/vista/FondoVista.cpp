#include "FondoVista.h"


FondoVista::FondoVista(char* capa_1,char* capa_2, char* capa_3, char* capa_4, char* capa_5, char* capa_6, SDL_Renderer* renderizador) {
    /*
     * CALCULO DEL RTIEMPO DEL NIVEL
     *
    (largo_de_fondo  - ventana) / paso = tiempo de nivel
    paso = 0.22 px / 16 ms (definido por límite de fps e incremento)
    ventana = 800          (fijo)
    largo_de_fondo = 4000 (fijo)

     3200 / 0.22 * 16 ms = 232s
     (a esto hay que sumarle el delay de la pantalla del fin del nivel)

     Si consideramos que está seteado en 2, entonces cada nivel dura casi
     4 minutos.

    */

    //Inicializo los rectangulos para cada una de las capas:

    this->posicion_capa_1=0;
    this->posicion_capa_2=0;
    this->posicion_capa_3=0;
    this->posicion_capa_4=0;
    this->posicion_capa_5=0;
    this->posicion_capa_6=0;

    initRect(&this->fondo_capa_1,0,0,ANCHO_CAPA,ALTO_VENTANA);
    initRect(&this->fondo_capa_2,0,0,ANCHO_CAPA,ALTO_VENTANA);
    initRect(&this->fondo_capa_3,0,0,ANCHO_CAPA,ALTO_VENTANA);
    initRect(&this->fondo_capa_4,0,0,ANCHO_CAPA,ALTO_VENTANA);
    initRect(&this->fondo_capa_5,0,0,ANCHO_CAPA,ALTO_VENTANA);
    initRect(&this->fondo_capa_6,0,0,ANCHO_FONDO,ALTO_VENTANA);

    initRect(&this->camara_capa_1,0,0,ANCHO_VENTANA,ALTO_VENTANA);
    initRect(&this->camara_capa_2,0,0,ANCHO_VENTANA,ALTO_VENTANA);
    initRect(&this->camara_capa_3,0,0,ANCHO_VENTANA,ALTO_VENTANA);
    initRect(&this->camara_capa_4,0,0,ANCHO_VENTANA,ALTO_VENTANA);
    initRect(&this->camara_capa_5,0,0,ANCHO_VENTANA,ALTO_VENTANA);
    initRect(&this->camara_capa_6,0,0,ANCHO_VENTANA,ALTO_VENTANA);

    this->incremento_capa_5 = VELOCIDAD_CAPA_5;
    this->incremento_capa_4 = VELOCIDAD_CAPA_4;
    this->incremento_capa_3 = VELOCIDAD_CAPA_3;
    this->incremento_capa_2 = VELOCIDAD_CAPA_2;
    this->incremento_capa_1 = VELOCIDAD_CAPA_1;

    this->textura_capa_1 = crearTextura(capa_1,renderizador);
    this->textura_capa_2 = crearTextura(capa_2,renderizador);
    this->textura_capa_3 = crearTextura(capa_3,renderizador);
    this->textura_capa_4 = crearTextura(capa_4,renderizador);
    this->textura_capa_5 = crearTextura(capa_5,renderizador);
    this->textura_capa_6 = crearTextura(capa_6,renderizador);
}

void FondoVista::actualizar() {

    this->posicion_capa_1 += this->incremento_capa_1;
    this->posicion_capa_2 += this->incremento_capa_2;
    this->posicion_capa_3 += this->incremento_capa_3;
    this->posicion_capa_4 += this->incremento_capa_4;
    this->posicion_capa_5 += this->incremento_capa_5;

    this->fondo_capa_1.x = -1 * (int)this->posicion_capa_1;
    this->fondo_capa_2.x = -1 * (int)this->posicion_capa_2;
    this->fondo_capa_3.x = -1 * (int)this->posicion_capa_3;
    this->fondo_capa_4.x = -1 * (int)this->posicion_capa_4;
    this->fondo_capa_5.x = -1 * (int)this->posicion_capa_5;

    if( this->fondo_capa_1.x < (-1) * ( this->fondo_capa_1.w - ANCHO_VENTANA) ){
        this->fondo_capa_1.x = (-1) * ( this->fondo_capa_1.w/2 - ANCHO_VENTANA );
        this->posicion_capa_1 = ANCHO_CAPA / 2 - ANCHO_VENTANA;
    }

    if( this->fondo_capa_2.x < (-1) * ( this->fondo_capa_2.w - ANCHO_VENTANA) ){
        this->fondo_capa_2.x = (-1) * ( this->fondo_capa_2.w/2 - ANCHO_VENTANA );
        this->posicion_capa_2 = ANCHO_CAPA / 2 - ANCHO_VENTANA;
    }


    if( this->fondo_capa_3.x < (-1) * ( this->fondo_capa_3.w - ANCHO_VENTANA) ){
        this->fondo_capa_3.x = (-1) * ( this->fondo_capa_3.w/2 - ANCHO_VENTANA );
        this->posicion_capa_3 = ANCHO_CAPA / 2 - ANCHO_VENTANA;
    }

    if( this->fondo_capa_4.x < (-1) * ( this->fondo_capa_4.w - ANCHO_VENTANA) ){
        this->fondo_capa_4.x = (-1) * ( this->fondo_capa_4.w/2 - ANCHO_VENTANA );
        this->posicion_capa_4 = ANCHO_CAPA / 2 - ANCHO_VENTANA;
    }

    if( this->fondo_capa_5.x < (-1) * ( this->fondo_capa_5.w - ANCHO_VENTANA) ){
        this->fondo_capa_5.x = (-1) * ( this->fondo_capa_5.w/2 - ANCHO_VENTANA );
        this->posicion_capa_5 = ANCHO_CAPA / 2 - ANCHO_VENTANA;
    }

}

void FondoVista::actualizar(int posicion_ventana){
    this->fondo_capa_6.x = (-1) * posicion_ventana;

    if( this->fondo_capa_6.x < (-1) * ( this->fondo_capa_6.w - ANCHO_VENTANA )  ){
        this->fondo_capa_6.x = (-1) * ( this->fondo_capa_6.w - ANCHO_VENTANA );
    }
}

SDL_Rect* FondoVista::getPrimeraCapa(){
    return &this->fondo_capa_1;
}

SDL_Rect* FondoVista::getSegundaCapa(){
    return &this->fondo_capa_2;
}

SDL_Rect* FondoVista::getTercerCapa() {
    return &this->fondo_capa_3;
}


SDL_Rect* FondoVista::getCuartaCapa() {
    return &this->fondo_capa_4;
}

SDL_Rect* FondoVista::getQuintaCapa() {
    return &this->fondo_capa_5;
}

SDL_Rect* FondoVista::getSextaCapa() {
    return &this->fondo_capa_6;
}

SDL_Texture* FondoVista::getTexturaPrimerCapa() {
    return this->textura_capa_1;
}

SDL_Texture* FondoVista::getTexturaSegundaCapa() {
    return this->textura_capa_2;
}

SDL_Texture* FondoVista::getTexturaTercerCapa() {
    return this->textura_capa_3;
}

SDL_Texture* FondoVista::getTexturaCuartaCapa() {
    return this->textura_capa_4;
}

SDL_Texture* FondoVista::getTexturaQuintaCapa() {
    return this->textura_capa_5;
}

SDL_Texture* FondoVista::getTexturaSextaCapa() {
    return this->textura_capa_6;
}

FondoVista::~FondoVista(){
    SDL_DestroyTexture(this->textura_capa_1);
    SDL_DestroyTexture(this->textura_capa_2);
    SDL_DestroyTexture(this->textura_capa_3);
    SDL_DestroyTexture(this->textura_capa_4);
    SDL_DestroyTexture(this->textura_capa_5);
    SDL_DestroyTexture(this->textura_capa_6);
}
