#ifndef CLIENTE_HILOENVIAR_H
#define CLIENTE_HILOENVIAR_H

#include "Hilo.h"
#include "ColaProtegida.h"
#include "../controlador/ControladorCliente.h"

class ControladorCliente;
class HiloEnviar : public Hilo {

    private:
        ColaProtegida<uint16_t>* cola;
        ControladorCliente* cliente;

    public:
        HiloEnviar(ColaProtegida<uint16_t>* q, ControladorCliente *c);
        ~HiloEnviar();

        void ejecutar();
        void matar();

        bool estaActivo();

        void inputEnviar();


};

/*hilo recibir, recibe el hilo desde el servidor el msj del tipo string y lo encola en una cola de msj, el cliente luego los desencola.
 * hilo enviar, desencolaBloqueante de la cola de inpus del tipo uint_16 y lo envia al servidor*/



#endif //CLIENTE_HILOENVIAR_H
