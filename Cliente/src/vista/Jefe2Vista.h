#ifndef CLIENTE_JEFE2VISTA_H
#define CLIENTE_JEFE2VISTA_H

#include "EnemigoVista.h"

class Jefe2Vista : public EnemigoVista {

private:
    int contador;
    int pos_x_vieja;
    int pos_y_vieja;

public:
    Jefe2Vista(int pos_x, int pos_y, CargadorTexturasEnemigos* cargador);
    void actualizar(int pos_x, int pos_y, int direccion, bool herido) override;
    int getPosRotacion();
};


#endif //CLIENTE_JEFE2VISTA_H
