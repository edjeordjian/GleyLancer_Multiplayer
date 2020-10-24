#ifndef SERVIDOR_JEFE2_H
#define SERVIDOR_JEFE2_H

#include "JefeBase.h"
#include "ArmamentoJefe2.h"

class Jefe2 : public JefeBase {
private:
    int contador_aux_armamento;
public:
    Jefe2(double pos_x,double pos_y, int potencia);
    void setEstado(IEstadoEnemigo* estado_nuevo) override;
    void actualizar(Posicion pos_ventana_personaje) override;
    void setDisparar() override;
    bool esJefe() override;
};


#endif //SERVIDOR_JEFE2_H
