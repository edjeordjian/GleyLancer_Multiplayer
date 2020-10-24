#ifndef CLIENTE_MENUJUEGO_H
#define CLIENTE_MENUJUEGO_H

#include <string>
#include <SDL2/SDL.h>
#include "../tools/ConstantesMenu.h"
#include "../tools/Log.h"
#include "../vista/JuegoSonido.h"

class MenuJuego {
  private:
    int actual;
    bool activo;

   public:
        MenuJuego();
        int inicializar();
        int actualizar(JuegoSonido *pSonido);
        bool estaActivo();
        bool estaIniciado();
        bool estaCancelado(SDL_Event* evento);
        void reestablecer();
        virtual ~MenuJuego();
};

#endif //CLIENTE_MENUJUEGO_H
