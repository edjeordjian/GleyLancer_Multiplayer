#include "Jefe3Vista.h"

Jefe3Vista::Jefe3Vista(int pos_x, int pos_y, CargadorTexturasEnemigos *cargador)
        : EnemigoVista(){

    this->texturas = cargador->getTexturas(TIPO_JEFE_3);
    //La direccion de los personajes y enemigos puede ser la misma?
    this->textura_actual = this->texturas[DIRECCION_ENEMIGO_IZQUIERDA];

    // Valores reales de la imagen
    initRect(&this->sprite_actual, 0, 0, ANCHO_JEFE_3, ALTO_JEFE_3);

    // Tamaño visualizado en pantalla
    initRect(&this->posicion, pos_x, pos_y, ANCHO_JEFE_3, ALTO_JEFE_3);

    this->contador=0;
    this->derecha=true;
}


int Jefe3Vista::getPosicionMov(){

    int pos = this->contador / LIMITE_CONTADOR_J1_Y_J3;


    if ( derecha ) this->contador++;
    else this->contador--;

    if ( pos == ( LIMITE_CONTADOR_J1_Y_J3 + 1 ) ) {
        this->derecha = false;
        pos=LIMITE_CONTADOR_J1_Y_J3;
    }
    if ( pos < 0 ) {
        this->derecha = true;
        pos=0;
    }

    return pos;
}


void Jefe3Vista::actualizar(int pos_x, int pos_y, int direccion, bool herido){
    this->posicion.x = pos_x;
    this->posicion.y = pos_y;

    direccion= this->getPosicionMov();

    if (herido){
        this->contador_daniado = MAX_VALOR_CONTADOR_DANIADO;
    }

    if (this->contador_daniado % CANT_ESTADOS) this->textura_actual = this->texturas[POS_VISTA_ENEMIGO_JEFE_DANIADO + (unsigned long)direccion];
    else this->textura_actual = this->texturas[(unsigned long)direccion];

    if (this->contador_daniado > 0){
        this->contador_daniado--;
    }
}
