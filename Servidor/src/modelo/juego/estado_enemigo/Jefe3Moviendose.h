#ifndef SERVIDOR_JEFE3MOVIENDOSE_H
#define SERVIDOR_JEFE3MOVIENDOSE_H

#include "IEstadoEnemigo.h"
#include <stdlib.h>
#include <time.h>
#include "../Enemigo.h"
#include "../Posicion.h"
#include "EnemigoQuieto.h"

class Enemigo;

class Jefe3Moviendose: public IEstadoEnemigo  {
private:
    Enemigo* jefe;
    Posicion direccion;
    int velocidad;

public:
    Jefe3Moviendose(Enemigo* enemigo);
    ~Jefe3Moviendose();
    void  activar() override ;
    bool estaQuieto() override ;
    void actualizar() override ;

};


#endif //SERVIDOR_JEFE3MOVIENDOSE_H
