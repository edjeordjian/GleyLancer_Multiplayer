#include "Cliente.h"

Cliente::Cliente(int peer, HiloRecibir *hr, HiloEnviar *he, ColaProtegida<std::string>* cola) :
        fd{peer},
        usuario(""),
        password(""),
        listo(false),
        nombreCompleto(false),
        hiloRecibir{hr},
        hiloEnviar{he},
        cola_enviar(cola),
        ping_recibido(true),
        ms_ping(0),
        t_actual_ping(SDL_GetTicks()),
        t_inicial_ping(SDL_GetTicks()){

    hiloRecibir->setFD(&this->fd);
    hiloEnviar->setFD(&this->fd);


    hiloRecibir->ejecutar();
    hiloEnviar->ejecutar();
}

Cliente::~Cliente() {
    delete(this->hiloRecibir);
    delete(this->hiloEnviar);
    delete(this->cola_enviar);
}

int Cliente::getFD() {
    return this->fd;
}

void Cliente::agregarCaracterUsuario(std::string ch) {
    this->usuario += ch;
}

void Cliente::agregarCaracterPassword(std::string ch) {
    this->password += ch;
}

void Cliente::setListo(bool esta_listo) {
    this->listo = esta_listo;
}

void Cliente::agregarCaracter(std::string letra) {
    if(this->nombreCompleto){
        this->agregarCaracterPassword(letra);
        return;
    }
    this->agregarCaracterUsuario(letra);
}

void Cliente::setNombreCompleto(bool estaCompleto) {
    this->nombreCompleto = estaCompleto;
}

std::string Cliente::getUsuario() {
    return this->usuario;
}

std::string Cliente::getPassword() {
    return this->password;
}

bool Cliente::estaListo() {
    //Caso borde: Listo esta en verdadero mientras que el fd ya fue apagado (desconexion al cambiar de nivel)
    return this->listo;
}

void Cliente::asignarNroCliente(size_t num_cliente) {
    this->hiloRecibir->setNroCliente((int) num_cliente);
}

int Cliente::getNroCliente(){
    return this->hiloRecibir->getNroCliente();
}

void Cliente::enviarMensaje(std::string mensaje){
    this->cola_enviar->encolar(mensaje);
}

void Cliente::setPingRecibido(bool estado){
    if (!estado){
        this->t_actual_ping = SDL_GetTicks();
        if (this->t_actual_ping - this->t_inicial_ping > MS_PING_ALTO){
            this->ping_recibido = estado;
        }
    } else {
        this->ms_ping = SDL_GetTicks() - this->t_actual_ping;
        //std::cout << "Jugador " << this->usuario << " ping: " << this->ms_ping << "ms.\n";
        this->ping_recibido = estado;
        this->t_inicial_ping = SDL_GetTicks();
    }

}

bool Cliente::pingRecibido(){
    return this->ping_recibido;
}

unsigned int Cliente::getPing(){
    this->t_actual_ping = SDL_GetTicks();
    return this->t_actual_ping - this->t_inicial_ping;
}
void Cliente::desconectar(){
    if (this->estaListo() and this->fd > FD_DEFECTO) {
        this->listo = false;
        this->hiloRecibir->matar();
    }
}
void Cliente::actualizarPingInicial(){
    this->t_inicial_ping = SDL_GetTicks();
}
