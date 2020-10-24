#ifndef CLIENTE_CONSTANTESPROYECTILES_H
#define CLIENTE_CONSTANTESPROYECTILES_H

#include <string>

/// PROYECTILES ///

static const std::string PRE_POSICION_PROYECTILES = "Pos_proyectiles";
static constexpr unsigned int ANCHO_PROYECTIL = 92;
static constexpr unsigned int ALTO_PROYECTIL = 29;
static constexpr unsigned int TAM_ANCHO_PROYECTIL = ANCHO_PROYECTIL;
static constexpr unsigned int TAM_ALTO_PROYECTIL = ALTO_PROYECTIL;
static constexpr unsigned int ANCHO_ALTO_PROYECTIL_ENEMIGO = 25;

static constexpr char *RUTA_LUZ_PROY_P1 = (char *) ("../data/imgs/proyectiles/proy_p1_luz.png");
static constexpr char *RUTA_LUZ_PROY_P2 = (char *) ("../data/imgs/proyectiles/proy_p2_luz.png");
static constexpr char *RUTA_LUZ_PROY_P3 = (char *) ("../data/imgs/proyectiles/proy_p3_luz.png");
static constexpr char *RUTA_LUZ_PROY_P4 = (char *) ("../data/imgs/proyectiles/proy_p4_luz.png");
static constexpr char *RUTA_LUZ_PROY_E1 = (char *) ("../data/imgs/proyectiles/proy_e1_luz.png");
static constexpr char *RUTA_LUZ_PROY_E2 = (char *) ("../data/imgs/proyectiles/proy_e2_luz.png");
static constexpr char *RUTA_LUZ_PROY_J = (char *) ("../data/imgs/proyectiles/proy_j_luz.png");
static constexpr char *RUTA_PROYECTIL_PERSONAJE_1 = (char *) ("../data/imgs/proyectiles/proyectil_p1.png");
static constexpr char *RUTA_PROYECTIL_PERSONAJE_2 = (char *) ("../data/imgs/proyectiles/proyectil_p2.png");
static constexpr char *RUTA_PROYECTIL_PERSONAJE_3 = (char *) ("../data/imgs/proyectiles/proyectil_p3.png");
static constexpr char *RUTA_PROYECTIL_PERSONAJE_4 = (char *) ("../data/imgs/proyectiles/proyectil_p4.png");
static constexpr char *RUTA_PROYECTIL_ENEMIGO = (char *) ("../data/imgs/proyectiles/proyectil_enemigo.png");
static constexpr char *RUTA_PROYECTIL_ENEMIGO_2 = (char *) ("../data/imgs/proyectiles/proyectil_enemigo_2.png");
static constexpr char *RUTA_PROYECTIL_JEFE = (char *) ("../data/imgs/proyectiles/proyectil_j.png");

static constexpr int OPACIDAD_LUZ_PROYECTIL = 40;

int getTamAltoProyectil();

int getTamAnchoProyectil();

#endif //CLIENTE_CONSTANTESPROYECTILES_H
