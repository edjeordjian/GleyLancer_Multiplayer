#ifndef SERVIDOR_ITEMVIDA_H
#define SERVIDOR_ITEMVIDA_H

#include "Item.h"

class ItemVida: public Item {
private:
    int tipo;
public:
    ItemVida(Posicion pos_inicial);
    ~ItemVida();
    int getTipo() override;
    void darEfecto(Personaje* personaje) override;

};


#endif //SERVIDOR_ITEMVIDA_H
