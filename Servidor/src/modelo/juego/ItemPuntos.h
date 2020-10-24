#ifndef SERVIDOR_ITEMPUNTOS_H
#define SERVIDOR_ITEMPUNTOS_H

#include "Item.h"

class ItemPuntos: public Item {
private:
    int tipo;
    int nivel;
public:
    ItemPuntos(Posicion pos_inicial, int nro_nivel);
    ~ItemPuntos();
    int getTipo() override;
    void darEfecto(Personaje* personaje) override;

};

#endif //SERVIDOR_ITEMPUNTOS_H
