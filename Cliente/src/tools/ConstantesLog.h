#ifndef CLIENTE_CONSTANTESLOG_H
#define CLIENTE_CONSTANTESLOG_H

#include <string>
#include <bits/stdc++.h>

/// LOGGING ///
static std::string RUTA_LOG = "../data/logs/log_";
static constexpr char *LOG_DEF_CON = (char *) "Valores de conexión por defecto:";

static constexpr char *FLAG_LOG = (char *) "-l";
static constexpr char *FLAG_RUTA_CONFIG = (char *) "-c";
static constexpr char *FLAG_IP = (char *) "-i";
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

static std::string RUTA_LOG_AUX = "log_";
static constexpr char* LOG_IP = (char *) "IP del servidor ";
static constexpr char* LOG_PUERTO = (char *) "Puerto del servidor: ";
static constexpr char* LOG_ERROR_GETADDR = (char *) "Error en el getaddrinfo. ¿Datos de conexión incorrectos?";
static constexpr char* LOG_ERROR_SEND = (char *) "No se pudo enviar un mensaje: error por desconexión.";
static constexpr char* LOG_ERROR_RECV = (char *) "No se pudo enviar un mensaje: error por desconexión.";
static constexpr char* LOG_CONEXION_EXITOSA = (char *) "Conexión exitosa.";
static constexpr char* LOG_CONEXION_CERRADA = (char *) "Conexión cerrada.";
static constexpr char* LOG_INTENTAR_CONEXION = (char *) "Se intentará conectar al servidor con los siguientes valores configurados:";
static constexpr char* LOG_SIN_FUENTE = (char *) "No se pudo cargar la fuente.";

static constexpr char* LOG_COMANDO_CONSOLA = (char *) "Utilizando el modo de logueo provisto por consola.";
static constexpr char* ERROR_FALLA_DE_CARGA_JSON_DEFAULT = (char *) "No se ha podido cargar el archivo de configuracion default";
static constexpr char* ERROR_SETEO_LOG = (char *) "Modo de log incorrecto. Seteado en DEBUG.";
static constexpr char* ERROR_LOG = (char *) "No se pudo crear el archivo de log, o el mismo es inaccesible.";
static constexpr char* ERROR_IMG_FALTANTE = (char *) "Imagen faltante: ";
static constexpr char* LOG_ERROR_FUENTE = (char *) "No se pudo abrir el archivo de la fuente.";
static constexpr char* LOG_NO_LOC_JSON = (char *) "No se encontró JSON local. Leyendo archivo por defecto.";
static constexpr char* LOG_LOC_JSON = (char *) "Leyendo archivo JSON local.";
static constexpr char* LOG_LOC_JSON_DEFAULT = (char *) "Leyendo archivo JSON por defecto.";
static constexpr char* LOG_CONFIG_PARAMETROS = (char *) "Se usa el archivo de configuracion pasado por consola.";
static constexpr char* LOG_CONFIG_SIN_PARAMETROS = (char *) "No se paso un archivo json de configuracion por parametro.";
static constexpr char* LOG_MODO_DEFAULT_CORRECTO = (char *) "Se leyo correctamente el modo del archivo por defecto.";
static constexpr char* LOG_MSJ_LISTO = (char *) " Se avisa al servidor que esta listo el cliente.";
static constexpr char* LOG_MSJ_NOMBRE_VALIDADO = (char *) "El usuario logro loguearse con el nombre: ";
static constexpr char* LOG_MSJ_PASSWORD_VALIDADO = (char *) "El usuario logro loguearse con el password: ";

static constexpr char* ERROR_PARAMETRO_POR_CONSOLA_INVALIDO = (char *) "El modo de log ingresado por consola no es valido";
static constexpr char* ERROR_FONDO_11_FALTANTE = (char *) "No se encontro ruta de capa 1 de fondo 1 en json local, se usara una ruta por defecto. ";
static constexpr char* ERROR_FONDO_11_FALTANTE_DEFAULT = (char *) "No se encontro ruta de capa 1 de fondo 1 en config default";
static constexpr char* ERROR_FONDO_12_FALTANTE = (char *) "No se encontro ruta de capa 2 de fondo 1 en json local, se usara una ruta por defecto. ";
static constexpr char* ERROR_FONDO_12_FALTANTE_DEFAULT = (char *) "No se encontro ruta de capa 2 de fondo 1 en config default.";
static constexpr char* ERROR_FONDO_13_FALTANTE = (char *) "No se encontro ruta de capa 3 de fondo 1 en json local, se usara una ruta por defecto. ";
static constexpr char* ERROR_FONDO_13_FALTANTE_DEFAULT = (char *) "No se encontro ruta de capa 3 de fondo 1 en config default.";
static constexpr char *ERROR_FONDO_14_FALTANTE = (char *) "No se encontro ruta de capa 4 de fondo 1 en json local, se usara una ruta por defecto. ";
static constexpr char *ERROR_FONDO_14_FALTANTE_DEFAULT = (char *) "No se encontro ruta de capa 4 de fondo 1 en config default.";
static constexpr char *ERROR_FONDO_15_FALTANTE = (char *) "No se encontro ruta de capa 5 de fondo 1 en json local, se usara una ruta por defecto. ";
static constexpr char *ERROR_FONDO_15_FALTANTE_DEFAULT = (char *) "No se encontro ruta de capa 5 de fondo 1 en config default.";
static constexpr char *ERROR_FONDO_16_FALTANTE = (char *) "No se encontro ruta de capa 6 de fondo 1 en json local, se usara una ruta por defecto. ";
static constexpr char *ERROR_FONDO_16_FALTANTE_DEFAULT = (char *) "No se encontro ruta de capa 6 de fondo 1 en config default.";
static constexpr char *ERROR_FONDO_21_FALTANTE = (char *) "No se encontro ruta de capa 1 de fondo 2 en json local, se usara una ruta por defecto. ";
static constexpr char *ERROR_FONDO_21_FALTANTE_DEFAULT = (char *) "No se encontro ruta de capa 1 de fondo 2 en config default. ";
static constexpr char *ERROR_FONDO_22_FALTANTE = (char *) "No se encontro ruta de capa 2 de fondo 2 en json local, se usara una ruta por defecto. ";
static constexpr char *ERROR_FONDO_22_FALTANTE_DEFAULT = (char *) "No se encontro ruta de capa 2 de fondo 2 en config default. ";
static constexpr char *ERROR_FONDO_23_FALTANTE = (char *) "No se encontro ruta de capa 3 de fondo 2 en json local, se usara una ruta por defecto. ";
static constexpr char *ERROR_FONDO_23_FALTANTE_DEFAULT = (char *) "No se encontro ruta de capa 3 de fondo 2 en config default. ";
static constexpr char *ERROR_FONDO_24_FALTANTE = (char *) "No se encontro ruta de capa 4 de fondo 2 en json local, se usara una ruta por defecto. ";
static constexpr char *ERROR_FONDO_24_FALTANTE_DEFAULT = (char *) "No se encontro ruta de capa 4 de fondo 2 en config default. ";
static constexpr char *ERROR_FONDO_25_FALTANTE = (char *) "No se encontro ruta de capa 5 de fondo 2 en json local, se usara una ruta por defecto. ";
static constexpr char *ERROR_FONDO_25_FALTANTE_DEFAULT = (char *) "No se encontro ruta de capa 5 de fondo 2 en config default. ";
static constexpr char *ERROR_FONDO_26_FALTANTE = (char *) "No se encontro ruta de capa 6 de fondo 2 en json local, se usara una ruta por defecto. ";
static constexpr char *ERROR_FONDO_26_FALTANTE_DEFAULT = (char *) "No se encontro ruta de capa 6 de fondo 2 en config default. ";
static constexpr char* ERROR_FONDO_31_FALTANTE = (char *) "No se encontro ruta de capa 1 de fondo 3 en json local, se usara una ruta por defecto. ";
static constexpr char* ERROR_FONDO_31_FALTANTE_DEFAULT = (char *) "No se encontro ruta de capa 1 de fondo 3 en config default";
static constexpr char* ERROR_FONDO_32_FALTANTE = (char *) "No se encontro ruta de capa 2 de fondo 3 en json local, se usara una ruta por defecto. ";
static constexpr char* ERROR_FONDO_32_FALTANTE_DEFAULT = (char *) "No se encontro ruta de capa 2 de fondo 3 en config default.";
static constexpr char* ERROR_FONDO_33_FALTANTE = (char *) "No se encontro ruta de capa 3 de fondo 3 en json local, se usara una ruta por defecto. ";
static constexpr char* ERROR_FONDO_33_FALTANTE_DEFAULT = (char *) "No se encontro ruta de capa 3 de fondo 3 en config default.";
static constexpr char *ERROR_FONDO_34_FALTANTE = (char *) "No se encontro ruta de capa 4 de fondo 3 en json local, se usara una ruta por defecto. ";
static constexpr char *ERROR_FONDO_34_FALTANTE_DEFAULT = (char *) "No se encontro ruta de capa 4 de fondo 3 en config default.";
static constexpr char *ERROR_FONDO_35_FALTANTE = (char *) "No se encontro ruta de capa 5 de fondo 3 en json local, se usara una ruta por defecto. ";
static constexpr char *ERROR_FONDO_35_FALTANTE_DEFAULT = (char *) "No se encontro ruta de capa 5 de fondo 3 en config default.";
static constexpr char *ERROR_FONDO_36_FALTANTE = (char *) "No se encontro ruta de capa 6 de fondo 3 en json local, se usara una ruta por defecto. ";
static constexpr char *ERROR_FONDO_36_FALTANTE_DEFAULT = (char *) "No se encontro ruta de capa 6 de fondo 3 en config default.";
static constexpr char* ERROR_FORMATO_JSON = (char *) "Se encontró un error en el json. Línea: ";
static constexpr char* ERROR_FORMATO_JSON_2 = (char *) ". Se usará configuración por defecto.";

static constexpr char* LOG_ERROR_MODO_LOG_LOCAL = (char*) "Modo de logueo ingresado en archivo de configuracion incorrecto, se leera el modo por defecto.";
static constexpr char* LOG_ERROR_SIN_DEFAULT = (char*) "No existe archivo jason por defecto.";
static constexpr char* ERROR_FORMATO_JSON_DEFAULT = (char*) ". No se cargara informacion a partir de este error. ";

static constexpr char* LOG_ERROR_TIPO_ENEMIGO_1_INVALIDO = (char *) "El tipo de enemigo 1 ingresado en el json es invalido, tomaremos el valor por default.";
static constexpr char* LOG_ERROR_TIPO_ENEMIGO_2_INVALIDO = (char *) "El tipo de enemigo 2 ingresado en el json es invalido, tomaremos el valor por default.";
static constexpr char* LOG_ERROR_TIPO_ENEMIGO_1_INVALIDO_DEFAULT = (char *)  "El tipo de enemigo 1 en la configuracion default es invalido";
static constexpr char* LOG_ERROR_TIPO_ENEMIGO_2_INVALIDO_DEFAULT = (char *)  "El tipo de enemigo 2 en la configuracion default es invalido";

static constexpr char* LOG_JUEGO_INICIADO = (char *) "Juego iniciado.";
static constexpr char* LOG_JUEGO_FINALIZADO = (char *) "Juego finalizado.";
static constexpr char* LOG_JUEGO_CERRADO_POR_USER = (char *) "Juego cerrado por usuario";
static constexpr char* LOG_SIGUIENTE_NIVEL = (char *) "Nivel finalizado.";
static constexpr char* LOG_FIN_MENU = (char *) "Se sale del menú y se inician los niveles.";
static constexpr char* LOG_MOV_SUP_IZQ = (char *) "La nave se mueve al margen superior izquierdo.";
static constexpr char* LOG_MOV_SUP_DER = (char *) "La nave se mueve al margen superior derecho.";
static constexpr char* LOG_MOV_ABA_IZQ = (char *) "La nave se mueve al margen inferior izquierdo.";
static constexpr char* LOG_MOV_ABA_DER = (char *) "La nave se mueve al margen inferior derecho.";
static constexpr char* LOG_MOV_ARRIBA = (char *) "La nave se mueve hacia arriba.";
static constexpr char* LOG_MOV_IZQ = (char *) "La nave se mueve a la izquierda.";
static constexpr char* LOG_MOV_DER = (char *) "La nave se mueve a la derecha.";
static constexpr char* LOG_MOV_ABAJO = (char *) "La nave se mueve hacia abajo.";

static constexpr char* LOG_DISPARAR = (char *) "La nave comenzo a disparar.";
static constexpr char* LOG_NO_DISPARAR = (char *) "La nave dejo de disparar.";
static constexpr char* LOG_TECLA_PROPULSION = (char *) "La nave propulsiono.";
static constexpr char* LOG_CAMBIAR_AUDIO = (char *) "Se cambió el modo de audio.";
static constexpr char* LOG_CAMBIAR_AUDIO_SFX = (char *) "Se cambió el modo de audio sfx.";
static constexpr char* LOG_CAMBIAR_MODO_JUEGO = (char *) "Se cambió el modo de juego.";


static constexpr char* LOG_MULTIPLES_ARGS = (char *) "Se demasiados argumentos";
static constexpr char* LOG_FALTAN_PARAMETROS = (char *) "No se ingresaron suficientes argumentos";

static constexpr char* LOG_MODO_DE_LOGUEO = (char *) "El modo de logueo es: ";
static constexpr char* LOG_INICIO_JSON = (char *) "Se detalla lo leído del JSON...";
static constexpr char* LOG_PATH_E1 = (char *) "Clase de enemigo 1: ";
static constexpr char* LOG_PATH_E2 = (char *) "Clase de enemigo 2: ";
static constexpr char* LOG_CANT_E1 = (char *) "Cant. de enemigo 1: ";
static constexpr char* LOG_CANT_E2 = (char *) "Cant. de enemigo 2: ";
static constexpr char* LOG_PATH_F1C1 = (char *) "Ruta de capa 1 de fondo 1: ";
static constexpr char* LOG_PATH_F1C2 = (char *) "Ruta de capa 2 de fondo 1: ";
static constexpr char* LOG_PATH_F1C3 = (char *) "Ruta de capa 3 de fondo 1: ";
static constexpr char *LOG_PATH_F1C4 = (char *) "Ruta de capa 4 de fondo 1: ";
static constexpr char *LOG_PATH_F1C5 = (char *) "Ruta de capa 5 de fondo 1: ";
static constexpr char *LOG_PATH_F1C6 = (char *) "Ruta de capa 6 de fondo 1: ";
static constexpr char *LOG_PATH_F2C1 = (char *) "Ruta de capa 1 de fondo 2: ";
static constexpr char *LOG_PATH_F2C2 = (char *) "Ruta de capa 2 de fondo 2: ";
static constexpr char *LOG_PATH_F2C3 = (char *) "Ruta de capa 3 de fondo 2: ";
static constexpr char *LOG_PATH_F2C4 = (char *) "Ruta de capa 4 de fondo 2: ";
static constexpr char *LOG_PATH_F2C5 = (char *) "Ruta de capa 5 de fondo 2: ";
static constexpr char *LOG_PATH_F2C6 = (char *) "Ruta de capa 6 de fondo 2: ";
static constexpr char* LOG_PATH_F3C1 = (char *) "Ruta de capa 1 de fondo 3: ";
static constexpr char* LOG_PATH_F3C2 = (char *) "Ruta de capa 2 de fondo 3: ";
static constexpr char* LOG_PATH_F3C3 = (char *) "Ruta de capa 3 de fondo 3: ";
static constexpr char *LOG_PATH_F3C4 = (char *) "Ruta de capa 4 de fondo 3: ";
static constexpr char *LOG_PATH_F3C5 = (char *) "Ruta de capa 5 de fondo 3: ";
static constexpr char *LOG_PATH_F3C6 = (char *) "Ruta de capa 6 de fondo 3: ";

static constexpr char* LOG_INIT_VERBOSE = (char *) "Se detallan valores adicionales utilizados.";
static constexpr char* LOG_V_JSON_DEFAULT = (char *) "Ruta del JSON por defecto: ";
static constexpr char* LOG_V_IMG_DEFAULT = (char *) "Ruta del imagen por defecto: ";
static constexpr char* LOG_V_IMG_LOGO = (char *) "Ruta de la imagen del logo: ";
static constexpr char* LOG_V_IMG_MENU = (char *) "Ruta de la imagen del menú: ";

static constexpr char* LOG_V_IMG_LV_1 = (char *) "Ruta de la imagen del nivel 1: ";
static constexpr char* LOG_V_IMG_LV_1_FIN = (char *) "Ruta de la imagen del fin de nivel 1: ";
static constexpr char* LOG_V_IMG_LV_2 = (char *) "Ruta de la imagen del nivel 2: ";
static constexpr char* LOG_V_IMG_LV_2_FIN = (char *) "Ruta de la imagen del fin de nivel 2: ";

static constexpr char* LOG_V_IMG_ARR = (char *) "Ruta de la imagen del personaje arriba: ";
static constexpr char* LOG_V_IMG_ARR_DER = (char *) "Ruta de la imagen del personaje en diagonal sup. der.: ";
static constexpr char* LOG_V_IMG_DER = (char *) "Ruta de la imagen del personaje a la derecha: ";
static constexpr char* LOG_V_IMG_ABA_DER = (char *) "Ruta de la imagen del personaje en diagonal inf. der.: ";
static constexpr char* LOG_V_IMG_ABA = (char *) "Ruta de la imagen del personaje abajo: ";
static constexpr char* LOG_V_IMG_ABA_IZQ = (char *) "Ruta de la imagen del personaje inf. izq.: ";
static constexpr char* LOG_V_IMG_IZQ = (char *) "Ruta de la imagen del personaje izq.: ";
static constexpr char* LOG_V_IMG_ARR_IZQ = (char *) "Ruta de la imagen del personaje sup. izq.: ";

static constexpr char* LOG_V_IMG_ENEMIGO_1 = (char *) "Ruta de la imagen del enemigo 1: ";
static constexpr char* LOG_V_IMG_ENEMIGO_2 = (char *) "Ruta de la imagen del enemigo 2: ";
static constexpr char* LOG_V_ANCHO_VENT = (char *) "Ancho ventana: ";
static constexpr char* LOG_V_ALTO_VENT = (char *) "Alto ventana: ";
static constexpr char* LOG_V_X_PERSONAJE = (char *) "X personaje: ";
static constexpr char* LOG_V_Y_PERSONAJE = (char *) "Y personaje: ";
static constexpr char* LOG_V_VEL_PERSONAJE = (char *) "Velocidad de movimiento personaje: ";
static constexpr char* LOG_V_VEL_FONDO = (char *) "Velocidad de movimiento del fondo: ";
static constexpr char* LOG_INIT_CARGA = (char *) "Iniciando la carga de la configuracion";
static constexpr char* LOG_FINAL_CARGA = (char *) "Finalizada la carga de la configuracion";

static constexpr char* LOG_COLISION_ENTRE_ENEMIGOS = (char *) "Colision entre enemigos al crearlos. Pos:(";

static constexpr char* LOG_CREACION_VENTANA_JUEGO = (char *) "Se crea la ventana del juego.";
static constexpr char* LOG_CARGANDO_ICONO = (char *) "Se esta cargando el icono del juego...";
static constexpr char* LOG_CARGANDO_IMAGEN_RUTA = (char *) "Se esta cargando la imagen de la ruta: ";
static constexpr char* LOG_IMAGEN = (char *) "La imagen se cargo exitosamente.";
static constexpr char* LOG_IMAGEN_DEFECTO = (char *) "La imagen en la ruta pedida no pudo ser encontrada, se usara la imagen por defecto en su lugar.";
static constexpr char* LOG_ICONO = (char *) "La imagen del icono se cargo exitosamente.";
static constexpr char* LOG_ICONO_DEFECTO = (char *) "No se encontro la imagen del icono, se cargo la imagen por defecto en su lugar.";
static constexpr char* LOG_CARTEL_STAGE_1 = (char *) "Aparece el cartel de inicio del nivel 1( STAGE 1 ).";
static constexpr char* LOG_CARTEL_STAGE_1_FIN = (char *) "Se sale del cartel de inicio del nivel 1.";
static constexpr char* LOG_CARTEL_FIN_STAGE_1 = (char *) "Aparece el cartel de fin del nivel 1( STAGE 1 CLEARED ).";
static constexpr char* LOG_CARTEL_FIN_STAGE_1_FIN = (char *) "Se sale del cartel de fin del nivel 1.";
static constexpr char* LOG_CARTEL_STAGE_2 = (char *) "Aparece el cartel de inicio del nivel 2( STAGE 2 ).";
static constexpr char* LOG_CARTEL_STAGE_2_FIN = (char *) "Se sale del cartel de inicio del nivel 2.";
static constexpr char* LOG_CARTEL_FIN_STAGE_2 = (char *) "Aparece el cartel de fin del nivel 2( STAGE 2 CLEARED ).";
static constexpr char* LOG_CARTEL_FIN_STAGE_2_FIN = (char *) "Se sale del cartel de fin del nivel 2.";

static constexpr char* LOG_NRO_JUGADOR = (char *) "Número de jugador: ";
static constexpr char* LOG_INICIO_ENVIO_NOMBRE = (char *) "Empezando a enviar el nombre... ";
static constexpr char* LOG_FIN_ENVIO_NOMBRE = (char *) "Fin del a envío del nombre.";
static constexpr char* LOG_ERROR_ENVIAR = (char *) "Error en el enviar.";
static constexpr char* LOG_ERROR_RECIBIR = (char *) "Error en el recibir.";

static constexpr char* LOG_MSJ_FD = (char *) "El fd de la conexion es: ";
static constexpr char* LOG_INTENTO_CONEXION_PUERTO = (char *) "Intento de conexion con puerto: ";
static constexpr char* LOG_ERROR_DATOS_INVALIDOS = (char *) "Datos inválidos de conexión.";
static constexpr char* LOG_ERROR_CONEXION_CLIENTE = (char *) "Error en la conexión del cliente.";

static constexpr char* LOG_FALLA_MIXER = (char *) "Error al intentar abrir Mixer.";

static constexpr char* LOG_ENEMIGO_MUERE = (char *) "Se destruyó a un enemigo.";
static constexpr char* LOG_JEFE_MUERE = (char *) "Se destruyó al jefe del nivel.";
static constexpr char* LOG_PERSONAJE_MUERE = (char *) "Se destruyó una nave.";

static std::map<int, char *> msj_log = {
        {LOG_ERROR, MSJ_LOG_ERROR},
        {LOG_INFO,  MSJ_LOG_INFO},
        {LOG_DEBUG, MSJ_LOG_DEBUG}
};

/* Esto en python no pasa!!!
 * Hay que pasarle al map una forma de comparar las claves
 * para que cadenas similares se mapeen igual. */
struct metodoDeComparacion {
    bool operator()(const char *s1, const char *s2) const {
        return std::strcmp(s1, s2) < 0;
    }
};

static std::map<char*, int, metodoDeComparacion> tipos_log = {
        {MSJ_LOG_ERROR, LOG_ERROR},
        {MSJ_LOG_INFO,  LOG_INFO},
        {MSJ_LOG_DEBUG, LOG_DEBUG}
};

#endif //CLIENTE_CONSTANTESLOG_H
