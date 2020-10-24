#include "PuntajeVista.h"


PuntajeVista::PuntajeVista(SDL_Renderer* renderizador_vista){
    this->renderizador = renderizador_vista;

    SDL_Texture *cartel_1 = crearTextura(RUTA_FONDO_1_FIN, this->renderizador);
    SDL_Texture *cartel_2 = crearTextura(RUTA_FONDO_2_FIN, this->renderizador);
    SDL_Texture *cartel_3 = crearTextura(RUTA_FONDO_3_FIN, this->renderizador);
    SDL_Texture *cartel_game_over = crearTextura(RUTA_FONDO_GAME_OVER, this->renderizador);

    this->carteles.push_back(cartel_1);
    this->carteles.push_back(cartel_2);
    this->carteles.push_back(cartel_3);
    this->carteles.push_back(cartel_game_over);

    this->opcion_cartel = 0;

    this->fuente_puntajes = TTF_OpenFont(NOMBRE_FUENTE_PUNTAJE, TAM_FUENTE_PUNTAJE);

    if (this->fuente_puntajes == NULL) {
        loguearError(LOG_SIN_FUENTE);
    }

    this->mejor_puntaje.push_back(new TextoSDL(this->renderizador, this->fuente_puntajes, COLOR_VERDE,
                                               TAM_FUENTE_PUNTAJE, TEXTO_HI_SCORE,
                                               ( ANCHO_VENTANA - anchos[TEXTO_HI_SCORE] ) / 2,
                                               25));;

    this->mejor_puntaje.push_back(new TextoSDL(this->renderizador, this->fuente_puntajes, COLOR_BLANCO,
                                               TAM_FUENTE_PUNTAJE, TEXTO_PUNTAJE_VACIO,
                                               ( ANCHO_VENTANA - anchos[TEXTO_PUNTAJE_VACIO] ) / 2,
                                               40));

    this->cargador_ui = new CargadorTexturasUIPersonaje(this->renderizador);


}

void PuntajeVista::actualizarPuntajes(std::string estado){
   
    std::string aux;  // palabras extraidas del estados
    std::string nombre;
    std::string puntaje;
    std::string vidas;
    std::string estado_personaje;
    std::string score;
    std::string energia_personaje;
    std::string modo_test;

    int puntaje_maximo = 0;

    std::stringstream stream_estado(estado); // stream de las palabras de estado
    stream_estado >> aux; //leo el PRE_PUNTAJE_VIDAS, no sirve de nada pero lo tengo que sacar
    stream_estado >> aux; // leo cantidad de personajes
    int cantidad_personaje = atoi(aux.c_str()); // convierto a entero la cantidad de clases

    if (cantidad_personaje > (int)this->tabla_puntaje_vida.size()) {
        this->crearPuntajes(cantidad_personaje - (int)this->tabla_puntaje_vida.size());
    }

    for(int i = 0; i < cantidad_personaje; i++){
        stream_estado >> nombre;
        stream_estado >> puntaje;
        stream_estado >> vidas;
        stream_estado >> estado_personaje;
        stream_estado >> energia_personaje;
        stream_estado >> modo_test;

        if ( puntaje_maximo < atoi(puntaje.c_str())){
            puntaje_maximo =atoi(puntaje.c_str());
            this->mejor_puntaje[1]->setTexto(puntaje.c_str());
        }

        score = TEXTO_SCORE + puntaje;
        int n_vidas = atoi(vidas.c_str());

        if (n_vidas) {
            vidas = TEXTO_VIDA + vidas;
        } else {
            vidas = "";
        }


        if(this->tabla_puntaje_vida.find(nombre) == this->tabla_puntaje_vida.end()) {
            this->puntajes_vista[(long unsigned)i*3 + 1]->setTexto(nombre.c_str());
        }

        this->tabla_puntaje_vida[nombre][UI_CLAVE_PUNTAJE] = puntaje;

        this->puntajes_vista[(long unsigned)i*3]->setTexto(score.c_str());

        this->tabla_puntaje_vida[nombre][UI_CLAVE_VIDAS] = vidas;
        this->puntajes_vista[(long unsigned)i*3 + 2]->setTexto(vidas.c_str());

        this->tabla_puntaje_vida[nombre][UI_CLAVE_ENERGIA_PERSONAJE] = energia_personaje;

        this->ui_personajes[(long unsigned)i]->actualizar(std::atoi(estado_personaje.c_str()), energia_personaje, n_vidas, (bool)atoi(modo_test.c_str()));

    }

}


//Este metodo se llama una única vez
void PuntajeVista::crearPuntajes(int cantidad){
    int x;
    int y;
    for (int i = 0; i < cantidad; ++i) {
        x = (i%2) * ((ANCHO_VENTANA * 57)/80) + 52;
        y = (i/2) * ((ALTO_VENTANA*13)/15) + 38;
        this->puntajes_vista.push_back(new TextoSDL(this->renderizador, this->fuente_puntajes, COLOR_BLANCO,
                                                    TAM_FUENTE_PUNTAJE, TEXTO_PUNTAJE_VACIO, x, y));
        this->puntajes_vista.push_back(new TextoSDL(this->renderizador, this->fuente_puntajes, COLOR_BLANCO,
                                                    TAM_FUENTE_PUNTAJE, TEXTO_PUNTAJE_VACIO, x, y+12));
        this->puntajes_vista.push_back(new TextoSDL(this->renderizador, this->fuente_puntajes, COLOR_BLANCO,
                                                    TAM_FUENTE_PUNTAJE, TEXTO_PUNTAJE_VACIO, x + 85, y+24));

        this->ui_personajes.push_back(new UIPersonajeVista(i, this->cargador_ui,x, y+26));


    }

    this->tabla_puntajes.push_back(new TextoSDL(this->renderizador, this->fuente_puntajes,
                                                COLOR_AZUL, TAM_FUENTE_CHICA, TEXTO_TITULO_PUNTAJES_0,
                                                ( ANCHO_VENTANA - anchos[TEXTO_TITULO_PUNTAJES_0] ) / 2 - 320,
                                                ( ALTO_VENTANA - int ( TAM_FUENTE_CHICA ) ) / 2 - 50) );

   	this->tabla_puntajes.push_back(new TextoSDL(this->renderizador, this->fuente_puntajes,	
                                                COLOR_AZUL, TAM_FUENTE_CHICA, TEXTO_TITULO_PUNTAJES_1,
                                                ( ANCHO_VENTANA - anchos[TEXTO_TITULO_PUNTAJES_1] ) / 2 - 150,
                                                ( ALTO_VENTANA - int ( TAM_FUENTE_CHICA ) ) / 2 - 50) );

    this->tabla_puntajes.push_back(new TextoSDL(this->renderizador, this->fuente_puntajes,
                                                COLOR_AZUL, TAM_FUENTE_CHICA, TEXTO_TITULO_PUNTAJES_2,
                                                ( ANCHO_VENTANA - anchos[TEXTO_TITULO_PUNTAJES_2] ) / 2,
                                                ( ALTO_VENTANA - int ( TAM_FUENTE_CHICA ) ) / 2 - 50) );

    this->tabla_puntajes.push_back(new TextoSDL(this->renderizador, this->fuente_puntajes,	
                                                COLOR_AZUL, TAM_FUENTE_CHICA,  TEXTO_TITULO_PUNTAJES_3,
                                                ( ANCHO_VENTANA - anchos[TEXTO_TITULO_PUNTAJES_3] ) / 2 + 150,
                                                ( ALTO_VENTANA - int ( TAM_FUENTE_CHICA ) ) / 2 - 50) );

    this->tabla_puntajes.push_back(new TextoSDL(this->renderizador, this->fuente_puntajes,
                                                COLOR_AZUL, TAM_FUENTE_CHICA, TEXTO_TITULO_PUNTAJES_4,
                                                ( ANCHO_VENTANA - anchos[TEXTO_TITULO_PUNTAJES_4] ) / 2 + 300,
                                                ( ALTO_VENTANA - int ( TAM_FUENTE_CHICA ) ) / 2 - 50) );
    
    for (int i = 0; i < cantidad; ++i) {	
        this->tabla_puntajes.push_back(new TextoSDL(this->renderizador, this->fuente_puntajes,	
                                                    COLOR_BLANCO, TAM_FUENTE_MUY_CHICA,TEXTO_PUNTAJE_VACIO,
                                                    ( ANCHO_VENTANA - anchos[TEXTO_PUNTAJE_VACIO] ) / 2 - 325,
                                                    ( ALTO_VENTANA - int ( TAM_FUENTE_CHICA ) ) / 2 + 50 * i ) );

        this->tabla_puntajes.push_back(new TextoSDL(this->renderizador, this->fuente_puntajes,
                                                    COLOR_BLANCO, TAM_FUENTE_MUY_CHICA,TEXTO_PUNTAJE_VACIO,
                                                    ( ANCHO_VENTANA - anchos[TEXTO_PUNTAJE_VACIO] ) / 2 - 150,
                                                    ( ALTO_VENTANA - int ( TAM_FUENTE_CHICA ) ) / 2 + 50 * i ) );

        this->tabla_puntajes.push_back(new TextoSDL(this->renderizador, this->fuente_puntajes,	
                                                    COLOR_BLANCO, TAM_FUENTE_MUY_CHICA, TEXTO_PUNTAJE_VACIO,
                                                    ( ANCHO_VENTANA - anchos[TEXTO_PUNTAJE_VACIO] ) / 2,
                                                    ( ALTO_VENTANA - int ( TAM_FUENTE_CHICA ) ) / 2 + 50 * i ) );

        this->tabla_puntajes.push_back(new TextoSDL(this->renderizador, this->fuente_puntajes,
                                                    COLOR_BLANCO, TAM_FUENTE_MUY_CHICA, TEXTO_PUNTAJE_VACIO,
                                                    ( ANCHO_VENTANA - anchos[TEXTO_PUNTAJE_VACIO] ) / 2 + 150,
                                                    ( ALTO_VENTANA - int ( TAM_FUENTE_CHICA ) ) / 2 + 50 * i ) );

        this->tabla_puntajes.push_back(new TextoSDL(this->renderizador, this->fuente_puntajes,
                                                    COLOR_BLANCO, TAM_FUENTE_MUY_CHICA, TEXTO_PUNTAJE_VACIO,
                                                    ( ANCHO_VENTANA - anchos[TEXTO_PUNTAJE_VACIO] ) / 2 + 300,
                                                    ( ALTO_VENTANA - int ( TAM_FUENTE_CHICA ) ) / 2 + 50 * i ) );
    }

}	


void PuntajeVista::mostrarPuntaje(){
    for (auto &personaje: this->ui_personajes) {
        SDL_RenderCopy(this->renderizador, personaje->getTextura(), NULL, personaje->getPosicion());
        personaje->mostrarBarraVida(this->renderizador);
    }

    for (auto &texto: this->puntajes_vista) {
        SDL_RenderCopy(this->renderizador, texto->getTexto(), NULL, texto->getRectangulo());
    }

    for (auto &texto: this->mejor_puntaje) {
        SDL_RenderCopy(this->renderizador, texto->getTexto(), NULL, texto->getRectangulo());
    }

}

void PuntajeVista::mostrarTablaPuntaje() {
    SDL_RenderClear(this->renderizador);

    SDL_RenderCopy(this->renderizador,
                   this->carteles[this->opcion_cartel],
                   NULL,
                   NULL);

    // CAMBIAR
    for (auto &texto: this->tabla_puntajes) {
        SDL_RenderCopy(this->renderizador, texto->getTexto(), NULL, texto->getRectangulo());
    }

    SDL_RenderPresent(this->renderizador);
}

void PuntajeVista::avanzarCartelNivel() {
    if(this->opcion_cartel < CANTIDAD_NIVELES - 1 ){
        this->opcion_cartel += 1;
    }
}


void PuntajeVista::reiniciar() {
    this->opcion_cartel = 0;
    this->mejor_puntaje[1]->setTexto(TEXTO_PUNTAJE_VACIO);
    for (auto &texto: this->puntajes_vista){
        delete(texto);
    }
    for (auto &ui_personaje: this->ui_personajes){
        delete(ui_personaje);
    }
    for (auto &puntaje: this->tabla_puntajes){
        delete(puntaje);
    }
    this->puntajes_vista.clear();
    this->ui_personajes.clear();
    this->tabla_puntajes.clear();
    this->tabla_puntaje_vida.clear();
}

void PuntajeVista::mostrarGameOver() {
    this->opcion_cartel = 3;
    this->mostrarTablaPuntaje();
}

void PuntajeVista::setTextoTablaPuntajes(unsigned int i, const char* texto) {
    tabla_puntajes[i]->setTexto(texto);
}

PuntajeVista::~PuntajeVista(){
    for (auto &texto: this->puntajes_vista){
        delete(texto);
    }
    for (auto &ui_personaje: this->ui_personajes){
        delete(ui_personaje);
    }
    for (auto &puntaje: this->tabla_puntajes){
        delete(puntaje);
    }
    for (auto &best_puntaje: this->mejor_puntaje){
        delete(best_puntaje);
    }
    for (auto &cartel: this->carteles){
        SDL_DestroyTexture(cartel);
    }

    this->puntajes_vista.clear();
    this->ui_personajes.clear();
    this->tabla_puntajes.clear();
    this->tabla_puntaje_vida.clear();
    this->mejor_puntaje.clear();

    TTF_CloseFont(this->fuente_puntajes);
    delete(this->cargador_ui);
}
