#ifndef PRIMERAENTREGA_CARGADORTEXTURASENEMIGOS_H
#define PRIMERAENTREGA_CARGADORTEXTURASENEMIGOS_H

#include "../tools/ConstantesEnemigo.h"
#include "../tools/SDL_Utils.h"

class CargadorTexturasEnemigos {
private:
    std::vector<SDL_Texture*> texturas_enemigo_1; //En principio solo las de las direcciones, luego habra un vector de texturas por estado
    std::vector<SDL_Texture*> texturas_enemigo_2;
    std::vector<SDL_Texture*> texturas_jefe_1;
    std::vector<SDL_Texture*> texturas_jefe_2;
    std::vector<SDL_Texture*> texturas_jefe_3;
    std::vector<SDL_Texture*> texturas_enemigo_default;

public:

    CargadorTexturasEnemigos(SDL_Renderer* renderizador);
    std::vector<SDL_Texture*> getTexturas(std::string tipo_enemigo);
    ~CargadorTexturasEnemigos();

};


#endif //PRIMERAENTREGA_CARGADORTEXTURASENEMIGOS_H
