#ifndef CLIENTE_MENUJUEGOCONTROLADOR_H
#define CLIENTE_MENUJUEGOCONTROLADOR_H

#include <SDL2/SDL.h>
#include "../vista/MenuJuegoVista.h"
#include "../modelo/MenuJuego.h"
#include "../vista/JuegoSonido.h"
#include <SDL2/SDL.h>

class MenuJuegoControlador {
    MenuJuegoVista* menu_vista;
    MenuJuego* menu;

public:
    explicit MenuJuegoControlador(SDL_Renderer* renderizador);
    virtual ~MenuJuegoControlador();

    void iniciar();
    bool actualizar(JuegoSonido *pSonido);
    bool estaIniciado();
    bool estaCancelado(SDL_Event *pEvent);
    void reestablecer();


};

#endif //CLIENTE_MENUJUEGOCONTROLADOR_H
