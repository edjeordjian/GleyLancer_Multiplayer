#ifndef CLIENTE_CARTELVISTA_H
#define CLIENTE_CARTELVISTA_H

#include <SDL2/SDL.h>
#include <vector>
#include <string>
#include "../vista/TextoSDL.h"
#include "../tools/SDL_Utils.h"
#include "../tools/ConstantesMenu.h"

class CartelVista {
    private:
        std::vector<SDL_Texture*> carteles;
        std::vector<SDL_Texture*> numeros;
        std::vector<SDL_Texture*> carteles_congratulations;
        SDL_Renderer* renderizador;
        TextoSDL* mensaje_adicional;
        TextoSDL* mensaje_muertos_conectados_1;
        TextoSDL* mensaje_muertos_conectados_2;
        TTF_Font* fuente;

public:
        explicit CartelVista(SDL_Renderer* renderizador);
        virtual ~CartelVista();

        void actualizar(size_t opcion_cartel);
        void actualizar(size_t opcion_cartel, size_t opcion_numero);
        void actualizarJugadoresConectados(std::string mensaje);

        void actualizarCartelMuertosConectados(char* m1, char* m2);
        void mostrarJuegoGanado(int cantidad_ganadores);
};

#endif //CLIENTE_CARTELVISTA_H
