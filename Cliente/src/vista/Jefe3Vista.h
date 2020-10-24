#ifndef CLIENTE_JEFE3VISTA_H
#define CLIENTE_JEFE3VISTA_H

#include "EnemigoVista.h"

class Jefe3Vista : public EnemigoVista {
private:
    bool derecha;
    int contador;
public:
    Jefe3Vista(int pos_x, int pos_y, CargadorTexturasEnemigos* cargador);
    void actualizar(int pos_x, int pos_y, int direccion, bool herido) override;
    int getPosicionMov();
};


#endif //CLIENTE_JEFE3VISTA_H
