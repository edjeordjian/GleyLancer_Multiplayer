#include "ConstantesJson.h"

static std::string RUTA_CONFIG;

void setRutaConfig(std::string ruta){
    RUTA_CONFIG = ruta;
}

char* getRutaConfig(){
    return (char*) RUTA_CONFIG.c_str();
}