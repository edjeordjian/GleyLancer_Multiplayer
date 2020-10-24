#ifndef SERVIDOR_PROYECTIL_H
#define SERVIDOR_PROYECTIL_H

#include "../../tools/constantes/ConstantesJson.h"
#include "../../tools/constantes/ConstantesModelo.h"
#include "../../tools/constantes/ConstantesVentana.h"
#include "../../tools/constantes/ConstantesPersonaje.h"
#include "../../tools/constantes/ConstantesEnemigos.h"
#include "Posicion.h"
#include "../../tools/SDL_Utils.h"
#include "IChocable.h"

class Proyectil : public IChocable {
private:
    int alcance;
    Posicion pos_inicial;
    Posicion pos;
    Posicion pos_ventana;
    bool esta_en_ventana;
    Posicion direccion;
    //Debe ser mas grande que el ancho del sprite
    int velocidad;
    bool destruido;
    int ancho;
    int alto;
    int nro_personaje;
    int potencia;
    int actualizaciones;
    bool es_nuevo;

public:
    Proyectil(int alcance_proyectil, Posicion pos_inic, Posicion direccion_proyectil, int pot_nueva);
    Proyectil(Posicion pos_inic, Posicion direccion_proyectil, int pot_nueva);
    ~Proyectil();
    void actualizar();
    void mover(Posicion dir);
    void destruir();
    bool estaDestruido();
    bool esNuevo();
    int getNumeroPersonaje();
    void setNumeroPersonaje(int numero_personaje);
    int getDireccion();
    int getAncho() override;
    int getAlto() override;
    double getPosX() override;
    double getPosY() override;
    Posicion getPosicionVentana() override;
    void setPosicionVentana(Posicion pos_nueva) override;
    bool getEstaEnVentana() override;
    void setEstaEnVentana(bool en_ventana) override;
    int getPotencia();

};

#endif //SERVIDOR_PROYECTIL_H
