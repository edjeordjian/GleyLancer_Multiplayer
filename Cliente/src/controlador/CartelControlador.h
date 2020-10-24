#ifndef CLIENTE_CARTELCONTROLADOR_H
#define CLIENTE_CARTELCONTROLADOR_H

#include <SDL2/SDL.h>
#include "../modelo/Cartel.h"
#include "../vista/CartelVista.h"
#include "../tools/ConstantesComunicacion.h"
#include "../vista/JuegoSonido.h"
#include <string>

class CartelControlador {
    private:
        Cartel* cartel;
        CartelVista* vista_cartel;

    public:
        CartelControlador(SDL_Renderer* renderizador);

        void desactivarInput();
        void retrocederCartel();
        bool actualizar(SDL_Event* evento, bool usar_numero, JuegoSonido* cSonido);
        void cambiar();
        bool iniciarNivel(SDL_Event* evento, bool actualizar_cartel, JuegoSonido* cSonido);
        void mostrarJuegoGanado(int cantidad_ganadores);

        //Setea el cartel al anterior al de los que aparecen en el transcurso del juego (stages)
        void setIniciarJuego();

        void resetearCarteles();

        void actualizarJugadoresConectados(std::string mensaje);

        void setNivel(int nivel);

        virtual ~CartelControlador();

    void actualizarCartelMuertosConectados(char* m1, char* m2);
};

#endif //CLIENTE_CARTELCONTROLADOR_H
