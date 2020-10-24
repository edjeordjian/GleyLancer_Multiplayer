#ifndef SERVIDOR_ENEMIGO_H
#define SERVIDOR_ENEMIGO_H
#include <string>
#include <stdlib.h>
#include <time.h>
#include "../../tools/constantes/ConstantesJson.h"
#include "../../tools/constantes/ConstantesEnemigos.h"
#include "../../tools/constantes/ConstantesPersonaje.h"
#include "IChocable.h"
#include "Armamento.h"
#include "Posicion.h"
#include "estado_enemigo/IEstadoEnemigo.h"
#include "estado_enemigo/EnemigoQuieto.h"
#include "ArmamentoEnemigo.h"

class Enemigo : public IChocable {
    protected:
        Posicion posicion;
        Posicion pos_ventana;
        Posicion direccion_mirando;
        IEstadoEnemigo* estado;
        std::string tipo;
        bool esta_en_ventana;
        bool direccion_contraria;
        int alto;
        int ancho;
        Armamento* armamento;
        int energia;
        bool daniado;
        int contador_daniado;
        int puntos_al_morir;
        int velocidad;
        Posicion pos_personaje_cercano;

    public:
        Enemigo() = default;
        Enemigo(double pos_x, double pos_y, std::string tipo, int alto, int ancho);
        ~Enemigo();

        void setPosX(double posX);
        double getPosX() override;
        void setPosY(double posY);
        double getPosY() override;
        std::string getTipo();
        virtual void setEstado(IEstadoEnemigo* estado_nuevo);

        void mover(Posicion direccion);
        virtual void actualizar(Posicion pos_personaje);
        void setProyectiles(std::vector<Proyectil*>* proyectiles);
        virtual void setDisparar();
        bool estaDaniado();
        bool estaVivo();
        void actualizarDireccionInicial();

        void actualizarDireccionContraria();

        int getAlto() override;
        int getAncho() override;
        Posicion getPosicionVentana() override;
        void setPosicionVentana(Posicion pos) override;
        bool getEstaEnVentana() override;
        void setEstaEnVentana(bool en_ventana) override;

        bool direccionContraria();

        virtual void impactar(Proyectil* proy);
        void matar();
        int getPuntos();

        void setDireccionContraria(bool dir_derecha);

        int getVelocidad();
        void setPosPersonajeCercano(Posicion pos_ventana);
        Posicion getPosPersonajeCercano();

        virtual bool esJefe();

};

#endif //SERVIDOR_ENEMIGO_H
