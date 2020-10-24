#include "HiloRecibir.h"

HiloRecibir::HiloRecibir(ColaProtegida<uint16_t>* cola_inputs, Servidor* s)
                :cola_recibir{cola_inputs},
                servidor{s} {}

HiloRecibir::~HiloRecibir(){
    this->apagarFD();
    if (this->estaActivo()) {
        this->matar();
    }
}

void HiloRecibir::ejecutar(){
    if (!this->estaActivo()) {
        this->hilo = std::thread(&HiloRecibir::protocoloRecibir, this);
    }
}

void HiloRecibir::matar(){
    this->apagarFD();
    if (this->estaActivo()){
        this->hilo.join();
    }
}

bool HiloRecibir::estaActivo(){
    return this->hilo.joinable();
}

void HiloRecibir::protocoloRecibir(){
    uint16_t num[1] {0};
    while(this->servidor->recibirMensajeCliente(*(this->peer_fd), num) == (int)sizeof(uint16_t)) {
        *num = ntohs(*num);
        *num =(uint16_t)(((int) *num * CANT_CONEXIONES_MAX ) + this->n_cliente % CANT_CONEXIONES_MAX);
        this->cola_recibir->encolar(*num);
    }
    this->apagarFD();
    loguearInfo(LOG_CLIENTE_DESCONECTADO_BORRADO);
}

int HiloRecibir::getNroCliente(){
    return this->n_cliente;
}

void HiloRecibir::setNroCliente(int nro_cliente) {
    this->n_cliente = nro_cliente;
}

void HiloRecibir::setFD(int *peer) {
    this->peer_fd = peer;
    this->n_cliente = *peer + N_JUGADORES_MAX;
}

void HiloRecibir::apagarFD(){
    this->mutex.lock();

    if (*this->peer_fd != FD_DEFECTO) {

        /* Si el fd no es -1 entonces tomo el control del mutex para que no modifiquen
        **  el valor del fd por fuera de este metodo y poder apagarlo correctamente.
        */

        this->cola_recibir->encolar((std::uint16_t) this->n_cliente);
        this->servidor->apagar(*(this->peer_fd));
        loguearDebug(LOG_CLIENTE_CERRADO + std::to_string(*(this->peer_fd)) );
        *(this->peer_fd) = FD_DEFECTO;
        loguearDebug(LOG_APAGAR_FD);
    }

    this->mutex.unlock();
}
