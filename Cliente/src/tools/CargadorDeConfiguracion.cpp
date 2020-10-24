#include "CargadorDeConfiguracion.h"

void CargadorDeConfiguracion::cargar(int argc, const char* argv[]) {

    int tipo_log = -1;
    bool flag_log_valida = true;
    std::string modo_log;
    std::string ruta_config = "";
    std::string ip = "";
    std::string puerto = "";

    setIP(IP_DEFECTO);
    setPuerto(PUERTO_DEFECTO);

    // Manejo de llamada por linea de comando
    if (argc > 1) {
        setRutaConfig(ruta_config);
        for (int i = 1; i < argc; ++i) {
            std::string argumento = argv[i];
            if (argumento == FLAG_LOG) {
                if (i + 1 < argc) {
                    modo_log = argv[i + 1];
                    // Para que acepte parámetros en minúscula
                    std::transform(modo_log.begin(), modo_log.end(), modo_log.begin(), toupper);
                    tipo_log = tipos_log[(char *) modo_log.c_str()];
                } else
                    flag_log_valida = false;

            } else if (argumento == FLAG_RUTA_CONFIG) {
                if (i + 1 < argc) {
                    ruta_config = argv[i + 1];
                    setRutaConfig(ruta_config);
                }

            } else if (argumento == FLAG_IP) {
                if (i + 1 < argc) {
                    ip = argv[i + 1];
                    setIP(ip);
                }
            } else if (argumento == FLAG_PUERTO){
                if (i + 1 < argc) {
                    puerto = argv[i + 1];
                    setPuerto(puerto);
                }
            }
        }
    }

    Json::Value json_res;
    std::ifstream ifs(getRutaConfig());
    Json::CharReaderBuilder builder;
    builder["collectComments"] = true;
    JSONCPP_STRING errs, errs_default;

    bool archivo_local = true;

    /* Abrimos el config original en caso de que haya valores erroneos en el enviado por el usuario */
    Json::Value json_default;
    std::ifstream ifs_default(RUTA_CONFIG_DEFAULT.c_str());
    bool archivo_config_default_valido = true;

    bool error_de_formato_json_defualt = false;
    std::string linea_de_error_en_json_default = "";

    if (!parseFromStream(builder, ifs_default, &json_default, &errs_default)) {
        if (!errs_default.empty()) {
            error_de_formato_json_defualt = true;
            linea_de_error_en_json_default = obtenerLineaDeError(errs_default);
        }
        archivo_config_default_valido = false;
    }

    bool error_de_formato_json = false;
    std::string linea_de_error_en_json_custom = " ";
    if (!parseFromStream(builder, ifs, &json_res, &errs)) {
        ifs.close();

        if (!errs.empty()) {
            error_de_formato_json = true;
            linea_de_error_en_json_custom = obtenerLineaDeError(errs);
        }

        archivo_local = false;

        ifs.open(RUTA_CONFIG_DEFAULT.c_str());
        parseFromStream(builder, ifs, &json_res, &errs);
    }

    // Se aceptan minúsculas en el tipo de logueo del archivo de configuración
    std::string log_config = json_res["configuration"]["log"]["level"].asString().c_str();
    std::transform(log_config.begin(), log_config.end(), log_config.begin(), toupper);
    char *tipo_log_config = (char *) log_config.c_str();

    int log_level = tipos_log[tipo_log_config];

    bool paramConsola = false;
    /* Si se pasó un tipo de parámetro válido por consola para el LOG, darle preponderancia por sobre el archivo. */
    if (tipo_log > 0) {
        log_level = tipo_log;
        paramConsola = true;
    }

    setNombreLog();
    bool nombreCorrecto = true;

    if (!logExiste(getNombreLog())) {
        setNombreLogAux();
        nombreCorrecto = false;
    }

    bool valido_tipo_log = setTipoLog(log_level);

    if (tipo_log == 0) {
        loguearError(ERROR_PARAMETRO_POR_CONSOLA_INVALIDO);
    }

    if (argc > ARGC_MAX_CANTIDAD_PARAMETROS)
        loguearInfo(LOG_MULTIPLES_ARGS);

    if (argc < ARGC_MIN_CANTIDAD_PARAMETROS && !flag_log_valida)
        loguearError(LOG_FALTAN_PARAMETROS);

    /*Este caso es cuando ya se esta leyendo de l archivo de configuracion.*/
    if (!valido_tipo_log) {

        loguearError(LOG_ERROR_MODO_LOG_LOCAL);

        // Se aceptan minúsculas en el tipo de logueo del archivo de configuración
        std::string log_default = json_default["configuration"]["log"]["level"].asString().c_str();
        std::transform(log_default.begin(), log_default.end(), log_default.begin(), toupper);
        char *tipo_log_default = (char *) log_default.c_str();

        log_level = tipos_log[tipo_log_default];

        if (!setTipoLog(log_level)) {
            loguearError(ERROR_SETEO_LOG);
        } else {
            loguearInfo(LOG_MODO_DEFAULT_CORRECTO);
        }
    }

    // Avisar que no se puede loguear en la carpeta log
    if (!nombreCorrecto) {
        loguearError(ERROR_LOG);
    }

    // Avisar que se utiliza el loggin por consola
    if (paramConsola) {
        loguearInfo(LOG_COMANDO_CONSOLA);
        loguearInfo(LOG_MODO_DE_LOGUEO + std::string(msj_log[getTipoLog()]));
    } else
        loguearInfo(LOG_MODO_DE_LOGUEO + std::string(msj_log[getTipoLog()]));

    loguearInfo(LOG_INIT_CARGA);

    if (ruta_config != "") {
        loguearInfo(LOG_CONFIG_PARAMETROS);
        if (!archivo_local && error_de_formato_json) {
            if (linea_de_error_en_json_custom == " 1") loguearError(LOG_NO_LOC_JSON);
            else loguearError(ERROR_FORMATO_JSON + linea_de_error_en_json_custom + ERROR_FORMATO_JSON_2);
        }
    } else {
        loguearInfo(LOG_CONFIG_SIN_PARAMETROS);
        loguearInfo(LOG_LOC_JSON_DEFAULT);
    }

    if (!archivo_config_default_valido) {
        if (linea_de_error_en_json_default == " 1" && error_de_formato_json_defualt){
            loguearError(LOG_ERROR_SIN_DEFAULT);
        } else {
            loguearError(ERROR_FALLA_DE_CARGA_JSON_DEFAULT);
            loguearError(ERROR_FORMATO_JSON + linea_de_error_en_json_default + ERROR_FORMATO_JSON_DEFAULT);
        }
    }

    loguearInfo(LOG_INICIO_JSON);


    bool (*verificadorTipoEnemigo)(char*);
    verificadorTipoEnemigo = &tipoEnemigoValido;

    /*
     * Seteo por default los tamaños y tipos de enemigo, se pisaran por los cargados por json o default si son validos
     */
    setTipoEnemigo1("default");
    setTipoEnemigo2("default");

    void (*setter_tipo_enemigo_1)(std::string);
    setter_tipo_enemigo_1 = &setTipoEnemigo1;
    manejoDeSet(const_cast<char *>(json_res["configuration"]["game"]["enemies"][0]["type"].asString().c_str()),
                const_cast<char *>(json_default["configuration"]["game"]["enemies"][0]["type"].asString().c_str()),
                archivo_local,
                setter_tipo_enemigo_1,
                verificadorTipoEnemigo,
                LOG_ERROR_TIPO_ENEMIGO_1_INVALIDO,
                LOG_ERROR_TIPO_ENEMIGO_1_INVALIDO_DEFAULT);

    void (*setter_tipo_enemigo_2)(std::string);
    setter_tipo_enemigo_2 = &setTipoEnemigo2;
    manejoDeSet(const_cast<char *>(json_res["configuration"]["game"]["enemies"][1]["type"].asString().c_str()),
                const_cast<char *>(json_default["configuration"]["game"]["enemies"][1]["type"].asString().c_str()),
                archivo_local,
                setter_tipo_enemigo_2,
                verificadorTipoEnemigo,
                LOG_ERROR_TIPO_ENEMIGO_2_INVALIDO,
                LOG_ERROR_TIPO_ENEMIGO_2_INVALIDO_DEFAULT);

    bool (*verificador_ruta)(char*);
    verificador_ruta = &existeArchivo;

    void (*setter_fondo_11)(std::string);
    setter_fondo_11 = &setRutaFondo11;
    manejoDeSet(const_cast<char *>(json_res["configuration"]["game"]["stages"][0]["fondo1"].asString().c_str()),
                const_cast<char *>(json_default["configuration"]["game"]["stages"][0]["fondo1"].asString().c_str()),
                archivo_local,
                setter_fondo_11,
                verificador_ruta,
                ERROR_FONDO_11_FALTANTE,
                ERROR_FONDO_11_FALTANTE_DEFAULT);

    void (*setter_fondo_12)(std::string);
    setter_fondo_12 = &setRutaFondo12;
    manejoDeSet(const_cast<char *>(json_res["configuration"]["game"]["stages"][0]["fondo2"].asString().c_str()),
                const_cast<char *>(json_default["configuration"]["game"]["stages"][0]["fondo2"].asString().c_str()),
                archivo_local,
                setter_fondo_12,
                verificador_ruta,
                ERROR_FONDO_12_FALTANTE,
                ERROR_FONDO_12_FALTANTE_DEFAULT);

    void (*setter_fondo_13)(std::string);
    setter_fondo_13 = &setRutaFondo13;
    manejoDeSet(const_cast<char *>(json_res["configuration"]["game"]["stages"][0]["fondo3"].asString().c_str()),
                const_cast<char *>(json_default["configuration"]["game"]["stages"][0]["fondo3"].asString().c_str()),
                archivo_local,
                setter_fondo_13,
                verificador_ruta,
                ERROR_FONDO_13_FALTANTE,
                ERROR_FONDO_13_FALTANTE_DEFAULT);

    void (*setter_fondo_14)(std::string);
    setter_fondo_14 = &setRutaFondo14;
    manejoDeSet(const_cast<char *>(json_res["configuration"]["game"]["stages"][0]["fondo4"].asString().c_str()),
                const_cast<char *>(json_default["configuration"]["game"]["stages"][0]["fondo4"].asString().c_str()),
                archivo_local,
                setter_fondo_14,
                verificador_ruta,
                ERROR_FONDO_14_FALTANTE,
                ERROR_FONDO_14_FALTANTE_DEFAULT);

    void (*setter_fondo_15)(std::string);
    setter_fondo_15 = &setRutaFondo15;
    manejoDeSet(const_cast<char *>(json_res["configuration"]["game"]["stages"][0]["fondo5"].asString().c_str()),
                const_cast<char *>(json_default["configuration"]["game"]["stages"][0]["fondo5"].asString().c_str()),
                archivo_local,
                setter_fondo_15,
                verificador_ruta,
                ERROR_FONDO_15_FALTANTE,
                ERROR_FONDO_15_FALTANTE_DEFAULT);

    void (*setter_fondo_16)(std::string);
    setter_fondo_16 = &setRutaFondo16;
    manejoDeSet(const_cast<char *>(json_res["configuration"]["game"]["stages"][0]["fondo6"].asString().c_str()),
                const_cast<char *>(json_default["configuration"]["game"]["stages"][0]["fondo6"].asString().c_str()),
                archivo_local,
                setter_fondo_16,
                verificador_ruta,
                ERROR_FONDO_16_FALTANTE,
                ERROR_FONDO_16_FALTANTE_DEFAULT);

    void (*setter_fondo_21)(std::string);
    setter_fondo_21 = &setRutaFondo21;
    manejoDeSet(const_cast<char *>(json_res["configuration"]["game"]["stages"][1]["fondo1"].asString().c_str()),
                const_cast<char *>(json_default["configuration"]["game"]["stages"][1]["fondo1"].asString().c_str()),
                archivo_local,
                setter_fondo_21,
                verificador_ruta,
                ERROR_FONDO_21_FALTANTE,
                ERROR_FONDO_21_FALTANTE_DEFAULT);

    void (*setter_fondo_22)(std::string);
    setter_fondo_22 = &setRutaFondo22;
    manejoDeSet(const_cast<char *>(json_res["configuration"]["game"]["stages"][1]["fondo2"].asString().c_str()),
                const_cast<char *>(json_default["configuration"]["game"]["stages"][1]["fondo2"].asString().c_str()),
                archivo_local,
                setter_fondo_22,
                verificador_ruta,
                ERROR_FONDO_22_FALTANTE,
                ERROR_FONDO_22_FALTANTE_DEFAULT);

    void (*setter_fondo_23)(std::string);
    setter_fondo_23 = &setRutaFondo23;
    manejoDeSet(const_cast<char *>(json_res["configuration"]["game"]["stages"][1]["fondo3"].asString().c_str()),
                const_cast<char *>(json_default["configuration"]["game"]["stages"][1]["fondo3"].asString().c_str()),
                archivo_local,
                setter_fondo_23,
                verificador_ruta,
                ERROR_FONDO_23_FALTANTE,
                ERROR_FONDO_23_FALTANTE_DEFAULT);

    void (*setter_fondo_24)(std::string);
    setter_fondo_24 = &setRutaFondo24;
    manejoDeSet(const_cast<char *>(json_res["configuration"]["game"]["stages"][1]["fondo4"].asString().c_str()),
                const_cast<char *>(json_default["configuration"]["game"]["stages"][1]["fondo4"].asString().c_str()),
                archivo_local,
                setter_fondo_24,
                verificador_ruta,
                ERROR_FONDO_24_FALTANTE,
                ERROR_FONDO_24_FALTANTE_DEFAULT);

    void (*setter_fondo_25)(std::string);
    setter_fondo_25 = &setRutaFondo25;
    manejoDeSet(const_cast<char *>(json_res["configuration"]["game"]["stages"][1]["fondo5"].asString().c_str()),
                const_cast<char *>(json_default["configuration"]["game"]["stages"][1]["fondo5"].asString().c_str()),
                archivo_local,
                setter_fondo_25,
                verificador_ruta,
                ERROR_FONDO_25_FALTANTE,
                ERROR_FONDO_25_FALTANTE_DEFAULT);


    void (*setter_fondo_26)(std::string);
    setter_fondo_26 = &setRutaFondo26;
    manejoDeSet(const_cast<char *>(json_res["configuration"]["game"]["stages"][1]["fondo6"].asString().c_str()),
                const_cast<char *>(json_default["configuration"]["game"]["stages"][1]["fondo6"].asString().c_str()),
                archivo_local, setter_fondo_26, verificador_ruta,
                ERROR_FONDO_26_FALTANTE,
                ERROR_FONDO_26_FALTANTE_DEFAULT);

    void (*setter_fondo_31)(std::string);
    setter_fondo_31 = &setRutaFondo31;
    manejoDeSet(const_cast<char *>(json_res["configuration"]["game"]["stages"][2]["fondo1"].asString().c_str()),
                const_cast<char *>(json_default["configuration"]["game"]["stages"][2]["fondo1"].asString().c_str()),
                archivo_local,
                setter_fondo_31,
                verificador_ruta,
                ERROR_FONDO_31_FALTANTE,
                ERROR_FONDO_31_FALTANTE_DEFAULT);

    void (*setter_fondo_32)(std::string);
    setter_fondo_32 = &setRutaFondo32;
    manejoDeSet(const_cast<char *>(json_res["configuration"]["game"]["stages"][2]["fondo2"].asString().c_str()),
                const_cast<char *>(json_default["configuration"]["game"]["stages"][2]["fondo2"].asString().c_str()),
                archivo_local,
                setter_fondo_32,
                verificador_ruta,
                ERROR_FONDO_32_FALTANTE,
                ERROR_FONDO_32_FALTANTE_DEFAULT);

    void (*setter_fondo_33)(std::string);
    setter_fondo_33 = &setRutaFondo33;
    manejoDeSet(const_cast<char *>(json_res["configuration"]["game"]["stages"][2]["fondo3"].asString().c_str()),
                const_cast<char *>(json_default["configuration"]["game"]["stages"][2]["fondo3"].asString().c_str()),
                archivo_local,
                setter_fondo_33,
                verificador_ruta,
                ERROR_FONDO_33_FALTANTE,
                ERROR_FONDO_33_FALTANTE_DEFAULT);

    void (*setter_fondo_34)(std::string);
    setter_fondo_34 = &setRutaFondo34;
    manejoDeSet(const_cast<char *>(json_res["configuration"]["game"]["stages"][2]["fondo4"].asString().c_str()),
                const_cast<char *>(json_default["configuration"]["game"]["stages"][2]["fondo4"].asString().c_str()),
                archivo_local,
                setter_fondo_34,
                verificador_ruta,
                ERROR_FONDO_34_FALTANTE,
                ERROR_FONDO_34_FALTANTE_DEFAULT);

    void (*setter_fondo_35)(std::string);
    setter_fondo_35 = &setRutaFondo35;
    manejoDeSet(const_cast<char *>(json_res["configuration"]["game"]["stages"][2]["fondo5"].asString().c_str()),
                const_cast<char *>(json_default["configuration"]["game"]["stages"][2]["fondo5"].asString().c_str()),
                archivo_local,
                setter_fondo_35,
                verificador_ruta,
                ERROR_FONDO_35_FALTANTE,
                ERROR_FONDO_35_FALTANTE_DEFAULT);

    void (*setter_fondo_36)(std::string);
    setter_fondo_36 = &setRutaFondo36;
    manejoDeSet(const_cast<char *>(json_res["configuration"]["game"]["stages"][2]["fondo6"].asString().c_str()),
                const_cast<char *>(json_default["configuration"]["game"]["stages"][2]["fondo6"].asString().c_str()),
                archivo_local,
                setter_fondo_36,
                verificador_ruta,
                ERROR_FONDO_36_FALTANTE,
                ERROR_FONDO_36_FALTANTE_DEFAULT);



    ifs.close();
    ifs_default.close();

    loguearInfo(LOG_PATH_E1 + std::string(getTipoEnemigo1()));
    loguearInfo(LOG_PATH_E2 + std::string(getTipoEnemigo2()));

    loguearInfo(LOG_PATH_F1C1 + std::string(getRutaFondo11()));
    loguearInfo(LOG_PATH_F1C2 + std::string(getRutaFondo12()));
    loguearInfo(LOG_PATH_F1C3 + std::string(getRutaFondo13()));
    loguearInfo(LOG_PATH_F1C4 + std::string(getRutaFondo14()));
    loguearInfo(LOG_PATH_F1C5 + std::string(getRutaFondo15()));
    loguearInfo(LOG_PATH_F1C6 + std::string(getRutaFondo16()));
    loguearInfo(LOG_PATH_F2C1 + std::string(getRutaFondo21()));
    loguearInfo(LOG_PATH_F2C2 + std::string(getRutaFondo22()));
    loguearInfo(LOG_PATH_F2C3 + std::string(getRutaFondo23()));
    loguearInfo(LOG_PATH_F2C4 + std::string(getRutaFondo24()));
    loguearInfo(LOG_PATH_F2C5 + std::string(getRutaFondo25()));
    loguearInfo(LOG_PATH_F2C6 + std::string(getRutaFondo26()));
    loguearInfo(LOG_PATH_F3C1 + std::string(getRutaFondo31()));
    loguearInfo(LOG_PATH_F3C2 + std::string(getRutaFondo32()));
    loguearInfo(LOG_PATH_F3C3 + std::string(getRutaFondo33()));
    loguearInfo(LOG_PATH_F3C4 + std::string(getRutaFondo34()));
    loguearInfo(LOG_PATH_F3C5 + std::string(getRutaFondo35()));
    loguearInfo(LOG_PATH_F3C6 + std::string(getRutaFondo36()));

    loguearInfo(LOG_FINAL_CARGA);

    loguearDebug( LOG_DEF_CON);
    loguearDebug(IP_DEFECTO);
    loguearDebug(PUERTO_DEFECTO);
}

void CargadorDeConfiguracion::manejoDeSet(char *valor_res, char *valor_default, bool arch_local ,
                                          void(*funcion_set)(std::string), bool(*funcion_verificar)(char*), char* ERROR_CASO_RES, char* ERROR_CASO_DEFAULT){
    //Caso valor en res valido
    if (arch_local){
        if(funcion_verificar(valor_res)){
            funcion_set(valor_res);
            return;
        }
        else
            loguearError(ERROR_CASO_RES);
    }
    //Caso res invalido, vemos que pasa con el default
    if(funcion_verificar(valor_default)) {
        funcion_set(valor_default);
    }
        //Caso ambos invalidos
    else {
        loguearError(ERROR_CASO_DEFAULT);
    }
}
