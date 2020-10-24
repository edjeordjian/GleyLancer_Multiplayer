#ifndef SERVIDOR_PERSONAJEMOVIENDOSE_H
#define SERVIDOR_PERSONAJEMOVIENDOSE_H

#include "IEstadoPersonaje.h"
#include "../Personaje.h"
#include "PersonajeQuieto.h"

class Personaje;

class PersonajeMoviendose: public IEstadoPersonaje {

private:
    Personaje* personaje;
    Posicion direccion;

public:
    PersonajeMoviendose(Personaje* per, Posicion direccion_nueva);
    ~PersonajeMoviendose() override ;
    void actualizar() override;
    void actualizarPosicion(Posicion direccion_nueva) override;
    void actualizarColision(Posicion pos_colision) override;
    bool estaQuieto() override;
    Posicion getDireccion() override ;

};


#endif //SERVIDOR_PERSONAJEMOVIENDOSE_H
