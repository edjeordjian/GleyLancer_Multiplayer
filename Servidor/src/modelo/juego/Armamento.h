#ifndef SERVIDOR_ARMAMENTO_H
#define SERVIDOR_ARMAMENTO_H

#include <bits/stdc++.h>
#include "../../tools/constantes/ConstantesJson.h"
#include "../../tools/constantes/ConstantesVentana.h"
#include "../../tools/constantes/ConstantesPersonaje.h"
#include "Posicion.h"
#include "Proyectil.h"

class Armamento {
protected:
    int cooldown;
    int cooldown_inicial;
    int nro_personaje;
    bool estaDisparando;
    std::vector<Proyectil *> *proyectiles;
    int potencia;

public:
    Armamento(int nro_personaje, int potencia_proyectiles);

    virtual ~Armamento() = default;

    //Direccion unitaria, es decir de la forma (1,0) o (0,1) por ejemplo
    virtual Proyectil *usar(Posicion pos_inic, Posicion direccion);

    bool getEstaDisparando();

    virtual void setEstaDisparando(bool disparando);

    int getNumeroPersonaje();

    std::vector<Proyectil *> *getProyectiles();

    void setProyectiles(std::vector<Proyectil *> *lista_proyectiles);

    virtual void actualizar(Posicion pos, Posicion direccion);
};


#endif //SERVIDOR_ARMAMENTO_H
