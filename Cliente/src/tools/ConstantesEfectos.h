#ifndef CLIENTE_CONSTANTESEFECTOS_H
#define CLIENTE_CONSTANTESEFECTOS_H


/// EFECTOS ///

#include "ConstantesEnemigo.h"

static constexpr char *RUTA_IMAGEN_EXPLOSION_1 = (char *) ("../data/imgs/explosion1.png");
static constexpr char *RUTA_IMAGEN_EXPLOSION_2 = (char *) ("../data/imgs/explosion2.png");
static constexpr char *RUTA_IMAGEN_EXPLOSION_3 = (char *) ("../data/imgs/explosion3.png");
static constexpr char *RUTA_IMAGEN_EXPLOSION_4 = (char *) ("../data/imgs/explosion4.png");
static constexpr char *RUTA_IMAGEN_EXPLOSION_5 = (char *) ("../data/imgs/explosion5.png");
static constexpr char *RUTA_IMAGEN_EXPLOSION_6 = (char *) ("../data/imgs/explosion6.png");

static constexpr char *RUTA_IMAGEN_EXPLOSION_1_J = (char *) ("../data/imgs/explosion1j.png");
static constexpr char *RUTA_IMAGEN_EXPLOSION_2_J = (char *) ("../data/imgs/explosion2j.png");
static constexpr char *RUTA_IMAGEN_EXPLOSION_3_J = (char *) ("../data/imgs/explosion3j.png");
static constexpr char *RUTA_IMAGEN_EXPLOSION_4_J = (char *) ("../data/imgs/explosion4j.png");
static constexpr char *RUTA_IMAGEN_EXPLOSION_5_J = (char *) ("../data/imgs/explosion5j.png");
static constexpr char *RUTA_IMAGEN_EXPLOSION_6_J = (char *) ("../data/imgs/explosion6j.png");

static constexpr char *RUTA_IMAGEN_EFECTO_VELOCIDAD = (char *) ("../data/imgs/efecto_velocidad.png");


static constexpr int CORRECCION_EFECTO_PERSONAJE_X = 80;
static constexpr int CORRECCION_EFECTO_PERSONAJE_Y = 100;
static constexpr int CORRECCION_EFECTO_ENEMIGO_X = 75;
static constexpr int CORRECCION_EFECTO_ENEMIGO_Y = 75;
static constexpr int CORRECCION_EFECTO_CAJA_X = 40;
static constexpr int CORRECCION_EFECTO_CAJA_Y = 35;

/* Calculo de correcciones de explosion jefes
(ancho explosion / 2 ) - (ancho jugable / 2)  ***jugable puede ser personaje caja enemigo o jefe***
(alto explosion / 2 ) - (alto jugable / 2)  ***jugable puede ser personaje caja enemigo o jefe***
 es lo mismo que tam / 4  !!!!!
*/

static constexpr int CORRECCION_X_JEFE_1 = ANCHO_JEFE_1/ 4;
static constexpr int CORRECCION_Y_JEFE_1 = ALTO_JEFE_1/ 4;
static constexpr int CORRECCION_X_JEFE_2 = ANCHO_JEFE_2 / 4;
static constexpr int CORRECCION_Y_JEFE_2 = ALTO_JEFE_2 / 4;
static constexpr int CORRECCION_X_JEFE_3 = ANCHO_JEFE_3 / 4;
static constexpr int CORRECCION_Y_JEFE_3 = ALTO_JEFE_3 / 4;

static constexpr unsigned int ANCHO_ALTO_EXPLOSION_PERSONAJE = 250;
static constexpr unsigned int ANCHO_ALTO_EXPLOSION_ENEMIGO = 200;
static constexpr unsigned int ANCHO_ALTO_EXPLOSION_CAJA = 200;

static constexpr unsigned int ALTO_EXPLOSION_JEFE_1 = ALTO_JEFE_1 + (ALTO_JEFE_1/2);
static constexpr unsigned int ANCHO_EXPLOSION_JEFE_1 = ANCHO_JEFE_1 + (ANCHO_JEFE_1/2);
static constexpr unsigned int ALTO_EXPLOSION_JEFE_2 = ALTO_JEFE_2 + (ALTO_JEFE_2/2);
static constexpr unsigned int ANCHO_EXPLOSION_JEFE_2 = ANCHO_JEFE_2 + (ANCHO_JEFE_2/2);
static constexpr unsigned int ALTO_EXPLOSION_JEFE_3 = ALTO_JEFE_3 + (ALTO_JEFE_3/2);
static constexpr unsigned int ANCHO_EXPLOSION_JEFE_3 = ANCHO_JEFE_3 + (ANCHO_JEFE_3/2);


static constexpr unsigned int TIEMPO_VIDA_EXPLOSION = 30;
static constexpr unsigned int TIEMPO_VIDA_EXPLOSION_FASE_1 = 5;
static constexpr int POS_EXPLOSION_FASE_1 = 0;
static constexpr unsigned int TIEMPO_VIDA_EXPLOSION_FASE_2 = 10;
static constexpr int POS_EXPLOSION_FASE_2 = 1;
static constexpr unsigned int TIEMPO_VIDA_EXPLOSION_FASE_3 = 15;
static constexpr int POS_EXPLOSION_FASE_3 = 2;
static constexpr unsigned int TIEMPO_VIDA_EXPLOSION_FASE_4 = 20;
static constexpr int POS_EXPLOSION_FASE_4 = 3;
static constexpr unsigned int TIEMPO_VIDA_EXPLOSION_FASE_5 = 25;
static constexpr int POS_EXPLOSION_FASE_5 = 4;

static constexpr int POS_EXPLOSION_FASE_6 = 5;

static constexpr int ALTO_ANCHO_EFECTO_VELO_1 = 10;
static constexpr int ALTO_ANCHO_EFECTO_VELO_2 = 20;
static constexpr int ALTO_ANCHO_EFECTO_VELO_3 = 30;
static constexpr int ALTO_ANCHO_EFECTO_VELO_PROP = 40;

static std::vector<int> CORRECCIONES_JEFES ={CORRECCION_X_JEFE_1, CORRECCION_Y_JEFE_1,CORRECCION_X_JEFE_2, CORRECCION_Y_JEFE_2,CORRECCION_X_JEFE_3, CORRECCION_Y_JEFE_3};
static std::vector<int> EXPLOSIONES_JEFES ={ANCHO_EXPLOSION_JEFE_1, ALTO_EXPLOSION_JEFE_1,ANCHO_EXPLOSION_JEFE_2, ALTO_EXPLOSION_JEFE_2, ANCHO_EXPLOSION_JEFE_3, ALTO_EXPLOSION_JEFE_3};

static constexpr int OPACIDAD_TEXTURA_ESCUDO=100;

static constexpr int TIEMPO_1_EFECTO_VELO=0;
static constexpr int TIEMPO_2_EFECTO_VELO=2;
static constexpr int TIEMPO_3_EFECTO_VELO=5;

static constexpr int CARRECCION_POS_EFECTO_VELO_1=20;
static constexpr int CARRECCION_POS_EFECTO_VELO_2=25;


#endif //CLIENTE_CONSTANTESEFECTOS_H
