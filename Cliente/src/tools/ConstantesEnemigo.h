#ifndef CLIENTE_CONSTANTESENEMIGO_H
#define CLIENTE_CONSTANTESENEMIGO_H

#include <string>
#include <bits/stdc++.h>

/// ENEMIGO ///
static const std::string PRE_POSICION_ENEMIGO = "Pos_Enemigo";
static const std::string TIPO_VALIDO_ENEMIGO_1 = "tipo_enemigo_1";
static const std::string TIPO_VALIDO_ENEMIGO_2 = "tipo_enemigo_2";
static const std::string TIPO_VALIDO_ENEMIGO_3 = "tipo_enemigo_3";
static const std::string TIPO_VALIDO_ENEMIGO_4 = "tipo_enemigo_4";
static const std::string TIPO_VALIDO_ENEMIGO_DEFAULT = "default";

static constexpr int NRO_ENEMIGO_TIPO_1 = -1;
static constexpr int NRO_ENEMIGO_TIPO_2 = -2;
static constexpr int NRO_ENEMIGO_TIPO_JEFE = -3;



static constexpr int DIRECCION_ENEMIGO_DERECHA = 1;
static constexpr int DIRECCION_ENEMIGO_IZQUIERDA = 0;


static constexpr unsigned int ANCHO_TIPO_ENEMIGO_1 = 84;
static constexpr unsigned int ALTO_TIPO_ENEMIGO_1 = 42;
static constexpr unsigned int TAM_ANCHO_TIPO_ENEMIGO_1 = ANCHO_TIPO_ENEMIGO_1;
static constexpr unsigned int TAM_ALTO_TIPO_ENEMIGO_1 = ALTO_TIPO_ENEMIGO_1;
static constexpr unsigned int ANCHO_TIPO_ENEMIGO_2 = 120;
static constexpr unsigned int ALTO_TIPO_ENEMIGO_2 = 110;
static constexpr unsigned int TAM_ANCHO_TIPO_ENEMIGO_2 = ANCHO_TIPO_ENEMIGO_2 / 2;
static constexpr unsigned int TAM_ALTO_TIPO_ENEMIGO_2 = ALTO_TIPO_ENEMIGO_2 / 2;
static constexpr unsigned int ANCHO_TIPO_ENEMIGO_3 = 65;
static constexpr unsigned int ALTO_TIPO_ENEMIGO_3 = 61;
static constexpr unsigned int TAM_ANCHO_TIPO_ENEMIGO_3 = ANCHO_TIPO_ENEMIGO_3;
static constexpr unsigned int TAM_ALTO_TIPO_ENEMIGO_3 = ALTO_TIPO_ENEMIGO_3;
static constexpr unsigned int ANCHO_TIPO_ENEMIGO_4 = 64;
static constexpr unsigned int ALTO_TIPO_ENEMIGO_4 = 73;
static constexpr unsigned int TAM_ANCHO_TIPO_ENEMIGO_4 = ANCHO_TIPO_ENEMIGO_4;
static constexpr unsigned int TAM_ALTO_TIPO_ENEMIGO_4 = ALTO_TIPO_ENEMIGO_4;

static constexpr unsigned int TAM_ALTO_TIPO_ENEMIGO_DEFAULT = 50;
static constexpr unsigned int TAM_ANCHO_TIPO_ENEMIGO_DEFAULT = 40;
static constexpr unsigned int ALTO_TIPO_ENEMIGO_DEFAULT = 50;
static constexpr unsigned int ANCHO_TIPO_ENEMIGO_DEFAULT = 40;

static constexpr unsigned long POS_VISTA_ENEMIGO_TIPO_1_Y_2_DANIADO = 2;
static constexpr unsigned long POS_VISTA_ENEMIGO_JEFE_DANIADO = 8;

static constexpr char *RUTA_IMAGEN_TIPO_ENEMIGO_1 = (char *) ("../data/imgs/enemigos/enemigo_1.png");
static constexpr char *RUTA_IMAGEN_TIPO_ENEMIGO_1_DERECHA = (char *) ("../data/imgs/enemigos/enemigo_1d.png");
static constexpr char *RUTA_IMAGEN_TIPO_ENEMIGO_2 = (char *) ("../data/imgs/enemigos/enemigo_2.png");
static constexpr char *RUTA_IMAGEN_TIPO_ENEMIGO_1_DANIADO = (char *) ("../data/imgs/enemigos/enemigo_1l.png");
static constexpr char *RUTA_IMAGEN_TIPO_ENEMIGO_1_DERECHA_DANIADO = (char *) ("../data/imgs/enemigos/enemigo_1dl.png");
static constexpr char *RUTA_IMAGEN_TIPO_ENEMIGO_2_DANIADO = (char *) ("../data/imgs/enemigos/enemigo_2l.png");
static constexpr char *RUTA_IMG_ENEMIGO_DEFECTO = (char *) ("../data/imgs/default.png");



/*
 * Mapa que contiene la imagen de cada tipo de enemigo valido.
*/
static std::map<std::string, char *> tipos_enemigos_imagen = {
        {TIPO_VALIDO_ENEMIGO_1,       RUTA_IMAGEN_TIPO_ENEMIGO_1},
        {TIPO_VALIDO_ENEMIGO_2,       RUTA_IMAGEN_TIPO_ENEMIGO_2},
        {TIPO_VALIDO_ENEMIGO_DEFAULT, RUTA_IMG_ENEMIGO_DEFECTO}
};

/*
 * Mapa que contiene los anchos de cada tipo de enemigo valido.
*/
static std::map<std::string, unsigned int> anchos_enemigo = {
        {TIPO_VALIDO_ENEMIGO_1,       ANCHO_TIPO_ENEMIGO_1},
        {TIPO_VALIDO_ENEMIGO_2,       ANCHO_TIPO_ENEMIGO_2},
        {TIPO_VALIDO_ENEMIGO_3,       ANCHO_TIPO_ENEMIGO_3},
        {TIPO_VALIDO_ENEMIGO_4,       ANCHO_TIPO_ENEMIGO_4},
        {TIPO_VALIDO_ENEMIGO_DEFAULT, ANCHO_TIPO_ENEMIGO_DEFAULT}
};

/*
 * Mapa que contiene los altos de cada tipo de enemigo valido.
*/
static std::map<std::string, unsigned int> altos_enemigos = {
        {TIPO_VALIDO_ENEMIGO_1,       ALTO_TIPO_ENEMIGO_1},
        {TIPO_VALIDO_ENEMIGO_2,       ALTO_TIPO_ENEMIGO_2},
        {TIPO_VALIDO_ENEMIGO_3,       ALTO_TIPO_ENEMIGO_3},
        {TIPO_VALIDO_ENEMIGO_4,       ALTO_TIPO_ENEMIGO_4},
        {TIPO_VALIDO_ENEMIGO_DEFAULT, ALTO_TIPO_ENEMIGO_DEFAULT}
};
/*
 * Mapa que contiene los tamaños de anchos de los tipos de enemigos en la vista .
*/
static std::map<std::string, unsigned int> tam_anchos_enemigos = {
        {TIPO_VALIDO_ENEMIGO_1,       TAM_ANCHO_TIPO_ENEMIGO_1},
        {TIPO_VALIDO_ENEMIGO_2,       TAM_ANCHO_TIPO_ENEMIGO_2},
        {TIPO_VALIDO_ENEMIGO_3,       TAM_ANCHO_TIPO_ENEMIGO_3},
        {TIPO_VALIDO_ENEMIGO_4,       TAM_ANCHO_TIPO_ENEMIGO_4},
        {TIPO_VALIDO_ENEMIGO_DEFAULT, TAM_ANCHO_TIPO_ENEMIGO_DEFAULT}
};

/*
 * Mapa que contiene los tamaños de alto de los tipos de enemigos en la vista .
*/
static std::map<std::string, unsigned int> tam_altos_enemigos = {
        {TIPO_VALIDO_ENEMIGO_1,       TAM_ALTO_TIPO_ENEMIGO_1},
        {TIPO_VALIDO_ENEMIGO_2,       TAM_ALTO_TIPO_ENEMIGO_2},
        {TIPO_VALIDO_ENEMIGO_3,       TAM_ALTO_TIPO_ENEMIGO_3},
        {TIPO_VALIDO_ENEMIGO_4,       TAM_ALTO_TIPO_ENEMIGO_4},
        {TIPO_VALIDO_ENEMIGO_DEFAULT, TAM_ALTO_TIPO_ENEMIGO_DEFAULT}
};


int getAnchoEnemigo1();
int getAnchoEnemigo2();

int getAltoEnemigo1();
int getAltoEnemigo2();

int getTamAnchoEnemigo1();
int getTamAnchoEnemigo2();

int getTamAltoEnemigo1();
int getTamAltoEnemigo2();

void setTipoEnemigo1(std::string tipo);
std::string getTipoEnemigo1();

void setTipoEnemigo2(std::string tipo);
std::string getTipoEnemigo2();


char *getRutaImagenEnemigo1();
char *getRutaImagenEnemigo2();

///JEFES///

static constexpr int MAX_VALOR_CONTADOR_DANIADO = 9;
static constexpr int CANT_ESTADOS = 2; //hay dos estados: dañado y no dañado

static const std::string TIPO_JEFE_1 = "Jefe_1";
static constexpr int ANCHO_JEFE_1 = 364;
static constexpr int ALTO_JEFE_1 = 283;

static constexpr int LIMITE_CONTADOR_J1_Y_J3 = 7;

static constexpr char *RUTA_IMAGEN_TIPO_JEFE_1_1 = (char *) ("../data/imgs/enemigos/jefe1_1.png");
static constexpr char *RUTA_IMAGEN_TIPO_JEFE_1_2 = (char *) ("../data/imgs/enemigos/jefe1_2.png");
static constexpr char *RUTA_IMAGEN_TIPO_JEFE_1_3 = (char *) ("../data/imgs/enemigos/jefe1_3.png");
static constexpr char *RUTA_IMAGEN_TIPO_JEFE_1_4 = (char *) ("../data/imgs/enemigos/jefe1_4.png");
static constexpr char *RUTA_IMAGEN_TIPO_JEFE_1_5 = (char *) ("../data/imgs/enemigos/jefe1_5.png");
static constexpr char *RUTA_IMAGEN_TIPO_JEFE_1_6 = (char *) ("../data/imgs/enemigos/jefe1_6.png");
static constexpr char *RUTA_IMAGEN_TIPO_JEFE_1_7 = (char *) ("../data/imgs/enemigos/jefe1_7.png");
static constexpr char *RUTA_IMAGEN_TIPO_JEFE_1_8 = (char *) ("../data/imgs/enemigos/jefe1_8.png");
static constexpr char *RUTA_IMAGEN_TIPO_JEFE_1_1_DANIADO = (char *) ("../data/imgs/enemigos/jefe1d_1.png");
static constexpr char *RUTA_IMAGEN_TIPO_JEFE_1_2_DANIADO = (char *) ("../data/imgs/enemigos/jefe1d_2.png");
static constexpr char *RUTA_IMAGEN_TIPO_JEFE_1_3_DANIADO = (char *) ("../data/imgs/enemigos/jefe1d_3.png");
static constexpr char *RUTA_IMAGEN_TIPO_JEFE_1_4_DANIADO = (char *) ("../data/imgs/enemigos/jefe1d_4.png");
static constexpr char *RUTA_IMAGEN_TIPO_JEFE_1_5_DANIADO = (char *) ("../data/imgs/enemigos/jefe1d_5.png");
static constexpr char *RUTA_IMAGEN_TIPO_JEFE_1_6_DANIADO = (char *) ("../data/imgs/enemigos/jefe1d_6.png");
static constexpr char *RUTA_IMAGEN_TIPO_JEFE_1_7_DANIADO = (char *) ("../data/imgs/enemigos/jefe1d_7.png");
static constexpr char *RUTA_IMAGEN_TIPO_JEFE_1_8_DANIADO = (char *) ("../data/imgs/enemigos/jefe1d_8.png");

static const std::string TIPO_JEFE_2 = "Jefe_2";
static constexpr int ANCHO_JEFE_2 = 140;
static constexpr int ALTO_JEFE_2 = 140;
static constexpr int ANCHO_IMG_JEFE_2 = 286;
static constexpr int ALTO_IMG_JEFE_2 = 285;
static constexpr int MAX_VALOR_CONTADOR_J2 = 7;

static constexpr char *RUTA_IMAGEN_TIPO_JEFE_2_ROT1 = (char *) ("../data/imgs/enemigos/jefe2_1.png");
static constexpr char *RUTA_IMAGEN_TIPO_JEFE_2_ROT2 = (char *) ("../data/imgs/enemigos/jefe2_2.png");
static constexpr char *RUTA_IMAGEN_TIPO_JEFE_2_ROT3 = (char *) ("../data/imgs/enemigos/jefe2_3.png");
static constexpr char *RUTA_IMAGEN_TIPO_JEFE_2_ROT4 = (char *) ("../data/imgs/enemigos/jefe2_4.png");
static constexpr char *RUTA_IMAGEN_TIPO_JEFE_2_ROT5 = (char *) ("../data/imgs/enemigos/jefe2_5.png");
static constexpr char *RUTA_IMAGEN_TIPO_JEFE_2_ROT6 = (char *) ("../data/imgs/enemigos/jefe2_6.png");
static constexpr char *RUTA_IMAGEN_TIPO_JEFE_2_ROT7 = (char *) ("../data/imgs/enemigos/jefe2_7.png");
static constexpr char *RUTA_IMAGEN_TIPO_JEFE_2_ROT8 = (char *) ("../data/imgs/enemigos/jefe2_8.png");
static constexpr char *RUTA_IMAGEN_TIPO_JEFE_2_ROT1_DANIADO = (char *) ("../data/imgs/enemigos/jefe2d_1.png");
static constexpr char *RUTA_IMAGEN_TIPO_JEFE_2_ROT2_DANIADO = (char *) ("../data/imgs/enemigos/jefe2d_2.png");
static constexpr char *RUTA_IMAGEN_TIPO_JEFE_2_ROT3_DANIADO = (char *) ("../data/imgs/enemigos/jefe2d_3.png");
static constexpr char *RUTA_IMAGEN_TIPO_JEFE_2_ROT4_DANIADO = (char *) ("../data/imgs/enemigos/jefe2d_4.png");
static constexpr char *RUTA_IMAGEN_TIPO_JEFE_2_ROT5_DANIADO = (char *) ("../data/imgs/enemigos/jefe2d_5.png");
static constexpr char *RUTA_IMAGEN_TIPO_JEFE_2_ROT6_DANIADO = (char *) ("../data/imgs/enemigos/jefe2d_6.png");
static constexpr char *RUTA_IMAGEN_TIPO_JEFE_2_ROT7_DANIADO = (char *) ("../data/imgs/enemigos/jefe2d_7.png");
static constexpr char *RUTA_IMAGEN_TIPO_JEFE_2_ROT8_DANIADO = (char *) ("../data/imgs/enemigos/jefe2d_8.png");



static const std::string TIPO_JEFE_3 = "Jefe_3";
static constexpr int ANCHO_JEFE_3 = 311;
static constexpr int ALTO_JEFE_3 = 440;
static constexpr char *RUTA_IMAGEN_TIPO_JEFE_3_1 = (char *) ("../data/imgs/enemigos/jefe3_1.png");
static constexpr char *RUTA_IMAGEN_TIPO_JEFE_3_2 = (char *) ("../data/imgs/enemigos/jefe3_2.png");
static constexpr char *RUTA_IMAGEN_TIPO_JEFE_3_3 = (char *) ("../data/imgs/enemigos/jefe3_3.png");
static constexpr char *RUTA_IMAGEN_TIPO_JEFE_3_4 = (char *) ("../data/imgs/enemigos/jefe3_4.png");
static constexpr char *RUTA_IMAGEN_TIPO_JEFE_3_5 = (char *) ("../data/imgs/enemigos/jefe3_5.png");
static constexpr char *RUTA_IMAGEN_TIPO_JEFE_3_6 = (char *) ("../data/imgs/enemigos/jefe3_6.png");
static constexpr char *RUTA_IMAGEN_TIPO_JEFE_3_7 = (char *) ("../data/imgs/enemigos/jefe3_7.png");
static constexpr char *RUTA_IMAGEN_TIPO_JEFE_3_8 = (char *) ("../data/imgs/enemigos/jefe3_8.png");
static constexpr char *RUTA_IMAGEN_TIPO_JEFE_3_1_DANIADO = (char *) ("../data/imgs/enemigos/jefe3d_1.png");
static constexpr char *RUTA_IMAGEN_TIPO_JEFE_3_2_DANIADO = (char *) ("../data/imgs/enemigos/jefe3d_2.png");
static constexpr char *RUTA_IMAGEN_TIPO_JEFE_3_3_DANIADO = (char *) ("../data/imgs/enemigos/jefe3d_3.png");
static constexpr char *RUTA_IMAGEN_TIPO_JEFE_3_4_DANIADO = (char *) ("../data/imgs/enemigos/jefe3d_4.png");
static constexpr char *RUTA_IMAGEN_TIPO_JEFE_3_5_DANIADO = (char *) ("../data/imgs/enemigos/jefe3d_5.png");
static constexpr char *RUTA_IMAGEN_TIPO_JEFE_3_6_DANIADO = (char *) ("../data/imgs/enemigos/jefe3d_6.png");
static constexpr char *RUTA_IMAGEN_TIPO_JEFE_3_7_DANIADO = (char *) ("../data/imgs/enemigos/jefe3d_7.png");
static constexpr char *RUTA_IMAGEN_TIPO_JEFE_3_8_DANIADO = (char *) ("../data/imgs/enemigos/jefe3d_8.png");

#endif //CLIENTE_CONSTANTESENEMIGO_H
