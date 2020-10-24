#ifndef SERVIDOR_CONTROLADOR_JUEGO_H
#define SERVIDOR_CONTROLADOR_JUEGO_H

#include <string>
#include "../modelo/juego/Juego.h"
#include "../tools/CargadorDeConfiguracion.h"

/**
 * Clase que se encarga de ser el controlador del juego en un modelo MVC con Cliente - Servidor
 **/

class ControladorJuego {

private:

    /// Atributo que representa al Juego
    Juego *juego;

public:

    /// Constructor de la clase
    ControladorJuego(int n_clientes);

    /// Destructor de la clase
    ~ControladorJuego();

    /// Actualiza al juego con el estado interno actual
    void actualizarJuego();

    /// Actualiza algun atributo del juego segun el input enviado por algun cliente
    void actualizarEstadoJuego(uint16_t input);

    /// Actualiza la tabla de puntajes del juego segun el estado de los personajes en el mismo
    void actualizarPuntajeJuego();

    /// Retorna un string decodificable que representa el estado de los personajes en el juego
    std::string getEstadoPersonajes();

    /// Retorna un string decodificable que representa el estado de los enemigos en el juego
    std::string getEstadoEnemigos();

    /// Retorna un string decodificable que representa el estado del fondo del nivel en el juego
    std::string getEstadoFondo();

    /// Retorna un string decodificable que representa el estado de los proyectiles_personajes en el juego
    std::string getEstadoProyectiles();

    /// Retorna un string decodificable que representa el estado de los puntajes en el juego
    std::string getEstadoPuntaje();

    /// Retorna un string decodificable que representa el estado de los efectos (ej: explosiones) en el juego
    std::string getEstadoEfectos();

    /// Retorna un string decodificable que representa el estado de las cajas de items en el juego
    std::string getEstadoCajas();

    /// Retorna un string decodificable que representa el estado de los items en el juego
    std::string getEstadoItems();

    /// Retorna un string decodificable que contiene los puntajes de los personajes ordenados de forma descendente
    std::string getPuntajesFinNivel();

    /// Retorna un valor booleano si queda algun personaje vivo en el juego
    /// TRUE -> hay jugador vivo, FALSE -> no hay jugador vivo
    bool hayJugadorVivo();

    /// Reinicia el nivel actual del juego
    void reiniciarNivel();

    /// Retorna el numero de nivel actual del juego (0, 1 o 2)
    int getNumeroNivel();

    /// Retorna un valor booleano si el nivel actual del juego ya ha comenzado
    /// TRUE -> nivel comenzado, FALSE -> nivel no comenzado
    bool nivelEmpezado();

    /// Retorna un valor booleano si el nivel actual del juego ya ha finalizado
    /// TRUE -> nivel finalizado, FALSE -> nivel no finalizado
    bool nivelFinalizado();

    /// Retorna un valor booleano si el juego ha finalizado y se ha ganado
    /// TRUE -> partida ganada, FALSE -> partida no ganada
    bool juegoGanado();

    /// Retorna un valor booleano si el juego ha finalizado y si ha perdido
    /// (Game over = destruccion de todos los personajes)
    /// TRUE -> partida perdida, FALSE -> partida no perdida
    bool juegoPerdido();

    /// Setea el personaje asociado al numero de cliente como conectado en el juego
    void desconectarPersonaje(int nro_cliente);

    /// Setea el nombre del jugador al personaje asociado al numero de cliente
    void setNombreJugador(int nro_cliente, std::string nombre);

    bool estanTodosLosJugadoresDesconectados();
};

#endif //SERVIDOR_CONTROLADOR_JUEGO_H
