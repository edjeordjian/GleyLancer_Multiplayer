#include "HiloRecibir.h"

HiloRecibir::HiloRecibir(ColaProtegida<std::string> *q, ControladorCliente *c):
            cola{q},
            cliente{c} {
}


HiloRecibir::~HiloRecibir(){
    if (this->estaActivo()){
        this->matar();
    }
}

void HiloRecibir::ejecutar(){
    this->hilo = std::thread(&HiloRecibir::protocoloRecibir, this);
}

void HiloRecibir::matar(){
    this->cliente->desconectarse();
    if(this->estaActivo()){
        this->hilo.join();
    }
}

bool HiloRecibir::estaActivo(){
    return this->hilo.joinable();
}

void HiloRecibir::protocoloRecibir(){
    try{
        std::string mensaje = this->cliente->recibir();

        while(mensaje != DESCONECTADO){
            this->cola->encolar(mensaje);
            mensaje = this->cliente->recibir();
        }

        this->cola->encolar(mensaje);
        this->cliente->desconectarse();

    } catch (char const* excepcion) {
        this->cliente->desconectarse();
    }

}