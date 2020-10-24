#ifndef CLIENTE_CARGADORTEXTURASUIPERSONAJE_H
#define CLIENTE_CARGADORTEXTURASUIPERSONAJE_H

#include "../tools/SDL_Utils.h"
#include "../tools/ConstantesPersonaje.h"

class CargadorTexturasUIPersonaje {
private:
    std::vector<SDL_Texture*> texturas_personaje_1;
    std::vector<SDL_Texture*> texturas_personaje_2;
    std::vector<SDL_Texture*> texturas_personaje_3;
    std::vector<SDL_Texture*> texturas_personaje_4;
    std::vector<SDL_Texture*> texturas_barras_vidas;

public:

    CargadorTexturasUIPersonaje(SDL_Renderer* renderizador);
    std::vector<SDL_Texture*> getTexturas(int n_personaje);
    SDL_Texture* getTexturaBarra(int n_personaje);
    SDL_Texture* getTexturaBarraTest();
    ~CargadorTexturasUIPersonaje();

};


#endif //CLIENTE_CARGADORTEXTURASUIPERSONAJE_H
