#include "ItemVida.h"

ItemVida::ItemVida(Posicion pos_inicial): Item(pos_inicial){
    this->tipo = TIPO_ITEM_VIDA;
}

ItemVida::~ItemVida(){

}

int ItemVida::getTipo(){
    return this->tipo;
}

void ItemVida::darEfecto(Personaje* personaje){
    personaje->sumarVida();
}
