#include "ProyectilVista.h"

ProyectilVista::ProyectilVista(int pos_x, int pos_y, int nro_jugador, CargadorTexturasProyectiles* cargador){

    this->texturas = cargador->getTexturas(nro_jugador);

    //Agarro siempre la misma textura, a futuro con mas texturas segun la direccion del disparo cambiar
    this->textura_actual = this->texturas[0];

    if ( nro_jugador >= 0 ) this->cargarRectangulos(pos_x,pos_y);
    else{
        initRect(&this->posicion, pos_x, pos_y, ANCHO_ALTO_PROYECTIL_ENEMIGO, ANCHO_ALTO_PROYECTIL_ENEMIGO);
        initRect(&this->sprite_actual, 0, 0, ANCHO_ALTO_PROYECTIL_ENEMIGO, ANCHO_ALTO_PROYECTIL_ENEMIGO);
    }

    this->textura_luz = cargador->getTexturaLuz(nro_jugador);
    this->rect_luz = {0, 0, 100, 100};

    this->contador = 0;
    this->contador_subiendo = true;
}

void ProyectilVista::cargarRectangulos(int pos_x, int pos_y){
    initRect(&this->posicion, pos_x, pos_y, getTamAnchoProyectil(), getTamAltoProyectil());
    initRect(&this->sprite_actual, 0, 0, getTamAnchoProyectil(), getTamAltoProyectil());
}

SDL_Rect* ProyectilVista::getPosicion(){
    return &this->posicion;
}

SDL_Texture* ProyectilVista::getTextura(){
    return this->textura_actual;
}

SDL_Rect* ProyectilVista::getSpriteActual(){
    return &this->sprite_actual;
}


void ProyectilVista::actualizar(int pos_x, int pos_y, int direccion){
    this->posicion.x = pos_x;
    this->posicion.y = pos_y;
    this->textura_actual = this->texturas[(unsigned long)direccion];

    if (contador_subiendo) {
        this->contador += 5;
    } else {
        this->contador -= 5;
    }
    if (contador >= 100) {
        this->contador_subiendo = false;
    } else if (contador <= 5) {
        this->contador_subiendo = true;
    }
    this->rect_luz.w = 100 + this->contador;
    this->rect_luz.h = 100 + this->contador;

    this->rect_luz.x = pos_x + (this->posicion.w / 2) - (rect_luz.w / 2);
    this->rect_luz.y = pos_y + (this->posicion.h / 2) - (rect_luz.h / 2);
}

SDL_Texture* ProyectilVista::getTexturaLuz(){
    return this->textura_luz;
}

SDL_Rect* ProyectilVista::getRectLuz(){
    return &this->rect_luz;

}

ProyectilVista::~ProyectilVista() {

}
