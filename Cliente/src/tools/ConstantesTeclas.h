#ifndef CLIENTE_CONSTANTESTECLAS_H
#define CLIENTE_CONSTANTESTECLAS_H

#include <SDL2/SDL.h>
#include <bits/stdc++.h>

/// TECLAS (para enviar) ///
static constexpr Uint16 TECLA_ARRIBA = 1;
static constexpr Uint16 TECLA_IZQUIERDA = 2;
static constexpr Uint16 TECLA_ABAJO = 3;
static constexpr Uint16 TECLA_DERECHA = 4;
static constexpr Uint16 TECLAS_ARRIBA_IZQUIERDA = 5;
static constexpr Uint16 TECLAS_ARRIBA_DERECHA = 6;
static constexpr Uint16 TECLAS_ABAJO_IZQUIERDA = 7;
static constexpr Uint16 TECLAS_ABAJO_DERECHA = 8;
static constexpr Uint16 TECLA_NINGUNA = 10;
static constexpr Uint16 TECLA_LISTO = 11;
static constexpr Uint16 TECLA_DISPARAR = 12;
static constexpr Uint16 TECLA_NO_DISPARAR = 13;
static constexpr Uint16 TECLA_TEST = 14;
static constexpr Uint16 TECLA_PROPULSION = 15;

static constexpr Uint16 TECLA_PING_RECIBIDO = 500;

static constexpr Uint16 TECLA_FIN_NOMBRE = 1038;
static constexpr Uint16 TECLA_FIN_PASS = 1039;

static std::map<char, Uint16> mapeo_letras = {
        //letras mayúsculas
        {65, 1001}, {66, 1002}, {67, 1003}, {68, 1004}, {69, 1005}, {70, 1006},
        {71, 1007}, {72, 1008}, {73, 1009}, {74, 1010}, {75, 1011}, {76, 1012},
        {77, 1013}, {78, 1014}, {79, 1015}, {80, 1016}, {81, 1017}, {82, 1018},
        {83, 1019}, {84, 1020}, {85, 1021}, {86, 1022}, {87, 1023}, {88, 1024},
        {89, 1025}, {90, 1026},
        // números del 0 al 9
        {48, 1027}, {49, 1028}, {50, 1029}, {51, 1030}, {52, 1031}, {53, 1032},
        {54, 1033}, {55, 1034}, {56, 1035}, {57, 1036},
        // punto
        {46, 1037},
        // letras minúsculas
        {97, 1040}, {98, 1041}, {99, 1042}, {100, 1043}, {101, 1044}, {102, 1045},
        {103, 1046}, {104, 1047}, {105, 1048}, {106, 1049}, {107, 1050}, {108, 1051},
        {109, 1052}, {110, 1053}, {111, 1054}, {112, 1055}, {113, 1056}, {114, 1057},
        {115, 1058}, {116, 1059}, {117, 1060}, {118, 1061}, {119, 1062}, {120, 1063},
        {121, 1064}, {122, 1065}
};


#endif //CLIENTE_CONSTANTESTECLAS_H
