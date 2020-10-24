#include "Enemigo1Vista.h"


Enemigo1Vista::Enemigo1Vista(int pos_x, int pos_y, CargadorTexturasEnemigos *cargador)
                    : EnemigoVista(){

    this->texturas = cargador->getTexturas(getTipoEnemigo1());
    //La direccion de los personajes y enemigos puede ser la misma?
    this->textura_actual = this->texturas[DIRECCION_ENEMIGO_IZQUIERDA];

    // Valores reales de la imagen
    initRect(&this->sprite_actual, 0, 0, getAnchoEnemigo1(), getAltoEnemigo1());

    // Tamaño visualizado en pantalla
    initRect(&this->posicion, pos_x, pos_y, getTamAnchoEnemigo1(), getTamAltoEnemigo1());
}
