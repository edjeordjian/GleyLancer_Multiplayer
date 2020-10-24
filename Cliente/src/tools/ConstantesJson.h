#ifndef CLIENTE_CONSTANTESJSON_H
#define CLIENTE_CONSTANTESJSON_H

#include "string"

/// JSON ///
static std::string RUTA_CONFIG_DEFAULT = "../data/config_default.json";

void setRutaConfig(std::string ruta);

char *getRutaConfig();

#endif //CLIENTE_CONSTANTESJSON_H
