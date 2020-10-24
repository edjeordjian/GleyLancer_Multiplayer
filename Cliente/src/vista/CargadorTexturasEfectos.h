#ifndef CLIENTE_CARGADORTEXTURASEFECTOS_H
#define CLIENTE_CARGADORTEXTURASEFECTOS_H

#include <vector>
#include <SDL2/SDL.h>
#include "../tools/ConstantesEfectos.h"
#include "../tools/SDL_Utils.h"

class CargadorTexturasEfectos {
    private:
        std::vector<SDL_Texture*> texturas_explosion;
        std::vector<SDL_Texture*> texturas_explosion_jefe;

    public:
        CargadorTexturasEfectos(SDL_Renderer* renderizador);
        std::vector<SDL_Texture*> getTexturaExplosion();
        std::vector<SDL_Texture*> getTexturaExplosionJefe();
        ~CargadorTexturasEfectos();

};


#endif //CLIENTE_CARGADORTEXTURASEFECTOS_H
