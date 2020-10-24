#ifndef CLIENTE_MENUJUEGOVISTA_H
#define CLIENTE_MENUJUEGOVISTA_H

#include "TextoSDL.h"
#include "../tools/ConstantesMenu.h"
#include <string>
#include <SDL2/SDL.h>


class MenuJuegoVista {
private:
    SDL_Texture* textura;
    SDL_Renderer* renderizador;
    SDL_Texture* cartel_espera;

    TextoSDL* texto_comenzar;
    TextoSDL* texto_salir;

    TTF_Font* fuente_normal;
    TTF_Font* fuente_chica;

public:
    explicit MenuJuegoVista(SDL_Renderer* renderizador);
    virtual ~MenuJuegoVista();

    void actualizar(int accion);
    SDL_Texture* getTextura();
    void cambiarColor(TextoSDL* t1, SDL_Color c1, TextoSDL* t2, SDL_Color c2);
};

#endif //CLIENTE_MENUJUEGOVISTA_H
