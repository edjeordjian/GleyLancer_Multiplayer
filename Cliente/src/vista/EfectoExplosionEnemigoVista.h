#ifndef CLIENTE_EFECTOEXPLOSIONENEMIGOVISTA_H
#define CLIENTE_EFECTOEXPLOSIONENEMIGOVISTA_H


#include "EfectoExplosionVista.h"
#include "CargadorTexturasEfectos.h"

class EfectoExplosionEnemigoVista : public EfectoExplosionVista{

public:
    EfectoExplosionEnemigoVista(int x, int y, CargadorTexturasEfectos* cargador);
};


#endif //CLIENTE_EFECTOEXPLOSIONENEMIGOVISTA_H
