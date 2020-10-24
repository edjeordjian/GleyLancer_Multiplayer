#ifndef CLIENTE_EFECTOVELOCIDADVISTA_H
#define CLIENTE_EFECTOVELOCIDADVISTA_H

#include <SDL2/SDL.h>
#include "../tools/ConstantesEfectos.h"

class EfectoVelocidadVista {
    private:
        SDL_Texture* textura_efecto;
        SDL_Rect rectangulo_posicion;
        int cont;
        bool derecha;
        int alto_ancho;
        bool propulsionando;
    public:
        EfectoVelocidadVista(SDL_Texture* textura);
        ~EfectoVelocidadVista();
        void actualizar(int pos_x,int pos_y, bool esta_propulsionando);
        SDL_Texture* getTextura();
        SDL_Rect* getRectangulo();
};


#endif //CLIENTE_EFECTOVELOCIDADVISTA_H
