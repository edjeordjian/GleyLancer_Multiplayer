#include "Log.h"

static std::string NOMBRE_LOG;
static int TIPO_LOG;

void setNombreLog() {
    NOMBRE_LOG = timestampParaNombreLog(RUTA_LOG) + EXTENSION_LOG;
}

std::string getNombreLog() {
    return NOMBRE_LOG;
}

bool setTipoLog(int tipo){
    TIPO_LOG = tipo;

    if(TIPO_LOG > LOG_DEBUG || TIPO_LOG < LOG_ERROR){
        TIPO_LOG = LOG_DEBUG;
        return false;
    }

    return true;
}

int getTipoLog(){
    return TIPO_LOG;
}

void setNombreLogAux() {
    NOMBRE_LOG = timestampParaNombreLog(RUTA_LOG_AUX) + EXTENSION_LOG;
}

bool loguearInfo(std::string msj_info) {
    return loguear(msj_info, LOG_INFO);
}

bool loguearDebug(std::string msj_debug) {
    return loguear(msj_debug, LOG_DEBUG);
}

bool loguearError(std::string msj_error) {
    return loguear(msj_error, LOG_ERROR);
}

bool loguear(std::string info, int tipo) {
    if (tipo > getTipoLog()) {
        return false;
    }

    std::ofstream archivo_log;
    /*std::ios_base::app --> agregar en vez de sobreescribir*/
    archivo_log.open(getNombreLog(), std::ios_base::app);

    archivo_log.is_open();
    archivo_log << timestampParaLog(msj_log[tipo]);
    archivo_log << info;
    archivo_log << "\n";
    archivo_log.close();

    return true;
}

bool logExiste(std::string ruta) {
    bool existe = true;
    std::ofstream archivo;
    archivo.open(ruta, std::ios_base::app);

    if (!archivo.is_open() ){
        existe = false;
    }

    archivo.close();
    return existe;
}

