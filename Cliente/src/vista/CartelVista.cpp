#include "CartelVista.h"

CartelVista::CartelVista(SDL_Renderer *renderizador) {
    this->renderizador = renderizador;
    this->mensaje_adicional = nullptr;

    this->fuente = TTF_OpenFont(NOMBRE_FUENTE, TAM_FUENTE_CHICA);
    if (this->fuente == NULL) {
        loguearError(LOG_SIN_FUENTE);
    }

    SDL_Texture *cartel_0 = crearTextura(RUTA_FONDO_CONECTANDO, this->renderizador);
    SDL_Texture *cartel_1 = crearTextura(RUTA_FONDO_ESPERA, this->renderizador);
    SDL_Texture *cartel_2 = crearTextura(RUTA_FONDO_1_INICIO, this->renderizador);
    SDL_Texture *cartel_3 = crearTextura(RUTA_FONDO_2_INICIO, this->renderizador);
    SDL_Texture *cartel_4 = crearTextura(RUTA_FONDO_3_INICIO, this->renderizador);

    SDL_Texture *numero_1 = crearTextura(RUTA_NUM_1, this->renderizador);
    SDL_Texture *numero_2 = crearTextura(RUTA_NUM_2, this->renderizador);
    SDL_Texture *numero_3 = crearTextura(RUTA_NUM_3, this->renderizador);

    SDL_Texture *cartel_congratulations_1 = crearTextura(RUTA_FONDO_CONGRATULATIONS_1, this->renderizador);
    SDL_Texture *cartel_congratulations_2 = crearTextura(RUTA_FONDO_CONGRATULATIONS_2, this->renderizador);
    SDL_Texture *cartel_congratulations_3 = crearTextura(RUTA_FONDO_CONGRATULATIONS_3, this->renderizador);
    SDL_Texture *cartel_congratulations_4 = crearTextura(RUTA_FONDO_CONGRATULATIONS_4, this->renderizador);

    this->carteles.push_back(cartel_0);
    this->carteles.push_back(cartel_1);
    this->carteles.push_back(cartel_2);
    this->carteles.push_back(cartel_3);
    this->carteles.push_back(cartel_4);

    this->numeros.push_back(numero_3);
    this->numeros.push_back(numero_2);
    this->numeros.push_back(numero_1);

    this->carteles_congratulations.push_back(cartel_congratulations_1);
    this->carteles_congratulations.push_back(cartel_congratulations_2);
    this->carteles_congratulations.push_back(cartel_congratulations_3);
    this->carteles_congratulations.push_back(cartel_congratulations_4);

    this->mensaje_adicional = new TextoSDL(this->renderizador, this->fuente, COLOR_BLANCO, TAM_FUENTE_CHICA,
                                           (char *) "", (int) (ANCHO_VENTANA - anchos[MSJ_JUGADOR_CONECTADO]) / 2,
                                           (ALTO_VENTANA - int(TAM_FUENTE_CHICA)) / 2 + (int) TAM_FUENTE_CHICA * 8);

    this->mensaje_muertos_conectados_1 = new TextoSDL(this->renderizador, this->fuente, COLOR_BLANCO, TAM_FUENTE_MUY_CHICA,
                                           (char *) "",
                                           (int) (ANCHO_VENTANA - anchos[MSJ_MUERTOS_CONECTADOS_1]) / 2,
                                           (ALTO_VENTANA - int(TAM_FUENTE_MUY_CHICA)) / 2 + 220);

    this->mensaje_muertos_conectados_2 = new TextoSDL(this->renderizador, this->fuente, COLOR_BLANCO, TAM_FUENTE_MUY_CHICA,
                                                    (char *) "",
                                                    (int) (ANCHO_VENTANA - anchos[MSJ_MUERTOS_CONECTADOS_2]) / 2,
                                                    (ALTO_VENTANA - int(TAM_FUENTE_MUY_CHICA)) / 2 + 270);

    SDL_RenderClear(this->renderizador);
}

void CartelVista::actualizar(size_t opcion_cartel) {
    SDL_RenderClear(this->renderizador);

    SDL_RenderCopy(this->renderizador,
                   this->carteles[opcion_cartel],
                   NULL,
                   NULL);

    SDL_RenderCopy(this->renderizador, this->mensaje_adicional->getTexto(),
                   NULL, this->mensaje_adicional->getRectangulo());

    SDL_RenderPresent(this->renderizador);
}

void CartelVista::actualizar(size_t opcion_cartel, size_t opcion_nro) {
    SDL_RenderClear(this->renderizador);

    if ( std::string(this->mensaje_muertos_conectados_1->getMensaje()) == "" ) {
        SDL_RenderCopy(this->renderizador,
                       this->carteles[opcion_cartel],
                       NULL,
                       NULL);
        SDL_RenderCopy(this->renderizador, this->numeros[opcion_nro],
                       NULL, NULL);
    }
    else{
        SDL_RenderCopy(this->renderizador,
                       this->carteles[1],
                       NULL,
                       NULL);
        SDL_RenderCopy(this->renderizador, this->mensaje_muertos_conectados_1->getTexto(),
                       NULL, this->mensaje_muertos_conectados_1->getRectangulo());
        SDL_RenderCopy(this->renderizador, this->mensaje_muertos_conectados_2->getTexto(),
                       NULL, this->mensaje_muertos_conectados_2->getRectangulo());
    }

    SDL_RenderPresent(this->renderizador);
}


void CartelVista::actualizarJugadoresConectados(std::string mensaje) {
    this->mensaje_adicional->setTexto(mensaje.c_str());
}

CartelVista::~CartelVista() {
    for (auto &i: this->carteles) {
        SDL_DestroyTexture(i);
    }
    for (auto &i: this->numeros) {
        SDL_DestroyTexture(i);
    }
    for (auto &i: this->carteles_congratulations) {
        SDL_DestroyTexture(i);
    }
    delete (this->mensaje_adicional);
    delete (this->mensaje_muertos_conectados_1);
    delete (this->mensaje_muertos_conectados_2);
    TTF_CloseFont(this->fuente);
}

void CartelVista::actualizarCartelMuertosConectados(char* m1, char* m2) {
    this->mensaje_muertos_conectados_1->setTexto(m1);
    this->mensaje_muertos_conectados_2->setTexto(m2);
}

void CartelVista::mostrarJuegoGanado(int cantidad_ganadores) {
    SDL_RenderClear(this->renderizador);

    SDL_RenderCopy(this->renderizador,
                   this->carteles_congratulations[(size_t)cantidad_ganadores - 1],
                   NULL,
                   NULL);


    SDL_RenderPresent(this->renderizador);
}


