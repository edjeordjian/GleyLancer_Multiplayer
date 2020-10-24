#include "Jefe2.h"

Jefe2::Jefe2(double pos_x,double pos_y, int potencia) :
       JefeBase(pos_x, pos_y){
    this->tipo = TIPO_JEFE_2;   
    this->alto=ANCHO_JEFE_2;
    this->ancho=ALTO_JEFE_2;
    this->velocidad = VELOCIDAD_JEFE_2;
    this->armamento = new ArmamentoJefe2(potencia);
    this->contador_aux_armamento = TIEMPO_QUIETO_JEFE_2;
}

void Jefe2::setEstado(IEstadoEnemigo* estado_nuevo) {
    this->Enemigo::setEstado(estado_nuevo);
    if (this->estado->estaQuieto()) {
        this->contador_aux_armamento = TIEMPO_QUIETO_JEFE_2;
    }

}

void Jefe2::actualizar(Posicion pos_ventana_personaje){
    this->Enemigo::actualizar(pos_ventana_personaje);
    if (this->contador_aux_armamento > 0) {
        this->contador_aux_armamento--;
    }
}

void Jefe2::setDisparar(){
    if ( !this->estado->estaQuieto() and this->contador_aux_armamento <= TIEMPO_QUIETO_JEFE_2 - (3 * TIEMPO_COOLDOWN_DISPAROS_JEFE_2) and
          this->contador_aux_armamento >= TIEMPO_QUIETO_JEFE_2 - (6 * TIEMPO_COOLDOWN_DISPAROS_JEFE_2)) {
        this->armamento->setEstaDisparando(true);
    } else {
        this->armamento->setEstaDisparando(false);
    }
}

bool Jefe2::esJefe() {
    return true;
}
