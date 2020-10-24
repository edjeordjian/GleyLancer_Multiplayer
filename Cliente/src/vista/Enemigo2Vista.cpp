#include "Enemigo2Vista.h"

Enemigo2Vista::Enemigo2Vista(int pos_x, int pos_y, CargadorTexturasEnemigos *cargador)
        : EnemigoVista(){

    this->texturas = cargador->getTexturas(getTipoEnemigo2());
    //La direccion de los personajes y enemigos puede ser la misma?
    this->textura_actual = this->texturas[DIRECCION_ENEMIGO_IZQUIERDA];

    // Valores reales de la imagen
    initRect(&this->sprite_actual, 0, 0, getAnchoEnemigo2(), getAltoEnemigo2());

    // Tamaño visualizado en pantalla
    initRect(&this->posicion, pos_x, pos_y, getTamAnchoEnemigo2(), getTamAltoEnemigo2());
}

