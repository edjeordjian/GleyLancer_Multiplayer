#ifndef SERVIDOR_ENEMIGOTIPO2MOVIENDOSE_H
#define SERVIDOR_ENEMIGOTIPO2MOVIENDOSE_H

#include "IEstadoEnemigo.h"
#include "../Enemigo.h"

class Enemigo;


class EnemigoTipo2Moviendose: public IEstadoEnemigo {

private:
    Enemigo* enemigo;
    Posicion direccion;
    int contador;
    int velocidad;
    bool llego_area_jefe;


public:
    EnemigoTipo2Moviendose(Enemigo* enemigo);
    ~EnemigoTipo2Moviendose();
    bool estaQuieto() override;
    void actualizar() override;
    void activar() override;
};


#endif //SERVIDOR_ENEMIGOTIPO2MOVIENDOSE_H
