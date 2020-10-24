#ifndef CLIENTE_ITEMVISTA_H
#define CLIENTE_ITEMVISTA_H

#include <SDL2/SDL_image.h>
#include <vector>
#include <string>
#include "CargadorTexturasItems.h"
#include "../tools/ConstantesItems.h"


class ItemVista {
private:
    SDL_Texture* textura_actual;
    SDL_Rect posicion;
    SDL_Rect sprite_actual;
    std::vector<SDL_Texture*> texturas;
public:
    ItemVista(int pos_x, int pos_y, int tipo, CargadorTexturasItems* cargador);
    ~ItemVista();

    void cargarRectangulos(int pos_x, int pos_y);
    SDL_Rect* getPosicion();
    SDL_Texture* getTextura();
    SDL_Rect* getSpriteActual();
    void actualizar(int pos_x, int pos_y);

};


#endif //CLIENTE_ITEMVISTA_H
