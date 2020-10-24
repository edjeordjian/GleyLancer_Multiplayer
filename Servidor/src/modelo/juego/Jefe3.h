#ifndef SERVIDOR_JEFE3_H
#define SERVIDOR_JEFE3_H

#include "JefeBase.h"
#include "ArmamentoJefe3.h"

class Jefe3 : public JefeBase {
public:
    Jefe3(double pos_x,double pos_y,int potencia);
    void impactar(Proyectil* proy) override;
    void actualizar(Posicion pos_personaje) override;
    bool esJefe() override;
};


#endif //SERVIDOR_JEFE3_H
