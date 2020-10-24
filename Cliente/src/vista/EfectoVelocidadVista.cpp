#include "EfectoVelocidadVista.h"

EfectoVelocidadVista::EfectoVelocidadVista(SDL_Texture *textura) {
    this->textura_efecto=textura;
    this->cont=0;
    this->derecha=true;
    this->rectangulo_posicion.x=0;
    this->rectangulo_posicion.y=0;
    this->rectangulo_posicion.w=0;
    this->rectangulo_posicion.h=0;
    this->alto_ancho=ALTO_ANCHO_EFECTO_VELO_1;
    this->propulsionando = false;
}

void EfectoVelocidadVista::actualizar(int pos_x, int pos_y, bool esta_propulsionando) {

    this->propulsionando = esta_propulsionando;

    int correccionX,correccionY;

    if ( derecha ){
        cont++;
        if ( cont > TIEMPO_3_EFECTO_VELO ) {
            cont = TIEMPO_1_EFECTO_VELO;
            derecha = false;
        }
    }
    else{
        cont--;
        if ( cont < TIEMPO_1_EFECTO_VELO ) {
            cont = TIEMPO_1_EFECTO_VELO;
            derecha=true;}
    }

    if (this->propulsionando) {
        this->alto_ancho=ALTO_ANCHO_EFECTO_VELO_PROP;
        correccionX=ALTO_ANCHO_EFECTO_VELO_3;
        correccionY=ALTO_ANCHO_EFECTO_VELO_3/2;
    }
    else if ( ( cont < TIEMPO_2_EFECTO_VELO ) && ( cont >= TIEMPO_1_EFECTO_VELO) ){
        this->alto_ancho=ALTO_ANCHO_EFECTO_VELO_1;
        correccionX=CARRECCION_POS_EFECTO_VELO_1;
        correccionY=CARRECCION_POS_EFECTO_VELO_2;
    }
    else if ( cont == TIEMPO_2_EFECTO_VELO ){
        this->alto_ancho=ALTO_ANCHO_EFECTO_VELO_2;
        correccionX=CARRECCION_POS_EFECTO_VELO_2;
        correccionY=CARRECCION_POS_EFECTO_VELO_1;
    }
    else if ( ( cont > TIEMPO_2_EFECTO_VELO ) && ( cont <= TIEMPO_3_EFECTO_VELO ) ){
        this->alto_ancho=ALTO_ANCHO_EFECTO_VELO_3;
        correccionX=ALTO_ANCHO_EFECTO_VELO_3;
        correccionY=ALTO_ANCHO_EFECTO_VELO_3/2;
    }


    this->rectangulo_posicion.x=pos_x-correccionX;
    this->rectangulo_posicion.y=pos_y+correccionY;

    this->rectangulo_posicion.w=this->alto_ancho;
    this->rectangulo_posicion.h=this->alto_ancho;
}

SDL_Texture* EfectoVelocidadVista::getTextura() {
    return this->textura_efecto;
}

SDL_Rect* EfectoVelocidadVista::getRectangulo(){
    return &this->rectangulo_posicion;
}

EfectoVelocidadVista::~EfectoVelocidadVista() {
}

