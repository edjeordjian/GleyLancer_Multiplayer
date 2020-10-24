#ifndef CLIENTE_EFECTOEXPLOSIONPERSONAJEVISTA_H
#define CLIENTE_EFECTOEXPLOSIONPERSONAJEVISTA_H


#include "EfectoExplosionVista.h"
#include "CargadorTexturasEfectos.h"

class EfectoExplosionPersonajeVista : public EfectoExplosionVista{

public:
    EfectoExplosionPersonajeVista(int x, int y, CargadorTexturasEfectos* cargador);
};


#endif //CLIENTE_EFECTOEXPLOSIONPERSONAJEVISTA_H
