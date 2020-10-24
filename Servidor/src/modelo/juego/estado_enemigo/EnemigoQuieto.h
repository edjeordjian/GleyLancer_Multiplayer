#ifndef SERVIDOR_ENEMIGOQUIETO_H
#define SERVIDOR_ENEMIGOQUIETO_H

#include "../Enemigo.h"
#include "IEstadoEnemigo.h"
#include "EnemigoTipo1Moviendose.h"
#include "EnemigoTipo2Moviendose.h"
#include "Jefe1Moviendose.h"
#include "Jefe2Moviendose.h"
#include "Jefe3Moviendose.h"

class Enemigo;

class EnemigoQuieto : public IEstadoEnemigo {
private:
    Enemigo *enemigo;
public:
    EnemigoQuieto(Enemigo *ene);
    ~EnemigoQuieto() override;

    bool estaQuieto() override;

    void actualizar() override;

    void activar() override ;

    Posicion getDireccion();
};


#endif //SERVIDOR_ENEMIGOQUIETO_H
