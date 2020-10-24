#ifndef CLIENTE_HILODIBUJADOR_H
#define CLIENTE_HILODIBUJADOR_H

#include "Hilo.h"
#include "ColaProtegida.h"
#include "../vista/JuegoVista.h"
#include <string>

class HiloDibujador: public Hilo {

    //Esta clase tiene que tener una cola protegida en la que recibe estados (actualizaciones, strings) y las dibuja
    //la forma de matar al hilo será acolando un mensaje especifico (fin_dibujar)
    //Lo unico que hace el protocolo es "desacolar->actualizar(estado_desacolado)"

    private:
        JuegoVista* vista;
        ColaProtegida<std::string>* actualizaciones;

    public:
    HiloDibujador(ColaProtegida<std::string>* q, JuegoVista* juego_vista);
    ~HiloDibujador();

    void ejecutar();
    void matar();

    bool estaActivo();

    void protocoloDibujar();

};


#endif //CLIENTE_HILODIBUJADOR_H
