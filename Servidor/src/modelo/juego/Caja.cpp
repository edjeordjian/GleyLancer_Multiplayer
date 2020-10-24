#include "Caja.h"

Caja::Caja(Posicion pos_inicial, int nro_nivel) {
    this->pos = pos_inicial;
    this->ancho = ANCHO_CAJA;
    this->alto = ALTO_CAJA;
    int rand_item = rand() % RANGO_NRO_RANDOM_CAJAS;
    if (rand_item < RANGO_NRO_RANDOM_CAJAS_PUNTOS) {
        this->item = new ItemPuntos(this->pos + Posicion(INCREMENTO_X_Y_CAJA, INCREMENTO_X_Y_CAJA), nro_nivel);
    } else if (rand_item < RANGO_NRO_RANDOM_CAJAS_ITEM) {
        this->item = new ItemEnergia(this->pos + Posicion(INCREMENTO_X_Y_CAJA, INCREMENTO_X_Y_CAJA));
    } else if (rand_item < RANGO_NRO_RANDOM_CAJAS_ENERGIA) {
        this->item = new ItemEscudo(this->pos + Posicion(INCREMENTO_X_Y_CAJA, INCREMENTO_X_Y_CAJA));
    } else {
        this->item = new ItemVida(this->pos + Posicion(INCREMENTO_X_Y_CAJA, INCREMENTO_X_Y_CAJA));
    }

}

Caja::~Caja() {
    if (this->item) {
        delete(this->item);
    }
}

int Caja::getAncho() {
    return this->ancho;
}

int Caja::getAlto() {
    return this->alto;
}

double Caja::getPosX() {
    return this->pos.getX();
}

double Caja::getPosY() {
    return this->pos.getY();
}

Posicion Caja::getPosicionVentana() {
    return this->pos_ventana;
}

void Caja::setPosicionVentana(Posicion pos_nueva) {
    this->pos_ventana = pos_nueva;
}

bool Caja::getEstaEnVentana() {
    return this->esta_en_ventana;
}

void Caja::setEstaEnVentana(bool en_ventana) {
    this->esta_en_ventana = en_ventana;
}

//Cuando le disparan a la caja esta se rompe y devuelve el item
Item* Caja::destruir() {
    Item* res = nullptr;
    if (this->item) {
        res = this->item;
        this->item = nullptr;
    }
    return res;
}
