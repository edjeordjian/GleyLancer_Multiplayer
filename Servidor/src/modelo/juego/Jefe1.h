#ifndef SERVIDOR_JEFE1_H
#define SERVIDOR_JEFE1_H

#include "JefeBase.h"
#include "ArmamentoJefe1.h"

class Jefe1 : public JefeBase {
public:
    Jefe1(double pos_x,double pos_y,int potencia);
    bool esJefe() override;
};


#endif //SERVIDOR_JEFE1_H
