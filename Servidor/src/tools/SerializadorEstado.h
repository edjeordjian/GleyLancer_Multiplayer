#ifndef SERVIDOR_SERIALIZADORESTADO_H
#define SERVIDOR_SERIALIZADORESTADO_H

#include <string>
#include <vector>
#include "../modelo/juego/Personaje.h"
#include "../modelo/juego/Enemigo.h"
#include "../modelo/juego/Caja.h"
#include "../modelo/juego/Ventana.h"

std::string getEstadoPersonajes(std::vector<Personaje*>* personajes);
std::string getEstadoEnemigos(std::vector<Enemigo*>* enemigos);
std::string getEstadoProyectiles(std::vector<Proyectil*>* proyectiles_personajes,std::vector<Proyectil*>* proyectiles_enemigos);
std::string getEstadoCajas(std::vector<Caja*>* cajas);
std::string getEstadoItems(std::vector<Item*>* items);
std::string getEstadoFondo(Ventana* ventana);
std::string getEstadoEfectoPersonaje(std::vector<Posicion> pos_efectos);
std::string getEstadoEfectoEnemigo(std::vector<Posicion> pos_efectos);
std::string getEstadoEfectoJefe(std::vector<Posicion> pos_efectos);
std::string getEstadoEfectoCaja(std::vector<Posicion> pos_efectos);
std::string getEstadoEfecto(std::string estado, unsigned int cantidad_tipos_efecto);
std::string getPosEstadoEfectos(std::vector<Posicion> pos_efectos);
void cargarMapaTipos(Proyectil* p, std::map<int, std::pair<long unsigned, std::string>>* tipos);


#endif //SERVIDOR_SERIALIZADORESTADO_H
