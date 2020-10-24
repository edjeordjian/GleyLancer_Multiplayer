#include "JefeBase.h"

JefeBase::JefeBase(double pos_x,double pos_y) : Enemigo(){
    this->posicion=Posicion(pos_x, pos_y);
    this->estado=new EnemigoQuieto(this);
    this->direccion_contraria=false;
    this->esta_en_ventana=false;
    this->daniado=false;
    this->contador_daniado=0;
    //Cada jefe asigna su propio armamento
    this->armamento = nullptr;
    this->energia = ENERGIA_JEFE;
    this->puntos_al_morir = PUNTOS_AL_MORIR_JEFE;
    this->direccion_mirando=POS_IZQUIERDA;
}

JefeBase::~JefeBase(){
    //Llama al destructor de la clase padre (destructor de Enemigo)
}