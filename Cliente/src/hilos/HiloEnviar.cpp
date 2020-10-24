#include "HiloEnviar.h"

HiloEnviar::HiloEnviar(ColaProtegida<uint16_t> *q, ControladorCliente *c):
        cola{q},
        cliente{c} {
}


HiloEnviar::~HiloEnviar(){
    if (this->estaActivo()){
        this->matar();
    }
}

void HiloEnviar::ejecutar(){
    this->hilo = std::thread(&HiloEnviar::inputEnviar, this);
}

void HiloEnviar::matar(){
    this->cliente->desconectarse();
    if(this->estaActivo()){
        //Encolo basura para que el desencolar bloqueante obtenga algo y falle el send
        this->cola->encolar(0);
        this->hilo.join();
    }
}

bool HiloEnviar::estaActivo(){
    return this->hilo.joinable();
}

void HiloEnviar::inputEnviar(){
    try{
        uint16_t input = this->cola->desencolarBloqueante();
        while(true){
            long int bytes_sent = this->cliente->enviar(input);
            if (bytes_sent <= 0) {
                this->cliente->desconectarse();
                break;
            }
            input = this->cola->desencolarBloqueante();
        }
    } catch (char const* excepcion) {
        this->cliente->desconectarse();
    }
}
