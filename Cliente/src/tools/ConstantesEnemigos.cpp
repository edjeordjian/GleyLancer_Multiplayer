#include "ConstantesEnemigo.h"

static int ANCHO_ENEMIGO_1;
static int ALTO_ENEMIGO_1;
static int ANCHO_ENEMIGO_2;
static int ALTO_ENEMIGO_2;
static int TAM_ANCHO_ENEMIGO_1;
static int TAM_ANCHO_ENEMIGO_2;
static int TAM_ALTO_ENEMIGO_1;
static int TAM_ALTO_ENEMIGO_2;
static std::string TIPO_ENEMIGO_1;
static std::string TIPO_ENEMIGO_2;
static std::string RUTA_IMAGEN_ENEMIGO_1;
static std::string RUTA_IMAGEN_ENEMIGO_2;

std::string getTipoEnemigo1() {
    return TIPO_ENEMIGO_1;
}

std::string getTipoEnemigo2() {
    return TIPO_ENEMIGO_2;
}

char *getRutaImagenEnemigo1() {
    return (char *) RUTA_IMAGEN_ENEMIGO_1.c_str();
}

char *getRutaImagenEnemigo2() {
    return (char *) RUTA_IMAGEN_ENEMIGO_2.c_str();
}

int getAnchoEnemigo1() {
    return ANCHO_ENEMIGO_1;
}

int getAnchoEnemigo2() {
    return ANCHO_ENEMIGO_2;
}

int getAltoEnemigo1() {
    return ALTO_ENEMIGO_1;
}

int getAltoEnemigo2() {
    return ALTO_ENEMIGO_2;
}

int getTamAnchoEnemigo1() {
    return TAM_ANCHO_ENEMIGO_1;
}

int getTamAnchoEnemigo2() {
    return TAM_ANCHO_ENEMIGO_2;
}

int getTamAltoEnemigo1() {
    return TAM_ALTO_ENEMIGO_1;
}

int getTamAltoEnemigo2() {
    return TAM_ALTO_ENEMIGO_2;
}


void setTipoEnemigo1(std::string tipo) {
    TIPO_ENEMIGO_1 = tipo;
    RUTA_IMAGEN_ENEMIGO_1 = tipos_enemigos_imagen[tipo];
    ANCHO_ENEMIGO_1 = (int) anchos_enemigo[tipo];
    ALTO_ENEMIGO_1 = (int) altos_enemigos[tipo];
    TAM_ALTO_ENEMIGO_1 = (int) tam_altos_enemigos[tipo];
    TAM_ANCHO_ENEMIGO_1 = (int) tam_anchos_enemigos[tipo];
}

void setTipoEnemigo2(std::string tipo) {
    TIPO_ENEMIGO_2 = tipo;
    RUTA_IMAGEN_ENEMIGO_2 = tipos_enemigos_imagen[tipo];
    ANCHO_ENEMIGO_2 = (int) anchos_enemigo[tipo];
    ALTO_ENEMIGO_2 = (int) altos_enemigos[tipo];
    TAM_ALTO_ENEMIGO_2 = (int) tam_altos_enemigos[tipo];
    TAM_ANCHO_ENEMIGO_2 = (int) tam_anchos_enemigos[tipo];
}
