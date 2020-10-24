#include "Jefe2Vista.h"


Jefe2Vista::Jefe2Vista(int pos_x, int pos_y, CargadorTexturasEnemigos *cargador)
        : EnemigoVista(){

    this->texturas = cargador->getTexturas(TIPO_JEFE_2);
    //La direccion de los personajes y enemigos puede ser la misma?
    this->textura_actual = this->texturas[DIRECCION_ENEMIGO_IZQUIERDA];

    // Valores reales de la imagen
    initRect(&this->sprite_actual, 0, 0, ANCHO_IMG_JEFE_2, ALTO_IMG_JEFE_2);

    // Tamaño visualizado en pantalla
    initRect(&this->posicion, pos_x, pos_y, ANCHO_JEFE_2, ALTO_JEFE_2);

    this->pos_x_vieja=pos_x;
    this->pos_y_vieja=pos_y;
    this->contador=0;
}


int Jefe2Vista::getPosRotacion(){
    int pos;

    if ( ( this->posicion.x == this->pos_x_vieja ) && ( this->posicion.y == this->pos_y_vieja ) ){
        this->contador=0;
    }

    pos=(this->contador);

    if ( pos == MAX_VALOR_CONTADOR_J2 ){
        this->contador=0;
    }
    this->pos_x_vieja = this->posicion.x;
    this->pos_y_vieja = this->posicion.y;

    this->contador++;

    return pos;
}

void Jefe2Vista::actualizar(int pos_x, int pos_y, int direccion, bool herido){

    direccion = this->getPosRotacion();

    this->posicion.x = pos_x;
    this->posicion.y = pos_y;

    if (herido){
        this->contador_daniado = MAX_VALOR_CONTADOR_DANIADO;
    }

    if (this->contador_daniado % CANT_ESTADOS) this->textura_actual = this->texturas[POS_VISTA_ENEMIGO_JEFE_DANIADO + (unsigned)direccion];
    else this->textura_actual = this->texturas[(unsigned)direccion];

    if (this->contador_daniado > 0){
        this->contador_daniado--;
    }
}
