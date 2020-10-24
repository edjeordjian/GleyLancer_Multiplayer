#ifndef SERVIDOR_ARMAMENTOENEMIGO_H
#define SERVIDOR_ARMAMENTOENEMIGO_H

#include "Armamento.h"

class ArmamentoEnemigo: public Armamento {
public:
    ArmamentoEnemigo(int potencia_proyectiles, std::string tipo);
    ~ArmamentoEnemigo();
    void actualizar(Posicion pos, Posicion direccion) override;
    //Direccion unitaria, es decir de la forma (1,0) o (0,1) por ejemplo
    Proyectil *usar(Posicion pos_inic, Posicion direccion) override;
};


#endif //SERVIDOR_ARMAMENTOENEMIGO_H
