#ifndef SERVIDOR_CONSTANTESMENSAJES_H
#define SERVIDOR_CONSTANTESMENSAJES_H

#include <string>

/// MENSAJES (para enviar) ///
static constexpr char* MSJ_JUGADOR_CONECTADO = (char*) " jugador(es) conectado(s).";
static std::string MSJ_INICIO_SV = "Servidor iniciado.";
static std::string MSJ_CLIENTE_LISTO = "Listo";
static std::string MSJ_CERRAR_CLIENTE = "cerrate";
static std::string MSJ_DATOS_VALIDOS = "datos_validos";
static std::string MSJ_DATOS_INVALIDOS = "datos_invalidos";
static std::string MSJ_DATOS_VALIDOS_PARTIDA_LLENA = "datos_validos_partida_llena";
static std::string MSJ_CLIENTE_YA_CONECTADO = "cliente_ya_conectado";
static std::string MSJ_SERVER_LLENO = "server_lleno";
static std::string MSJ_SERVER_FIN_PARTIDA = "Partida_finalizada";
static std::string MSJ_VIVOS_DESCONECTADOS = "vivos_desconectados";

static std::string MSJ_SEPARADOR = " ";
static std::string MSJ_DESCONOCIDO = "desconocido";

static std::string MSJ_COLA_VACIA = "cola vacia";
static std::string MSJ_NUMERO_PERSONAJE_DESCONECTADO = "4";
static std::string MSJ_COLA_HILO_ENVIAR = "CLOSE";

static std::string MSJ_PING = "ping";
static const std::string SEPARADOR = " ";

static const std::string PRE_POSICION_JUGADOR = "Pos_Jugador";
static const std::string PRE_POSICION_ENEMIGO = "Pos_Enemigo";
static const std::string PRE_POSICION_VENTANA = "Pos_Ventana";
static const std::string PRE_NIVEL_INICIAR = "Nivel_iniciar";
static const std::string PRE_NIVEL_REINICIAR = "Nivel_reiniciar";
static const std::string PRE_NIVEL_FINALIZAR = "Nivel_finalizar";
static const std::string PRE_CONGRATULATIONS = "Juego_ganado";
static const std::string PRE_NIVEL_NUM = "Nivel";
static const std::string PRE_GAME_OVER = "GAME_OVER";
static const std::string PRE_PUNTAJES_VIDAS = "puntaje_vidas";
static const std::string PRE_POSICION_PROYECTILES = "Pos_proyectiles";
static const std::string PRE_EFECTO = "efecto";
static const std::string PRE_CAJAS = "cajas";
static const std::string PRE_ITEMS = "items";
static const std::string PRE_EFECTO_PERSONAJE = "efecto_personaje";
static const std::string PRE_EFECTO_ENEMIGO = "efecto_enemigo";
static const std::string PRE_EFECTO_JEFE = "efecto_jefe";
static const std::string PRE_EFECTO_CAJA = "efecto_caja";
static const std::string PRE_TABLA_PUNTAJES = "tabla_puntajes";

#endif //SERVIDOR_CONSTANTESMENSAJES_H
