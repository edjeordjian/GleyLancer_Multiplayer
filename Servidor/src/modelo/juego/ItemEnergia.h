#ifndef SERVIDOR_ITEMENERGIA_H
#define SERVIDOR_ITEMENERGIA_H

#include "Item.h"

class ItemEnergia: public Item {
private:
    int tipo;
public:
    ItemEnergia(Posicion pos_inicial);
    ~ItemEnergia();
    int getTipo() override;
    void darEfecto(Personaje* personaje) override;

};


#endif //SERVIDOR_ITEMENERGIA_H
