#ifndef CLIENTE_MENULOGCONTROLADOR_H
#define CLIENTE_MENULOGCONTROLADOR_H

#include "../modelo/MenuLog.h"
#include "../vista/MenuLogVista.h"
#include "../vista/JuegoSonido.h"

class MenuLogControlador {
    private:
        MenuLog* menu_log;
        MenuLogVista* menu_vista;

    public:
        explicit MenuLogControlador(SDL_Renderer* renderizador);

        int actualizar(JuegoSonido *pSonido);
        bool estaActivo();
        bool estaIniciado();
        bool estaCancelado(SDL_Event *pEvent);

        void reestablecer();

        virtual ~MenuLogControlador();
};

#endif //CLIENTE_MENULOGCONTROLADOR_H
