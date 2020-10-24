#include "Personaje.h"

Personaje::Personaje(double pos_x, double pos_y, int incremento, int n_personaje, int cant_vidas)
        : posicion(pos_x, pos_y),
        pos_ventana(pos_x,pos_y),
        incremento(incremento),
        direccion_mirando(1,0),
        estado(new PersonajeQuieto(this)),
        listo(false),
        conectado(true),
        nro_personaje(n_personaje),
        armamento(new Armamento(n_personaje,POTENCIA_PROY_PERSONAJE)),
        vidas(cant_vidas),
        ancho(getTamAnchoPersonaje()),
        alto(getTamAltoPersonaje()),
        puntaje(0),
        item(nullptr),
        energia(ENERGIA_PERSONAJE),
        contador_daniado(0),
        modo_test(false),
        puntajes_nivel{0,0,0},
        contador_propulsion(0),
        escudo(false){

}

Personaje::~Personaje(){
    if (this->item){
        delete(this->item);
    }
    delete(this->estado);
}

void Personaje::setPosX(double pos_x){
    this->posicion.setX(pos_x);
}

double Personaje::getPosX(){
    return this->posicion.getX();
}

void Personaje::setPosY(double pos_y){
    this->posicion.setY(pos_y);
}

double Personaje::getPosY(){
    return this->posicion.getY();
}

int Personaje::getAlto() {
    return this->alto;
}
int Personaje::getAncho() {
    return this->ancho;
}

int Personaje::getPuntaje() {
    return this->puntaje;
}

int Personaje::getPuntajeNivel(int nro_nivel){
    return this->puntajes_nivel[(long unsigned)nro_nivel - 1];
}


void Personaje::agregarPuntaje(int nuevo_puntaje, int nro_nivel){
    this->puntaje += nuevo_puntaje;
    this->puntajes_nivel[(long unsigned)nro_nivel - 1] += nuevo_puntaje;
}


std::string Personaje::getNombre() {
    return this->nombre;
}

void Personaje::setNombre(std::string n) {
    this->nombre = n;
}

void Personaje::setEstado(IEstadoPersonaje* estado_nuevo){
    delete(this->estado);
    this->estado = estado_nuevo;
}

void Personaje::mover(Posicion direccion){
    this->posicion += direccion;
}

bool Personaje::estaQuieto(){
    return this->estado->estaQuieto();
}

void Personaje::actualizar(){
    this->estado->actualizar();
    this->armamento->actualizar(this->posicion, POS_DERECHA);
    if ( this->contador_daniado > 0 ){
        this->contador_daniado--;
    }
    if ( this->contador_item > 0 ){
        this->contador_item--;
    }
    if (this->contador_propulsion > 0){
        if (this->contador_propulsion > COOLDOWN_PROPULSION) {
            double dir_x = this->contador_propulsion - COOLDOWN_PROPULSION;
            dir_x /= PROPULSION_MAX - COOLDOWN_PROPULSION;
            dir_x *= 3*this->incremento;
            if(this->pos_ventana.getX() + ANCHO_PERSONAJE + dir_x >= ANCHO_VENTANA) {
                dir_x = ANCHO_VENTANA - this->pos_ventana.getX() - ANCHO_PERSONAJE;
            }
            Posicion direccion(dir_x, 0);
            this->mover(direccion);
        }
        this->contador_propulsion--;
    }
}

void Personaje::actualizar(Posicion direccion){
    if (direccion != POS_NINGUNA) {
        this->direccion_mirando = direccion;
    }
    else{
        this->direccion_mirando = POS_DERECHA;
    }

    this->estado->actualizarPosicion( direccion * (this->incremento) );
}

void Personaje::setConectado(bool estado_actual_conectado) {
    this->conectado = estado_actual_conectado;
}

bool Personaje::estaConectado() {
    return this->conectado;
}

int Personaje::getDireccion() {
    if (this->direccion_mirando == POS_ARRIBA) {
        return DIRECCION_PERSONAJE_ARRIBA;

    } else if ((this->direccion_mirando == POS_ARRIBA_DER)) {
        return DIRECCION_PERSONAJE_ARRIBA;

    }else if ((this->direccion_mirando == POS_ARRIBA_IZQ)) {
        return DIRECCION_PERSONAJE_ARRIBA;

    } else if ((this->direccion_mirando == POS_ABAJO_DER)) {
        return DIRECCION_PERSONAJE_ABAJO;

    } else if ((this->direccion_mirando == POS_ABAJO)) {
        return DIRECCION_PERSONAJE_ABAJO;

    } else if ((this->direccion_mirando == POS_ABAJO_IZQ)) {
        return DIRECCION_PERSONAJE_ABAJO;
    }
    return DIRECCION_PERSONAJE_IZQUIERDA_DERECHA;

}

int Personaje::getNumeroPersonaje() {
    return this->nro_personaje;
}

Posicion Personaje::getPosicionVentana() {
    return pos_ventana;
}

void Personaje::setPosicionVentana(Posicion pos) {
    this->pos_ventana = pos;
}

bool Personaje::getEstaEnVentana() {
    return true;
}

void Personaje::setEstaEnVentana(bool en_ventana) {
    en_ventana = en_ventana + true;
}

void Personaje::actualizarColision(Posicion pos_colision){
    this->estado->actualizarColision(pos_colision);
}

void Personaje::setListo(bool estado_listo){
    this->listo = estado_listo;
}

bool Personaje::estaListo(){
    return this->listo;
}

void Personaje::reiniciarEnergia() {
    this->energia = ENERGIA_PERSONAJE;
    this->contador_daniado = 0;
}

bool Personaje::estaDaniado(){
    return this->contador_daniado == 1;
}

bool Personaje::estaVivo() {
    return this->energia > 0;
}

int Personaje::getVidas() {
    return this->vidas;
}

void Personaje::matar() {

    if(this->modo_test || !this->conectado){
        return;
    }

    if (this->escudo){
        this->escudo = false;
        return;
    }

    this->energia = 0;
    this->vidas -= 1;
}

void Personaje::disparar() {
    this->armamento->setEstaDisparando(true);
}
void Personaje::dejarDeDisparar() {
    this->armamento->setEstaDisparando(false);
}
void Personaje::setProyectiles(std::vector<Proyectil*>* lista_proyectiles){
    this->armamento->setProyectiles(lista_proyectiles);
}
bool Personaje::estaDisparando() {
    return this->armamento->getEstaDisparando();
}

void Personaje::agarrarItem(Item* item_nuevo){
    item_nuevo->darEfecto(this);
    if (this->item){
        delete(this->item);
    }
    this->item = item_nuevo;
    this->contador_item = 2;
}

void Personaje::impactar(int potencia){

    this->contador_daniado = 2;

    if(this->modo_test || !this->conectado){
        return;
    }

    if (this->escudo){
        this->escudo = false;
        return;
    }

    this->energia -= potencia;
    if (this->energia < 0){
        this->energia = 0;
    }
}

int Personaje::getEnergia(){
    return this->energia;
}

void Personaje::setTest(){
    this->modo_test = !this->modo_test;
}

bool Personaje::getTest(){
    return this->modo_test;
}

void Personaje::activarPropulsion(){
    if (this->contador_propulsion == 0){
        this->contador_propulsion = PROPULSION_MAX;
    }
}

bool Personaje::estaPropulsionando() {
    return this->contador_propulsion > COOLDOWN_PROPULSION;
}

void Personaje::dejarDePropulsionar(){
    this->contador_propulsion = 0;
}

bool Personaje::agarroItem() {
    return this->contador_item == 1;
}

void Personaje::removerItem() {
    this->contador_item = 0;
    if (this->item) {
        delete(this->item);
        this->item = nullptr;
    }
}

void Personaje::sumarVida(){
    this->vidas++;
}

void Personaje::agregarEnergia(int energia_extra){
    this->energia += energia_extra;
    if (this->energia > ENERGIA_PERSONAJE) {
        this->energia = ENERGIA_PERSONAJE;
    }
}

void Personaje::agregarEscudo() {
    this->escudo = true;
}

bool Personaje::tieneEscudo(){
    return this->escudo or this->modo_test;
}

