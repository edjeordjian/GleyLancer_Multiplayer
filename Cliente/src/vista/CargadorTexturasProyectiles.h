#ifndef PRUEBADISPAROS_CARGADORTEXTURASPROYECTIL_H
#define PRUEBADISPAROS_CARGADORTEXTURASPROYECTIL_H

#include "../tools/ConstantesProyectiles.h"
#include "../tools/ConstantesPersonaje.h"
#include "../tools/ConstantesEnemigo.h"
#include "../tools/SDL_Utils.h"


class CargadorTexturasProyectiles {
private:
    std::vector<SDL_Texture*> texturas_proyectil_personaje_1;
    std::vector<SDL_Texture*> texturas_proyectil_personaje_2;
    std::vector<SDL_Texture*> texturas_proyectil_personaje_3;
    std::vector<SDL_Texture*> texturas_proyectil_personaje_4;
    std::vector<SDL_Texture*> texturas_proyectil_enemigo_1;
    std::vector<SDL_Texture*> texturas_proyectil_enemigo_2;
    std::vector<SDL_Texture*> texturas_proyectil_jefe;

    SDL_Texture* textura_luz_p1;
    SDL_Texture* textura_luz_p2;
    SDL_Texture* textura_luz_p3;
    SDL_Texture* textura_luz_p4;
    SDL_Texture* textura_luz_e1;
    SDL_Texture* textura_luz_e2;
    SDL_Texture* textura_luz_j;

public:

    CargadorTexturasProyectiles(SDL_Renderer* renderizador);
    std::vector<SDL_Texture*> getTexturas(int nro_personaje);
    SDL_Texture* getTexturaLuz(int nro_personaje);
    ~CargadorTexturasProyectiles();

};


#endif //PRUEBADISPAROS_CARGADORTEXTURASPROYECTIL_H
