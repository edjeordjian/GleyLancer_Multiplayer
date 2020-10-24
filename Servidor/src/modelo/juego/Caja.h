#ifndef SERVIDOR_CAJA_H
#define SERVIDOR_CAJA_H

#include "../../tools/constantes/ConstantesModelo.h"
#include "IChocable.h"
#include "Item.h"
#include "ItemVida.h"
#include "ItemEnergia.h"
#include "ItemPuntos.h"
#include "ItemEscudo.h"

class Caja: public IChocable {
private:
    Posicion pos;
    Posicion pos_ventana;
    bool esta_en_ventana;
    int ancho;
    int alto;
    Item* item;

public:
    Caja(Posicion pos_inicial, int nro_nivel);
    ~Caja();
    int getAncho() override;
    int getAlto() override;
    double getPosX() override;
    double getPosY() override;
    Posicion getPosicionVentana() override;
    void setPosicionVentana(Posicion pos_nueva) override;
    bool getEstaEnVentana() override;
    void setEstaEnVentana(bool en_ventana) override;
    //Cuando le disparan a la caja esta se rompe y devuelve el item
    Item* destruir();

};


#endif //SERVIDOR_CAJA_H
