#ifndef SERVIDOR_ITEM_H
#define SERVIDOR_ITEM_H

#include "../../tools/constantes/ConstantesModelo.h"
#include "IChocable.h"
#include "Posicion.h"
#include "Personaje.h"

class Personaje;

class Item: public IChocable {
private:
    Posicion pos;
    Posicion pos_ventana;
    bool esta_en_ventana;
    int ancho;
    int alto;

public:
    //Constructor sobrecargado
    Item(Posicion pos_inicial);
    Item();
    ~Item();
    int getAncho() override;
    int getAlto() override;
    double getPosX() override;
    double getPosY() override;
    Posicion getPosicionVentana() override;
    void setPosicionVentana(Posicion pos_nueva) override;
    bool getEstaEnVentana() override;
    void setEstaEnVentana(bool en_ventana) override;
    virtual int getTipo() = 0;
    virtual void darEfecto(Personaje* personaje) = 0;

};


#endif //SERVIDOR_ITEM_H
