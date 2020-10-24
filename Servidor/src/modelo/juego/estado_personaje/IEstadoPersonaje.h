#ifndef SERVIDOR_IESTADOPERSONAJE_H
#define SERVIDOR_IESTADOPERSONAJE_H

#include "../Posicion.h"

class IEstadoPersonaje {

public:
    //El destructor no hace nada, tira error si no lo declaro
    virtual ~IEstadoPersonaje() = default;
    virtual void actualizar() = 0;
    virtual void actualizarPosicion(Posicion direccion_nueva) = 0;
    virtual void actualizarColision(Posicion pos_colision) = 0;
    virtual bool estaQuieto() = 0;
    virtual Posicion getDireccion() = 0;

};

#endif //SERVIDOR_IESTADOPERSONAJE_H
