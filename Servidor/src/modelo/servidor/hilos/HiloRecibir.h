#ifndef SERVIDOR_HILORECIBIR_H
#define SERVIDOR_HILORECIBIR_H

#include <mutex>
#include <cstdint>
#include <netinet/in.h>
#include <iostream>
#include "Hilo.h"
#include "ColaProtegida.h"
#include "../Servidor.h"

/**
* Clase que se encarga de recibir mensajes de los clientes de forma concurrente
**/

class HiloRecibir : public Hilo {

private:

    /// Valor entero que representa el fd  (file descriptor) del cliente asociado al hilo
    int *peer_fd;

    /// Valor entero que representa al numero del cliente asociado al hilo
    int n_cliente;

    /// Cola utilizada para guardar los inputs recibidos de cada cliente
    ColaProtegida<uint16_t> *cola_recibir;

    /// Este mutex se usa para proteger el acceso a la cola_recibir
    std::mutex mutex;

    /// Atributo que representa al servidor del juego
    Servidor *servidor;


public:

    /// Constructor de clase
    /// Recibe un puntero al socket servidor para poder aceptar clientes y un puntero a la cola de mensajes recibidos
    HiloRecibir(ColaProtegida<uint16_t> *cola_inputs, Servidor *s);

    ///Destructor de clase
    ~HiloRecibir();

    /// Comienza a ejecutar en forma concurrente el metodo protocoloRecibir
    void ejecutar();

    /// Detiene la ejecucion del hilo si el mismo se esta ejecutando
    void matar();

    /// Retorna un valor booleano que representa si el hilo esta ejecutandose
    /// TRUE esta en ejecucion
    /// FALSE no esta en ejecucion
    bool estaActivo();

    /** Funcion que va a Va a recibir numeros (unsigned short 16) del fd y los va a pushear a la cola
    * hasta recibirListo un 0 (desconexion)
    *
    * Lo que se recibe del cliente se multiplica por 4 antes de encolarse.
    * De esta forma, como los números de cliente asignados después de la fase
    * inicial son números del 0 al 9, entonces haciendo:
    * mensaje mod 10
    * se obtiene el número de cliente que mandó ese mensaje, lo cual sirve en el
    * actualizar para poder impactar los cambios del modelo recibidos por el servidor
    * en lo que el cliente visualiza.
    **/
    void protocoloRecibir();

    ///Devuelve un valor entero que representa al numero de cliente asociado al hilo
    int getNroCliente();

    ///Asigna el valor entero recibido por parametro al n_cliente
    void setNroCliente(int nro_cliente);

    ///Setea el file descriptor (peer_fd)con el valor recibido por parametro
    void setFD(int *fd);


    /** WARNING: Este metodo puede ser llamado por el propio hilo cuando se cierra una conexion de forma remota
    *           o tambien por el hilo principal en cualquier momento al matar la ejecucion
     *          o al destruir al objeto hilo
    *           por lo que hay que tener cuidado con posibles condiciones de carrera futuras.
    *           Si el fd guardado no es invalido (-1) lo apaga (shutdown), cierra (close) y setea en -1
    **/
    void apagarFD();

};


#endif //SERVIDOR_HILORECIBIR_H
