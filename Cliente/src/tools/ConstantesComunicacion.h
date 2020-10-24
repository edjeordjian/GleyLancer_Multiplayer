#ifndef CLIENTE_CONSTANTESCOMUNICACION_H
#define CLIENTE_CONSTANTESCOMUNICACION_H

#include <string>

/// COMUNICACIÓN ///
static std::string IP_DEFECTO = "127.0.0.1";
static std::string PUERTO_DEFECTO = "3333";
static const int FD_DESCONECTADO = -1;

static const int FIX_PUERTO_SUCIO = 2649; //Numero random

void setFin(bool f);
bool getFin();

static constexpr unsigned int MILISEG_TIMEOUT_EVENTOS = 5; /* 0,05 segundos */
static constexpr int CANTIDAD_REINTENTOS_RECONEXION = 7;

static constexpr char *TIMEOUT = (char *) "-1";
static constexpr char *DESCONECTADO = (char *) "-2";

static constexpr unsigned int SEGUNDOS_TIMEOUT_CONNECT = 0;
static constexpr unsigned int MICROSEGUNDOS_TIMEOUT_CONNECT = 500000;

static constexpr unsigned int SEGUNDOS_TIMEOUT_NORMAL = 0;
static constexpr unsigned int MICROSEGUNDOS_TIMEOUT_NORMAL = 0;

static constexpr unsigned int TIMEOUT_RECEPCION_SV = 400000; // Empiricamente da alrededor de 6.5 segundos

static constexpr unsigned int TIMEOUT_ACTUALIZACIONES_CLIENTE = 16;


#endif //CLIENTE_CONSTANTESCOMUNICACION_H
