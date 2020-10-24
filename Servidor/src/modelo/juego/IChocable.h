#ifndef SERVIDOR_ICHOCABLE_H
#define SERVIDOR_ICHOCABLE_H

#include "Posicion.h"

class IChocable {
public:
    virtual ~IChocable() = default;
    virtual int getAncho() = 0;
    virtual int getAlto() = 0;
    virtual double getPosX() = 0;
    virtual double getPosY() = 0;
    virtual void setPosicionVentana(Posicion pos_ventana_nueva) = 0;
    virtual Posicion getPosicionVentana() = 0;
    virtual void setEstaEnVentana(bool estado) = 0;
    virtual bool getEstaEnVentana() = 0;
};


#endif //SERVIDOR_ICHOCABLE_H

