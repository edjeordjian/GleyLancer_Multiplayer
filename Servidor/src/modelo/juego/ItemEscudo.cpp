#include "ItemEscudo.h"

ItemEscudo::ItemEscudo(Posicion pos_inicial): Item(pos_inicial){
    this->tipo = TIPO_ITEM_ESCUDO;
}

ItemEscudo::~ItemEscudo(){

}

int ItemEscudo::getTipo(){
    return this->tipo;
}

void ItemEscudo::darEfecto(Personaje* personaje){
    personaje->agregarEscudo();
}
