#include "ItemPuntos.h"

ItemPuntos::ItemPuntos(Posicion pos_inicial, int nro_nivel): Item(pos_inicial){
    this->tipo = TIPO_ITEM_PUNTOS;
    this->nivel = nro_nivel;
}

ItemPuntos::~ItemPuntos(){

}

int ItemPuntos::getTipo(){
    return this->tipo;
}

void ItemPuntos::darEfecto(Personaje* personaje){
    personaje->agregarPuntaje(PUNTOS_ITEM, this->nivel);
}
