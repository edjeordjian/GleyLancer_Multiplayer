#include "PersonajeMoviendose.h"

PersonajeMoviendose::PersonajeMoviendose(Personaje* per, Posicion direccion_nueva):
                                                                        personaje(per),  direccion(direccion_nueva){

}

PersonajeMoviendose::~PersonajeMoviendose() = default;

void PersonajeMoviendose::actualizar() {
    this->personaje->mover(this->direccion);
}

void PersonajeMoviendose::actualizarPosicion(Posicion direccion_nueva){
    if (direccion_nueva == POS_NINGUNA) {
        this->personaje->setEstado(new PersonajeQuieto(personaje));

    } else if (direccion_nueva != this->direccion) {
        this->direccion.setX(direccion_nueva.getX());
        this->direccion.setY(direccion_nueva.getY());
    }
}

bool PersonajeMoviendose::estaQuieto(){
    return false;
}

Posicion PersonajeMoviendose::getDireccion() {
    return this->direccion;
}

void PersonajeMoviendose::actualizarColision(Posicion pos_colision){

    if(this->direccion.getX() * pos_colision.getX() > 0){
        this->direccion.setX(FRENAR_DIRECCION);
    }
    if(this->direccion.getY() * pos_colision.getY() > 0){
        this->direccion.setY(FRENAR_DIRECCION);
    }
    if (this->direccion == POS_NINGUNA){
        this->personaje->setEstado(new PersonajeQuieto(this->personaje));
    }

}
