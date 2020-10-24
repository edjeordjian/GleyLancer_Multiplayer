#include "EnemigoQuieto.h"

EnemigoQuieto::EnemigoQuieto(Enemigo* ene): enemigo(ene) {
}

EnemigoQuieto::~EnemigoQuieto() = default;

bool EnemigoQuieto::estaQuieto(){
    return true;
}

void EnemigoQuieto::actualizar(){
    this->activar();
}

void EnemigoQuieto::activar() {
    std::string tipo = this->enemigo->getTipo();
    if (tipo == TIPO_JEFE_1) {
        this->enemigo->setEstado(new Jefe1Moviendose(this->enemigo));

    } else if (tipo == TIPO_JEFE_2) {
        this->enemigo->setEstado(new Jefe2Moviendose(this->enemigo));

    } else if (tipo == TIPO_JEFE_3) {
        this->enemigo->setEstado(new Jefe3Moviendose(this->enemigo));

    } else if (tipo == getTipoEnemigo1()){
        this->enemigo->setEstado(new EnemigoTipo1Moviendose(this->enemigo));
    } else {
        // Enemigo tipo 2
        this->enemigo->setEstado(new EnemigoTipo2Moviendose(this->enemigo));
    }

}


Posicion EnemigoQuieto::getDireccion(){
    Posicion direccion(0,0);
    return direccion;
}
