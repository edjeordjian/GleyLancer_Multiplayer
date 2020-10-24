#include "Jefe1.h"

Jefe1::Jefe1(double pos_x,double pos_y, int potencia) :
       JefeBase(pos_x, pos_y){
    this->tipo = TIPO_JEFE_1;
    this->alto=ANCHO_JEFE_1;
    this->ancho=ALTO_JEFE_1;
    this->velocidad = VELOCIDAD_JEFE_1;
    this->armamento = new ArmamentoJefe1(potencia);


}

bool Jefe1::esJefe() {
    return true;
}
