#include "Utils.h"


bool tipoEnemigoValido(char* tipo) {
    return tipos_enemigos_imagen.find(std::string(tipo)) != tipos_enemigos_imagen.end();
}

std::string obtenerLineaDeError(std::string error) {
    std::string::size_type pos = error.find(',');
    if (pos != std::string::npos) {
        return error.substr(0, pos).replace(0, 7, " ");
    } else {
        return error;
    }
}

bool existeArchivo(char *nombre) {
    std::ifstream f(nombre);
    return f.good();
}
/*
bool compararPuntajes(std::pair<std::string, std::pair<std::string, std::string>> i, std::pair<std::string, std::pair<std::string, std::string>> j) {
    return (atoi(i.second.first.c_str()) > atoi(j.second.first.c_str()));
}*/

bool compararPuntajes(std::pair<std::string, std::string> i, std::pair<std::string, std::string> j) {
    return (atoi(i.second.c_str()) > atoi(j.second.c_str()));
}


