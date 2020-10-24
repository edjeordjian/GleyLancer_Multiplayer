#ifndef PRIMERAENTREGA_FONDOVISTA_H
#define PRIMERAENTREGA_FONDOVISTA_H

#include "../tools/SDL_Utils.h"
#include <SDL2/SDL_image.h>

class FondoVista {
    private:

        float incremento_capa_1;
        float incremento_capa_2;
        float incremento_capa_3;
        float incremento_capa_4;
        float incremento_capa_5;


        float posicion_capa_1;
        float posicion_capa_2;
        float posicion_capa_3;
        float posicion_capa_4;
        float posicion_capa_5;
        float posicion_capa_6;

        SDL_Rect fondo_capa_1;
        SDL_Rect fondo_capa_2;
        SDL_Rect fondo_capa_3;
        SDL_Rect fondo_capa_4;
        SDL_Rect fondo_capa_5;
        SDL_Rect fondo_capa_6;

        SDL_Rect camara_capa_1;
        SDL_Rect camara_capa_2;
        SDL_Rect camara_capa_3;
        SDL_Rect camara_capa_4;
        SDL_Rect camara_capa_5;
        SDL_Rect camara_capa_6;

        SDL_Texture* textura_capa_1;
        SDL_Texture* textura_capa_2;
        SDL_Texture* textura_capa_3;
        SDL_Texture* textura_capa_4;
        SDL_Texture* textura_capa_5;
        SDL_Texture* textura_capa_6;


public:
        FondoVista(char* capa_1,char* capa_2, char* capa_3, char* capa_4, char* capa_5, char* capa_6, SDL_Renderer* renderizador);
        void actualizar();
        void actualizar(int posicion_ventana);
        SDL_Rect* getPrimeraCapa();
        SDL_Rect* getSegundaCapa();
        SDL_Rect* getTercerCapa();
        SDL_Rect* getCuartaCapa();
        SDL_Rect* getQuintaCapa();
        SDL_Rect* getSextaCapa();
        SDL_Texture* getTexturaPrimerCapa();
        SDL_Texture* getTexturaSegundaCapa();
        SDL_Texture* getTexturaTercerCapa();
        SDL_Texture* getTexturaCuartaCapa();
        SDL_Texture* getTexturaQuintaCapa();
        SDL_Texture* getTexturaSextaCapa();
        ~FondoVista();
};


#endif //PRIMERAENTREGA_FONDOVISTA_H
