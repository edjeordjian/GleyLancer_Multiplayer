#include <iostream>
#include "src/controlador/ControladorCliente.h"

void reiniciarControladorCliente(ControladorCliente *pCliente);

int main(int argc, const char* argv[]) {
    setFin(false);
    ControladorCliente* cliente = new ControladorCliente(argc, argv);

    while(!getFin()) {
        if (cliente->iniciar()) {
            while (cliente->estaActivo()) {
                cliente->actualizar();
            }
        }

        if (!getFin()) {
            cliente->reiniciar();
        }
    }

    delete (cliente);
    return 0;
}


