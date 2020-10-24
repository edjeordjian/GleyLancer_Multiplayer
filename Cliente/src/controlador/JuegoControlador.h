#ifndef CLIENTE_JUEGOCONTROLADOR_H
#define CLIENTE_JUEGOCONTROLADOR_H

#include "../vista/JuegoVista.h"
#include "../tools/ConstantesTeclas.h"
#include "../vista/JuegoSonido.h"
#include "../hilos/ColaProtegida.h"
#include "../hilos/HiloDibujador.h"
#include "MenuJuegoControlador.h"
#include "CartelControlador.h"
#include "MenuLogControlador.h"
#include <SDL2/SDL.h>

class JuegoControlador{
    private:
        JuegoVista* vista;
        MenuJuegoControlador* menu;
        MenuLogControlador* menu_log;
        CartelControlador* cartel_controlador;

        int tecla_movimiento;   //True si mantengo apretada alguna tecla de movimiento
        int tecla_disparo;      //True si mantengo apretada alguna tecla de disparo
        bool tecla_propulsion;        //True si mantengo apretada alguna tecla de propulsion

        bool tecla_mute;        //True si mantengo apretada la tecla mute
        bool tecla_test;        //True si mantengo apretada la tecla test
        bool tecla_mute_sfx;    //True si mantengo apretada la tecla mute_sfx

        ColaProtegida<std::string>* cola_actualizaciones_vista;
        HiloDibujador* hilo_dibujador;

        JuegoSonido* controlador_sonido;

    public:
        explicit JuegoControlador();
        virtual ~JuegoControlador();

        void reiniciar();
        void desactivarInput();
        void retrocederCartel();
        bool actualizarMenu();
        void reestablecerMenu();
        bool inicioElJuego();
        bool juegoCancelado(SDL_Event *p_event);
        bool iniciarNivel(SDL_Event* evento, bool actualizar_cartel);
        void finalizarNivel();
        void mostrarGameOver();
        void juegoGanado(int cantidad_ganadores);
        void iniciarVista();
        void actualizarVista(std::string estado);
        void setNumeroPersonaje(int nro_personaje);

        bool actualizarCartel(SDL_Event* evento);
        void cambiarCartel();

        void resetearCartel();

        bool iniciar();
        bool actualizar(SDL_Event* evento, ColaProtegida<uint16_t>* cola_inputs);

        bool menuLogEstaIniciado();
        void menuLogReestablecer();
        int actualizarMenuLog();
        void actualizarJugadoresConectados(std::string mensaje);
        void cartelIniciarJuego();

        void actualizarNivel(std::string estado_nivel);

        void cerrarMenuPrincipal();
        void recrearMenu();

        void actualizarCartelMuertosConectados(char* m1, char* m2);
        void avanzarCartelNivel();
};

#endif //CLIENTE_JUEGOCONTROLADOR
