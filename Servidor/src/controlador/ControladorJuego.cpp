#include "ControladorJuego.h"


ControladorJuego::ControladorJuego(int n_clientes) {
    this->juego = new Juego(n_clientes);
}

ControladorJuego::~ControladorJuego() {
    delete (this->juego);
}

void ControladorJuego::actualizarJuego() {
    this->juego->actualizar();
}

void ControladorJuego::actualizarEstadoJuego(uint16_t input) {
    this->juego->actualizar(input);
}

void ControladorJuego::actualizarPuntajeJuego() {
    this->juego->actualizarPuntajeVida();
}

std::string ControladorJuego::getEstadoPersonajes() {
    return this->juego->getEstadoPersonajes();
}

std::string ControladorJuego::getEstadoEnemigos() {
    return this->juego->getEstadoEnemigos();
}

std::string ControladorJuego::getEstadoFondo() {
    return this->juego->getEstadoFondo();
}

std::string ControladorJuego::getEstadoProyectiles() {
    return this->juego->getEstadoProyectiles();
}

std::string ControladorJuego::getEstadoEfectos() {
    return this->juego->getEstadoEfectos();
}

std::string ControladorJuego::getEstadoPuntaje() {
    return this->juego->getPuntajePersonaje();
}

std::string ControladorJuego::getEstadoCajas() {
    return this->juego->getEstadoCajas();
}

std::string ControladorJuego::getEstadoItems() {
    return this->juego->getEstadoItems();
}

std::string ControladorJuego::getPuntajesFinNivel(){
    return this->juego->getPuntajesFinNivel();
}

bool ControladorJuego::hayJugadorVivo() {
    return this->juego->hayJugadorVivo();
}

void ControladorJuego::reiniciarNivel() {
    this->juego->reiniciarNivel();
}

int ControladorJuego::getNumeroNivel() {
    return this->juego->getNumeroNivel();
}

bool ControladorJuego::nivelEmpezado() {
    return this->juego->nivelEmpezado();
}

bool ControladorJuego::nivelFinalizado() {
    return this->juego->getNivelFinalizado();
}

bool ControladorJuego::juegoGanado() {
    return this->juego->finalizado();
}

bool ControladorJuego::juegoPerdido() {
    return this->juego->gameOver();
}

void ControladorJuego::desconectarPersonaje(int nro_cliente) {
    this->juego->desconectarPersonaje(nro_cliente);
}

void ControladorJuego::setNombreJugador(int n, std::string nombre) {
    this->juego->setNombreJugador(n, nombre);
}

bool ControladorJuego::estanTodosLosJugadoresDesconectados(){
    return this->juego->estanTodosLosJugadoresDesconectados();
}
