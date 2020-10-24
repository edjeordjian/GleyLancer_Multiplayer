#ifndef SERVIDOR_ARMAMENTOJEFE1_H
#define SERVIDOR_ARMAMENTOJEFE1_H

#include "Armamento.h"

class ArmamentoJefe1: public Armamento {
public:
    ArmamentoJefe1(int potencia_proyectiles);
    void actualizar(Posicion pos, Posicion direccion) override;
    //Direccion unitaria, es decir de la forma (1,0) o (0,1) por ejemplo
    Proyectil *usar(Posicion pos_inic, Posicion direccion) override;
    ~ArmamentoJefe1();
};

#endif //SERVIDOR_ARMAMENTOJEFE1_H
