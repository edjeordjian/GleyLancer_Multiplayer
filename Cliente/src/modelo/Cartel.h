#ifndef CLIENTE_CARTEL_H
#define CLIENTE_CARTEL_H

#include <vector>
#include <SDL2/SDL.h>
#include "../tools/ConstantesMenu.h"


class Cartel{
    private:
        int cartel_actual;
        int numero_actual;
        bool espera_input;

    public:
        explicit Cartel();

        void retrocederCartel();

        void setEsperaInput(bool espera);

        size_t getCartel();

        void setCartel(int nro_cartel);

        bool continuar(SDL_Event* evento);

        int cambiar();

        size_t getNumeroActual();

        void proximoNumero();

        void iniciarNumero();

        virtual ~Cartel();
};

#endif //CLIENTE_CARTEL_H
