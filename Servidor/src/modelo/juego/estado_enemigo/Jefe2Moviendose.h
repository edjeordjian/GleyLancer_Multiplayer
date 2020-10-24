#ifndef SERVIDOR_JEFE2MOVIENDOSE_H
#define SERVIDOR_JEFE2MOVIENDOSE_H

#include "IEstadoEnemigo.h"
#include <stdlib.h>
#include <time.h>
#include "../Enemigo.h"
#include "../Posicion.h"
#include "EnemigoQuieto.h"

class Jefe2Moviendose : public IEstadoEnemigo {

private:
    Enemigo* jefe;
    Posicion direccion;
    int contador;
    int velocidad;
    int correccion;
    Posicion pos_final;

public:
    Jefe2Moviendose(Enemigo* enemigo);
    ~Jefe2Moviendose();
    void  activar() override ;
    bool estaQuieto() override ;
    void actualizar() override ;
    //Ia jefe 2: cargar contra personaje
    Posicion obtenerProximaDireccion(Posicion pos);
};


#endif //SERVIDOR_JEFE2MOVIENDOSE_H
