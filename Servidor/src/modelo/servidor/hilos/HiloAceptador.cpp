#include "HiloAceptador.h"

HiloAceptador::HiloAceptador(std::vector<Cliente*> *c, std::mutex *mutex_peers, Servidor *s, ColaProtegida<uint16_t>* recibir) :
        clientes{c},
        mutex{mutex_peers},
        servidor{s},
        cola_recibir{recibir},
        juego_finalizado(false)
        {}

HiloAceptador::~HiloAceptador() {
    this->matar();
}

void HiloAceptador::ejecutar() {
    if (!this->estaActivo()) {
        this->hilo = std::thread(&HiloAceptador::protocoloAceptar, this);
    }
}

void HiloAceptador::matar() {
    if(this->estaActivo()){
        this->mutex->lock();
        this->servidor->apagar();
        this->mutex->unlock();
        this->hilo.join();
    }
}

bool HiloAceptador::estaActivo() {
    return this->hilo.joinable();
}

void HiloAceptador::rechazarConexion(Cliente* cliente_nuevo, std::string mensaje){

    this->mutex->unlock();    ///Se desbloquea para que no se trabe el juego y al final se vuelve a bloquear

    cliente_nuevo->enviarMensaje(mensaje);
    //Le mando el mensaje al cliente explicando el rechazo de la conexion
    std::this_thread::sleep_for(std::chrono::milliseconds(200));
    delete(cliente_nuevo);
    loguearDebug(LOG_CLIENTE_DE_MAS_BORRADO);
    this->mutex->lock();
}

void HiloAceptador::protocoloAceptar() {
    int fd;
    ColaProtegida<std::string> *cola_send = nullptr;
    HiloRecibir *hr = nullptr;
    HiloEnviar *he = nullptr;
    Cliente* cliente_nuevo = nullptr;
    while (this->servidor->esta_prendido()) {
        fd = this->servidor->aceptarCliente();
        this->mutex->lock();
        if ( fd != FD_DEFECTO and this->clientes->size() < (CANT_CONEXIONES_MAX - 2*N_JUGADORES_MAX - 1) ){
            int cant_listos = 0;
            for(auto &c: *(this->clientes)){
                if(c->estaListo()){
                    cant_listos++;
                }
            }
            cola_send = new ColaProtegida<std::string>();
            hr = new HiloRecibir(this->cola_recibir, this->servidor);
            he = new HiloEnviar(cola_send, this->servidor);
            cliente_nuevo = new Cliente(fd, hr, he, cola_send);
            if(this->juego_finalizado){
                this->rechazarConexion(cliente_nuevo, MSJ_SERVER_FIN_PARTIDA);
            }
            if(cant_listos >= (int) getCantidadUsuarios()){
                this->rechazarConexion(cliente_nuevo, MSJ_SERVER_LLENO);
            } else {
                this->clientes->emplace_back(cliente_nuevo);
            }
        }
        else{
            if(fd != FD_DEFECTO) {
                this->servidor->apagar(fd);
            }
            std::this_thread::sleep_for(std::chrono::milliseconds (500));
        }
        mutex->unlock();
    }
}

void HiloAceptador::setJuegoFinalizado(bool estado) {
    std::unique_lock<std::mutex> lock(*(this->mutex));
    this->juego_finalizado = estado;
}
