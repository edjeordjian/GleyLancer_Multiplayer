#ifndef CLIENTE_CARGADORTEXTURASCAJAS_H
#define CLIENTE_CARGADORTEXTURASCAJAS_H

#include <SDL2/SDL_image.h>
#include <vector>
#include <string>
#include "../tools/SDL_Utils.h"
#include "../tools/ConstantesItems.h"

class CargadorTexturasCajas {
    std::vector<SDL_Texture*> texturas;

public:
    CargadorTexturasCajas(SDL_Renderer* renderizador);
    std::vector<SDL_Texture*> getTexturas();
    ~CargadorTexturasCajas();

};


#endif //CLIENTE_CARGADORTEXTURASCAJAS_H
