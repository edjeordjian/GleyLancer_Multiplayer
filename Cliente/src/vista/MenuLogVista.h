#ifndef CLIENTE_MENULOGVISTA_H
#define CLIENTE_MENULOGVISTA_H

#include <SDL2/SDL_system.h>
#include "TextoSDL.h"
#include "../tools/ConstantesMenu.h"


class MenuLogVista {
    private:
        SDL_Renderer* renderizador;
        SDL_Texture* textura;

        TextoSDL* texto_usuario;
        TextoSDL* usuario;
        TextoSDL* texto_pass;
        TextoSDL* pass;
        TextoSDL* validar;

        TTF_Font* fuente_normal;
        TTF_Font* fuente_chica;

    public:
        explicit MenuLogVista(SDL_Renderer* renderizador);
        virtual ~MenuLogVista();

        void cambiarColor(TextoSDL* t1, SDL_Color c1, TextoSDL* t2, SDL_Color c2,
                          TextoSDL* t3, SDL_Color c3);

        void actualizar(int accion);
        void actualizarValores(TextoSDL* usuario, TextoSDL* password);
};

#endif //CLIENTE_MENULOGVISTA_H
