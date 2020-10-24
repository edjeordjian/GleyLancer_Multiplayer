#ifndef SERVIDOR_HILOENVIAR_H
#define SERVIDOR_HILOENVIAR_H

#include "Hilo.h"
#include <sys/socket.h>
#include <cstdint>
#include <netdb.h>
#include <vector>
#include <string>
#include <condition_variable>
#include "ColaProtegida.h"
#include "../Servidor.h"
#include "../../../tools/constantes/ConstantesMensajes.h"


/**
* Clase que se encarga de enviar mensajes a los clientes de forma concurrente
**/

class HiloEnviar : public Hilo {

private:

    /// Valor entero que representa el fd  (file descriptor) del cliente asociado al hilo
    int *peer_fd;

    /// Cola utilizada para guardar los mensajes a enviar al cliente  asociado al hilo
    ColaProtegida<std::string> *cola_enviar;

    /// Atributo que representa al servidor del juego
    Servidor *servidor;

public:
    /// Constructor de clase
    /// Recibe un puntero al socket servidor para poder aceptar clientes y un puntero a la cola de mensajes a enviar
    HiloEnviar(ColaProtegida<std::string> *q, Servidor *s);

    ///Destructor de clase
    ~HiloEnviar();

    /// Comienza a ejecutar en forma concurrente el metodo protocoloEnviar
    void ejecutar();

    /// Detiene la ejecucion del hilo si el mismo se esta ejecutando
    void matar();

    /// Retorna un valor booleano que representa si el hilo esta ejecutandose
    /// TRUE esta en ejecucion
    /// FALSE no esta en ejecucion
    bool estaActivo();

    /// Funcion que desencola mensaje de la cola_enviar y lo envia al cliente asociado al hilo
    void protocoloEnviar();

    ///Setea el file descriptor con el valor recibido por parametro
    void setFD(int *peer);
};


#endif //SERVIDOR_HILOENVIAR_H
