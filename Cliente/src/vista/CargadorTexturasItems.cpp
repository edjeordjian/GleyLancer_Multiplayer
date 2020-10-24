#include "CargadorTexturasItems.h"

CargadorTexturasItems::CargadorTexturasItems(SDL_Renderer* renderizador){
    this->texturas.push_back(crearTextura(RUTA_ITEM_VIDA, renderizador));
    this->texturas.push_back(crearTextura(RUTA_ITEM_ENERGIA, renderizador));
    this->texturas.push_back(crearTextura(RUTA_ITEM_PUNTOS, renderizador));
    this->texturas.push_back(crearTextura(RUTA_ITEM_ESCUDO, renderizador));

}

std::vector<SDL_Texture*> CargadorTexturasItems::getTexturas(){
    return this->texturas;
}

CargadorTexturasItems::~CargadorTexturasItems(){
    for (auto &i: this->texturas) {
        SDL_DestroyTexture(i);
    }
}
