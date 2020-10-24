#ifndef SERVIDOR_PERSONAJE_H
#define SERVIDOR_PERSONAJE_H

#include <string>
#include <iostream>
#include "../../tools/constantes/ConstantesJson.h"
#include "../../tools/constantes/ConstantesPersonaje.h"
#include "Posicion.h"
#include "estado_personaje/IEstadoPersonaje.h"
#include "IChocable.h"
#include "Armamento.h"
#include "Item.h"
#include "estado_personaje/PersonajeQuieto.h"
#include "estado_personaje/PersonajeMoviendose.h"

class Item;

class Personaje : public IChocable {
private:
    Posicion posicion;
    Posicion pos_ventana;
    int incremento;
    std::string nombre;
    Posicion direccion_mirando;
    IEstadoPersonaje* estado;
    bool listo;
    bool conectado;
    int nro_personaje;
    Armamento* armamento;
    int vidas;
    int ancho;
    int alto;
    int puntaje;
    Item* item;
    int energia;
    int contador_daniado;
    bool modo_test;
    std::vector<int> puntajes_nivel;
    int contador_propulsion;
    int contador_item;
    bool escudo;

public:
    Personaje(double pos_x, double pos_y, int incremento, int n_personaje , int cant_vidas);
    ~Personaje();

    void setPosX(double posX);
    void setPosY(double posY);

    int getPuntaje();
    int getPuntajeNivel(int nro_nivel);
    void setPuntaje(int nuevo_puntaje);
    //El puntaje del nivel sera entre 1 y 3
    void agregarPuntaje(int nuevo_puntaje, int nro_nivel);

    void setNombre(std::string nombre);
    std::string getNombre();

    void setConectado(bool estado_actual_conectado);
    bool estaConectado();

    int getAncho() override;
    int getAlto() override;
    double getPosX() override;
    double getPosY() override;
    bool getEstaEnVentana() override;
    void setEstaEnVentana(bool en_ventana) override;
    Posicion getPosicionVentana() override;
    void setPosicionVentana(Posicion pos_nueva) override;

    void actualizarColision(Posicion pos_colision);

    void setEstado(IEstadoPersonaje* estado_nuevo);
    void mover(Posicion direccion);
    bool estaQuieto();
    void actualizar();
    void actualizar(Posicion direccion);
    //Devuelve la constante que representa a que direccion esta mirando
    int getDireccion();
    int getNumeroPersonaje();

    void setListo(bool estado_listo);
    bool estaListo();

    bool estaDaniado();
    bool estaVivo();
    int getVidas();
    void matar();
    void disparar();
    void dejarDeDisparar();
    bool estaDisparando();
    void setProyectiles(std::vector<Proyectil*>* lista_proyectiles);

    void agarrarItem(Item* item_nuevo);
    int getEnergia();
    void reiniciarEnergia();
    void impactar(int potencia);
    void setTest();
    bool getTest();

    void activarPropulsion();
    bool estaPropulsionando();
    void dejarDePropulsionar();
    bool agarroItem();
    void removerItem();

    void sumarVida();
    void agregarEnergia(int energia_extra);
    void agregarEscudo();
    bool tieneEscudo();
};


#endif //SERVIDOR_PERSONAJE_H
