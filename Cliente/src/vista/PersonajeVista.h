#ifndef PRIMERAENTREGA_PERSONAJEVISTA_H
#define PRIMERAENTREGA_PERSONAJEVISTA_H

#include <SDL2/SDL_image.h>
#include "CargadorTexturasPersonajes.h"
#include "EfectoVelocidadVista.h"
#include "EfectoEscudoVista.h"
#include <vector>

class PersonajeVista {
private:
    SDL_Texture* textura_actual;
    SDL_Rect posicion;
    SDL_Rect sprite_actual;
    std::vector<SDL_Texture*> texturas;
    int nro_personaje;
    bool a_derecha;
    int contador_brillo_nave;
    int contador_brillo_disparo;
    EfectoVelocidadVista* efecto_velocidad;
    EfectoEscudoVista* efecto_escudo;
    int contador_daniado;
    bool escudo;
    bool propulsionando;

public:
    explicit PersonajeVista(int pos_x, int pos_y, int nro_personaje_nuevo, CargadorTexturasPersonajes* cargador);
    virtual ~PersonajeVista();
    int getNumeroPersonaje();
    SDL_Rect* getPosicion();
    SDL_Texture* getTextura();
    SDL_Rect* getSpriteActual();
    void mostrarEfectoVelocidad(SDL_Renderer* renderizador);
    void mostrarEfectoEscudo(SDL_Renderer* renderizador);
    void actualizar(int pos_x, int pos_y,int direccion, int disparando, int daniado, int escudo_nuevo, int esta_propulsionando);
    void actualizarTexturas(int nro_personaje_nuevo, CargadorTexturasPersonajes* cargador);
    bool estaPropulsionando();
};


#endif //PRIMERAENTREGA_PERSONAJEVISTA_H