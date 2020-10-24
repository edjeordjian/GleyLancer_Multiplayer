#ifndef SERVIDOR_CONTROLADORSERVIDOR_H
#define SERVIDOR_CONTROLADORSERVIDOR_H

#include <SDL2/SDL_stdinc.h>
#include <string>
#include <vector>
#include <iostream>
#include "../modelo/servidor/Servidor.h"
#include "ControladorJuego.h"
#include "../modelo/servidor/hilos/HiloEnviar.h"
#include "../modelo/servidor/hilos/ColaProtegida.h"
#include "../modelo/servidor/Cliente.h"
#include "../modelo/servidor/hilos/HiloAceptador.h"
#include "../tools/constantes/ConstantesComunicacion.h"
#include "../tools/constantes/ConstantesMensajes.h"
#include "../tools/constantes/ConstantesTeclas.h"

/**
 * Clase que se encarga de ser el controlador del servidor del juego
 **/

class ControladorServidor {

private:

    /// Atributo que representa al servidor del juego
    Servidor *servidor;

    /// Atributo que representa al controlador del juego
    ControladorJuego *controlador_juego;

    /// Cola utilizada para guardar los inputs recibidos de cada cliente
    ColaProtegida<uint16_t> cola_inputs_recibidos;

    /// Este mutex se usa para proteger el acceso al vector de clientes
    std::mutex mutex;

    /// Vector utilizado para guardar los datos asociados a los clientes conectados al servidor
    std::vector<Cliente *> clientes;

    /// El hilo encargado de aceptar o rechazar conexiones de clientes al servidor
    HiloAceptador *hilo_aceptador;

    /// Contador de actualizaciones por segundo
    uint32_t fps;

    /// Atributo booleano que representa si el nivel se actualizó mas de una vez
    /// Cambia de verdadero a falso si el nivel se actualizo mas de una vez
    bool nivel_principio;

    uint32_t contador_timeout_desconexion;
    uint32_t contador_timeout_inicio;


public:

    /// Constructor de la clase
    ControladorServidor(int argc, char *argv[]);

    /// Destructor de la clase
    ~ControladorServidor();

    /// Inicializa el controlador del servidor creando el servidor, hilo aceptador y controlador del juego
    void inicializar();

    ///Retorna un valor booleano si el servidor/juego esta activo
    /// TRUE si hay jugadores conectados y no se gano y no se perdio la partida
    /// FALSE si no hay jugadores conectado o si se gano o perdio la partida
    bool estaActivo();

    /// Acepta clientes mediante el hilo aceptador y se queda esperando hasta tener la cantidad para iniciar la partida
    /// Funcion bloqueante
    void aceptarClientes();

    /// Recibe nombre y password de los clientes y los guarda en cada uno de sus jugadores/personajes
    /// Retorna un numero entero que representa la cantidad de clientes que ingresaron credenciales validas para jugar
    int recibirInfoCliente();

    /// Funcion auxiliar que valida si el cliente asociado al numero de cliente tiene credenciales validas para jugar
    /// Si valida las credenciales y la partida no esta llena permite su ingreso
    /// Si no valida las credenciales o la partida esta llena no permite su ingreso
    void validarInfoCliente(long unsigned n_cliente, unsigned short *cantidad_listos);


    /// Elimina a los clientes que se desconectaron y todos sus atributos y datos asociados
    /// Retorna un valor entero que representa la cantidad de clientes borrados
    int borrarClientesDesconectados();


    /// Actualiza a los clientes desconectado seteandolos en estado "No Listo" para permitirles reconectarse
    /// Retorna un valor entero que representa la cantidad de clientes actualizados
    int actualizarDesconectados();

    /// Actualiza los estados del juego y del servidor, valida clientes, y realiza la comunicacion con los mismos
    void actualizar();

    /// Obtiene de la cola_inputs_recibidos los datos recibidos de los clientes, los decodifica
    /// y actualiza los estados correspondientes (juego o servidor)
    void actualizarInputs();

    /// Funcion auxiliar que actualiza el juego si se desconecto un jugador en medio del mismo
    void actualizarInputDesconexion(uint16_t input);

    ///nFuncion auxiliar que actualiza el ping del cliente que mando el dato (input)
    void actualizarInputPing(uint16_t input);

    /// Funcion auxiliar para actualizar el user o password del cliente que mando el dato (input)
    /// Utilizada para la reconexion
    void actualizarInputInfoCliente(uint16_t input);

    /// Funcion auxiliar para validar y actualizar el estado de un cliente (credenciales)
    /// valida si permite la reconexion del cliente con user/password
    /// Se recibieron todas las letras correspondientes al user y password
    void validarInputInfoCliente(std::vector<Cliente *>::iterator *itr);

    /// Envia los estados de todos los elementos (personajes, enemigos, fondo, etc) a los clientes
    void enviarEstados();

    /// Envia el mensaje recibido por parametro a todos los clientes conectados
    void enviarATodos(std::string mensaje);

    /// Borra del vector de clientes aquellos que no tenga estado "listos"
    void borrarClientesNoListos();

    /// Retorna un valor booleano que representa si el cliente tiene un user y password de los predeterminados para jugar.
    /// TRUE si el user y password son validos
    /// FALSE si el user o la password son invalidos
    bool esValidoCliente(Cliente *cliente);

    void mensajesGameOver();

    // Reemplazar el sleep, mejorando la forma en que el cliente sabe si el servidor se cayó.
    void esperarTiempo(const unsigned int milisegs);

    void esperarTiempoConLock(const unsigned int milisegs);

};


#endif //SERVIDOR_CONTROLADORSERVIDOR_H
