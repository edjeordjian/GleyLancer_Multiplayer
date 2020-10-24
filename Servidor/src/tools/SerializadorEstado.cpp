#include "SerializadorEstado.h"
#include "constantes/ConstantesMensajes.h"


/** Pre_pos_personaje + Cantidad_personajes_vivos + n_personaje_1 + x_1 + y_1 + dir_1 + disparando_1 +
** n_personaje_2 + ... + n_personaje_k + x_k + y_k + dir_k + disparando_k **/

std::string getEstadoPersonajes(std::vector<Personaje*>* personajes){

    std::string estado = PRE_POSICION_JUGADOR + MSJ_SEPARADOR + std::to_string((int) (*personajes).size());
    for (auto & personaje : (*personajes)){

        if( (int) personaje->estaConectado() ){
            estado += (MSJ_SEPARADOR +
                       std::to_string((int)personaje->getNumeroPersonaje()));
        }
        else{
            estado += (MSJ_SEPARADOR +
                       MSJ_NUMERO_PERSONAJE_DESCONECTADO);
        }

        estado += MSJ_SEPARADOR +
                  std::to_string((int) personaje->getPosicionVentana().getX()) +
                  MSJ_SEPARADOR +
                  std::to_string((int) personaje->getPosicionVentana().getY()) +
                  MSJ_SEPARADOR +
                  std::to_string((int) personaje->getDireccion()) +
                  MSJ_SEPARADOR +
                  std::to_string((int) personaje->estaDisparando()) +
                  MSJ_SEPARADOR +
                  std::to_string((int) personaje->estaDaniado()) +
                  MSJ_SEPARADOR +
                  std::to_string((int) personaje->tieneEscudo()) +
                  MSJ_SEPARADOR +
                  std::to_string((int) personaje->estaPropulsionando()) +
                  MSJ_SEPARADOR +
                  std::to_string((int) personaje->agarroItem());
    }
    return estado;
}

/** Pre_pos_enemigo + Cantidad_tipos_enemigos + tipo_1 + cantidad_enemigos_tipo_1 + x_1_tipo_1 + y_1_tipo_1 + x_2_tipo_1 +
    y_2_tipo_1 + ... + tipo_k + cantidad_enemigos_tipo_k + x_1_tipo_k + y_1_tipo_k + x_2_tipo_k + y_2_tipo_k    **/

std::string getEstadoEnemigos(std::vector<Enemigo*>* enemigos){
    std::string estado = (PRE_POSICION_ENEMIGO);
    long unsigned cantidad;
    std::map<std::string, std::pair<long unsigned, std::string>> tipos;
    std::string posiciones_enemigos;

    int dir;

    for (auto &i: (*enemigos)){
        if (i->getEstaEnVentana()){
            if (i->direccionContraria()) {
                dir = DIRECCION_ENEMIGO_DERECHA;
            } else {
                dir = DIRECCION_ENEMIGO_IZQUIERDA;
            }
            posiciones_enemigos = (SEPARADOR +
                                   std::to_string((int)i->getPosicionVentana().getX()) +
                                   SEPARADOR +
                                   std::to_string((int)i->getPosicionVentana().getY()) +
                                   SEPARADOR +
                                   std::to_string(dir) +
                                   SEPARADOR +
                                   std::to_string(i->estaDaniado())
            );
            if(tipos.find(i->getTipo()) != tipos.end()) {
                tipos[std::string(i->getTipo())].first = tipos[std::string(i->getTipo())].first + 1;
                tipos[std::string(i->getTipo())].second += posiciones_enemigos;
            } else {
                tipos[std::string(i->getTipo())].first = 1;
                tipos[std::string(i->getTipo())].second = posiciones_enemigos;
            }
        }

    }
    long unsigned cantidad_de_clases = tipos.size();

    estado += (SEPARADOR + std::to_string(cantidad_de_clases));

    for(auto & tipo : tipos){
        //Tipo enemigo:
        estado += (SEPARADOR + tipo.first);
        //Cantidad tipo enemigo:
        cantidad = tipo.second.first;
        estado += (SEPARADOR + std::to_string(cantidad));
        //Posiciones de enemigos de ese tipo
        estado += tipo.second.second;
    }
    return estado;
}


/** Pre_pos_proyectiles + Cantidad_tipos_proyectiles + numero_jugador + cantidad_proyectiles_jugador_1 + x_1_tipo_1 + y_1_tipo_1 + x_2_tipo_1 +
    y_2_tipo_1 + ... + tipo_k + cantidad_proyectiles_jugador_k + x_1_tipo_k + y_1_tipo_k + x_2_tipo_k + y_2_tipo_k
    + tipo_k+1 + cantidad-proyectiles_personajes-enemigos + x_1_tipo_k+1 + + y_1_tipo_k+1 + ... + x_n_tipo_k+1 + + y_n_tipo_k+1 **/

std::string getEstadoProyectiles(std::vector<Proyectil*>* proyectiles_personajes,std::vector<Proyectil*>* proyectiles_enemigos){
    std::string estado = (PRE_POSICION_PROYECTILES);
    long unsigned cantidad;
    std::map<int, std::pair<long unsigned, std::string>> tipos;
    std::string posiciones_proyectiles;
    std::string proyectil_es_nuevo;
    for (auto &i: (*proyectiles_personajes)) {
        cargarMapaTipos(i,&tipos);
    }
    for (auto &i: (*proyectiles_enemigos)) {
       cargarMapaTipos(i,&tipos);
    }

    long unsigned cantidad_de_clases = tipos.size();
    estado += (SEPARADOR + std::to_string(cantidad_de_clases));
    for (auto & tipo : tipos) {
        //Tipo proyectil:
        estado += (SEPARADOR + std::to_string(tipo.first));
        //Cantidad tipo proyectil:
        cantidad = tipo.second.first;
        estado += (SEPARADOR + std::to_string(cantidad));
        //Posiciones de proyectiles_personajes de ese tipo y si es nuevo o no
        estado += tipo.second.second;
    }
    return estado;
}

std::string getEstadoCajas(std::vector<Caja*>* cajas){
    std::string estado;
    unsigned long cantidad = 0;
    for( auto &caja: (*cajas)){
        if (caja->getEstaEnVentana()){
            estado += MSJ_SEPARADOR;
            estado += std::to_string((int)caja->getPosicionVentana().getX());
            estado +=MSJ_SEPARADOR;
            estado += std::to_string((int)caja->getPosicionVentana().getY());
            cantidad++;
        }
    }
    estado = PRE_CAJAS + MSJ_SEPARADOR + std::to_string(cantidad) + MSJ_SEPARADOR + estado;
    return estado;
}

std::string getEstadoItems(std::vector<Item*>* items){
    //Pre_pos_items + Cantidad_tipos_items + tipo_item_1 + cantidad_items_tipo_1 + x_1_tipo_1 + y_1_tipo_1 + x_2_tipo_1 +
    //y_2_tipo_1 + ... + tipo_item_k + cantidad_items_tipo_k + x_1_tipo_k + y_1_tipo_k + x_2_tipo_k + y_2_tipo_k
    std::string estado = (PRE_ITEMS);
    int cantidad;
    //Clave: Tipo item, valor: (cantidad_tipo_item, posiciones_items)
    std::map<int, std::pair<int, std::string>> tipos;
    std::string posiciones_items;
    for (auto &i: (*items)) {
        if (i->getEstaEnVentana()) {
            posiciones_items = (SEPARADOR +
                                std::to_string((int) i->getPosicionVentana().getX()) +
                                SEPARADOR +
                                std::to_string((int) i->getPosicionVentana().getY())
            );
            if (tipos.find(i->getTipo()) != tipos.end()) {
                tipos[i->getTipo()].first = tipos[i->getTipo()].first + 1;
                tipos[i->getTipo()].second += posiciones_items;
            } else {
                tipos[i->getTipo()].first = 1;
                tipos[i->getTipo()].second = posiciones_items;
            }
        }
    }
    long unsigned cantidad_de_tipos = tipos.size();
    estado += (SEPARADOR + std::to_string(cantidad_de_tipos));
    for (auto par = tipos.begin();
         par != tipos.end(); ++par) {
        //Tipo item:
        estado += (SEPARADOR + std::to_string(par->first));
        //Cantidad tipo proyectil:
        cantidad = par->second.first;
        estado += (SEPARADOR + std::to_string(cantidad));
        //Posiciones de items de ese tipo
        estado += par->second.second;
    }
    return estado;
}

std::string getEstadoFondo(Ventana* ventana){
    std::string estado = (PRE_POSICION_VENTANA +
                          MSJ_SEPARADOR +
                          std::to_string((int)((ventana->getX() - ANCHO_FONDO/2) / ESCALA_FONDO)
                          ));
    return estado;
}

std::string getEstadoEfectoPersonaje(std::vector<Posicion> pos_efectos){
    std::string aux;
    aux += MSJ_SEPARADOR;
    aux += PRE_EFECTO_PERSONAJE;
    aux += getPosEstadoEfectos(pos_efectos);
    return aux;
}

std::string getEstadoEfectoEnemigo(std::vector<Posicion> pos_efectos){
    std::string aux;
    aux += MSJ_SEPARADOR;
    aux += PRE_EFECTO_ENEMIGO;
    aux += getPosEstadoEfectos(pos_efectos);
    return aux;
}
std::string getEstadoEfectoJefe(std::vector<Posicion> pos_efectos){
    std::string aux;
    aux += MSJ_SEPARADOR;
    aux += PRE_EFECTO_JEFE;
    aux += getPosEstadoEfectos(pos_efectos);
    return aux;
}

std::string getEstadoEfectoCaja(std::vector<Posicion> pos_efectos){
    std::string aux;
    aux += MSJ_SEPARADOR;
    aux += PRE_EFECTO_CAJA;
    aux += getPosEstadoEfectos(pos_efectos);
    return aux;
}

std::string getEstadoEfecto(std::string aux, unsigned int cantidad_tipos_efecto){
    std::string estado = PRE_EFECTO;
    estado += MSJ_SEPARADOR;
    estado += std::to_string(cantidad_tipos_efecto);
    estado += aux;
    return estado;
}

std::string getPosEstadoEfectos(std::vector<Posicion> posiciones_efectos){
    std::string aux;
    aux += MSJ_SEPARADOR;
    aux += std::to_string(posiciones_efectos.size());
    for( auto &posicion: posiciones_efectos){
        aux += MSJ_SEPARADOR;
        aux += std::to_string((int)posicion.getX());
        aux +=MSJ_SEPARADOR;
        aux += std::to_string((int)posicion.getY());
    }
    return aux;
}

void cargarMapaTipos(Proyectil* p, std::map<int, std::pair<long unsigned, std::string>>* tipos){
    std::string posiciones_proyectiles;
    std::string proyectil_es_nuevo;
    if (p->getEstaEnVentana()) {
        posiciones_proyectiles = (SEPARADOR +
                                  std::to_string((int) p->getPosicionVentana().getX()) +
                                  SEPARADOR +
                                  std::to_string((int) p->getPosicionVentana().getY())
        );
        proyectil_es_nuevo = (SEPARADOR + std::to_string((int) p->esNuevo()));
        if ((*tipos).find(p->getNumeroPersonaje()) != (*tipos).end()) {
            (*tipos)[p->getNumeroPersonaje()].first = (*tipos)[p->getNumeroPersonaje()].first + 1;
            (*tipos)[p->getNumeroPersonaje()].second += posiciones_proyectiles;
            (*tipos)[p->getNumeroPersonaje()].second += proyectil_es_nuevo;
        } else {
            (*tipos)[p->getNumeroPersonaje()].first = 1;
            (*tipos)[p->getNumeroPersonaje()].second = posiciones_proyectiles;
            (*tipos)[p->getNumeroPersonaje()].second += proyectil_es_nuevo;
        }
    }
}


