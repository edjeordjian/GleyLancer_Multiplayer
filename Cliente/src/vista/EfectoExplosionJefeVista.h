#ifndef CLIENTE_EFECTOEXPLOSIONJEFEVISTA_H
#define CLIENTE_EFECTOEXPLOSIONJEFEVISTA_H


#include "EfectoExplosionVista.h"
#include "CargadorTexturasEfectos.h"


class EfectoExplosionJefeVista : public EfectoExplosionVista{

    public:
        EfectoExplosionJefeVista(int x, int y,int nro_nivel,CargadorTexturasEfectos* cargador);
};


#endif //CLIENTE_EFECTOEXPLOSIONJEFEVISTA_H
