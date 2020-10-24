#ifndef SERVIDOR_JEFEBASE_H
#define SERVIDOR_JEFEBASE_H

#include "Enemigo.h"

class JefeBase : public Enemigo {

    public:
        JefeBase(double pos_x,double pos_y);
        ~JefeBase();
};


#endif //SERVIDOR_JEFEBASE_H
