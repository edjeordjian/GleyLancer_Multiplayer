#ifndef PRIMERAENTREGA_CARGADORDECONFIGURACION_H
#define PRIMERAENTREGA_CARGADORDECONFIGURACION_H

#include <jsoncpp/json/json.h>
#include "Log.h"
#include <string>
#include "Utils.h"
#include "ConstantesComunicacion.h"
#include "ConstantesLog.h"
#include "ConstantesJson.h"
#include "ConstantesMenu.h"


class CargadorDeConfiguracion {

public:
    void cargar(int argc, const char* argv[]);

    static void manejoDeSet(char *valor_res, char *valor_default, bool arch_default ,
                            void(*funcion_set)(std::string), bool(*funcion_verificar)(char*), char* ERROR_CASO_RES, char* ERROR_CASO_DEFAULT);

};


#endif //PRIMERAENTREGA_CARGADORDECONFIGURACION_H
