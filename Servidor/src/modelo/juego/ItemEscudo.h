#ifndef SERVIDOR_ITEMESCUDO_H
#define SERVIDOR_ITEMESCUDO_H

#include "Item.h"

class ItemEscudo: public Item  {
private:
    int tipo;
public:
    ItemEscudo(Posicion pos_inicial);
    ~ItemEscudo();
    int getTipo() override;
    void darEfecto(Personaje* personaje) override;

};


#endif //SERVIDOR_ITEMESCUDO_H
