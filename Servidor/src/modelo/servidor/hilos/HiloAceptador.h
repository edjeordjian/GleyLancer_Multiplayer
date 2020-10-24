#ifndef SERVIDOR_HILOACEPTADOR_H
#define SERVIDOR_HILOACEPTADOR_H

#include <mutex>
#include <vector>
#include "Hilo.h"
#include "../Servidor.h"
#include "../Cliente.h"

/**
* Clase que se encarga de ser la encargada de aceptar nuevas conexiones contra el servidor
**/

class HiloAceptador : public Hilo {

private:

    /// Vector utilizado para guardar los datos asociados a los clientes conectados al servidor
    std::vector<Cliente*> *clientes;

    /// Este mutex se usa para proteger el acceso al vector de clientes
    std::mutex *mutex;

    /// Atributo que representa al servidor del juego
    Servidor *servidor;

    /// Cola utilizada para guardar los inputs recibidos de cada cliente
    ColaProtegida<uint16_t>* cola_recibir;

    /// Atributo que representa si el juego esta finalizado
    bool juego_finalizado;

public:

    /// Constructor de clase
    /// Recibe el vector de clientes conectados, el mutex de proteccion al acceso de ese vector, un puntero al socket servidor
    /// para poder aceptar clientes y un puntero a la cola de inputs en la que se guardan los datos recibidos de los clientes
    HiloAceptador(std::vector<Cliente*> *c,std::mutex *mutex_peers, Servidor *s, ColaProtegida<uint16_t>* cola_inputs);

    ///Destructor de clase
    ~HiloAceptador();

    /// Comienza a ejecutar en forma concurrente el metodo protocoloAceptar
    void ejecutar();

    /// Detiene la ejecucion del hilo si el mismo se esta ejecutando
    void matar();

    /// Retorna un valor booleano que representa si el hilo esta ejecutandose
    /// TRUE esta en ejecucion
    /// FALSE no esta en ejecucion
    bool estaActivo();

    /// Funcion bloqueante que espera de forma indefinida de conexciones de clientes al servidor
    /// En caso de aceptar una conexion agrega al cliente a la lista de clientes
    void protocoloAceptar();

    /// Rechaza la conexion entrante y le envia al cliente un mensaje con el motivo del rechazo
    void rechazarConexion(Cliente* cliente_nuevo, std::string mensaje);

    /// Guarda el valor booleano recibido por parametro en el atributo juego finalizado
    /// Si el juego esta finalizado (partida ganada o perdida) acepto las conexiones pero les indica
    /// que el juego finalizó y cierra la conexion.
    void setJuegoFinalizado(bool estado);

};


#endif //SERVIDOR_HILOACEPTADOR_H
