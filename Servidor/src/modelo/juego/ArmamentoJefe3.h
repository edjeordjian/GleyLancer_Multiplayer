#ifndef SERVIDOR_ARMAMENTOJEFE3_H
#define SERVIDOR_ARMAMENTOJEFE3_H

#include "Armamento.h"

class ArmamentoJefe3: public Armamento  {
private:
    int contador_disparos;
public:
    ArmamentoJefe3(int potencia_proyectiles);
    ~ArmamentoJefe3();
    void actualizar(Posicion pos, Posicion direccion) override;
    Proyectil *usar(Posicion pos_inic, Posicion direccion) override;
    void setEstaDisparando(bool disparando) override;
    void disparoSimpleCentral(Posicion pos_inic);
    void disparoDobleCentral(Posicion pos_inic);
    void disparoTriple(Posicion pos_inic);
    void disparoCuadruple(Posicion pos_inic);
    void disparoDobleHoming(Posicion pos_inic, Posicion direccion);
};


#endif //SERVIDOR_ARMAMENTOJEFE3_H
