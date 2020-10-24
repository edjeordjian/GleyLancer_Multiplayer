#include "EfectoExplosionJefeVista.h"

EfectoExplosionJefeVista::EfectoExplosionJefeVista(int x, int y, int nro_nivel, CargadorTexturasEfectos* cargador) {

    this->tiempo_de_vida=0;
    this->rectangulo_explosion = new SDL_Rect;

    initRect(this->rectangulo_explosion,x-CORRECCIONES_JEFES[(unsigned int) nro_nivel * 2],
             y-CORRECCIONES_JEFES[(unsigned int) nro_nivel * 2 + 1],
             EXPLOSIONES_JEFES[(unsigned int) nro_nivel * 2],
            EXPLOSIONES_JEFES[(unsigned int) nro_nivel * 2 + 1]);

    this->texturas_explosiones=cargador->getTexturaExplosionJefe();

}