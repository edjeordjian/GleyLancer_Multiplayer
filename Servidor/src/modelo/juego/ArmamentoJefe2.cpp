#include "ArmamentoJefe2.h"

ArmamentoJefe2::ArmamentoJefe2(int potencia_proyectiles): Armamento(-1, potencia_proyectiles){
    this->estaDisparando = false;

    this->cooldown_inicial = TIEMPO_COOLDOWN_DISPAROS_JEFE_2;
    this->cooldown = this->cooldown_inicial;

    // Esto es para indicar que el proyectil pertenece a un enemigo y no a un jugador
    this->nro_personaje = NRO_ENEMIGO_JEFE;
    this->potencia = potencia_proyectiles;
    this->contador_disparos = 0;
}

Proyectil* ArmamentoJefe2::usar(Posicion pos_inic, Posicion direccion){
    int velocidad = getTamAnchoProyectil() / 3;
    Posicion pos_aux = direccion * (velocidad / 3);
    if (this->cooldown == MIN_VALOR_COOLDOWN_J2_Y_J3 and this->estaDisparando ) {
        return new Proyectil(pos_inic, pos_aux, this->potencia);
    }

    return nullptr;

}

void ArmamentoJefe2::actualizar(Posicion pos_inic, Posicion direccion){
    if (this->contador_disparos % TIPO_DISPARO_J2) {
        Proyectil *proyectil = this->usar(pos_inic + Posicion((ANCHO_JEFE_2 / 5), (ALTO_JEFE_2 / 5)), POS_ARRIBA_IZQ);
        if (proyectil) {
            proyectil->setNumeroPersonaje(this->getNumeroPersonaje());
            this->proyectiles->push_back(proyectil);
        }
        proyectil = this->usar(pos_inic + Posicion(((4*ANCHO_JEFE_2) / 5) , (ALTO_JEFE_2 / 5)), POS_ARRIBA_DER);
        if (proyectil) {
            proyectil->setNumeroPersonaje(this->getNumeroPersonaje());
            this->proyectiles->push_back(proyectil);
        }
        proyectil = this->usar(pos_inic + Posicion((ANCHO_JEFE_2 / 5), ((4*ALTO_JEFE_2) / 5)), POS_ABAJO_IZQ);
        if (proyectil) {
            proyectil->setNumeroPersonaje(this->getNumeroPersonaje());
            this->proyectiles->push_back(proyectil);
        }
        proyectil = this->usar(pos_inic + Posicion(((4*ANCHO_JEFE_2) / 5), ((4*ALTO_JEFE_2) / 5)), POS_ABAJO_DER);
        if (proyectil) {
            proyectil->setNumeroPersonaje(this->getNumeroPersonaje());
            this->proyectiles->push_back(proyectil);
        }
    } else {
        Proyectil *proyectil = this->usar(pos_inic + Posicion((ANCHO_JEFE_2 / 2) - (ANCHO_ALTO_PROYECTIL_ENEMIGO / 2), 0), POS_ARRIBA);
        if (proyectil) {
            proyectil->setNumeroPersonaje(this->getNumeroPersonaje());
            this->proyectiles->push_back(proyectil);
        }
        proyectil = this->usar(pos_inic + Posicion((ANCHO_JEFE_2), (ALTO_JEFE_2 / 2)), POS_DERECHA);
        if (proyectil) {
            proyectil->setNumeroPersonaje(this->getNumeroPersonaje());
            this->proyectiles->push_back(proyectil);
        }
        proyectil = this->usar(pos_inic + Posicion((ANCHO_JEFE_2 / 2) - (ANCHO_ALTO_PROYECTIL_ENEMIGO / 2), ALTO_JEFE_2), POS_ABAJO);
        if (proyectil) {
            proyectil->setNumeroPersonaje(this->getNumeroPersonaje());
            this->proyectiles->push_back(proyectil);
        }
        proyectil = this->usar(pos_inic + Posicion(0, (ALTO_JEFE_2 / 2)), POS_IZQUIERDA);
        if (proyectil) {
            proyectil->setNumeroPersonaje(this->getNumeroPersonaje());
            this->proyectiles->push_back(proyectil);
        }
    }

    if (this->contador_disparos < CONT_DISPAROS_UNO and this->cooldown == MIN_VALOR_COOLDOWN_J2_Y_J3) {
        this->cooldown = this->cooldown_inicial;
        this->contador_disparos++;
    } else if (this->contador_disparos == CONT_DISPAROS_UNO and this->cooldown == MIN_VALOR_COOLDOWN_J2_Y_J3) {
        this->cooldown = this->cooldown_inicial;
        this->contador_disparos = 0;
    } else if (this->cooldown > MIN_VALOR_COOLDOWN_J2_Y_J3) {
        this->cooldown--;
    }

    (void)direccion;
}

void ArmamentoJefe2::setEstaDisparando(bool disparando){
    this->estaDisparando = disparando;
    if (!disparando){
        this->cooldown = this->cooldown_inicial;
    }
}

ArmamentoJefe2::~ArmamentoJefe2(){

}
