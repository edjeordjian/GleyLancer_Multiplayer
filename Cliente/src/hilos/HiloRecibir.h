#ifndef CLIENTE_HILORECIBIR_H
#define CLIENTE_HILORECIBIR_H

#include "Hilo.h"
#include "ColaProtegida.h"
#include "../controlador/ControladorCliente.h"

class ControladorCliente;
class HiloRecibir: public Hilo {
private:
    ColaProtegida<std::string>* cola;
    ControladorCliente* cliente;

public:
    HiloRecibir(ColaProtegida<std::string>* q, ControladorCliente *c);
    ~HiloRecibir();

    void ejecutar();
    void matar();

    bool estaActivo();

    void protocoloRecibir();
};


#endif //CLIENTE_HILORECIBIR_H
