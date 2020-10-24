#ifndef CLIENTE_CARGADORTEXTURASPERSONAJES_H
#define CLIENTE_CARGADORTEXTURASPERSONAJES_H

#include "../tools/SDL_Utils.h"
#include "../tools/ConstantesPersonaje.h"
#include "../tools/ConstantesEfectos.h"

class CargadorTexturasPersonajes {
private:
    std::vector<SDL_Texture*> texturas_personaje_1; //En principio solo las de las direcciones, luego habra un vector de texturas por estado
    std::vector<SDL_Texture*> texturas_personaje_2;
    std::vector<SDL_Texture*> texturas_personaje_3;
    std::vector<SDL_Texture*> texturas_personaje_4;
    std::vector<SDL_Texture*> texturas_personaje_desconectado;
    SDL_Texture* textura_efecto_velocidad;
    std::vector<SDL_Texture*> texturas_escudo;

public:

    CargadorTexturasPersonajes(SDL_Renderer* renderizador);
    std::vector<SDL_Texture*> getTexturas(int n_personaje);
    SDL_Texture* getTexturaEfectoVelocidad();
    SDL_Texture* getTexturaEscudo(int n_personaje);
    ~CargadorTexturasPersonajes();

};


#endif //CLIENTE_CARGADORTEXTURASPERSONAJES_H
