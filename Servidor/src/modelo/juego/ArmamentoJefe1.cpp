#include "ArmamentoJefe1.h"

ArmamentoJefe1::ArmamentoJefe1(int potencia_proyectiles): Armamento(-1, potencia_proyectiles){
    this->estaDisparando = false;

    this->cooldown_inicial = TIEMPO_COOLDOWN_DISPAROS_JEFE_1;
    this->cooldown = this->cooldown_inicial;

    // Esto es para indicar que el proyectil pertenece a un enemigo y no a un jugador
    this->nro_personaje = NRO_ENEMIGO_JEFE;
    this->potencia = potencia_proyectiles;
}

Proyectil* ArmamentoJefe1::usar(Posicion pos_inic, Posicion direccion){
    int velocidad = getTamAnchoProyectil() / 4;
    if (this->cooldown == 0 and this->estaDisparando ) {
        this->cooldown += TIEMPO_COOLDOWN_DISPAROS_JEFE_1;

        if (this->cooldown_inicial > COOLDOWN_MAXIMO_J1) {
            this->cooldown_inicial = TIEMPO_COOLDOWN_DISPAROS_JEFE_1;
        }

        return new Proyectil(pos_inic, direccion * (velocidad / 3), this->potencia);
    }
    if (this->estaDisparando ) {
        this->cooldown--;
    }
    return nullptr;

}

void ArmamentoJefe1::actualizar(Posicion pos_inic, Posicion direccion){
    Proyectil *proyectil = this->usar(pos_inic, direccion);
    if (proyectil) {
        proyectil->setNumeroPersonaje(this->getNumeroPersonaje());
        this->proyectiles->push_back(proyectil);
    }
    proyectil = this->usar(pos_inic + Posicion(0, ALTO_JEFE_1 / 2), direccion);
    if (proyectil) {
        proyectil->setNumeroPersonaje(this->getNumeroPersonaje());
        this->proyectiles->push_back(proyectil);
    }
    proyectil = this->usar(pos_inic + Posicion(0, 5*ALTO_JEFE_1 / 6), direccion);
    if (proyectil) {
        proyectil->setNumeroPersonaje(this->getNumeroPersonaje());
        this->proyectiles->push_back(proyectil);
    }
}

ArmamentoJefe1::~ArmamentoJefe1(){

}
