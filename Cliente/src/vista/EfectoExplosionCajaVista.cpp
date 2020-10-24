
#include "EfectoExplosionCajaVista.h"

EfectoExplosionCajaVista::EfectoExplosionCajaVista(int x, int y, CargadorTexturasEfectos* cargador) {

    this->tiempo_de_vida=0;
    this->rectangulo_explosion = new SDL_Rect;

    initRect(this->rectangulo_explosion,x-CORRECCION_EFECTO_CAJA_X,
             y-CORRECCION_EFECTO_CAJA_Y,
             ANCHO_ALTO_EXPLOSION_CAJA,
             ANCHO_ALTO_EXPLOSION_CAJA);

    this->texturas_explosiones=cargador->getTexturaExplosion();

}