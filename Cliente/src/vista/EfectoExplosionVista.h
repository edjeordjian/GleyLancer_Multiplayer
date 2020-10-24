#ifndef CLIENTE_EFECTOEXPLOSIONVISTA_H
#define CLIENTE_EFECTOEXPLOSIONVISTA_H

#include<SDL2/SDL_image.h>
#include "../tools/SDL_Utils.h"
#include "../tools/ConstantesEfectos.h"

class EfectoExplosionVista {
protected:
    std::vector<SDL_Texture *> texturas_explosiones;
    SDL_Rect* rectangulo_explosion;
    unsigned int tiempo_de_vida;
public:
    SDL_Rect* getRectangulo();

    bool estaActivo();

    SDL_Texture *getTextura();

    ~EfectoExplosionVista();

};


#endif //CLIENTE_EFECTOEXPLOSIONVISTA_H
