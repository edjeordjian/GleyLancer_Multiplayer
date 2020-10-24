#ifndef SERVIDOR_JEFE1MOVIENDOSE_H
#define SERVIDOR_JEFE1MOVIENDOSE_H

#include "IEstadoEnemigo.h"
#include <stdlib.h>
#include <time.h>
#include "../Enemigo.h"
#include "../Posicion.h"
#include "EnemigoQuieto.h"

class Enemigo;

class Jefe1Moviendose: public IEstadoEnemigo {
private:
    Enemigo* jefe;
    Posicion direccion;
    int velocidad;

public:
    Jefe1Moviendose(Enemigo* enemigo);
    ~Jefe1Moviendose();
    void  activar() override ;
    bool estaQuieto() override ;
    void actualizar() override ;
    //Ia jefe 1: Alinearse
    void actualizarDireccionHorizontal(Posicion pos_ventana_jefe);
    void actualizarDireccionVertical(Posicion pos_ventana_jefe);

};


#endif //SERVIDOR_JEFE1MOVIENDOSE_H
