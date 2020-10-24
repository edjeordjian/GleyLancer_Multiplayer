#ifndef SERVIDOR_POSICION_H
#define SERVIDOR_POSICION_H

#include <vector>
#include <math.h>
#include "../../tools/SDL_Utils.h"

class Posicion {
private:
    std::vector<double> pos;

public:
    Posicion();
    //Crea direccion unitaria rotada en "angulo" radianes
    Posicion(double angulo);
    Posicion(double pos_x, double pos_y);
    Posicion(const Posicion& pos_copia);
    ~Posicion();
    double getX() const;
    double getY() const;
    double distancia(Posicion otra_posicion);
    Posicion direccion(Posicion otra_posicion);
    Posicion normalizar();
    void setX(double new_x);
    void setY(double new_y);
    Posicion& operator+=(Posicion otra_posicion);
    Posicion& operator-=(Posicion otra_posicion);
    bool operator==(Posicion otra_posicion);
    bool operator!=(Posicion otra_posicion);
    Posicion operator+(Posicion otra_posicion);
    Posicion operator*(double entero);

};


#endif //SERVIDOR_POSICION_H
