#include "MenuLogVista.h"

MenuLogVista::MenuLogVista(SDL_Renderer* renderizador) {
    this->renderizador = renderizador;

    this->textura = crearTextura(RUTA_FONDO_VALIDAR, this->renderizador);

    this->fuente_normal = TTF_OpenFont(NOMBRE_FUENTE, TAM_FUENTE_NORMAL);

    if (this->fuente_normal == NULL) {
        loguearError(LOG_SIN_FUENTE);
    }

    this->fuente_chica = TTF_OpenFont(NOMBRE_FUENTE, TAM_FUENTE_NORMAL);
    if (this->fuente_chica == NULL) {
        loguearError(LOG_SIN_FUENTE);
    }

    this->texto_usuario = new TextoSDL(this->renderizador, fuente_normal, COLOR_GRIS, TAM_FUENTE_NORMAL,
                                       MENSAJE_USUARIO,
                                      ( ANCHO_VENTANA - anchos[MENSAJE_USUARIO] ) / 2,
                                      ( ALTO_VENTANA - int ( TAM_FUENTE_NORMAL ) ) / 2 - (int) (TAM_FUENTE_NORMAL)
    );

    this->usuario = new TextoSDL(this->renderizador, fuente_chica, COLOR_GRIS, TAM_FUENTE_CHICA,
                                      (char*) "",
                                      ( (unsigned int)ANCHO_VENTANA - (unsigned int)(MAX_LEN_USUARIO) * TAM_FUENTE_CHICA ) / 2,
                                      ( ALTO_VENTANA - int ( TAM_FUENTE_NORMAL ) ) / 2
    );

    this->texto_pass = new TextoSDL(this->renderizador, this->fuente_normal, COLOR_GRIS, TAM_FUENTE_NORMAL,
                                        MENSAJE_PASS,
                                       ( ANCHO_VENTANA - anchos[MENSAJE_PASS] ) / 2,
                                       ( ALTO_VENTANA - int ( TAM_FUENTE_NORMAL ) ) / 2 + (int) (TAM_FUENTE_NORMAL * 2)
    );

    this->pass = new TextoSDL(this->renderizador, this->fuente_chica, COLOR_GRIS, TAM_FUENTE_CHICA,
                                 (char*)  "",
                                 ( (unsigned int)ANCHO_VENTANA - (unsigned int)(MAX_LEN_PASS - 5) * TAM_FUENTE_CHICA ) / 2,
                                 ( ALTO_VENTANA - int ( TAM_FUENTE_NORMAL ) ) / 2 + ( (int) TAM_FUENTE_NORMAL * 3)
    );

    this->validar = new TextoSDL(this->renderizador, this->fuente_normal, COLOR_GRIS, TAM_FUENTE_NORMAL, MENSAJE_INICIAR,
                                      ( ANCHO_VENTANA - anchos[MENSAJE_INICIAR] ) / 2,
                                      ( ALTO_VENTANA - int ( TAM_FUENTE_NORMAL ) ) / 2 + (int) (TAM_FUENTE_NORMAL * 5)
    );

    SDL_RenderClear(this->renderizador);
}

MenuLogVista::~MenuLogVista() {
    delete(this->texto_usuario);
    delete(this->texto_pass);
    delete(this->validar);
    delete(this->usuario);
    delete(this->pass);

    TTF_CloseFont(this->fuente_normal);
    TTF_CloseFont(this->fuente_chica);

    SDL_DestroyTexture(this->textura);
}

void MenuLogVista::actualizarValores(TextoSDL* u, TextoSDL* p){
    u->setTexto(getUsuario(), u->getColor());
    p->setTexto(getPassAsteriscos(), p->getColor());
}

void MenuLogVista::actualizar(int accion){
    SDL_RenderCopy(this->renderizador, this->textura, NULL, NULL);

    if(accion == MENU_VALIDAR_1){
        cambiarColor(this->texto_usuario, COLOR_BLANCO, this->texto_pass, COLOR_GRIS,
                     this->validar, COLOR_GRIS);
    }

    else if(accion == MENU_VALIDAR_2){
        cambiarColor(this->texto_usuario, COLOR_GRIS, this->texto_pass, COLOR_BLANCO,
                     this->validar, COLOR_GRIS);
    }

    else if(accion == MENU_VALIDAR_3){
        cambiarColor(this->texto_usuario, COLOR_GRIS, this->texto_pass, COLOR_GRIS,
                     this->validar, COLOR_BLANCO);
    }

    actualizarValores(this->usuario, this->pass);

    SDL_RenderCopy(this->renderizador, this->texto_usuario->getTexto(), NULL, this->texto_usuario->getRectangulo());
    SDL_RenderCopy(this->renderizador, this->usuario->getTexto(), NULL, this->usuario->getRectangulo());
    SDL_RenderCopy(this->renderizador, this->texto_pass->getTexto(), NULL, this->texto_pass->getRectangulo());
    SDL_RenderCopy(this->renderizador, this->pass->getTexto(), NULL, this->pass->getRectangulo());
    SDL_RenderCopy(this->renderizador, this->validar->getTexto(), NULL, this->validar->getRectangulo());

    SDL_RenderPresent(this->renderizador);
}

void MenuLogVista::cambiarColor(TextoSDL* t1, SDL_Color c1, TextoSDL* t2, SDL_Color c2,
                                  TextoSDL* t3, SDL_Color c3){
    t1->setTexto(t1->getMensaje(), c1);
    t2->setTexto(t2->getMensaje(), c2);
    t3->setTexto(t3->getMensaje(), c3);
}
