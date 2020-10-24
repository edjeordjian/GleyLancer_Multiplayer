#ifndef CLIENTE_UIPERSONAJEVISTA_H
#define CLIENTE_UIPERSONAJEVISTA_H

#include <SDL2/SDL_image.h>
#include "CargadorTexturasUIPersonaje.h"
#include "BarraVidaVista.h"
#include <vector>


class UIPersonajeVista {
private:
    SDL_Texture* textura_actual;
    SDL_Rect posicion;
    std::vector<SDL_Texture*> texturas;
    int contador_disparando;
    int contador_impactado;
    BarraVidaVista* barra_vida;


public:
    UIPersonajeVista(int nro_personaje, CargadorTexturasUIPersonaje* cargador, int x_barra, int y_barra);
    SDL_Rect* getPosicion();
    SDL_Texture* getTextura();
    void actualizar(int estado_personaje_ui, std::string energia, int n_vidas, bool modo_test);
    void mostrarBarraVida(SDL_Renderer* renderizador);
    ~UIPersonajeVista();
};


#endif //CLIENTE_UIPERSONAJEVISTA_H
