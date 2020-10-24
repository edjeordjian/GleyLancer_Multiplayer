#include "Proyectil.h"

Proyectil::Proyectil(int alcance_proyectil, Posicion pos_inic, Posicion direccion_proyectil, int pot_nueva)
                  : alcance(alcance_proyectil),
                    pos_inicial(pos_inic),
                    pos(pos_inic),
                    direccion(direccion_proyectil),
                    destruido(false),
                    ancho(getTamAnchoProyectil()),
                    alto(getTamAltoProyectil()),
                    potencia(pot_nueva),
                    actualizaciones(0),
                    es_nuevo(true) {

}

Proyectil::Proyectil(Posicion pos_inic, Posicion direccion_proyectil, int pot_nueva)
        : alcance(ANCHO_VENTANA +  ANCHO_VENTANA / 2),
          pos_inicial(pos_inic),
          pos(pos_inic),
          direccion(direccion_proyectil),
          destruido(false),
          ancho(ANCHO_ALTO_PROYECTIL_ENEMIGO),
          alto(ANCHO_ALTO_PROYECTIL_ENEMIGO),
          potencia(pot_nueva),
          actualizaciones(0),
          es_nuevo(true){

}

Proyectil::~Proyectil(){

}

void Proyectil::actualizar(){
    if (!destruido) {
        this->actualizaciones += 1;
        // Para ver si el proyectil es nuevo o no
        if(this->actualizaciones > 1){
            this->es_nuevo = false;
        }
        this->pos += this->direccion;
        if (this->alcance < this->pos_inicial.distancia(this->pos) or !this->esta_en_ventana){
            this->destruir();
        }
    }
}

void Proyectil::mover(Posicion dir) {
    this->pos += dir;
}

int Proyectil::getAlto() {
    return this->alto;
}

int Proyectil::getAncho() {
    return this->ancho;
}

double Proyectil::getPosX() {
    return this->pos.getX();
}

double Proyectil::getPosY() {
    return this->pos.getY();
}

void Proyectil::destruir(){
    this->destruido = true;
}

bool Proyectil::estaDestruido() {
    return this->destruido;
}

bool Proyectil::esNuevo(){
    return this->es_nuevo;
}

Posicion Proyectil::getPosicionVentana() {
    return pos_ventana;
}

void Proyectil::setPosicionVentana(Posicion pos_nueva) {

    this->pos_ventana = pos_nueva;
}

bool Proyectil::getEstaEnVentana() {
    return this->esta_en_ventana;
}

void Proyectil::setEstaEnVentana(bool en_ventana){
    this->esta_en_ventana = en_ventana;
}

int Proyectil::getNumeroPersonaje() {
    return this->nro_personaje;
}

void Proyectil::setNumeroPersonaje(int numero_personaje){
    this->nro_personaje = numero_personaje;
}

int Proyectil::getDireccion(){
    if (doblesIguales(this->direccion.getX(), 0) and this->direccion.getY() < 0) {
        return DIRECCION_PERSONAJE_ARRIBA;

    } else if ((this->direccion.getX() > 0 and this->direccion.getY() < 0)) {
        return DIRECCION_PERSONAJE_ARRIBA;

    } else if ((this->direccion.getX() > 0 and doblesIguales(this->direccion.getY(), 0))) {
        return DIRECCION_PERSONAJE_IZQUIERDA_DERECHA;

    } else if ((this->direccion.getX() > 0 and this->direccion.getY() > 0.0)) {
        return DIRECCION_PERSONAJE_ABAJO;

    } else if ((doblesIguales(this->direccion.getX(), 0) and this->direccion.getY() > 0.0)) {
        return DIRECCION_PERSONAJE_ABAJO;

    } else if (this->direccion.getX() < 0 and this->direccion.getY() > 0.0) {
        return DIRECCION_PERSONAJE_ABAJO;

    } else if ((this->direccion.getX() < 0 and doblesIguales(this->direccion.getY(), 0))) {
        return DIRECCION_PERSONAJE_IZQUIERDA_DERECHA;

    } //else  if (this->direccion.getX() < 0 and this->direccion.getY() < 0.0)
    return DIRECCION_PERSONAJE_ARRIBA;
}

int Proyectil::getPotencia() {
    return this->potencia;
}
