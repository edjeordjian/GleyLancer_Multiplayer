#include "Juego.h"

Juego::Juego(int n_clientes) {
    personajes = new std::vector<Personaje*>();

    for(int nro_jugador = 0; nro_jugador < n_clientes; ++nro_jugador){
        this->personajes->push_back(new Personaje(X_PERSONAJE_DEFAULT,
                Y_PERSONAJE_DEFAULT + Y_PERSONAJE_DEFAULT*nro_jugador,
                INCREMENTO_PERSONAJE, nro_jugador, CANTIDAD_VIDAS_PERSONAJE)
        );
    }

    this->numero_nivel = NRO_NIVEL_INICIAL;
    this->nivel_empezado = false;

    //ENEMIGOS NIVEL 1
    this->tipos_enemigos_nivel_1.push_back(getTipoEnemigo1());
    this->tipos_enemigos_nivel_1.push_back(getTipoEnemigo2());

    this->cantidad_enemigos_nivel_1.push_back(getCantEnemigo1Nivel1());
    this->cantidad_enemigos_nivel_1.push_back(getCantEnemigo2Nivel1());

    //ENEMIGOS NIVEL 2
    this->tipos_enemigos_nivel_2.push_back(getTipoEnemigo1());
    this->tipos_enemigos_nivel_2.push_back(getTipoEnemigo2());

    this->cantidad_enemigos_nivel_2.push_back(getCantEnemigo1Nivel2());
    this->cantidad_enemigos_nivel_2.push_back(getCantEnemigo2Nivel2());

    //ENEMIGOS NIVEL 3
    this->tipos_enemigos_nivel_3.push_back(getTipoEnemigo1());
    this->tipos_enemigos_nivel_3.push_back(getTipoEnemigo2());
    this->cantidad_enemigos_nivel_3.push_back(getCantEnemigo1Nivel3());
    this->cantidad_enemigos_nivel_3.push_back(getCantEnemigo2Nivel3());

    //this->nivel = new Nivel(this->personajes, this->tipos_enemigos_nivel_1, this->cantidad_enemigos_nivel_1, JEFE_DE_NIVEL[((this->numero_nivel + 1) % 3) + 1], this->numero_nivel);
    this->nivel = new Nivel(this->personajes, this->tipos_enemigos_nivel_1, this->cantidad_enemigos_nivel_1, JEFE_DE_NIVEL[this->numero_nivel], this->numero_nivel);

    this->contador_para_reinicio = 0;
    this->jugadores_desconectados = 0;
}

Juego::~Juego(){
    delete this->nivel;
    for (auto &personaje: *(this->personajes)){
        delete(personaje);
    }
    for (auto &jefe: (this->jefes)){
        delete(jefe);
    }

    delete this->personajes;

}

void Juego::setNombreJugador(int n, std::string nombre) {
    (*personajes)[(unsigned long)n]->setNombre(nombre);
    this->tabla_puntaje_vida.push_back(std::pair<std::string, std::map<std::string, int>>(nombre, {{UI_CLAVE_PUNTAJE, 0},
                                                                                                   {UI_CLAVE_VIDAS, 0},
                                                                                                   {UI_CLAVE_ESTADO_PERSONAJE, 0},
                                                                                                   {UI_CLAVE_ENERGIA_PERSONAJE, 0},
                                                                                                   {UI_CLAVE_PUNTAJE_NIVEL_1, 0},
                                                                                                   {UI_CLAVE_PUNTAJE_NIVEL_2, 0},
                                                                                                   {UI_CLAVE_PUNTAJE_NIVEL_3, 0},
                                                                                                   {UI_CLAVE_MODO_TEST, 0}}));

}

std::string Juego::getNombreJugador(Uint16 n) {
    return  (*personajes)[n]->getNombre();
}


void Juego::actualizar(){
    if (!this->nivel_empezado){
        return;
    }

    this->nivel->actualizar();

}

void Juego::actualizar(int input) {
    int tecla = input / CANT_CONEXIONES_MAX;
    int nro_personaje = input % CANT_CONEXIONES_MAX;

    unsigned long iterador = 0;
    unsigned long personaje = 0;
    while(iterador < this->personajes->size()){
        if ((*(this->personajes))[iterador]->getNumeroPersonaje() == nro_personaje){
            personaje = iterador;
            break;
        }
        ++iterador;
    }

    if(iterador == this->personajes->size()){
        return;
    }

    else if (!this->nivel_empezado){

        if (tecla == TECLA_LISTO) {
            (*(this->personajes))[personaje]->setListo(true);
            this->conectarPersonaje((*(this->personajes))[personaje]);
        }
        unsigned long jugadores_conectados = 0;
        unsigned long personajes_listos = 0;

        for (unsigned long i=0; i < this->personajes->size(); ++i){
            if ((*(this->personajes))[i]->estaListo()){
                personajes_listos += 1;
            }
            if ((*(this->personajes))[i]->estaConectado()){
                jugadores_conectados += 1;
            }
        }

        if (personajes_listos == jugadores_conectados){
            this->nivel_empezado = true;
        }

    }

    else {
        if (tecla == TECLA_LISTO) {
            this->conectarPersonaje((*(this->personajes))[personaje]);
        }

        else if ((*(this->personajes))[personaje]->estaVivo()) {
            this->nivel->actualizar(tecla, personaje);
        }
    }
}

std::string Juego::getEstadoPersonajes(){
    return this->nivel->getEstadoPersonajes();
}

std::string Juego::getEstadoEnemigos(){
    return this->nivel->getEstadoEnemigos();
}

std::string Juego::getEstadoFondo() {
    return this->nivel->getEstadoFondo();
}

std::string Juego::getEstadoProyectiles() {
    return this->nivel->getEstadoProyectiles();
}

std::string Juego::getEstadoEfectos(){
    return this->nivel->getEstadoEfectos();
}

std::string Juego::getEstadoCajas(){
    return this->nivel->getEstadoCajas();
}

std::string Juego::getEstadoItems(){
    return this->nivel->getEstadoItems();
}

std::string Juego::getPuntajePersonaje() {
    std::string estado_puntaje = PRE_PUNTAJES_VIDAS
                                 + MSJ_SEPARADOR
                                 + std::to_string(this->tabla_puntaje_vida.size());
    for(std::vector<std::pair<std::string, std::map<std::string,int>>>::iterator i = this->tabla_puntaje_vida.begin();
        i != this->tabla_puntaje_vida.end(); ++i){
        estado_puntaje +=MSJ_SEPARADOR
                         + i->first
                         + MSJ_SEPARADOR
                         //guarda el puntaje
                         + std::to_string(i->second[UI_CLAVE_PUNTAJE])
                         + MSJ_SEPARADOR
                         //guarda la cantidad de vidas
                         + std::to_string(i->second[UI_CLAVE_VIDAS])
                         + MSJ_SEPARADOR
                         //guarda el estado (normal, disparando, golpeado, muerto, desconectado() del personaje
                         + std::to_string(i->second[UI_CLAVE_ESTADO_PERSONAJE])
                         + MSJ_SEPARADOR
                         //guarda la energia restante del personaje
                         + std::to_string(i->second[UI_CLAVE_ENERGIA_PERSONAJE])
                         + MSJ_SEPARADOR
                         //indica si esta en modo test
                         + std::to_string(i->second[UI_CLAVE_MODO_TEST]);
    }
    return  estado_puntaje;
}

std::string Juego::getPuntajesFinNivel(){
    std::string puntajes_fin_nivel = PRE_TABLA_PUNTAJES + MSJ_SEPARADOR + std::to_string(this->tabla_puntaje_vida.size());
    std::vector<std::pair<std::string, std::vector<int>>> puntajes_ordenados;
    for(auto itr = this->tabla_puntaje_vida.begin(); itr != this->tabla_puntaje_vida.end(); ++itr){
        puntajes_ordenados.push_back(std::pair<std::string, std::vector<int>>(itr->first, {itr->second[UI_CLAVE_PUNTAJE_NIVEL_1],
                                                                                              itr->second[UI_CLAVE_PUNTAJE_NIVEL_2],
                                                                                              itr->second[UI_CLAVE_PUNTAJE_NIVEL_3],
                                                                                              itr->second[UI_CLAVE_PUNTAJE]}));
    }

    std::sort(puntajes_ordenados.begin(), puntajes_ordenados.end(), compararPuntajesFinales);
    for(auto itr = puntajes_ordenados.begin(); itr != puntajes_ordenados.end(); ++itr){
        puntajes_fin_nivel += MSJ_SEPARADOR +
                              itr->first +
                              MSJ_SEPARADOR +
                              std::to_string(itr->second[0]) +
                              MSJ_SEPARADOR +
                              std::to_string(itr->second[1]) +
                              MSJ_SEPARADOR +
                              std::to_string(itr->second[2]) +
                              MSJ_SEPARADOR +
                              std::to_string(itr->second[3]);

        loguearDebug(std::string(LOG_PUNTOS_FIN_NIVEL_1) + std::string(itr->first) +
                     std::string(LOG_PUNTOS_FIN_NIVEL_2) + std::to_string(itr->second[0]) +
                     std::string(LOG_PUNTOS_FIN_NIVEL_3) + std::to_string(itr->second[1]) +
                     std::string(LOG_PUNTOS_FIN_NIVEL_4) + std::to_string(itr->second[2]) +
                     std::string(LOG_PUNTOS_FIN_NIVEL_5) + std::to_string(itr->second[3]));

    }
    return puntajes_fin_nivel;

}

void Juego::actualizarPuntajeVida() {
    for( auto &personaje: *this->personajes ){
        this->tabla_puntaje_vida[(unsigned long)personaje->getNumeroPersonaje()].second[UI_CLAVE_PUNTAJE] = personaje->getPuntaje();
        this->tabla_puntaje_vida[(unsigned long)personaje->getNumeroPersonaje()].second[UI_CLAVE_VIDAS] = personaje->getVidas();
        this->tabla_puntaje_vida[(unsigned long)personaje->getNumeroPersonaje()].second[UI_CLAVE_ENERGIA_PERSONAJE] = personaje->getEnergia();
        this->tabla_puntaje_vida[(unsigned long)personaje->getNumeroPersonaje()].second[UI_CLAVE_MODO_TEST] = (int)personaje->getTest();

        this->tabla_puntaje_vida[(unsigned long)personaje->getNumeroPersonaje()].second[UI_CLAVE_PUNTAJE_NIVEL_1] = personaje->getPuntajeNivel(1);
        this->tabla_puntaje_vida[(unsigned long)personaje->getNumeroPersonaje()].second[UI_CLAVE_PUNTAJE_NIVEL_2] = personaje->getPuntajeNivel(2);
        this->tabla_puntaje_vida[(unsigned long)personaje->getNumeroPersonaje()].second[UI_CLAVE_PUNTAJE_NIVEL_3] = personaje->getPuntajeNivel(3);

        if (personaje->estaVivo()) {
            if(!personaje->estaConectado()) {
                this->tabla_puntaje_vida[(unsigned long)personaje->getNumeroPersonaje()].second[UI_CLAVE_ESTADO_PERSONAJE] = PERSONAJE_UI_DESCONECTADO;
            } else if (personaje->estaDaniado()) {
                this->tabla_puntaje_vida[(unsigned long)personaje->getNumeroPersonaje()].second[UI_CLAVE_ESTADO_PERSONAJE] = PERSONAJE_UI_IMPACTADO;
            } else if (personaje->estaDisparando()) {
                this->tabla_puntaje_vida[(unsigned long)personaje->getNumeroPersonaje()].second[UI_CLAVE_ESTADO_PERSONAJE] = PERSONAJE_UI_DISPARANDO;
            } else {
                this->tabla_puntaje_vida[(unsigned long)personaje->getNumeroPersonaje()].second[UI_CLAVE_ESTADO_PERSONAJE] = PERSONAJE_UI_VIVO;
            }
        } else {
            this->tabla_puntaje_vida[(unsigned long)personaje->getNumeroPersonaje()].second[UI_CLAVE_ESTADO_PERSONAJE] = PERSONAJE_UI_MUERTO;
        }
    }
}

void Juego::desconectarPersonaje(int nro_personaje) {
    this->nivel->desconectarPersonaje(nro_personaje);
    this->jugadores_desconectados +=1 ;
}

void Juego::conectarPersonaje(Personaje* per) {
    if (!per->estaConectado()){
        per->setConectado(true);
        this->jugadores_desconectados -= 1;
    }

}

bool Juego::getNivelFinalizado() {
    bool finalizado = this->nivel->getNivelFinalizado();

    if (finalizado) {
        this->avanzarNivel();
    }

    if (this->numero_nivel <= CANTIDAD_NIVELES){
        return finalizado;
    }

    return false;
}

//Se murieron todos los personajes con vidas y no les quedan vidas
bool Juego::gameOver() {
    return (this->personajes->size() == 0);
}

bool Juego::hayJugadorVivo() {
    for (auto &personaje: *(this->personajes)) {
        if (personaje->estaVivo() && personaje->estaConectado()){
            return true;
        }
    }

    if (this->contador_para_reinicio < TIEMPO_FIN_NIVEL) {
        this->contador_para_reinicio += 1;
        return true;
    }

    this->contador_para_reinicio = 0;
    return false;
}

void Juego::reiniciarNivel(){
    delete(this->nivel);
    for (long unsigned personaje = 0; personaje < (this->personajes)->size();){
        if ( (*(this->personajes))[personaje]->getVidas() == 0) {
            this->tabla_puntaje_vida[(size_t)(*(this->personajes))[personaje]->getNumeroPersonaje()].second[UI_CLAVE_PUNTAJE] = (*(this->personajes))[personaje]->getPuntaje();
            this->tabla_puntaje_vida[(size_t)(*(this->personajes))[personaje]->getNumeroPersonaje()].second[UI_CLAVE_PUNTAJE_NIVEL_1] = (*(this->personajes))[personaje]->getPuntajeNivel(1);
            this->tabla_puntaje_vida[(size_t)(*(this->personajes))[personaje]->getNumeroPersonaje()].second[UI_CLAVE_PUNTAJE_NIVEL_2] = (*(this->personajes))[personaje]->getPuntajeNivel(2);
            this->tabla_puntaje_vida[(size_t)(*(this->personajes))[personaje]->getNumeroPersonaje()].second[UI_CLAVE_PUNTAJE_NIVEL_3] = (*(this->personajes))[personaje]->getPuntajeNivel(3);
            this->tabla_puntaje_vida[(size_t)(*(this->personajes))[personaje]->getNumeroPersonaje()].second[UI_CLAVE_VIDAS] = 0;
            this->tabla_puntaje_vida[(size_t)(*(this->personajes))[personaje]->getNumeroPersonaje()].second[UI_CLAVE_ESTADO_PERSONAJE] = PERSONAJE_UI_MUERTO;
            this->tabla_puntaje_vida[(size_t)(*(this->personajes))[personaje]->getNumeroPersonaje()].second[UI_CLAVE_ENERGIA_PERSONAJE] = 0;
            this->tabla_puntaje_vida[(size_t)(*(this->personajes))[personaje]->getNumeroPersonaje()].second[UI_CLAVE_MODO_TEST] = (int)(*(this->personajes))[personaje]->getTest();
            delete((*(this->personajes))[personaje]);
            this->personajes->erase(this->personajes->begin() + (int)personaje);
        } else {
            (*(this->personajes))[personaje]->setPosX(X_PERSONAJE_DEFAULT);
            (*(this->personajes))[personaje]->setPosY(Y_PERSONAJE_DEFAULT + Y_PERSONAJE_DEFAULT * ((*(this->personajes))[personaje])->getNumeroPersonaje());
            (*(this->personajes))[personaje]->setListo(false);
            (*(this->personajes))[personaje]->reiniciarEnergia();
            (*(this->personajes))[personaje]->actualizar(POS_NINGUNA);
            (*(this->personajes))[personaje]->dejarDeDisparar();
            (*(this->personajes))[personaje]->dejarDePropulsionar();
            (*(this->personajes))[personaje]->removerItem();
            ++personaje;
        }
    }

    this->nivel_empezado = false;

    if (this->numero_nivel == 1) {
        this->nivel = new Nivel(this->personajes, this->tipos_enemigos_nivel_1, this->cantidad_enemigos_nivel_1, JEFE_DE_NIVEL[this->numero_nivel], this->numero_nivel);
    }

    else if (this->numero_nivel == 2) {
        this->nivel = new Nivel(this->personajes, this->tipos_enemigos_nivel_2, this->cantidad_enemigos_nivel_2, JEFE_DE_NIVEL[this->numero_nivel], this->numero_nivel);
    }

    else{
        this->nivel = new Nivel(this->personajes, this->tipos_enemigos_nivel_3, this->cantidad_enemigos_nivel_3, JEFE_DE_NIVEL[this->numero_nivel], this->numero_nivel);
    }
}

void Juego::avanzarNivel() {
    if ((++this->numero_nivel) <= CANTIDAD_NIVELES) {
        this->reiniciarNivel();
    }
}

bool Juego::nivelEmpezado(){
    return this->nivel_empezado;
}

bool Juego::finalizado() {
    return( ( this->numero_nivel == CANTIDAD_NIVELES ) && ( this->nivel->getNivelFinalizado() ) );
}

int Juego::getNumeroNivel() {
    return (this->numero_nivel - 1);
}

// this->personajes: SOLO los jugadores con vidas > 0
bool Juego::estanTodosLosJugadoresDesconectados() {
    return this->jugadores_desconectados == this->personajes->size();
}
