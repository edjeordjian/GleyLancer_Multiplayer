#ifndef SERVIDOR_CONSTANTESMODELO_H
#define SERVIDOR_CONSTANTESMODELO_H

#include "ConstantesGenerales.h" //Aca esta guardada la constante de escala fondo
#include "ConstantesVentana.h"
#include "../../modelo/juego/Posicion.h"

/// MODELO ///

static constexpr int NRO_NIVEL_INICIAL=1;

static constexpr int TIMEOUT_PARA_GAMEOVER_DESCONECTADOS = 30000; // 30 segundos

static constexpr unsigned int MILISEG_TIMEOUT_EVENTOS = 16; /* 0,016 segundos */
static constexpr unsigned int ANCHO_PERSONAJE = 90;
static constexpr unsigned int ALTO_PERSONAJE = 50;
static constexpr unsigned int TAM_ANCHO_PERSONAJE = ANCHO_PERSONAJE;
static constexpr unsigned int TAM_ALTO_PERSONAJE = ALTO_PERSONAJE;

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
static constexpr unsigned int ANCHO_TIPO_ENEMIGO_4 = 64;
static constexpr unsigned int ALTO_TIPO_ENEMIGO_4 = 73;

static constexpr unsigned int TAM_ALTO_TIPO_ENEMIGO_DEFAULT = 50;
static constexpr unsigned int TAM_ANCHO_TIPO_ENEMIGO_DEFAULT = 40;
static constexpr unsigned int ALTO_TIPO_ENEMIGO_DEFAULT = 50;
static constexpr unsigned int ANCHO_TIPO_ENEMIGO_DEFAULT = 40;

static constexpr unsigned int ANCHO_PROYECTIL = 92;
static constexpr unsigned int ALTO_PROYECTIL = 29;
static constexpr unsigned int TAM_ANCHO_PROYECTIL = ANCHO_PROYECTIL;
static constexpr unsigned int TAM_ALTO_PROYECTIL = ALTO_PROYECTIL;

static constexpr int ANCHO_ALTO_PROYECTIL_ENEMIGO = 25;

static constexpr int POTENCIA_PROY_PERSONAJE = 50;

static constexpr unsigned int ANCHO_ITEM_1 = 37;
static constexpr unsigned int ALTO_ITEM_1 = 37;
static constexpr unsigned int ANCHO_ITEM_2 = 30;
static constexpr unsigned int ALTO_ITEM_2 = 30;


static constexpr int TIPO_ITEM_VIDA = 0;
static constexpr int TIPO_ITEM_ENERGIA = 1;
static constexpr int TIPO_ITEM_PUNTOS = 2;
static constexpr int TIPO_ITEM_ESCUDO = 3;

static constexpr int ENERGIA_ITEM = 60;
static constexpr int PUNTOS_ITEM = 5000;

///CAJAS///
static constexpr int POS_X_CAJA_1 = (ANCHO_FONDO / 2) + (ANCHO_FONDO / 6);
static constexpr int POS_X_CAJA_2 = (ANCHO_FONDO / 2) + (ANCHO_FONDO / 4);
static constexpr int POS_X_CAJA_3 = (ANCHO_FONDO / 2) + (ANCHO_FONDO / 3);

static constexpr int RANGO_NRO_RANDOM_CAJAS=100;
static constexpr int RANGO_NRO_RANDOM_CAJAS_PUNTOS=30;
static constexpr int RANGO_NRO_RANDOM_CAJAS_ITEM=60;
static constexpr int RANGO_NRO_RANDOM_CAJAS_ENERGIA=90;

static constexpr unsigned int ANCHO_CAJA = 80;
static constexpr unsigned int ALTO_CAJA = 87;

static constexpr int INCREMENTO_X_Y_CAJA=20;



///DESPLAZAMIENTO FONDO///
//TODO ENTREGA: Poner desplazamiento_fondo en 0.23f
static constexpr float DESPLAZAMIENTO_FONDO = 0.75f * ESCALA_FONDO;


/// POSICIONES
static const Posicion POS_ARRIBA_IZQ = Posicion(-0.707, -0.707);
static const Posicion POS_ARRIBA_DER = Posicion(0.707, -0.707);
static const Posicion POS_ABAJO_IZQ = Posicion(-0.707, 0.707);
static const Posicion POS_ABAJO_DER = Posicion(0.707, 0.707);
static const Posicion POS_ARRIBA = Posicion(0,-1);
static const Posicion POS_IZQUIERDA = Posicion(-1,0);
static const Posicion POS_ABAJO = Posicion(0, 1);
static const Posicion POS_DERECHA = Posicion(1, 0);
static const Posicion POS_NINGUNA = Posicion(0, 0);
static const Posicion POS_DERECHA_FONDO = Posicion(DESPLAZAMIENTO_FONDO, 0);

#endif //SERVIDOR_CONSTANTESMODELO_H
