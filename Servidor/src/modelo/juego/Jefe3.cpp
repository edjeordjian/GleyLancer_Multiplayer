#include "Jefe3.h"

Jefe3::Jefe3(double pos_x,double pos_y, int potencia) :
       JefeBase(pos_x, pos_y){
    this->tipo = TIPO_JEFE_3;   
    this->alto=ANCHO_JEFE_3;
    this->ancho=ALTO_JEFE_3;
    this->velocidad = VELOCIDAD_JEFE_3;
    this->armamento = new ArmamentoJefe3(potencia);
}

void Jefe3::impactar(Proyectil* proy){
    if (proy->getPosY() + proy->getAlto() > this->posicion.getY() + ( (5* this->alto)/8) and
            proy->getPosY() <  this->posicion.getY() + ( (3* this->alto)/4)) {

        this->energia -= proy->getPotencia();
        if (this->energia < 0) {
            this->energia = 0;
        }
        this->contador_daniado = 1;
    }
}

void Jefe3::actualizar(Posicion pos_personaje){
    this->estado->actualizar();
    this->armamento->actualizar(this->posicion, pos_personaje);
    if ( this->contador_daniado > 0 ){
        this->daniado = true;
        this->contador_daniado--;
    }
    else{
        this->daniado = false;
    }
}

bool Jefe3::esJefe() {
    return true;
}
