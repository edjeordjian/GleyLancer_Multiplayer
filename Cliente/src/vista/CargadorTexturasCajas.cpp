#include "CargadorTexturasCajas.h"

CargadorTexturasCajas::CargadorTexturasCajas(SDL_Renderer* renderizador){
    this->texturas.push_back(crearTextura(RUTA_CAJA, renderizador));
}

std::vector<SDL_Texture*> CargadorTexturasCajas::getTexturas(){
    return this->texturas;
}

CargadorTexturasCajas::~CargadorTexturasCajas(){
    for (auto &i: this->texturas) {
        SDL_DestroyTexture(i);
    }
}