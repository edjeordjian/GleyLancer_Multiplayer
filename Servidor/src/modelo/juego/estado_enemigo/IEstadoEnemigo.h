#ifndef SERVIDOR_ESTADOENEMIGO_H
#define SERVIDOR_ESTADOENEMIGO_H

#include "../Posicion.h"

class IEstadoEnemigo {

public:
    virtual ~IEstadoEnemigo() = default;
    virtual bool estaQuieto() = 0;
    virtual void actualizar() = 0;
    virtual void activar() = 0;
};

#endif //SERVIDOR_ESTADOENEMIGO_H
