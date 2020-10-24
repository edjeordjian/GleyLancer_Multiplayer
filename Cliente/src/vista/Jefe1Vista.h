#ifndef CLIENTE_JEFE1VISTA_H
#define CLIENTE_JEFE1VISTA_H

#include "EnemigoVista.h"

class Jefe1Vista : public EnemigoVista {
private:
    int contador;
    bool derecha;


public:
    Jefe1Vista(int pos_x, int pos_y, CargadorTexturasEnemigos* cargador);
    void actualizar(int pos_x, int pos_y, int direccion, bool herido) override;
    int getPosicionMov();
};


#endif //CLIENTE_JEFE1VISTA_H
