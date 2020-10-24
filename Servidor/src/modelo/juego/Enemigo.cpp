#include "Enemigo.h"

Enemigo::Enemigo(double pos_x, double pos_y, std::string tipo, int alto, int ancho)
        : posicion(pos_x, pos_y),
          estado(new EnemigoQuieto(this)),
          tipo(tipo),
          esta_en_ventana{false},
          alto(alto),
          ancho(ancho),
          daniado(false),
          contador_daniado(0){
    int potencia = (tipo == getTipoEnemigo1() ? POTENCIA_PROY_ENEM_1 : POTENCIA_PROY_ENEM_2);
    this->armamento = new ArmamentoEnemigo(potencia, tipo);
    this->energia = (tipo == getTipoEnemigo1() ? ENERGIA_ENEM_1 : ENERGIA_ENEM_2);
    this->puntos_al_morir = (tipo == getTipoEnemigo1() ? PUNTAJE_MATAR_ENEMIGO_1 : PUNTAJE_MATAR_ENEMIGO_2);
    this->velocidad = (tipo == getTipoEnemigo1() ? VELOCIDAD_ENEMIGO_1 : VELOCIDAD_ENEMIGO_2);
    this->actualizarDireccionInicial();
}

Enemigo::~Enemigo(){
    delete(this->estado);
    if (this->armamento) {
        delete (this->armamento);
    }
}

void Enemigo::actualizarDireccionInicial(){

    if (this->posicion.getX() < ANCHO_FONDO / 2) {
        this->direccion_contraria = true;
        this->direccion_mirando = POS_DERECHA;
    } else {
        this->direccion_contraria = false;
        this->direccion_mirando = POS_IZQUIERDA;
    }
}

void Enemigo::setPosX(double pos_x){
    this->posicion.setX(pos_x);
}

double Enemigo::getPosX(){
    return this->posicion.getX();
}

void Enemigo::setPosY(double pos_y){
    this->posicion.setY(pos_y);
}

double Enemigo::getPosY(){
    return this->posicion.getY();
}

void Enemigo::setEstado(IEstadoEnemigo* estado_nuevo){
    delete(this->estado);
    this->estado = estado_nuevo;
}

std::string Enemigo::getTipo() {
    return this->tipo;
}

int Enemigo::getAlto() {
    return this->alto;
}
int Enemigo::getAncho() {
    return this->ancho;
}

Posicion Enemigo::getPosicionVentana() {
    return pos_ventana;
}

void Enemigo::setPosicionVentana(Posicion pos) {

    this->pos_ventana = pos;
}

bool Enemigo::getEstaEnVentana() {
    return this->esta_en_ventana;
}

void Enemigo::setEstaEnVentana(bool en_ventana){
    this->esta_en_ventana = en_ventana;
}


bool Enemigo::direccionContraria(){
    return this->direccion_contraria;
}

/*
El comportamiento del enemigo es el siguiente:
+) Si el enemigo esta disparando entonces se setea en dejar de dispara,
        esto es para que solo dispare de a un proyectil por vez.
+) si no esta disparando entonces se usara un numero aleatorio para saber si el
enemigo va a disparar o no.
*/
void Enemigo::setDisparar() {

    if ( this->tipo == getTipoEnemigo1() && !this->estado->estaQuieto() ){
        this->armamento->setEstaDisparando(false);
        return;
    }

    this->armamento->setEstaDisparando(true);
}

void Enemigo::setDireccionContraria(bool dir_derecha) {
    this->direccion_contraria=dir_derecha;

    if ( this->direccion_contraria ) this->direccion_mirando = POS_DERECHA;
    else this->direccion_mirando = POS_IZQUIERDA;
}

bool Enemigo::estaVivo() {
    return this->energia > 0;
}

bool Enemigo::estaDaniado(){
    return this->daniado;
}

void Enemigo::mover(Posicion direccion){
    this->posicion += direccion;
}

void Enemigo::actualizarDireccionContraria() {
    if (this->direccion_contraria){
        double nueva_pos_x = this->getPosX() + DESPLAZAMIENTO_FONDO * 2;
        if(nueva_pos_x  < (ANCHO_FONDO - ANCHO_VENTANA - 100)) {
            this->posicion.setX(nueva_pos_x);
        }
        if (this->pos_ventana.getX() > ( ANCHO_VENTANA * 6 ) / 7){
            this->direccion_contraria = false;
            this->direccion_mirando = POS_IZQUIERDA;
        }
    }
}

void Enemigo::actualizar(Posicion pos_personaje){
    Posicion direccion_disparo = this->direccion_mirando;

    if (this->tipo == getTipoEnemigo2()) {
        direccion_disparo = this->posicion.direccion(pos_personaje);
    }
    this->estado->actualizar();
    this->armamento->actualizar(this->posicion, direccion_disparo);
    if ( this->contador_daniado > 0 ){
        this->daniado = true;
        this->contador_daniado--;
    }
    else{
        this->daniado = false;
    }
}

void Enemigo::setProyectiles(std::vector<Proyectil *>* proyectiles) {
    this->armamento->setProyectiles(proyectiles);
}

void Enemigo::impactar(Proyectil* proy){
    this->energia -= proy->getPotencia();
    if (this->energia < 0) {
        this->energia = 0;
    }
    this->contador_daniado = 1;
}

void Enemigo::matar(){
    this->energia = 0;
}

int Enemigo::getPuntos(){
    return this->puntos_al_morir;
}

int Enemigo::getVelocidad() {
    return this->velocidad;
}

void Enemigo::setPosPersonajeCercano(Posicion pos_ventana_per) {
    //Pos ventana
    this->pos_personaje_cercano = pos_ventana_per;
}

Posicion Enemigo::getPosPersonajeCercano(){
    return this->pos_personaje_cercano;
}

bool Enemigo::esJefe() {
    return false;
}
