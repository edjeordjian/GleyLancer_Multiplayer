#include "ItemEnergia.h"

ItemEnergia::ItemEnergia(Posicion pos_inicial): Item(pos_inicial){
    this->tipo = TIPO_ITEM_ENERGIA;
}

ItemEnergia::~ItemEnergia(){

}

int ItemEnergia::getTipo(){
    return this->tipo;
}

void ItemEnergia::darEfecto(Personaje* personaje){
    personaje->agregarEnergia(ENERGIA_ITEM);
}

