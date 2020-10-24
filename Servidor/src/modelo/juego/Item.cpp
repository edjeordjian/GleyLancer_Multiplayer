#include "Item.h"

//Constructor sobrecargado
Item::Item(Posicion pos_inicial) {
    this->pos = pos_inicial;
    this->pos_ventana = pos_inicial;
    this->esta_en_ventana = false;
    this->ancho = ANCHO_ITEM_1;
    this->alto = ALTO_ITEM_1;

}

Item::Item(): pos(0,0),
            ancho(ANCHO_ITEM_2),
            alto(ANCHO_ITEM_2) {
}

Item::~Item(){
    //do nothing
}

int Item::getAncho() {
    return this->ancho;
}

int Item::getAlto() {
    return this->alto;
}

double Item::getPosX() {
    return this->pos.getX();
}

double Item::getPosY() {
    return this->pos.getY();
}

Posicion Item::getPosicionVentana() {
    return this->pos_ventana;
}

void Item::setPosicionVentana(Posicion pos_nueva) {
    this->pos_ventana = pos_nueva;
}

bool Item::getEstaEnVentana() {
    return this->esta_en_ventana;
}

void Item::setEstaEnVentana(bool en_ventana) {
    this->esta_en_ventana = en_ventana;
}
