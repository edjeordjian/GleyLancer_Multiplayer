#ifndef SERVIDOR_CLIENTE_H
#define SERVIDOR_CLIENTE_H

#include <SDL2/SDL_timer.h>
#include <iostream>
#include "hilos/HiloEnviar.h"
#include "hilos/HiloRecibir.h"

class Cliente {

private:
    int fd;
    std::string usuario;
    std::string password;
    bool listo;
    bool nombreCompleto;
    HiloRecibir *hiloRecibir;
    HiloEnviar *hiloEnviar;
    ColaProtegida<std::string>* cola_enviar;
    bool ping_recibido;
    uint32_t ms_ping;
    uint32_t t_actual_ping;
    uint32_t t_inicial_ping;

public:
    Cliente(int peer, HiloRecibir *hiloRecibir, HiloEnviar *hiloEnviar, ColaProtegida<std::string>* cola);
    ~Cliente();
    int getFD();
    bool estaListo();
    void setListo(bool esta_listo);
    void setNombreCompleto(bool nombre_completo);
    void agregarCaracterUsuario(std::string ch);
    void agregarCaracterPassword(std::string ch);
    void agregarCaracter(std::string letra);
    std::string getUsuario();
    std::string getPassword();
    void asignarNroCliente(size_t num_cliente);
    int getNroCliente();
    void enviarMensaje(std::string mensaje);
    void setPingRecibido(bool estado);
    bool pingRecibido();

    unsigned int getPing();
    void desconectar();
    void actualizarPingInicial();

};


#endif //SERVIDOR_CLIENTE_H
