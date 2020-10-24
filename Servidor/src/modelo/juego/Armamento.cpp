#include "Armamento.h"

Armamento::Armamento(int numero_personaje, int potencia_proyectiles) {
    this->estaDisparando = false;
    this->cooldown = 0;
    this->cooldown_inicial = FRECUENCIA_DE_DISPARO;
    this->nro_personaje = numero_personaje;
    this->potencia = potencia_proyectiles;
}

void Armamento::setEstaDisparando(bool disparando) {
    this->estaDisparando = disparando;
}
void Armamento::setProyectiles(std::vector<Proyectil*>* lista_proyectiles) {
    this->proyectiles = lista_proyectiles;
}

bool Armamento::getEstaDisparando() {
    return this->estaDisparando;
}

void Armamento::actualizar(Posicion pos, Posicion direccion) {
    Proyectil *proyectil = this->usar(pos, direccion);
    if (proyectil) {
        proyectil->setNumeroPersonaje(this->getNumeroPersonaje());
        this->proyectiles->push_back(proyectil);
    }
}

Proyectil *Armamento::usar(Posicion pos_inic, Posicion direccion) {
    int alcance_proyectil = ANCHO_VENTANA + ANCHO_VENTANA / 2; //1000
    int velocidad = getTamAnchoProyectil() / 4;

    if (this->cooldown == 0 and this->estaDisparando ) {
        this->cooldown = this->cooldown_inicial;
        return new Proyectil(alcance_proyectil, pos_inic + Posicion(0, 10), direccion * velocidad, this->potencia);
    }
    else if (this->cooldown > 0 ) this->cooldown -= 1;
    return nullptr;
}

std::vector<Proyectil *> *Armamento::getProyectiles() {
    return this->proyectiles;
}

int Armamento::getNumeroPersonaje() {
    return this->nro_personaje;
}



