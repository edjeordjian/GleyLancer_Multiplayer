#ifndef PRIMERAENTREGA_UTILS_H
#define PRIMERAENTREGA_UTILS_H

#include "ConstantesLog.h"
#include "ConstantesVentana.h"
#include "ConstantesEnemigo.h"
#include <cstdlib>
#include <ctime>
#include <string>

bool tipoEnemigoValido(char *tipo);

bool existeArchivo(char *nombre);

std::string obtenerLineaDeError(std::string error);
/*
bool compararPuntajes(std::pair<std::string,std::pair<std::string,std::string>> i,
                      std::pair<std::string,std::pair<std::string,std::string>> j);
*/
bool compararPuntajes(std::pair<std::string, std::string> i, std::pair<std::string, std::string> j);

#endif //PRIMERAENTREGA_UTILS_H
