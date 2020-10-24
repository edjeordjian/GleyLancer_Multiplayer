#include "HiloDibujador.h"

HiloDibujador::HiloDibujador(ColaProtegida<std::string>* q, JuegoVista* juego_vista){
    this->actualizaciones=q;
    this->vista = juego_vista;
}

HiloDibujador::~HiloDibujador(){
    this->matar();
}

void HiloDibujador::ejecutar(){
    if(!this->estaActivo()){
        this->hilo = std::thread(&HiloDibujador::protocoloDibujar, this);
    }

}

void HiloDibujador::matar(){
    if(this->estaActivo()){
        this->actualizaciones->encolar("FIN_DIBUJO");
        this->hilo.join();
    }
}

bool HiloDibujador::estaActivo(){
    return this->hilo.joinable();
}

void HiloDibujador::protocoloDibujar(){
    std::string estado;
    while((estado = this->actualizaciones->desencolarBloqueante()) != "FIN_DIBUJO"){
        this->vista->actualizar(estado);
    }
}