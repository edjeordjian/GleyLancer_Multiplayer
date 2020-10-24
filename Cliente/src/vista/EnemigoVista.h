#ifndef PRIMERAENTREGA_ENEMIGOVISTA_H
#define PRIMERAENTREGA_ENEMIGOVISTA_H

#include <SDL2/SDL_image.h>
#include <vector>
#include "CargadorTexturasEnemigos.h"


class EnemigoVista {
protected:
    SDL_Texture* textura_actual;
    SDL_Rect posicion;
    SDL_Rect sprite_actual;
    std::vector<SDL_Texture*> texturas;
    int contador_daniado;

public:
    explicit EnemigoVista();
    virtual ~EnemigoVista();

    SDL_Rect* getPosicion();
    SDL_Texture* getTextura();
    SDL_Rect* getSpriteActual();
    virtual void actualizar(int pos_x, int pos_y, int direccion, bool herido);
};


#endif //PRIMERAENTREGA_ENEMIGOVISTA_H
