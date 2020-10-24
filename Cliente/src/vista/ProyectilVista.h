#ifndef PRUEBADISPAROS_PROYECTILVISTA_H
#define PRUEBADISPAROS_PROYECTILVISTA_H

#include <SDL2/SDL_image.h>
#include <vector>
#include <string>
#include "CargadorTexturasProyectiles.h"
#include "../tools/ConstantesMenu.h"

class ProyectilVista {
private:
    SDL_Texture* textura_actual;
    SDL_Rect posicion;
    SDL_Rect sprite_actual;
    std::vector<SDL_Texture*> texturas;

    SDL_Texture* textura_luz;
    SDL_Rect rect_luz;
    int contador;
    bool contador_subiendo;

public:
    explicit ProyectilVista(int pos_x, int pos_y, int nro_jugador, CargadorTexturasProyectiles* cargador);
    virtual ~ProyectilVista();

    void cargarRectangulos(int pos_x, int pos_y);
    SDL_Rect* getPosicion();
    SDL_Texture* getTextura();
    SDL_Rect* getSpriteActual();
    void actualizar(int pos_x, int pos_y, int direccion);

    SDL_Texture* getTexturaLuz();
    SDL_Rect* getRectLuz();
};


#endif //PRUEBADISPAROS_PROYECTILVISTA_H
