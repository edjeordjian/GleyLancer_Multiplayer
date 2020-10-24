#ifndef SERVIDOR_ARMAMENTOJEFE2_H
#define SERVIDOR_ARMAMENTOJEFE2_H

#include "Armamento.h"

class ArmamentoJefe2: public Armamento {
private:
    int contador_disparos;
public:
    ArmamentoJefe2(int potencia_proyectiles);
    void actualizar(Posicion pos, Posicion direccion) override;
    //Direccion unitaria, es decir de la forma (1,0) o (0,1) por ejemplo
    Proyectil *usar(Posicion pos_inic, Posicion direccion) override;
    void setEstaDisparando(bool disparando) override;
    ~ArmamentoJefe2();
};


#endif //SERVIDOR_ARMAMENTOJEFE2_H
