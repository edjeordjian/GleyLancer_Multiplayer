#ifndef SERVIDOR_CONSTANTESTECLAS_H
#define SERVIDOR_CONSTANTESTECLAS_H

#include <bits/stdc++.h>

/// TECLAS (para recibir) ///
static constexpr uint16_t COLA_VACIA = 65535;

static constexpr uint16_t TECLA_ARRIBA = 1;
static constexpr uint16_t TECLA_IZQUIERDA = 2;
static constexpr uint16_t TECLA_ABAJO = 3;
static constexpr uint16_t TECLA_DERECHA = 4;
static constexpr uint16_t TECLAS_ARRIBA_IZQUIERDA = 5;
static constexpr uint16_t TECLAS_ARRIBA_DERECHA = 6;
static constexpr uint16_t TECLAS_ABAJO_IZQUIERDA = 7;
static constexpr uint16_t TECLAS_ABAJO_DERECHA = 8;
static constexpr uint16_t TECLA_NINGUNA = 10;
static constexpr uint16_t TECLA_LISTO = 11;
static constexpr uint16_t TECLA_DISPARAR = 12;
static constexpr uint16_t TECLA_NO_DISPARAR = 13;
static constexpr Uint16 TECLA_TEST = 14;
static constexpr Uint16 TECLA_PROPULSION = 15;

static constexpr uint16_t TECLA_PING_RECIBIDO = 500;

static constexpr uint16_t TECLA_FIN_NOMBRE = 1038;
static constexpr uint16_t TECLA_FIN_PASS = 1039;

static constexpr uint16_t TECLA_JUEGO_MAX = 1000;


static std::map<uint16_t, std::string> mapeo_nro_letra = {
        { 1001, "A" }, { 1002, "B" }, { 1003, "C"}, { 1004, "D" }, { 1005, "E" }, { 1006, "F" },
        { 1007, "G" }, { 1008, "H" }, { 1009, "I"}, { 1010, "J" }, { 1011, "K" }, { 1012, "L" },
        { 1013, "M" }, { 1014, "N" }, { 1015, "O"}, { 1016, "P" }, { 1017, "Q" }, { 1018, "R" },
        { 1019, "S" }, { 1020, "T" }, { 1021, "U"}, { 1022, "V" }, { 1023, "W" }, { 1024, "X" },
        { 1025, "Y" }, { 1026, "Z" },

        { 1027, "0"}, { 1028, "1" }, { 1029, "2" }, { 1030, "3" },
        { 1031, "4" }, { 1032, "5" }, { 1033, "6"}, { 1034, "7" }, { 1035, "8" }, { 1036, "9" },
        { 1037, "." },

        { 1040, "a" }, { 1041, "b" }, { 1042, "c"}, { 1043, "d" }, { 1044, "e" }, { 1045, "f" },
        { 1046, "g" }, { 1047, "h" }, { 1048, "i"}, { 1049, "j" }, { 1050, "k" }, { 1051, "l" },
        { 1052, "m" }, { 1053, "n" }, { 1054, "o"}, { 1055, "p" }, { 1056, "q" }, { 1057, "r" },
        { 1058, "s" }, { 1059, "t" }, { 1060, "u"}, { 1061, "v" }, { 1062, "w" }, { 1063, "x" },
        { 1064, "y" }, { 1065, "z" }
};

#endif //SERVIDOR_CONSTANTESTECLAS_H
