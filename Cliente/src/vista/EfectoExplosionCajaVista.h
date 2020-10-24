#ifndef CLIENTE_EFECTOEXPLOSIONCAJAVISTA_H
#define CLIENTE_EFECTOEXPLOSIONCAJAVISTA_H


#include "EfectoExplosionVista.h"
#include "CargadorTexturasEfectos.h"


class EfectoExplosionCajaVista  : public EfectoExplosionVista {

public:

    EfectoExplosionCajaVista(int x, int y, CargadorTexturasEfectos* cargador);
};


#endif //CLIENTE_EFECTOEXPLOSIONCAJAVISTA_H
