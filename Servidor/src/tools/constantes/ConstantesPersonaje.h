#ifndef SERVIDOR_CONSTANTESPERSONAJE_H
#define SERVIDOR_CONSTANTESPERSONAJE_H

#include <string>
#include "ConstantesModelo.h"
#include "ConstantesVentana.h"
#include "../../modelo/juego/Posicion.h"

/// PERSONAJE ///

static constexpr int ENERGIA_PERSONAJE = 100;
static constexpr int FRECUENCIA_DE_DISPARO = 10;

static constexpr int PROPULSION_MAX = 120;
static constexpr int COOLDOWN_PROPULSION = 105;

static constexpr int INCREMENTO_PERSONAJE = 6;
static constexpr int X_PERSONAJE_DEFAULT = ANCHO_FONDO/2;
static constexpr int Y_PERSONAJE_DEFAULT = 100;

static constexpr int CANTIDAD_VIDAS_PERSONAJE = 3;
static constexpr int PERSONAJE_UI_MUERTO = 0;
static constexpr int PERSONAJE_UI_VIVO = 1;
static constexpr int PERSONAJE_UI_DESCONECTADO = 2;
static constexpr int PERSONAJE_UI_DISPARANDO = 3;
static constexpr int PERSONAJE_UI_IMPACTADO = 5; //No es 4 porque en el cliente esta reservado el valor 4 para "disparando_2"
static const std::string UI_CLAVE_PUNTAJE = "Puntaje";
static const std::string UI_CLAVE_VIDAS = "Vidas";
static const std::string UI_CLAVE_ESTADO_PERSONAJE = "Estado_personaje";
static const std::string UI_CLAVE_ENERGIA_PERSONAJE = "Energia_personaje";
static const std::string UI_CLAVE_PUNTAJE_NIVEL_1 = "Puntaje_n1";
static const std::string UI_CLAVE_PUNTAJE_NIVEL_2 = "Puntaje_n2";
static const std::string UI_CLAVE_PUNTAJE_NIVEL_3 = "Puntaje_n3";
static const std::string UI_CLAVE_MODO_TEST = "Test";


static constexpr int DIRECCION_PERSONAJE_IZQUIERDA_DERECHA = 0;
static constexpr int DIRECCION_PERSONAJE_ARRIBA = 1;
static constexpr int DIRECCION_PERSONAJE_ABAJO = 2;

static constexpr int FRENAR_DIRECCION = 0;

#endif //SERVIDOR_CONSTANTESPERSONAJE_H
