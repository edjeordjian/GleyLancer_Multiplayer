#ifndef SERVIDOR_CONSTANTESVENTANA_H
#define SERVIDOR_CONSTANTESVENTANA_H

#include <string>
#include "ConstantesGenerales.h"

/// VENTANA ///
static constexpr int ANCHO_VENTANA = 800;
static constexpr int ALTO_VENTANA = 600;
//Ancho fondo = Ancho_imagen_fondo * 2 (para que aparezcan enemigos izquierda) * ESCALA_FONDO (para que entren mas enemigos en el nivel)
static constexpr int ANCHO_FONDO = 4000*2*ESCALA_FONDO;

static constexpr int CANTIDAD_NIVELES = 3;
static constexpr int TIEMPO_FIN_NIVEL = 180; // 2 SEGUNDOS --> 2 * 60 fps


#endif //SERVIDOR_CONSTANTESVENTANA_H
