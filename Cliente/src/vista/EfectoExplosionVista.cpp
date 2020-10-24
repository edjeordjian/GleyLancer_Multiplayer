#include "EfectoExplosionVista.h"

SDL_Rect* EfectoExplosionVista::getRectangulo() {
    this->tiempo_de_vida++;
    return this->rectangulo_explosion;
}

bool EfectoExplosionVista::estaActivo() {
    return this->tiempo_de_vida < TIEMPO_VIDA_EXPLOSION;
}

SDL_Texture* EfectoExplosionVista::getTextura() {
    if (this->tiempo_de_vida < TIEMPO_VIDA_EXPLOSION_FASE_1) {
        return this->texturas_explosiones[POS_EXPLOSION_FASE_1];
    } else if (this->tiempo_de_vida < TIEMPO_VIDA_EXPLOSION_FASE_2) {
        return this->texturas_explosiones[POS_EXPLOSION_FASE_2];
    } else if (this->tiempo_de_vida < TIEMPO_VIDA_EXPLOSION_FASE_3) {
        return this->texturas_explosiones[POS_EXPLOSION_FASE_3];
    } else if (this->tiempo_de_vida < TIEMPO_VIDA_EXPLOSION_FASE_4) {
        return this->texturas_explosiones[POS_EXPLOSION_FASE_4];
    } else if (this->tiempo_de_vida < TIEMPO_VIDA_EXPLOSION_FASE_5) {
        return this->texturas_explosiones[POS_EXPLOSION_FASE_5];
    } else
        return this->texturas_explosiones[POS_EXPLOSION_FASE_6];
}

EfectoExplosionVista::~EfectoExplosionVista() {
    for(auto &i: this->texturas_explosiones){
        SDL_DestroyTexture(i);
    }
}