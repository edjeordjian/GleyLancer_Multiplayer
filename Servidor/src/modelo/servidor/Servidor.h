#ifndef SERVIDOR_SERVIDOR_H
#define SERVIDOR_SERVIDOR_H

#include <sys/socket.h>
#include <sys/types.h>
#include <netdb.h>
#include <netinet/tcp.h>
#include <unistd.h>
#include <cstdint>
#include <string>
#include <iostream>
#include <algorithm>
#include <string>
#include <vector>
#include <errno.h>
#include "../../tools/constantes/ConstantesComunicacion.h"
#include "../../tools/constantes/ConstantesJson.h"
#include "../../tools/constantes/ConstantesLog.h"
#include "../../tools/Log.h"



class Servidor {
private:
    /*File descriptor del socket aceptador, despues de hacer el accept
    se crea un nuevo fd que representa la conexion con un cliente
    (lo llamo peer_socket_fd ya que 'peer' es el nombre que se le da
    a los usuarios individuales dentro de una red, en este caso clientes)
    */
    int fd; //Un file descriptor es un entero que se usa para representar un archivo abierto en el sistema operativo.
    const char* puerto;

public:
    Servidor();
    ~Servidor();

    void inicializar();

    //Devuelve el fd asignado al servidor o lanza excepcion (string) en caso de error
    int bind(const char*& port);

    //Se asigna que el server pueda esperar hasta a 1 cliente o
    //lanza excepcion (string) en caso de error
    void listen();

    //Funcion que espera un tiempo (timeout constante) y devuelve cuantos clientes intentaron conectarse dentro de ese tiempo
    int seleccionarCliente();

    //Devuelve el fd asignado a la conexion con el cliente (peer) o
    //lanza excepcion (string) en caso de error
    int aceptarCliente();

    //Devuelve cuantos bytes se recibieron del buffer, 0 si hubo desconexion o -1 en caso de timeout
    //Si hubo desconexion se encarga de llamar a apagar el peer_fd
    int recibirMensajeCliente(int peer_fd, void* buffer);

    //Devuelve cuantos bytes se enviaron al cliente o 0 si hubo desconexion,
    // si hubo desconexion se encarga de llamar a apagar el peer_fd
    long int enviarMensajeCliente(int peer_fd, void* msg, long unsigned int size);

    //Hace shutdown(SHUT_RDWR) y close al fd recibido
    void apagar(int peer_fd);

    //Hace shutdown y close del fd aceptador para no aceptar mas conexiones
    void apagar();

    //Cierra el archivo asignado al fd recibido
    void cerrar(int fd);

    bool esta_prendido();
};


#endif //SERVIDOR_SERVIDOR_H
