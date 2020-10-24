#ifndef SERVIDOR_CONSTANTESCOMUNICACION_H
#define SERVIDOR_CONSTANTESCOMUNICACION_H

#include <bits/stdc++.h>

/// COMUNICACION ENTRE CLIENTE Y SERVIDOR
static const int FIX_PUERTO_SUCIO = 2649; //Numero random
static const int FD_DEFECTO = -1;
static const int CANTIDAD_REINTENTOS_RECONEXION = 7;

static constexpr int CANT_CONEXIONES_MAX = 32;
static constexpr int N_JUGADORES_MAX = 4;

static constexpr uint32_t MS_PING_ALTO = 80;
static constexpr uint32_t MS_PING_DESCONECTADO = 6500;

static constexpr unsigned int SEGUNDOS_TIMEOUT = 0;
static constexpr unsigned int MICROSEGUNDOS_TIMEOUT = 50000; /* 0,05 segundos  */
static const std::chrono::seconds TIMEOUT_NOMBRES = std::chrono::seconds(2);
static constexpr unsigned int MILISEG_LOCK_CERRAR_FD = 16; /* 0,016 segundos  */
static constexpr unsigned int MILISEG_COLA_VACIA = 16; /* 0,016 segundos  */

static constexpr int CONECTADO_NO_LISTO = -2;

static constexpr int SEGUNDOS_FIN_NIVEL = 9000;
static constexpr int SEGUNDOS_CERRAR_CLIENTES  = 2000;
static constexpr int SEGUNDOS_GAME_OVER  = 7000;
static constexpr int SEGUNDOS_CONGRATULATIONS = 10000;

static constexpr int MILISEG_MINI_SLEEP = 500;


#endif //SERVIDOR_CONSTANTESCOMUNICACION_H
