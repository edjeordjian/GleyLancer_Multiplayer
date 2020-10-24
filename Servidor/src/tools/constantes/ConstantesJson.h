#ifndef SERVIDOR_CONSTANTESJSON_H
#define SERVIDOR_CONSTANTESJSON_H

#include <string>
#include <vector>
#include "../Timestamp.h"
#include "ConstantesEnemigos.h"
#include "ConstantesComunicacion.h"

/// JSON ///
static std::string RUTA_CONFIG_DEFAULT = "../data/config_default.json";
static std::string ERROR_JSON = "No se encontró JSON local. Leyendo archivo por defecto...\n";
static const size_t MAX_LEN_USER = 8;
static const size_t MAX_LEN_PASS = 16;


void setRutaConfig(std::string ruta);

char *getRutaConfig();

static std::string RUTA_IMGS_JSON = "../data/imgs/";

void setTipoEnemigo1(std::string tipo);
std::string getTipoEnemigo1();
void setCantEnemigo1Nivel1(std::string cant);
void setCantEnemigo1Nivel2(std::string cant);
void setCantEnemigo1Nivel3(std::string cant);
int getCantEnemigo1Nivel1();
int getCantEnemigo1Nivel2();
int getCantEnemigo1Nivel3();

void setTipoEnemigo2(std::string tipo);
std::string getTipoEnemigo2();
void setCantEnemigo2Nivel1(std::string cant);
void setCantEnemigo2Nivel2(std::string cant);
void setCantEnemigo2Nivel3(std::string cant);
int getCantEnemigo2Nivel1();
int getCantEnemigo2Nivel2();
int getCantEnemigo2Nivel3();

int getCantMaxEnemigos();

int getAnchoEnemigo1();
int getAnchoEnemigo2();

int getAltoEnemigo1();
int getAltoEnemigo2();

int getTamAnchoEnemigo1();
int getTamAnchoEnemigo2();

int getTamAltoEnemigo1();
int getTamAltoEnemigo2();

int getTamAltoPersonaje();
int getTamAnchoPersonaje();
int getTamAltoProyectil();
int getTamAnchoProyectil();

std::string getPuerto();
void setPuerto(std::string puerto_nuevo);

void agregarNombreUsuario(std::string user);
void agregarPass(std::string pass);

std::vector<std::string> getNombresUsuarios();
std::vector<std::string> getPasswords();

size_t getCantidadUsuarios();

#endif //SERVIDOR_CONSTANTESJSON_H
