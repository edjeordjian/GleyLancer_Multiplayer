#ifndef CLIENTE_MENULOG_H
#define CLIENTE_MENULOG_H

#include <string>
#include <SDL2/SDL.h>
#include "../tools/ConstantesMenu.h"
#include "../tools/Log.h"
#include "../vista/JuegoSonido.h"

class MenuLog {
    private:
        int actual;

    public:
        explicit MenuLog();
        int actualizar(JuegoSonido *pSonido);
        void configurar(int caso, std::string valor);
        bool estaActivo();
        bool estaIniciado();
        bool estaCancelado(SDL_Event *evento);
        void reestablecer();
        virtual ~MenuLog();
};


#endif //CLIENTE_MENULOG_H
