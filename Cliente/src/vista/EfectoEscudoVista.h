#ifndef CLIENTE_EFECTOESCUDOVISTA_H
#define CLIENTE_EFECTOESCUDOVISTA_H

#include <SDL2/SDL.h>
#include <iostream>
#include "../tools/ConstantesPersonaje.h"

class EfectoEscudoVista {
private:
    SDL_Texture* textura_escudo;
    SDL_Rect rectangulo_posicion;
    int ancho;
    int alto;
    unsigned contador;

public:
    EfectoEscudoVista(SDL_Texture* textura);
    ~EfectoEscudoVista();
    void actualizar(int pos_x,int pos_y);
    SDL_Texture* getTextura();
    void setTextura(SDL_Texture* nueva_textura);
    SDL_Rect* getRectangulo();
};


#endif //CLIENTE_EFECTOESCUDOVISTA_H
