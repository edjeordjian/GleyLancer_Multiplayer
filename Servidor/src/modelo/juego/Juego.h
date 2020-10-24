#ifndef SERVIDOR_JUEGO_H
#define SERVIDOR_JUEGO_H

#include <string>
#include <vector>
#include "../../tools/constantes/ConstantesModelo.h"
#include "../../tools/constantes/ConstantesLog.h"
#include "../../tools/constantes/ConstantesPersonaje.h"
#include "../../tools/constantes/ConstantesJson.h"
#include "../../tools/constantes/ConstantesTeclas.h"
#include "../../tools/constantes/ConstantesMensajes.h"
#include "../../tools/Utils.h"
#include "Nivel.h"

class Juego {
    Nivel* nivel;
    int numero_nivel;
    bool nivel_empezado;
    std::vector<int> cantidad_enemigos_nivel_1;
    std::vector<std::string> tipos_enemigos_nivel_1;
    std::vector<Personaje*>* personajes;

    std::vector<int> cantidad_enemigos_nivel_2;
    std::vector<std::string> tipos_enemigos_nivel_2;

    std::vector<int> cantidad_enemigos_nivel_3;
    std::vector<std::string> tipos_enemigos_nivel_3;

    std::vector<JefeBase*> jefes;

    int contador_para_reinicio;
    //Clave: Nombre_jugador, valores: [("puntaje", n_puntaje), ("vidas", cant_vidas), ("estado", estado \\(muerto, vivo, disparando), ("energia", cant_energia)]
    std::vector<std::pair<std::string, std::map<std::string,int>>> tabla_puntaje_vida;

    // Para cerrar el juego si solo quedan desconectados.
    unsigned int timeout_gameover;
    size_t jugadores_desconectados;

public:
    Juego(int n_clientes);
    ~Juego();

    void actualizar();
    void actualizar(int input);

    std::string getEstadoPersonajes();
    std::string getEstadoEnemigos();
    std::string getEstadoFondo();
    std::string getEstadoProyectiles();
    std::string getPuntajePersonaje();
    std::string getEstadoEfectos();
    std::string getEstadoCajas();
    std::string getEstadoItems();
    std::string getPuntajesFinNivel();

    bool gameOver();
    void actualizarPuntajeVida();
    bool hayJugadorVivo();
    void reiniciarNivel();

    void conectarPersonaje(Personaje *per);
    void desconectarPersonaje(int nro_personaje);

    bool getNivelFinalizado();
    void avanzarNivel();

    bool nivelEmpezado();

    int getNumeroNivel();

    bool finalizado();

    void setNombreJugador(int n, std::string nombre);
    std::string getNombreJugador(Uint16 n);
    bool estanTodosLosJugadoresDesconectados();
};

#endif //SERVIDOR_JUEGO_H
