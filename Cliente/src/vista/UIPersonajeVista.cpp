#include "UIPersonajeVista.h"

UIPersonajeVista::UIPersonajeVista(int nro_personaje_nuevo, CargadorTexturasUIPersonaje* cargador, int x_barra, int y_barra){

    int pos_x = (nro_personaje_nuevo % 2) * (ANCHO_VENTANA - (int)ANCHO_PERSONAJE_UI);
    int pos_y = (nro_personaje_nuevo / 2) * (ALTO_VENTANA - (int)ALTO_PERSONAJE_UI);

    this->texturas = cargador->getTexturas(nro_personaje_nuevo);

    this->barra_vida=new BarraVidaVista(cargador->getTexturaBarra(nro_personaje_nuevo), cargador->getTexturaBarraTest(), x_barra, y_barra);

    this->textura_actual = this->texturas[PERSONAJE_UI_VIVO];

    initRect(&this->posicion, pos_x, pos_y, ANCHO_PERSONAJE_UI, ALTO_PERSONAJE_UI);

    this->contador_disparando = 15;
    this->contador_impactado = 12;

}


SDL_Rect* UIPersonajeVista::getPosicion(){
    return &this->posicion;
}

SDL_Texture* UIPersonajeVista::getTextura(){
    return this->textura_actual;
}

void UIPersonajeVista::actualizar(int estado_personaje_ui, std::string energia, int n_vidas, bool modo_test){
    if (estado_personaje_ui == PERSONAJE_UI_IMPACTADO or (estado_personaje_ui != PERSONAJE_UI_DESCONECTADO and estado_personaje_ui != PERSONAJE_UI_MUERTO and this->contador_impactado < 12)) {
        if (estado_personaje_ui == PERSONAJE_UI_IMPACTADO) {
            this->contador_impactado = 0;
        }
        estado_personaje_ui = PERSONAJE_UI_MUERTO;
        this->contador_impactado += 1;
        if (((this->contador_impactado % 4) / 2) == 1 ) {
            estado_personaje_ui = PERSONAJE_UI_DISPARANDO_2;
        }
    }

    else if (estado_personaje_ui == PERSONAJE_UI_DISPARANDO or (estado_personaje_ui == PERSONAJE_UI_VIVO and contador_disparando < 15)) {
        estado_personaje_ui = PERSONAJE_UI_DISPARANDO;
        this->contador_disparando += 1;
        if (this->contador_disparando > 15 ) {
            this->contador_disparando = 0;
        } else if (this->contador_disparando > 10){
            estado_personaje_ui = PERSONAJE_UI_VIVO;
        } else if (this->contador_disparando > 4){
            estado_personaje_ui = PERSONAJE_UI_DISPARANDO_2;
        }
    }

    else {
        this->contador_disparando = 15;
        this->contador_impactado = 12;
    }

    this->barra_vida->actualizar(std::atoi(energia.c_str()), modo_test);

    if(n_vidas == 0){
        estado_personaje_ui = PERSONAJE_UI_GAME_OVER;
    }

    this->textura_actual = this->texturas[(unsigned long)estado_personaje_ui];

}

void UIPersonajeVista::mostrarBarraVida(SDL_Renderer *renderizador) {
    SDL_RenderCopy(renderizador,
                   this->barra_vida->getTextura(),
                   this->barra_vida->getBarraVida(),
                   this->barra_vida->getRectCompleto());
}

UIPersonajeVista::~UIPersonajeVista() {
    delete(this->barra_vida);
}

