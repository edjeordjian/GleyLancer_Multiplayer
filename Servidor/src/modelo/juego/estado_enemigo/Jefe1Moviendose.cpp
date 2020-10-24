#include "Jefe1Moviendose.h"

Jefe1Moviendose::Jefe1Moviendose(Enemigo *enemigo_nuevo):
        jefe(enemigo_nuevo),
        direccion(POS_IZQUIERDA),
        velocidad(enemigo_nuevo->getVelocidad()){

}

Jefe1Moviendose::~Jefe1Moviendose(){

}

bool Jefe1Moviendose::estaQuieto() {
    return false;
}

void Jefe1Moviendose::activar() {

}


void Jefe1Moviendose::actualizar() {
    //Direcciones posibles de movimiento: izquierda y derecha segun algoritmo de enemigo
    //Despues se mueve hacia arriba o abajo segun la posicion Y del personje

    Posicion pos_enemigo = this->jefe->getPosicionVentana();
    // Correccion para que la direccion a asignar dependa del centro de masa del enemigo y no de la posicion de su esquina superior izquierda
    pos_enemigo += Posicion(this->jefe->getAncho() / 2, this->jefe->getAlto() / 4);

    this->actualizarDireccionHorizontal(pos_enemigo);
    this->actualizarDireccionVertical(pos_enemigo);

    this->direccion = this->direccion.normalizar();
    this->jefe->mover(this->direccion * this->velocidad);
}


void Jefe1Moviendose::actualizarDireccionHorizontal(Posicion pos_ventana_jefe){

    /// Si esta en tope derecho y se mueve a la derecha o esta en tope izquierdo (media ventana) y se mueve a la izquierda
    /// le invierto la direccion
    if ((pos_ventana_jefe.getX() > ANCHO_VENTANA - ANCHO_JEFE_1/2 - TOPE_HORIZONTAL_JEFE_1 and this->direccion.getX() > 0) or
        (pos_ventana_jefe.getX() < ANCHO_VENTANA/2 + TOPE_HORIZONTAL_JEFE_1 and this->direccion.getX() < 0)){
        this->direccion.setX(this->direccion.getX() * -1);
    }

}

void Jefe1Moviendose::actualizarDireccionVertical(Posicion pos_ventana_jefe){

    /// Si el personaje esta mas arriba que el jefe, el jefe sube (direccion vertical negativa)
    if (pos_ventana_jefe.getY() - this->jefe->getPosPersonajeCercano().getY() > VALOR_LIMITE_Y_ARRIBA) {
        this->direccion.setY(DIR_ATRAS_EJE_Y);
    }

    /// Si el personaje esta mas abajo que el jefe, el jefe baja (direccion vertical positiva)
    else if (this->jefe->getPosPersonajeCercano().getY() - pos_ventana_jefe.getY() > VALOR_LIMITE_Y_ABAJO){
        this->direccion.setY(DIR_ADELANTE_EN_EJE);
    }

    /// Si el personaje esta alineado con el jefe, el jefe se detiene verticalmente
    else {
        this->direccion.setY(DIR_FRENAR_EJE_Y);
    }

}