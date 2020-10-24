#include "EfectoExplosionEnemigoVista.h"

EfectoExplosionEnemigoVista::EfectoExplosionEnemigoVista(int x, int y, CargadorTexturasEfectos* cargador) {
        this->tiempo_de_vida=0;
        this->rectangulo_explosion = new SDL_Rect;

        initRect(this->rectangulo_explosion,x-CORRECCION_EFECTO_ENEMIGO_X,
                y-CORRECCION_EFECTO_ENEMIGO_Y,
                ANCHO_ALTO_EXPLOSION_ENEMIGO,
                ANCHO_ALTO_EXPLOSION_ENEMIGO);

        this->texturas_explosiones=cargador->getTexturaExplosion();
}