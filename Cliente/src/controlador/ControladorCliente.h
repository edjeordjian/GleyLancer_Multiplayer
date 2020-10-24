#ifndef CLIENTE_CONTROLADORCLIENTE_H
#define CLIENTE_CONTROLADORCLIENTE_H

#include <mutex>
#include <string>
#include <SDL2/SDL.h>
#include "JuegoControlador.h"
#include "../modelo/Cliente.h"
#include "../vista/JuegoVista.h"
#include "../hilos/ColaProtegida.h"
#include "../tools/CargadorDeConfiguracion.h"
#include "../tools/ConstantesExcepciones.h"
#include "../tools/Log.h"
#include "../hilos/HiloRecibir.h"
#include "../hilos/HiloEnviar.h"


class HiloRecibir;
class HiloEnviar;
class ControladorCliente {
private:
    JuegoControlador* juego_controlador;
    Cliente* cliente_modelo;
    SDL_Event evento;
    bool continuar;
    int timeout;

    Uint16 nro_cliente;
    bool listo;

    ColaProtegida<uint16_t>* cola_inputs;
    ColaProtegida<std::string>* cola_mensajes;

    HiloRecibir* hilo_recv;
    HiloEnviar* hilo_envr;

public:
    ControladorCliente(int argc, const char* argv[]);
    bool iniciar();
    void alistarse();
    //Devuelve true si hay conexion con el servidor
    bool estaActivo();
    void actualizar();
    void enviarStr(std::string str);
    void rechazarConexiones(char* titulo,char* msj);
    void reiniciar();
    void setAtributosDefault();

    std::string recibir();
    long int enviar(uint16_t input);
    void desconectarse();
    void borrarConexion();
    ~ControladorCliente();
};

#endif //CLIENTE_CONTROLADORCLIENTE_H
