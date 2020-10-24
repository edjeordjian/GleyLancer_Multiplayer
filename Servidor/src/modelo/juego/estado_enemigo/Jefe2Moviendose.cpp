#include "Jefe2Moviendose.h"

#include "Jefe1Moviendose.h"

Jefe2Moviendose::Jefe2Moviendose(Enemigo *enemigo_nuevo):
        jefe(enemigo_nuevo),
        direccion(POS_NINGUNA),
        contador(0),
        velocidad(enemigo_nuevo->getVelocidad()),
        correccion(0){

}

Jefe2Moviendose::~Jefe2Moviendose(){

}

bool Jefe2Moviendose::estaQuieto() {
    return false;
}

void Jefe2Moviendose::activar() {

}


void Jefe2Moviendose::actualizar() {

    double distancia;

    if ( this->contador == TIEMPO_QUIETO_JEFE_2){
        this->direccion = this->obtenerProximaDireccion(this->jefe->getPosicionVentana());
        this->pos_final=this->jefe->getPosPersonajeCercano();
    }
    else if ( ( this->contador > TIEMPO_QUIETO_JEFE_2 ) && ( this->contador < 3 * TIEMPO_QUIETO_JEFE_2 ) ){
        this->jefe->mover(this->direccion * this->velocidad);
        distancia = this->pos_final.distancia(this->jefe->getPosicionVentana());
        if ( distancia < DISTANCIA_MIN_A_PERSONAJE ){
            this->jefe->setEstado(new EnemigoQuieto(this->jefe));
        }
    }

    this->contador += INCREMENTO_CONTADOR;
}


Posicion Jefe2Moviendose::obtenerProximaDireccion(Posicion pos) {
    return pos.direccion( this->jefe->getPosPersonajeCercano() );
}


