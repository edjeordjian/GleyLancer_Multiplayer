#ifndef CLIENTE_CONSTANTESMENU_H
#define CLIENTE_CONSTANTESMENU_H

#include <string>
#include <SDL2/SDL.h>
#include "ConstantesFuente.h"
#include <bits/stdc++.h>


/// MENU ///
static constexpr char *RUTA_FONDO_MENU = (char *) ("../data/imgs/fondos/fondo_0.png");
static constexpr char *RUTA_FONDO_CONECTANDO = (char *) ("../data/imgs/fondos/fondo_conectando.png");
static constexpr char *RUTA_FONDO_ESPERA = (char *) ("../data/imgs/fondos/fondo_espera.png");
static constexpr char *RUTA_FONDO_VALIDAR = (char *) ("../data/imgs/fondos/fondo_validar.png");

static constexpr char *RUTA_NUM_1 = (char *) ("../data/imgs/num1.png");
static constexpr char *RUTA_NUM_2 = (char *) ("../data/imgs/num2.png");
static constexpr char *RUTA_NUM_3 = (char *) ("../data/imgs/num3.png");
static constexpr char *RUTA_FONDO_1_INICIO = (char *) ("../data/imgs/fondos/fondo_1.png");
static constexpr char *RUTA_FONDO_2_INICIO = (char *) ("../data/imgs/fondos/fondo_2.png");
static constexpr char *RUTA_FONDO_3_INICIO = (char *) ("../data/imgs/fondos/fondo_3.png");

static constexpr char *RUTA_FONDO_CONGRATULATIONS_1 = (char *) ("../data/imgs/fondos/fondo_congratulations_1.png");
static constexpr char *RUTA_FONDO_CONGRATULATIONS_2 = (char *) ("../data/imgs/fondos/fondo_congratulations_2.png");
static constexpr char *RUTA_FONDO_CONGRATULATIONS_3 = (char *) ("../data/imgs/fondos/fondo_congratulations_3.png");
static constexpr char *RUTA_FONDO_CONGRATULATIONS_4 = (char *) ("../data/imgs/fondos/fondo_congratulations_4.png");


// Refactor: si se agrega un cartel aca, también hay
// que sumarlo en CartelVista.
// Y CUIDADO SI ES UN CARTEL PRE_JUEGO (hay que aumentar una variable)
// :|
static std::vector<char *> CARTELES = {
        RUTA_FONDO_CONECTANDO,
        RUTA_FONDO_ESPERA,
        RUTA_FONDO_1_INICIO,
        RUTA_FONDO_2_INICIO,
        RUTA_FONDO_3_INICIO
};

static const int CANTIDAD_CARTELES_PRE_JUEGO = 2;
static const int CANTIDAD_CARTELES = (int) CARTELES.size();
static const int CANTIDAD_CARTELES_NROS= 3;

static const std::chrono::seconds TIMEOUT_NUMERO_NIVEL = std::chrono::seconds(1);

static constexpr char *TITULO_CARTEL_CONEXION = (char *) ("Error de conexión");
static constexpr char *MSJ_CARTEL_CONEXION = (char *) ("La combinación IP/Puerto no es válida.");
static constexpr char *MSJ_SIN_CONEXION = (char *) ("No hay servidor disponible para los datos provistos.");
static constexpr char *TITULO_CREDENCIALES = (char *) ("Error de credenciales");
static constexpr char *MSJ_USR_PASS_MAL = (char *) ("Se deben especificar un usuario y una password.");
static constexpr char *MSJ_SV_REJECTED_YA_CONECTADO = (char *) ("El usuario con esas credenciales ya esta jugando.");
static constexpr char *MSJ_SV_REJECTED = (char *) ("La combinación Usuario/Password no es válida.");
static constexpr char *MSJ_SV_VALIDO_PARTIDA_LLENA = (char *) ("Partida ya iniciada, no se admiten mas jugadores.");
static constexpr char *MSJ_SV_LLENO = (char *) ("El servidor al que quizo conectarse esta lleno.");
static constexpr char *MSJ_SV_FIN_PARTIDA = (char *) ("La partida en el servidor ya finalizo.");

static constexpr char *MSJ_FIN = (char *) ("Reinicio de la aplicación");
static constexpr char *MSJ_ACLARACION_FIN = (char *) ("Se perdió la conexión con el servidor.");

static constexpr SDL_Color COLOR_VERDE = {0, 179, 0, 0};
static constexpr SDL_Color COLOR_BLANCO = {255, 255, 255, 0};
static constexpr SDL_Color COLOR_GRIS = {119, 136, 153, 0};
static constexpr SDL_Color COLOR_AZUL = {110, 115, 247, 0};
static constexpr int MENU_OPCION_1 = 1;
static constexpr int MENU_OPCION_2 = 2;
static constexpr int MENU_OPCION_ULT = MENU_OPCION_2;
static constexpr int MENU_INICIAR = -3;
static constexpr int MENU_SALIR = -1;

static constexpr char *MENSAJE_CONECTARSE = (char *) ("CONECTARSE");
static constexpr char *MENSAJE_SALIR = (char *) ("SALIR");

static constexpr char *MENSAJE_USUARIO = (char *) ("USUARIO");
static constexpr char *MENSAJE_PASS = (char *) ("PASSWORD");
static constexpr char *MENSAJE_INICIAR = (char *) ("INICIAR");

static constexpr int MENU_VALIDAR_1 = 1;
static constexpr int MENU_VALIDAR_2 = 2;
static constexpr int MENU_VALIDAR_3 = 3;
static constexpr int MENU_VALIDAR_ULT = MENU_VALIDAR_3;

static constexpr char *BACKSPACE = (char *) ("BORRAR");

void setIP(std::string ip);
const char *getIPServidorCte();
char* getIPServidor();

void setPuerto(std::string puerto);
char* getPuertoServidor();

void setUsuario(std::string n, bool trim);
char *getUsuario();

void setPass(std::string n, bool trim);
char *getPass();
char* getPassAsteriscos();


static constexpr unsigned int MAX_LEN_USUARIO = 8;
static constexpr unsigned int MAX_LEN_PASS = 16;

static constexpr char *TEXTO_PUNTAJE_VACIO = (char *) ("000000");
static constexpr char *TEXTO_HI_SCORE = (char *) ("HI-SCORE");
static constexpr char *TEXTO_TITULO_PUNTAJES_0 = (char *) ("NOMBRE");
static constexpr char *TEXTO_TITULO_PUNTAJES_1 = (char *) ("LV 1");
static constexpr char *TEXTO_TITULO_PUNTAJES_2 = (char *) ("LV 2");
static constexpr char *TEXTO_TITULO_PUNTAJES_3 = (char *) ("LV 3");
static constexpr char *TEXTO_TITULO_PUNTAJES_4 = (char *) ("TOTAL");

static constexpr char *  MSJ_JUGADOR_CONECTADO = (char*) "jugador(es) conectado(s).";
static constexpr char *  MSJ_MUERTOS_CONECTADOS_1= (char*)  "El juego va a terminar si los jugadores";
static constexpr char *  MSJ_MUERTOS_CONECTADOS_2 = (char*) "con vidas restantes no se reconectan...";


static std::map<char *, int> anchos = {
        {MENSAJE_CONECTARSE,    std::strlen(MENSAJE_CONECTARSE) * TAM_FUENTE_NORMAL},
        {MENSAJE_SALIR,         std::strlen(MENSAJE_SALIR) * TAM_FUENTE_NORMAL},
        {MENSAJE_USUARIO,        std::strlen(MENSAJE_USUARIO) * TAM_FUENTE_NORMAL},
        {MENSAJE_PASS,        std::strlen(MENSAJE_PASS) * TAM_FUENTE_NORMAL},
        {MSJ_JUGADOR_CONECTADO, std::strlen(MSJ_JUGADOR_CONECTADO) * TAM_FUENTE_CHICA},
        {MENSAJE_INICIAR, std::strlen(MENSAJE_INICIAR) * TAM_FUENTE_NORMAL},
        {TEXTO_HI_SCORE, std::strlen(TEXTO_HI_SCORE) * TAM_FUENTE_PUNTAJE},
        {TEXTO_PUNTAJE_VACIO, std::strlen(TEXTO_PUNTAJE_VACIO) * TAM_FUENTE_PUNTAJE},
        {TEXTO_TITULO_PUNTAJES_0, std::strlen(TEXTO_TITULO_PUNTAJES_1) * TAM_FUENTE_CHICA},
        {TEXTO_TITULO_PUNTAJES_1, std::strlen(TEXTO_TITULO_PUNTAJES_1) * TAM_FUENTE_CHICA},
        {TEXTO_TITULO_PUNTAJES_2, std::strlen(TEXTO_TITULO_PUNTAJES_1) * TAM_FUENTE_CHICA},
        {TEXTO_TITULO_PUNTAJES_3, std::strlen(TEXTO_TITULO_PUNTAJES_1) * TAM_FUENTE_CHICA},
        {TEXTO_TITULO_PUNTAJES_4, std::strlen(TEXTO_TITULO_PUNTAJES_2) * TAM_FUENTE_CHICA},
        {MSJ_MUERTOS_CONECTADOS_1, std::strlen(MSJ_MUERTOS_CONECTADOS_1)* TAM_FUENTE_MUY_CHICA},
        {MSJ_MUERTOS_CONECTADOS_2, std::strlen(MSJ_MUERTOS_CONECTADOS_2)* TAM_FUENTE_MUY_CHICA}

};

#endif //CLIENTE_CONSTANTESMENU_H
