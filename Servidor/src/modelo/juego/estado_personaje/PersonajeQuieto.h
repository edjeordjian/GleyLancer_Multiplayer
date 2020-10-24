#ifndef SERVIDOR_PERSONAJEQUIETO_H
#define SERVIDOR_PERSONAJEQUIETO_H

#include "../Personaje.h"
#include "IEstadoPersonaje.h"
#include "PersonajeMoviendose.h"

class Personaje;

class PersonajeQuieto: public IEstadoPersonaje {
private:
    Personaje* personaje;
public:
    PersonajeQuieto(Personaje* per);
    ~PersonajeQuieto() override ;
    void actualizar() override ;
    Posicion getDireccion() override ;
    void actualizarPosicion(Posicion direccion) override ;
    void actualizarColision(Posicion pos_colision) override ;
    bool estaQuieto() override;

};


#endif //PRIMERAENTREGA_PERSONAJEQUIETO_H
