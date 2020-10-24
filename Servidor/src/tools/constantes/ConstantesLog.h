#ifndef SERVIDOR_CONSTANTESLOG_H
#define SERVIDOR_CONSTANTESLOG_H

#include <string>
#include <map>
#include <bits/stdc++.h>

/// LOGGING ///
static std::string RUTA_LOG = "../data/logs/log_";
static std::string RUTA_LOG_AUX = "log_";

static constexpr char *FLAG_LOG = (char *) "-l";
static constexpr char *FLAG_RUTA_CONFIG = (char *) "-c";
static constexpr char *FLAG_PUERTO = (char *) "-p";

static constexpr int ARGC_MAX_CANTIDAD_PARAMETROS = 5;
static constexpr int ARGC_MIN_CANTIDAD_PARAMETROS = 3;

static std::string EXTENSION_LOG = ".log";
static constexpr int LOG_ERROR = 1;
static constexpr char *MSJ_LOG_ERROR = (char *) "ERROR";
static constexpr int LOG_INFO = 2;
static constexpr char *MSJ_LOG_INFO = (char *) "INFO";
static constexpr int LOG_DEBUG = 3;
static constexpr char *MSJ_LOG_DEBUG = (char *) "DEBUG";

static constexpr char *LOG_COMANDO_CONSOLA = (char *) "Utilizando el modo de logueo provisto por consola.";
static constexpr char *ERROR_FALLA_DE_CARGA_JSON_DEFAULT = (char *) "No se ha podido cargar el archivo de configuracion default";
static constexpr char *ERROR_SETEO_LOG = (char *) "Modo de log incorrecto. Seteado en DEBUG.";
static constexpr char *ERROR_LOG = (char *) "No se pudo crear el archivo de log en la ruta esperada. Logueando en ruta local.";
static constexpr char *ERROR_IMG_FALTANTE = (char *) "Imagen faltante: ";
static constexpr char *ERROR_PARAMETRO_POR_CONSOLA_INVALIDO = (char *) "El modo de log ingresado por consola no es valido";
static constexpr char *ERROR_FORMATO_JSON = (char *) "Se encontró un error en el json. Línea: ";
static constexpr char *ERROR_FORMATO_JSON_2 = (char *) ". Se usará configuración por defecto.";
static constexpr char *LOG_ERROR_SUPERADA_CANTIDAD_MAXIMA_ENEMIGOS_1 = (char *) "Se ha superado la cantidad maxima de enemigos posibles en el nivel 1, se realizara una correccion";
static constexpr char *LOG_ERROR_SUPERADA_CANTIDAD_MAXIMA_ENEMIGOS_2 = (char *) "Se ha superado la cantidad maxima de enemigos posibles en el nivel 2, se realizara una correccion";
static constexpr char *LOG_ERROR_SUPERADA_CANTIDAD_MAXIMA_ENEMIGOS_3 = (char *) "Se ha superado la cantidad maxima de enemigos posibles en el nivel 3, se realizara una correccion";
static constexpr char *LOG_ERROR_NUMERO_ENEMIGOS_1_1_INVALIDO = (char *) "La cantidad de enemigos tipo 1 en el nivel 1 ingresada en el json es invalida";
static constexpr char *LOG_ERROR_NUMERO_ENEMIGOS_1_2_INVALIDO = (char *) "La cantidad de enemigos tipo 1 en el nivel 2 ingresada en el json es invalida";
static constexpr char *LOG_ERROR_NUMERO_ENEMIGOS_1_3_INVALIDO = (char *) "La cantidad de enemigos tipo 1 en el nivel 3 ingresada en el json es invalida";
static constexpr char *LOG_ERROR_NUMERO_ENEMIGOS_1_1_INVALIDO_DEFAULT = (char *) "La cantidad de enemigos tipo 1 en el nivel 1 en la configuracion default es invalida";
static constexpr char *LOG_ERROR_NUMERO_ENEMIGOS_1_2_INVALIDO_DEFAULT = (char *) "La cantidad de enemigos tipo 1 en el nivel 2 en la configuracion default es invalida";
static constexpr char *LOG_ERROR_NUMERO_ENEMIGOS_1_3_INVALIDO_DEFAULT = (char *) "La cantidad de enemigos tipo 1 en el nivel 3 en la configuracion default es invalida";
static constexpr char *LOG_ERROR_NUMERO_ENEMIGOS_2_1_INVALIDO = (char *) "La cantidad de enemigos tipo 2 en el nivel 1 ingresada en el json es invalida";
static constexpr char *LOG_ERROR_NUMERO_ENEMIGOS_2_2_INVALIDO = (char *) "La cantidad de enemigos tipo 2 en el nivel 2 ingresada en el json es invalida";
static constexpr char *LOG_ERROR_NUMERO_ENEMIGOS_2_3_INVALIDO = (char *) "La cantidad de enemigos tipo 2 en el nivel 3 ingresada en el json es invalida";
static constexpr char *LOG_ERROR_NUMERO_ENEMIGOS_2_1_INVALIDO_DEFAULT = (char *) "La cantidad de enemigos tipo 2 en el nivel 1 en la configuracion default es invalida";
static constexpr char *LOG_ERROR_NUMERO_ENEMIGOS_2_2_INVALIDO_DEFAULT = (char *) "La cantidad de enemigos tipo 2 en el nivel 2 en la configuracion default es invalida";
static constexpr char *LOG_ERROR_NUMERO_ENEMIGOS_2_3_INVALIDO_DEFAULT = (char *) "La cantidad de enemigos tipo 2 en el nivel 3 en la configuracion default es invalida";

static constexpr char *LOG_ERROR_TIPO_ENEMIGO_1_INVALIDO = (char *) "El tipo de enemigo 1 ingresado en el json es invalido";
static constexpr char *LOG_ERROR_TIPO_ENEMIGO_2_INVALIDO = (char *) "El tipo de enemigo 2 ingresado en el json es invalido";
static constexpr char *LOG_ERROR_TIPO_ENEMIGO_1_INVALIDO_DEFAULT = (char *)  "El tipo de enemigo 1 en la configuracion default es invalido";
static constexpr char *LOG_ERROR_TIPO_ENEMIGO_2_INVALIDO_DEFAULT = (char *)  "El tipo de enemigo 2 en la configuracion default es invalido";

static constexpr char *LOG_NO_LOC_JSON = (char *) "Leyendo archivo por defecto.";
static constexpr char *LOG_LOC_JSON = (char *) "Leyendo archivo JSON local.";
static constexpr char *LOG_CONFIG_PARAMETROS = (char *) "Se usa el archivo de configuracion pasado por consola.";
static constexpr char *LOG_CONFIG_SIN_PARAMETROS = (char *) "No se paso un archivo json de configuracion por parametro.";
static constexpr char *LOG_PUERTO_CONSOLA_INVALIDO = (char *) "El puerto ingresado por consola es invalido, se usara el puerto por defecto";
static constexpr char *ERROR_USUARIOS_JSON_LOCAL = (char *) "No se encontraron usuarios en el archivo de configuracion provisto. Se tomaran los valores por defecto";


static constexpr char *LOG_JUEGO_INICIADO = (char *) "Juego iniciado.";
static constexpr char *LOG_JUEGO_FINALIZADO = (char *) "Juego finalizado.";
static constexpr char* LOG_SIGUIENTE_NIVEL = (char*) "Nivel finalizado.";
static constexpr char *LOG_FIN_JUEGO_CORRECTO = (char *) "Se ha alcanzado el final del ultimo nivel correctamente.";
static constexpr char *LOG_JUEGO_CERRADO_POR_USER = (char *) "Juego cerrado por usuario";
static constexpr char *LOG_NUEVO_NIVEL = (char *) "Nuevo nivel iniciado. Numero: ";
static constexpr char *LOG_NIVEL_FINALIZADO = (char *) "Nivel finalizado.";
static constexpr char *LOG_MOV_SUP_IZQ = (char *) "La nave se mueve al margen superior izquierdo.";
static constexpr char *LOG_MOV_SUP_DER = (char *) "La nave se mueve al margen superior derecho.";
static constexpr char *LOG_MOV_ABA_IZQ = (char *) "La nave se mueve al margen inferior izquierdo.";
static constexpr char *LOG_MOV_ABA_DER = (char *) "La nave se mueve al margen inferior derecho.";
static constexpr char *LOG_MOV_ARRIBA = (char *) "La nave se mueve hacia arriba.";
static constexpr char *LOG_MOV_IZQ = (char *) "La nave se mueve a la izquierda.";
static constexpr char *LOG_MOV_DER = (char *) "La nave se mueve a la derecha.";
static constexpr char *LOG_MOV_ABAJO = (char *) "La nave se mueve hacia abajo.";

static constexpr char *LOG_PUNTOS_FIN_NIVEL_1 = (char *) "El personaje ";
static constexpr char *LOG_PUNTOS_FIN_NIVEL_2 = (char *) " termino el nivel 1 con ";
static constexpr char *LOG_PUNTOS_FIN_NIVEL_3 = (char *) " puntos, el nivel 2 con ";
static constexpr char *LOG_PUNTOS_FIN_NIVEL_4 = (char *) " puntos, el nivel 3 con ";
static constexpr char *LOG_PUNTOS_FIN_NIVEL_5 = (char *) " puntos, en total tiene: ";
static constexpr char *LOG_PUNTOS_PERSONAJE_1 = (char *) "Se le agregan ";
static constexpr char *LOG_PUNTOS_PERSONAJE_2 = (char *) " puntos al personaje: ";
static constexpr char *LOG_MURIO_PERSONAJE = (char *) "Murio el personaje: ";
static constexpr char *LOG_JEFE_DESTRUIDO = (char *) "El jefe fue destruido.";
static constexpr char *LOG_ENEMIGO_DESTRUIDO = (char *) "Se destruyo enemigo de tipo ";

static constexpr char *LOG_MULTIPLES_ARGS = (char *) "Se pasaron demasiados argumentos";
static constexpr char *LOG_FALTAN_PARAMETROS = (char *) "No se ingresaron suficientes argumentos";

static constexpr char *LOG_MODO_DE_LOGUEO = (char *) "El modo de logueo es: ";
static constexpr char *LOG_INICIO_JSON = (char *) "Se detalla lo leído del JSON...";
static constexpr char *LOG_PATH_E1 = (char *) "Clase de enemigo 1: ";
static constexpr char *LOG_PATH_E2 = (char *) "Clase de enemigo 2: ";
static constexpr char *LOG_CANT_E1_1 = (char *) "Cant. de enemigo 1 en Nivel 1: ";
static constexpr char *LOG_CANT_E1_2 = (char *) "Cant. de enemigo 1 en Nivel 2: ";
static constexpr char *LOG_CANT_E1_3 = (char *) "Cant. de enemigo 1 en Nivel 3: ";
static constexpr char *LOG_CANT_E2_1 = (char *) "Cant. de enemigo 2 en Nivel 1: ";
static constexpr char *LOG_CANT_E2_2 = (char *) "Cant. de enemigo 2 en Nivel 2: ";
static constexpr char *LOG_CANT_E2_3 = (char *) "Cant. de enemigo 2 en Nivel 3: ";
static constexpr char *LOG_CANT_MAX_E = (char *) "Cant. maxima de enemigos por Nivel: ";

static constexpr char *LOG_NOMBRE_USUARIO = (char *) "Jugador: ";

static constexpr char *LOG_INIT_VERBOSE = (char *) "Se detallan valores adicionales utilizados.";
static constexpr char *LOG_V_JSON_DEFAULT = (char *) "Ruta del JSON por defecto: ";

static constexpr char *LOG_V_ANCHO_VENT = (char *) "Ancho ventana: ";
static constexpr char *LOG_V_ALTO_VENT = (char *) "Alto ventana: ";
static constexpr char *LOG_V_X_PERSONAJE = (char *) "X personaje: ";
static constexpr char *LOG_V_Y_PERSONAJE = (char *) "Y personaje: ";
static constexpr char *LOG_V_VEL_PERSONAJE = (char *) "Velocidad de movimiento personaje: ";
static constexpr char *LOG_V_VEL_FONDO = (char *) "Velocidad de movimiento del fondo: ";
static constexpr char *LOG_INIT_CARGA = (char *) "Iniciando la carga de la configuracion";
static constexpr char *LOG_FINAL_CARGA = (char *) "Finalizada la carga de la configuracion";

static constexpr char *LOG_COLISION_ENTRE_ENEMIGOS = (char *) "Colision entre enemigos al crearlos. Pos:(";

static constexpr char *LOG_ERROR_BIND_1 = (char *) "No se pudo realizar el bind: socket fd es -1";
static constexpr char *LOG_ERROR_BIND_2 = (char *) "No se pudo realizar el bind.";

static constexpr char *LOG_ERROR_ACEPTAR_CLIENTE = (char *) "Error para aceptar cliente.";
static constexpr char *LOG_ERROR_USUARIO_INVALIDO = (char *) "No se pudo agregar usuario del archivo de configuracion custom.";
static constexpr char *LOG_ERROR_USUARIO_INVALIDO_DEFAULT = (char *) "No se pudo agregar usuario del archivo de configuracion default";
static constexpr char *LOG_ERROR_PASS_INVALIDO = (char *) "No se pudo agregar password del archivo de configuracion custom";
static constexpr char *LOG_ERROR_PASS_INVALIDO_DEFAULT = (char *) "No se pudo agregar password del archivo de configuracion default";

static constexpr char* LOG_ERROR_LONGITUD_USUARIO = (char*) "La longitud del nombre de este usuario es invalida: ";
static constexpr char* LOG_ERROR_USUARIO_REPETIDO = (char*) "Este usuario ya fue registrado: ";
static constexpr char* LOG_ERROR_LONGITUD_PASS = (char*) "La longitud de esta password es invalida: ";

static constexpr char* LOG_CLIENTE_CONECTADO = (char*) "Cliente conectado.";
static constexpr char* LOG_CLIENTE_CERRADO = (char*) "Cerrando conexion de fd: ";
static constexpr char* LOG_FIN_ACEPTAR = (char*) "Terminó la fase de aceptación de clientes.";
static constexpr char* LOG_NOMBRE_RECIBIDO = (char*) "Nombre de jugador recibido: ";
static constexpr char* LOG_CLIENTE_VALIDADO = (char *) "Cliente identificado con el nombre ";
static constexpr char* LOG_CLIENTE_VALIDO = (char *) "Se valido al cliente ";
static constexpr char* LOG_PARTIDA_LLENA = (char *) "Un cliente se conecto a una partida llena, sera desconectado.";
static constexpr char* LOG_CLIENTE_YA_CONECTADO_1 = (char *) "Ya hay un cliente valido con el nombre ";
static constexpr char* LOG_CLIENTE_YA_CONECTADO_2 = (char *) ", este cliente sera desconectado.";
static constexpr char* ERROR_THROW_INICIALIZAR = (char*) "ERROR en inicializar";
static constexpr char* ERROR_THROW_SERVER_BIND = (char*) "ERROR EN SERVER BIND, getaddrinfo: ";
static constexpr char* ERROR_THROW_SERVER_LISTEN = (char*) "ERROR: SERVER LISTEN, error ";
static constexpr char* ERROR_THROW_SERVER_CLOSE = (char*) "ERROR: CIERRE SERVER";

static constexpr char* LOG_UN_CLIENTE_DESCONECTADO = (char*) "Se desconectó un cliente.";
static constexpr char* LOG_CLIENTE_DESCONECTADO = (char*) "Cliente desconectado: ";
static constexpr char* LOG_APAGAR_FD = (char*) "El servidor apagó el fd del cliente.";
static constexpr char* LOG_PEER_SIGUE_CONECTADO = (char*) "El siguiente peer sigue conectado: ";
static constexpr char* LOG_CLIENTE_DE_MAS_BORRADO = (char*) "Se borró cliente de más.";
static constexpr char* LOG_CLIENTE_DESCONECTADO_BORRADO = (char*) "Se borró cliente desconectado.";
static constexpr char* LOG_CLIENTE_INVALIDO_BORRADO = (char*) "Se borró cliente no valido.";
static constexpr char* LOG_CLIENTE_RECONECTADO = (char*) "Se reconectó un cliente.";

static constexpr char* LOG_SERVIDOR_CERRADO_NO_CLIENTES = (char*) "Cerrado de servidor por desconexion de clientes.";
static constexpr char* LOG_SERVIDOR_CERRADO_JUEGO_FINALIZADO = (char*) "Cerrado de servidor por finalizacion del juego.";

static constexpr char*  LOG_MSJ_MANDAR_NUMERO_USUARIO= (char*) "Mandando número al usuario: ";
static constexpr char*  LOG_MSJ_CANT_JUGADORES_LISTOS= (char*) "Cantidad de jugadores listos: ";
static constexpr char*  LOG_MSJ_TECLA_1= (char*) "Tecla: ";
static constexpr char*  LOG_MSJ_TECLA_2= (char*) " de usuario nro ";
static constexpr char*  LOG_MSJ_CLIENTE_LISTO_1= (char*) "El cliente con fd ";
static constexpr char*  LOG_MSJ_CLIENTE_LISTO_2= (char*) " esta listo.";

static constexpr char*  LOG_MSJ_BIND= (char*) "Intento de bind con puerto: ";
static constexpr char*  LOG_MSJ_PUERTO= (char*) "Puerto: ";

static std::map<int, char*> msj_log = {
        { LOG_ERROR, MSJ_LOG_ERROR },
        { LOG_INFO, MSJ_LOG_INFO },
        { LOG_DEBUG, MSJ_LOG_DEBUG }
};

/* Esto en python no pasa!!!
 * Hay que pasarle al map una forma de comparar las claves
 * para que cadenas similares se mapeen igual. */
struct metodoDeComparacion{
    bool operator()(const char* s1, const char* s2) const{
        return std::strcmp(s1, s2) < 0;
    }
};

static std::map<char*, int, metodoDeComparacion> tipos_log = {
        { MSJ_LOG_ERROR, LOG_ERROR },
        { MSJ_LOG_INFO, LOG_INFO },
        { MSJ_LOG_DEBUG, LOG_DEBUG }
};

static constexpr char* LOG_ENEMIGO_MUERE = (char *) "Se destruyó a un enemigo.";
static constexpr char* LOG_JEFE_MUERE = (char *) "Se destruyó al jefe del nivel.";
static constexpr char* LOG_PERSONAJE_MUERE = (char *) "Se destruyó una nave.";
static constexpr char* LOG_CAJA_DESTRUIDA = (char *) "Se destruyó una caja.";

#endif //SERVIDOR_CONSTANTESLOG_H
