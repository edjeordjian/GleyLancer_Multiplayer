#ifndef SERVIDOR_NIVEL_H
#define SERVIDOR_NIVEL_H

#include <SDL2/SDL_stdinc.h>
#include <string>
#include <map>
#include <SDL2/SDL.h>
#include "../../tools/constantes/ConstantesJson.h"
#include "../../tools/constantes/ConstantesModelo.h"
#include "../../tools/constantes/ConstantesVentana.h"
#include "../../tools/constantes/ConstantesPersonaje.h"
#include "../../tools/constantes/ConstantesEnemigos.h"
#include "../../tools/constantes/ConstantesTeclas.h"
#include "../../tools/constantes/ConstantesMensajes.h"
#include "Personaje.h"
#include "Ventana.h"
#include "Colisionador.h"
#include "../../tools/Log.h"
#include "../../tools/Utils.h"
#include "Caja.h"
#include "Item.h"
#include "JefeBase.h"
#include "../../tools/SerializadorEstado.h"

class Nivel{
    
    private:
        int nro_nivel;
        std::vector<Enemigo*> enemigos;
        int cantidad_enemigos;
        Ventana* ventana;
        std::vector<Personaje*>* personajes;
        std::vector<Personaje*> personajes_vivos;
        std::vector<Proyectil*>* proyectiles_personajes;
        std::vector<Proyectil*>* proyectiles_enemigos;
        std::vector<Posicion> posicion_efectos_personajes;
        std::vector<Posicion> posicion_efectos_enemigos;
        std::vector<Posicion> posicion_efectos_jefes;
        std::vector<Posicion> posicion_efectos_cajas;
        std::vector<Caja*> cajas;
        std::vector<Item*> items;
        std::vector<JefeBase*> jefes;

        int contador; //Variable momentanea, es condicion para pasar de nivel
        bool finalizado;


public:
        Nivel(std::vector<Personaje*>* pers, std::vector<std::string> tipo_enemigos_nivel,
                std::vector<int> cantidad_enemigos_nivel, std::string tipo_jefe, int n_nivel);
        ~Nivel();

        void desconectarPersonaje(int nro_personaje);

        void actualizar();
        void actualizar(int input, long unsigned nro_personaje);
        void actualizarPersonajes();
        void actualizarProyectiles(std::vector<Proyectil*>* lista_proyectiles);
        void actualizarEnemigos();
        void actualizarCajas();
        void actualizarItems();
        void actualizarVentana();
        void actualizarColisionProyectilConEnemigo();
        void actualizarColisionProyectilConPersonaje();
        void actualizarColisionProyectilConCaja();
        void actualizarColisionPersonajeConEnemigo();
        void actualizarColisionPersonajeConCaja();
        void actualizarColisionPersonajeConItem();

        std::string getEstadoPersonajes();
        std::string getEstadoFondo();
        std::string getEstadoEnemigos();
        std::string getEstadoProyectiles();
        std::string getEstadoEfectos();
        std::string getEstadoCajas();
        std::string getEstadoItems();

        bool getNivelFinalizado();

        void setearProyectiles();
        void crearEnemigos(std::vector<std::string> tipo_enemigos_nivel, std::vector<int> cantidad_enemigos_nivel);
        void limpiarEfectos();
};

#endif //SERVIDOR_NIVEL_H
