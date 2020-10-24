#ifndef CLIENTE_CAJAVISTA_H
#define CLIENTE_CAJAVISTA_H

#include <SDL2/SDL_image.h>
#include <vector>
#include <string>
#include "CargadorTexturasCajas.h"
#include "../tools/ConstantesItems.h"

class CajaVista {
private:
    SDL_Texture* textura_actual;
    SDL_Rect posicion;
    SDL_Rect sprite_actual;
    std::vector<SDL_Texture*> texturas;
public:
    CajaVista(int pos_x, int pos_y, CargadorTexturasCajas* cargador);
    ~CajaVista();

    void cargarRectangulos(int pos_x, int pos_y);
    SDL_Rect* getPosicion();
    SDL_Texture* getTextura();
    SDL_Rect* getSpriteActual();
    void actualizar(int pos_x, int pos_y);

};


#endif //CLIENTE_CAJAVISTA_H
