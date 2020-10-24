#include "ArmamentoEnemigo.h"

ArmamentoEnemigo::ArmamentoEnemigo(int potencia_proyectiles, std::string tipo): Armamento(-1, potencia_proyectiles) {
    this->estaDisparando = false;

    this->cooldown_inicial = (tipo == getTipoEnemigo1() ? COOLDOWN_INICIAL_E1 : COOLDOWN_INICIAL_E2);
    this->cooldown = this->cooldown_inicial;

    // Esto es para indicar que el proyectil pertenece a un enemigo y no a un jugador
    this->nro_personaje = (tipo == getTipoEnemigo1() ? NRO_ENEMIGO_CLASE_1 : NRO_ENEMIGO_CLASE_2);
    this->potencia = potencia_proyectiles;
}

ArmamentoEnemigo::~ArmamentoEnemigo() {

}

void ArmamentoEnemigo::actualizar(Posicion pos, Posicion direccion) {
    Proyectil *proyectil = this->usar(pos, direccion);
    if (proyectil) {
        proyectil->setNumeroPersonaje(this->getNumeroPersonaje());
        this->proyectiles->push_back(proyectil);
    }
}

Proyectil *ArmamentoEnemigo::usar(Posicion pos_inic, Posicion direccion) {

    int velocidad = ANCHO_ALTO_PROYECTIL_ENEMIGO;
    if (this->cooldown == 0 and this->estaDisparando ) {
        this->cooldown = this->cooldown_inicial;
        return new Proyectil(pos_inic, direccion * (velocidad/4), this->potencia);
    }
    if (this->estaDisparando) {
        this->cooldown--;
    }
    return nullptr;
}
