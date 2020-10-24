#ifndef CLIENTE_CARGADORTEXTURASITEMS_H
#define CLIENTE_CARGADORTEXTURASITEMS_H

#include "../tools/SDL_Utils.h"
#include "../tools/ConstantesItems.h"

class CargadorTexturasItems {
    std::vector<SDL_Texture*> texturas;

public:
    CargadorTexturasItems(SDL_Renderer* renderizador);
    std::vector<SDL_Texture*> getTexturas();
    ~CargadorTexturasItems();

};

#endif //CLIENTE_CARGADORTEXTURASITEMS_H
