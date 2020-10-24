#include "CargadorTexturasEfectos.h"


CargadorTexturasEfectos::CargadorTexturasEfectos(SDL_Renderer *renderizador) {

    ///EXPLOSION COMUN ///

    this->texturas_explosion.emplace_back(crearTextura(RUTA_IMAGEN_EXPLOSION_1, renderizador));
    this->texturas_explosion.emplace_back(crearTextura(RUTA_IMAGEN_EXPLOSION_2, renderizador));
    this->texturas_explosion.emplace_back(crearTextura(RUTA_IMAGEN_EXPLOSION_3, renderizador));
    this->texturas_explosion.emplace_back(crearTextura(RUTA_IMAGEN_EXPLOSION_4, renderizador));
    this->texturas_explosion.emplace_back(crearTextura(RUTA_IMAGEN_EXPLOSION_5, renderizador));
    this->texturas_explosion.emplace_back(crearTextura(RUTA_IMAGEN_EXPLOSION_6, renderizador));

    ///EXPLOSION JEFE ///

    this->texturas_explosion_jefe.emplace_back(crearTextura(RUTA_IMAGEN_EXPLOSION_1_J, renderizador));
    this->texturas_explosion_jefe.emplace_back(crearTextura(RUTA_IMAGEN_EXPLOSION_2_J, renderizador));
    this->texturas_explosion_jefe.emplace_back(crearTextura(RUTA_IMAGEN_EXPLOSION_3_J, renderizador));
    this->texturas_explosion_jefe.emplace_back(crearTextura(RUTA_IMAGEN_EXPLOSION_4_J, renderizador));
    this->texturas_explosion_jefe.emplace_back(crearTextura(RUTA_IMAGEN_EXPLOSION_5_J, renderizador));
    this->texturas_explosion_jefe.emplace_back(crearTextura(RUTA_IMAGEN_EXPLOSION_6_J, renderizador));
}

std::vector<SDL_Texture*> CargadorTexturasEfectos::getTexturaExplosion() {
    return this->texturas_explosion;
}

std::vector<SDL_Texture*> CargadorTexturasEfectos::getTexturaExplosionJefe() {
    return this->texturas_explosion_jefe;
}

CargadorTexturasEfectos::~CargadorTexturasEfectos(){

    for( auto i: this->texturas_explosion ){
        SDL_DestroyTexture(i);
    }
    for( auto i: this->texturas_explosion_jefe ){
        SDL_DestroyTexture(i);
    }
}