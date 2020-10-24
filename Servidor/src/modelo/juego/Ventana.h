#ifndef SERVIDOR_VENTANA_H
#define SERVIDOR_VENTANA_H

#include <SDL2/SDL_image.h>
#include "Personaje.h"
#include "../../tools/SDL_Utils.h"
#include "Enemigo.h"
#include "IChocable.h"

class Ventana {
    private:
        SDL_Rect marco_ventana;
        double posicion_x_fondo;
        float incremento_ventana;
        bool llego_al_final;

    public:
        Ventana(float incremento);
        ~Ventana();
        bool actualizar();
        void corregirColisionBorde(Personaje* personaje);
        void actualizarPosicionVista(IChocable* chocable);
        double getX();
        bool llegoAlFinal();
};

#endif //SERVIDOR_VENTANA_H
