#ifndef CLIENTE_BARRAVIDAVISTA_H
#define CLIENTE_BARRAVIDAVISTA_H

#include<SDL2/SDL.h>
#include "../tools/SDL_Utils.h"
#include "../tools/ConstantesPersonaje.h"


class BarraVidaVista {
    private:
        SDL_Rect* rectangulo_barra_completa;
        SDL_Rect* barra_vida;
        SDL_Texture* textura_barra_personaje;
        SDL_Texture* textura_barra_test;
        SDL_Texture* textura_actual;
    public:
        BarraVidaVista(SDL_Texture* textura_barra_personaje, SDL_Texture* textura_barra_test, int x, int y);
        void actualizar(int energia, bool modo_test);
        SDL_Texture* getTextura();
        SDL_Rect* getRectCompleto();
        SDL_Rect* getBarraVida();
        ~BarraVidaVista();

};


#endif //CLIENTE_BARRAVIDAVISTA_H
