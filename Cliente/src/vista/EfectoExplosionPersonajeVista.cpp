#include "EfectoExplosionPersonajeVista.h"

EfectoExplosionPersonajeVista::EfectoExplosionPersonajeVista(int x, int y, CargadorTexturasEfectos* cargador) {

        this->tiempo_de_vida=0;
        this->rectangulo_explosion = new SDL_Rect;

        initRect(this->rectangulo_explosion,x-CORRECCION_EFECTO_PERSONAJE_X,
                y-CORRECCION_EFECTO_PERSONAJE_Y,
                ANCHO_ALTO_EXPLOSION_PERSONAJE,
                ANCHO_ALTO_EXPLOSION_PERSONAJE);

        this->texturas_explosiones=cargador->getTexturaExplosion();

}