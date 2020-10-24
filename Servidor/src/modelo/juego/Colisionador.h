#ifndef SERVIDOR_COLISIONADOR_H
#define SERVIDOR_COLISIONADOR_H


#include <vector>
#include "Enemigo.h"

#include "IChocable.h"

class Colisionador {
public:
    Colisionador();
    virtual ~Colisionador();

    static void obtenerVertices(double *vertices, const double *pos_inicial, int ancho, int alto);
    static bool hayColisionesInicialesDeEnemigos(Enemigo *enemigo_nuevo, std::vector<Enemigo *> enemigos);
    static bool hayColision(IChocable *obj1, IChocable *obj2);
};


#endif //SERVIDOR_COLISIONADOR_H
