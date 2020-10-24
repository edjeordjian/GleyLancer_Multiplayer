#include "Jefe3Moviendose.h"

Jefe3Moviendose::Jefe3Moviendose(Enemigo *enemigo_nuevo):
        jefe(enemigo_nuevo),
        direccion(POS_ABAJO),
        velocidad(enemigo_nuevo->getVelocidad()){

}

Jefe3Moviendose::~Jefe3Moviendose(){

}

bool Jefe3Moviendose::estaQuieto() {
    return false;
}

void Jefe3Moviendose::activar() {

}


void Jefe3Moviendose::actualizar() {
    Posicion pos = this->jefe->getPosicionVentana();
    // Correccion para que la direccion a asignar dependa del centro de masa del enemigo y no de la posicion de su esquina superior izquierda
    pos += Posicion(0, this->jefe->getAlto() / 2);
    if (pos.getY() < ALTO_VENTANA / 3) {
        this->direccion = POS_ABAJO;
    } else if (pos.getY() > (ALTO_VENTANA / 2)){
        this->direccion = POS_ARRIBA;
    }

    this->jefe->mover(this->direccion * this->velocidad);
}

