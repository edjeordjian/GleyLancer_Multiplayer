#include "CargadorDeConfiguracion.h"

void CargadorDeConfiguracion::cargar(int argc, char *argv[]) {
    int tipo_log = -1;
    bool flag_log_valida = true;
    bool flag_puerto_valida = true;
    std::string modo_log;
    std::string ruta_config = "";
    std::string puerto_cli = "";

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
            }
            else if(argumento == FLAG_PUERTO) {
                if(i+1 < argc) {
                    puerto_cli = std::string(argv[i+1]);
                    if (std::strtol(puerto_cli.c_str(), NULL, 10) > 1024 and std::strtol(puerto_cli.c_str(),  NULL, 10) < 65536) {
                        setPuerto(puerto_cli);
                    }else
                        flag_puerto_valida = false;
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

    if (!valido_tipo_log) {
        loguearError(ERROR_SETEO_LOG);
    }

    if (!flag_puerto_valida){
        loguearError(LOG_PUERTO_CONSOLA_INVALIDO);
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
        loguearInfo(LOG_NO_LOC_JSON);
    }

    if (!archivo_config_default_valido) {
        loguearInfo(ERROR_FALLA_DE_CARGA_JSON_DEFAULT);
        if (error_de_formato_json_defualt) {
            loguearError(ERROR_FORMATO_JSON + linea_de_error_en_json_default + ERROR_FORMATO_JSON_2);
        }
    }


    loguearInfo(LOG_INICIO_JSON);

    if (!archivo_config_default_valido)
        loguearError(ERROR_FALLA_DE_CARGA_JSON_DEFAULT);

    bool (*verificadorTipoEnemigo)(char *);
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


    int cantEnemigo1_1 = atoi(
            (char *) (json_res["configuration"]["game"]["enemies"][0]["quantity_1"].asString().c_str()));
    int cantEnemigo1_2 = atoi(
            (char *) (json_res["configuration"]["game"]["enemies"][0]["quantity_2"].asString().c_str()));
    int cantEnemigo1_3 =  atoi(
            (char*) (json_res["configuration"]["game"]["enemies"][0]["quantity_3"].asString().c_str()));
    int cantEnemigo2_1 = atoi(
            (char *) (json_res["configuration"]["game"]["enemies"][1]["quantity_1"].asString().c_str()));
    int cantEnemigo2_2 = atoi(
            (char *) (json_res["configuration"]["game"]["enemies"][1]["quantity_2"].asString().c_str()));
    int cantEnemigo2_3 =  atoi(
            (char*) (json_res["configuration"]["game"]["enemies"][1]["quantity_3"].asString().c_str()));

    bool (*verificador_numero)(char *);
    verificador_numero = &numeroValido;

    void (*setter_cant_enemigos_1)(std::string);
    setter_cant_enemigos_1 = &setCantEnemigo1Nivel1;
    manejoDeSet(const_cast<char *>(json_res["configuration"]["game"]["enemies"][0]["quantity_1"].asString().c_str()),
                const_cast<char *>(json_default["configuration"]["game"]["enemies"][0]["quantity_1"].asString().c_str()),
                archivo_local,
                setter_cant_enemigos_1,
                verificador_numero,
                LOG_ERROR_NUMERO_ENEMIGOS_1_1_INVALIDO,
                LOG_ERROR_NUMERO_ENEMIGOS_1_1_INVALIDO_DEFAULT);

    setter_cant_enemigos_1 = &setCantEnemigo1Nivel2;
    manejoDeSet(const_cast<char *>(json_res["configuration"]["game"]["enemies"][0]["quantity_2"].asString().c_str()),
                const_cast<char *>(json_default["configuration"]["game"]["enemies"][0]["quantity_2"].asString().c_str()),
                archivo_local,
                setter_cant_enemigos_1,
                verificador_numero,
                LOG_ERROR_NUMERO_ENEMIGOS_1_2_INVALIDO,
                LOG_ERROR_NUMERO_ENEMIGOS_1_2_INVALIDO_DEFAULT);

    setter_cant_enemigos_1 = &setCantEnemigo1Nivel3;
    manejoDeSet(const_cast<char *>(json_res["configuration"]["game"]["enemies"][0]["quantity_3"].asString().c_str()),
                const_cast<char *>(json_default["configuration"]["game"]["enemies"][0]["quantity_3"].asString().c_str()),
                archivo_local,
                setter_cant_enemigos_1,
                verificador_numero,
                LOG_ERROR_NUMERO_ENEMIGOS_1_3_INVALIDO,
                LOG_ERROR_NUMERO_ENEMIGOS_1_3_INVALIDO_DEFAULT);



    void (*setter_cant_enemigos_2)(std::string);
    setter_cant_enemigos_2 = &setCantEnemigo2Nivel1;
    manejoDeSet(const_cast<char *>(json_res["configuration"]["game"]["enemies"][1]["quantity_1"].asString().c_str()),
                const_cast<char *>(json_default["configuration"]["game"]["enemies"][1]["quantity_1"].asString().c_str()),
                archivo_local,
                setter_cant_enemigos_2,
                verificador_numero,
                LOG_ERROR_NUMERO_ENEMIGOS_2_1_INVALIDO,
                LOG_ERROR_NUMERO_ENEMIGOS_2_1_INVALIDO_DEFAULT);

    setter_cant_enemigos_2 = &setCantEnemigo2Nivel2;
    manejoDeSet(const_cast<char *>(json_res["configuration"]["game"]["enemies"][1]["quantity_2"].asString().c_str()),
                const_cast<char *>(json_default["configuration"]["game"]["enemies"][1]["quantity_2"].asString().c_str()),
                archivo_local,
                setter_cant_enemigos_2,
                verificador_numero,
                LOG_ERROR_NUMERO_ENEMIGOS_2_2_INVALIDO,
                LOG_ERROR_NUMERO_ENEMIGOS_2_2_INVALIDO_DEFAULT);

    setter_cant_enemigos_2 = &setCantEnemigo2Nivel3;
    manejoDeSet(const_cast<char *>(json_res["configuration"]["game"]["enemies"][1]["quantity_3"].asString().c_str()),
                const_cast<char *>(json_default["configuration"]["game"]["enemies"][1]["quantity_3"].asString().c_str()),
                archivo_local,
                setter_cant_enemigos_2,
                verificador_numero,
                LOG_ERROR_NUMERO_ENEMIGOS_2_3_INVALIDO,
                LOG_ERROR_NUMERO_ENEMIGOS_2_3_INVALIDO_DEFAULT);



    void (*setter_usuario)(std::string);
    setter_usuario = &agregarNombreUsuario;

    void (*setter_pass)(std::string);
    setter_pass = &agregarPass;

    bool (*verificador_pass)(char *);
    verificador_pass = &verificadorPass;

    bool (*verificador_usuario)(char *);
    verificador_usuario = &verificadorUsuario;

    int cant_usuarios = 0;
    int iter_usuarios = 0;
    const Json::Value &users = json_res["configuration"]["game"]["users"]; // array of users

    while (iter_usuarios < (int)users.size()){
        std::string nombre_usuario = json_res["configuration"]["game"]["users"][iter_usuarios]["username"].asString();
        std::string pass = json_res["configuration"]["game"]["users"][iter_usuarios]["password"].asString();

        if (verificador_usuario((char*)nombre_usuario.c_str()) and verificador_pass((char*)pass.c_str())) {
            manejoDeSet((char*)nombre_usuario.c_str(),
                        nullptr,
                        true,
                        setter_usuario,
                        verificador_usuario,
                        LOG_ERROR_USUARIO_INVALIDO,
                        LOG_ERROR_USUARIO_INVALIDO_DEFAULT);

            manejoDeSet((char*)pass.c_str(),
                        nullptr,
                        true,
                        setter_pass,
                        verificador_pass,
                        LOG_ERROR_PASS_INVALIDO,
                        LOG_ERROR_PASS_INVALIDO_DEFAULT);

            cant_usuarios++;
            loguearInfo(LOG_NOMBRE_USUARIO + std::string(nombre_usuario));
        }
        ++iter_usuarios;
    }

    if (cant_usuarios == 0) {
        loguearError(ERROR_USUARIOS_JSON_LOCAL);
        char *nombre_usuario_default = const_cast<char *> (json_default["configuration"]["game"]["users"][0]["username"].asString().c_str());
        char *pass_default = const_cast<char *> (json_default["configuration"]["game"]["users"][0]["password"].asString().c_str());
        manejoDeSet(nullptr,
                    nombre_usuario_default,
                    false,
                    setter_usuario,
                    verificador_usuario,
                    LOG_ERROR_USUARIO_INVALIDO_DEFAULT,
                    LOG_ERROR_USUARIO_INVALIDO_DEFAULT);

        manejoDeSet(nullptr,
                    pass_default,
                    false,
                    setter_pass,
                    verificador_pass,
                    LOG_ERROR_PASS_INVALIDO_DEFAULT,
                    LOG_ERROR_PASS_INVALIDO_DEFAULT);
    }

    ifs.close();
    ifs_default.close();

    // Log y aplicamos la correccion
    if (this->corregirCantidadEnemigos(&cantEnemigo1_1, &cantEnemigo2_1)) {
        loguearError(LOG_ERROR_SUPERADA_CANTIDAD_MAXIMA_ENEMIGOS_1);
        setCantEnemigo1Nivel1(std::to_string(cantEnemigo1_1));
        setCantEnemigo2Nivel1(std::to_string(cantEnemigo2_1));
    }


    if (this->corregirCantidadEnemigos(&cantEnemigo1_2, &cantEnemigo2_2)) {
        loguearError(LOG_ERROR_SUPERADA_CANTIDAD_MAXIMA_ENEMIGOS_2);
        setCantEnemigo1Nivel2(std::to_string(cantEnemigo1_2));
        setCantEnemigo2Nivel2(std::to_string(cantEnemigo2_2));
    }

    if (this->corregirCantidadEnemigos(&cantEnemigo1_3, &cantEnemigo2_3)) {
        loguearError(LOG_ERROR_SUPERADA_CANTIDAD_MAXIMA_ENEMIGOS_3);
        setCantEnemigo1Nivel2(std::to_string(cantEnemigo1_3));
        setCantEnemigo2Nivel2(std::to_string(cantEnemigo2_3));
    }

    loguearInfo(LOG_PATH_E1 + std::string(getTipoEnemigo1()));
    loguearInfo(LOG_CANT_E1_1 + std::to_string(getCantEnemigo1Nivel1()));
    loguearInfo(LOG_CANT_E1_2 + std::to_string(getCantEnemigo1Nivel2()));
    loguearInfo(LOG_CANT_E1_3 + std::to_string(getCantEnemigo1Nivel3()));
    loguearInfo(LOG_PATH_E2 + std::string(getTipoEnemigo2()));
    loguearInfo(LOG_CANT_E2_1 + std::to_string(getCantEnemigo2Nivel1()));
    loguearInfo(LOG_CANT_E2_2 + std::to_string(getCantEnemigo2Nivel2()));
    loguearInfo(LOG_CANT_E2_3 + std::to_string(getCantEnemigo2Nivel3()));
    loguearInfo(LOG_CANT_MAX_E + std::to_string(getCantMaxEnemigos()));



    loguearInfo(LOG_FINAL_CARGA);
}

void CargadorDeConfiguracion::manejoDeSet(char *valor_res, char *valor_default, bool arch_local,
                                          void(*funcion_set)(std::string), bool(*funcion_verificar)(char *),
                                          char *ERROR_CASO_RES, char *ERROR_CASO_DEFAULT) {
    //Caso valor en res valido
    if (arch_local) {
        if (funcion_verificar(valor_res)) {
            funcion_set(valor_res);
            return;
        } else
            loguearError(ERROR_CASO_RES);
    }
    //Caso res invalido, vemos que pasa con el default
    if (funcion_verificar(valor_default)) {
        funcion_set(valor_default);
    }
        //Caso ambos invalidos
    else {
        loguearError(ERROR_CASO_DEFAULT);
    }
}

bool CargadorDeConfiguracion::corregirCantidadEnemigos(int *cant_enemigo_1, int *cant_enemigo_2) {
    int totalEnemigos = (*cant_enemigo_1) + (*cant_enemigo_2);

    // Vemos si se sobrepaso la cant maxima para activar el flag
    bool cantidadMaximaDeEnemigosSobrepasada = false;
    if (totalEnemigos > getCantMaxEnemigos()) {
        cantidadMaximaDeEnemigosSobrepasada = true;
    }

    // Realizamos la correccion localmente
    while (totalEnemigos > getCantMaxEnemigos()) {
        *cant_enemigo_1 = (*cant_enemigo_1) / 2;
        *cant_enemigo_2 = (*cant_enemigo_2) / 2;
        totalEnemigos = (*cant_enemigo_1) + (*cant_enemigo_2);
    }

    return cantidadMaximaDeEnemigosSobrepasada;
}
