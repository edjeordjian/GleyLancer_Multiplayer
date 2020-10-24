#include "EnemigoTipo2Moviendose.h"

EnemigoTipo2Moviendose::EnemigoTipo2Moviendose(Enemigo *enemigo_nuevo):
        enemigo(enemigo_nuevo),
        direccion(POS_ARRIBA),
        velocidad(enemigo_nuevo->getVelocidad()),
        llego_area_jefe(false){

}

EnemigoTipo2Moviendose::~EnemigoTipo2Moviendose(){

}

bool EnemigoTipo2Moviendose::estaQuieto() {
    return false;
}

void EnemigoTipo2Moviendose::activar() {
    //Activar no hace nada porque cuando el enemigo se esta moviendo ya esta activo
}

void EnemigoTipo2Moviendose::actualizar() {

    if (this->llego_area_jefe){
        this->enemigo->mover( this->direccion * this->velocidad);
        return;
    }

    if (this->enemigo->getPosicionVentana().getX() < LIMITE_POS_X_VENTANA_ENEMIGO_2) {
        this->enemigo->setDireccionContraria(true);
    }

    if (this->enemigo->getPosY() < ALTO_TIPO_ENEMIGO_2 / 2 && this->direccion.getY() < 0) {
        this->direccion.setY(INVERSION_DIR_EJE_Y_ENEMIGO_2 * this->direccion.getY());

    } else if (this->enemigo->getPosY() > ALTO_VENTANA - ALTO_TIPO_ENEMIGO_2 && this->direccion.getY() > 0) {
        this->direccion.setY(INVERSION_DIR_EJE_Y_ENEMIGO_2 * this->direccion.getY());

    }

    double desplazamiento_y_aux = (ALTO_VENTANA / 2) - abs(this->enemigo->getPosY() - ALTO_VENTANA / 2);
    desplazamiento_y_aux /= (ALTO_VENTANA / 2) - LIMITE_POS_X_VENTANA_ENEMIGO_2;
    desplazamiento_y_aux *= INCREMENTO_DEZPLAZAMIENTO_EJE_Y_ENEMIGO_2;
    if (this->direccion.getY() < 0){
        desplazamiento_y_aux *= INVERSION_DIR_EJE_Y_ENEMIGO_2;
    }

    double desplazamiento_x_aux = Posicion(0, this->enemigo->getPosY()).distancia(Posicion(0, ALTO_VENTANA / 2));
    desplazamiento_x_aux /= ALTO_VENTANA/2;

    if (!this->enemigo->direccionContraria()) {
        desplazamiento_x_aux *= INVERSION_DIR_EJE_Y_ENEMIGO_2;
    }

    this->direccion.setX(desplazamiento_x_aux);
    this->direccion.setY(desplazamiento_y_aux);
    this->direccion = this->direccion.normalizar();

    if( this->enemigo->getPosX() + direccion.getX()  < (ANCHO_FONDO - (1.5*ANCHO_VENTANA))) {

        this->enemigo->mover(this->direccion * this->velocidad);

    } else {
        this->llego_area_jefe = true;
        if ( this->enemigo->direccionContraria() ){
            this->enemigo->actualizarDireccionInicial();
        }
        this->direccion = POS_IZQUIERDA;
        this->enemigo->mover( this->direccion * this->velocidad);
    }

}
