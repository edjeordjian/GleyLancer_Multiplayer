#ifndef CLIENTE_TEXTOSDL_H
#define CLIENTE_TEXTOSDL_H

#include <SDL2/SDL.h>
#include <SDL2/SDL_ttf.h>
#include "../tools/SDL_Utils.h"

class TextoSDL{
    private:
        SDL_Renderer *renderizador;
        SDL_Texture* texto;
        SDL_Rect rectangulo;
        SDL_Color color;
        TTF_Font* fuente;
        char* mensaje;

    public:
        explicit TextoSDL(SDL_Renderer *renderizador, TTF_Font* fuente_nueva, SDL_Color color, int tam, char *msj,
                int x, int y);
        SDL_Texture* getTexto();
        char* getMensaje();
        void setTexto(const char *msj);
        void setTexto(const char *msj, SDL_Color color);
        SDL_Rect* getRectangulo();
        SDL_Color getColor();
        virtual ~TextoSDL();

};

#endif //CLIENTE_TEXTOSDL_H
