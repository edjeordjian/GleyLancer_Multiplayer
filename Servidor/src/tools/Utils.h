#ifndef SERVIDOR_UTILS_H
#define SERVIDOR_UTILS_H

#include <string>
#include "constantes/ConstantesJson.h"
#include "constantes/ConstantesModelo.h"
#include "constantes/ConstantesVentana.h"
#include "constantes/ConstantesEnemigos.h"
#include "constantes/ConstantesComunicacion.h"
#include "Log.h"

void obtenerRandom(int *pos);

bool numeroValido(char *numero_ingresado);

bool tipoEnemigoValido(char* tipo);

std::string obtenerLineaDeError(std::string error);

bool verificadorPass(char *pass);

bool verificadorUsuario(char *usuario);

bool esUsuarioValido(std::string nombre, std::string pass);

//Funcion auxiliar para ordenar puntajes
//Pre: el vector de enteros debe tener al menos 4 elementos
//Pos: True si el puntaje total de i (i.second[3]) es mayor que el de j (j.second[3])
bool compararPuntajesFinales(std::pair<std::string, std::vector<int>> i, std::pair<std::string, std::vector<int>> j);

#endif //SERVIDOR_UTILS_H
