#include "MenuJuegoVista.h"

MenuJuegoVista::MenuJuegoVista(SDL_Renderer* renderizador) {
    /* Configurar el contenido de la ventana. */
    this->renderizador =  renderizador;

    /* Las posiciones de los mensajes y su tamaño deben ser relativos al tamaño de la pabtalla
     * y a su longitud. */

    this->textura = crearTextura(RUTA_FONDO_MENU, this->renderizador);
    this->cartel_espera = crearTextura(RUTA_FONDO_ESPERA, this->renderizador);

    this->fuente_normal = TTF_OpenFont(NOMBRE_FUENTE, TAM_FUENTE_NORMAL);
    if (this->fuente_normal == NULL) {
        loguearError(LOG_SIN_FUENTE);
    }

    this->fuente_chica = TTF_OpenFont(NOMBRE_FUENTE, TAM_FUENTE_NORMAL);
    if (this->fuente_chica == NULL) {
        loguearError(LOG_SIN_FUENTE);
    }

    this->texto_comenzar = new TextoSDL(this->renderizador, this->fuente_normal, COLOR_BLANCO, TAM_FUENTE_NORMAL, MENSAJE_CONECTARSE,
                                        ( ANCHO_VENTANA - anchos[MENSAJE_CONECTARSE] ) / 2,
                                       ( ALTO_VENTANA - int ( TAM_FUENTE_NORMAL ) ) / 2 - (int) TAM_FUENTE_NORMAL
     );

    this->texto_salir = new TextoSDL(this->renderizador, this->fuente_normal, COLOR_GRIS, TAM_FUENTE_NORMAL, MENSAJE_SALIR,
                                    ( ANCHO_VENTANA - anchos[MENSAJE_SALIR] ) / 2,
                                    ( ALTO_VENTANA - int ( TAM_FUENTE_NORMAL ) ) / 2 + (int) TAM_FUENTE_NORMAL * 2
                                    );

    SDL_RenderClear(this->renderizador);
}

MenuJuegoVista::~MenuJuegoVista() {
    delete(this->texto_comenzar);
    delete(this->texto_salir);

    TTF_CloseFont(this->fuente_normal);
    TTF_CloseFont(this->fuente_chica);

    SDL_DestroyTexture(this->textura);
    SDL_DestroyTexture(this->cartel_espera);
}

void MenuJuegoVista::cambiarColor(TextoSDL* t1, SDL_Color c1, TextoSDL* t2, SDL_Color c2){
    t1->setTexto(t1->getMensaje(), c1);
    t2->setTexto(t2->getMensaje(), c2);
}

void MenuJuegoVista::actualizar(int accion) {

    SDL_RenderClear(this->renderizador);

    // El fondo tiene que ir primero
    SDL_RenderCopy(this->renderizador, this->textura, NULL, NULL);

    if(accion == MENU_OPCION_1){
        cambiarColor(this->texto_comenzar, COLOR_BLANCO, this->texto_salir, COLOR_GRIS);
    }

    else if(accion == MENU_OPCION_2){
        cambiarColor(this->texto_comenzar, COLOR_GRIS, this->texto_salir, COLOR_BLANCO);
    }

    SDL_RenderCopy(this->renderizador, this->texto_comenzar->getTexto(), NULL, this->texto_comenzar->getRectangulo());
    SDL_RenderCopy(this->renderizador, this->texto_salir->getTexto(), NULL, this->texto_salir->getRectangulo());

    SDL_RenderPresent(this->renderizador);
}

SDL_Texture *MenuJuegoVista::getTextura() {
    return this->textura;
}