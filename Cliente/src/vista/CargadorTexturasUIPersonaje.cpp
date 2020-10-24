#include "CargadorTexturasUIPersonaje.h"

CargadorTexturasUIPersonaje::CargadorTexturasUIPersonaje(SDL_Renderer* renderizador){
    /// TEXTURAS PERSONAJE 1
    this->texturas_personaje_1.emplace_back(crearTextura(RUTA_UI_PERSONAJE_1_MUERTO, renderizador));
    this->texturas_personaje_1.emplace_back(crearTextura(RUTA_UI_PERSONAJE_1_VIVO, renderizador));
    this->texturas_personaje_1.emplace_back(crearTextura(RUTA_UI_PERSONAJE_1_DESCONECTADO, renderizador));
    this->texturas_personaje_1.emplace_back(crearTextura(RUTA_UI_PERSONAJE_1_DISPARANDO, renderizador));
    this->texturas_personaje_1.emplace_back(crearTextura(RUTA_UI_PERSONAJE_1_DISPARANDO_2, renderizador));
    this->texturas_personaje_1.emplace_back(crearTextura(RUTA_UI_PERSONAJE_1_GAME_OVER, renderizador));

    /// TEXTURAS PERSONAJE 2
    this->texturas_personaje_2.emplace_back(crearTextura(RUTA_UI_PERSONAJE_2_MUERTO, renderizador));
    this->texturas_personaje_2.emplace_back(crearTextura(RUTA_UI_PERSONAJE_2_VIVO, renderizador));
    this->texturas_personaje_2.emplace_back(crearTextura(RUTA_UI_PERSONAJE_2_DESCONECTADO, renderizador));
    this->texturas_personaje_2.emplace_back(crearTextura(RUTA_UI_PERSONAJE_2_DISPARANDO, renderizador));
    this->texturas_personaje_2.emplace_back(crearTextura(RUTA_UI_PERSONAJE_2_DISPARANDO_2, renderizador));
    this->texturas_personaje_2.emplace_back(crearTextura(RUTA_UI_PERSONAJE_2_GAME_OVER, renderizador));

    /// TEXTURAS PERSONAJE 3
    this->texturas_personaje_3.emplace_back(crearTextura(RUTA_UI_PERSONAJE_3_MUERTO, renderizador));
    this->texturas_personaje_3.emplace_back(crearTextura(RUTA_UI_PERSONAJE_3_VIVO, renderizador));
    this->texturas_personaje_3.emplace_back(crearTextura(RUTA_UI_PERSONAJE_3_DESCONECTADO, renderizador));
    this->texturas_personaje_3.emplace_back(crearTextura(RUTA_UI_PERSONAJE_3_DISPARANDO, renderizador));
    this->texturas_personaje_3.emplace_back(crearTextura(RUTA_UI_PERSONAJE_3_DISPARANDO_2, renderizador));
    this->texturas_personaje_3.emplace_back(crearTextura(RUTA_UI_PERSONAJE_3_GAME_OVER, renderizador));

    /// TEXTURAS PERSONAJE 4
    this->texturas_personaje_4.emplace_back(crearTextura(RUTA_UI_PERSONAJE_4_MUERTO, renderizador));
    this->texturas_personaje_4.emplace_back(crearTextura(RUTA_UI_PERSONAJE_4_VIVO, renderizador));
    this->texturas_personaje_4.emplace_back(crearTextura(RUTA_UI_PERSONAJE_4_DESCONECTADO, renderizador));
    this->texturas_personaje_4.emplace_back(crearTextura(RUTA_UI_PERSONAJE_4_DISPARANDO, renderizador));
    this->texturas_personaje_4.emplace_back(crearTextura(RUTA_UI_PERSONAJE_4_DISPARANDO_2, renderizador));
    this->texturas_personaje_4.emplace_back(crearTextura(RUTA_UI_PERSONAJE_4_GAME_OVER, renderizador));

    /// TEXTURAS BARRAS DE VIDA PERSONAJES
    this->texturas_barras_vidas.emplace_back(crearTextura(RUTA_UI_PERSONAJE_1_BV, renderizador));
    this->texturas_barras_vidas.emplace_back(crearTextura(RUTA_UI_PERSONAJE_2_BV, renderizador));
    this->texturas_barras_vidas.emplace_back(crearTextura(RUTA_UI_PERSONAJE_3_BV, renderizador));
    this->texturas_barras_vidas.emplace_back(crearTextura(RUTA_UI_PERSONAJE_4_BV, renderizador));
    this->texturas_barras_vidas.emplace_back(crearTextura(RUTA_UI_PERSONAJE_TEST_BV, renderizador));

}

std::vector<SDL_Texture*> CargadorTexturasUIPersonaje::getTexturas(int n_personaje){
    if (n_personaje == NRO_PERSONAJE_ROJO) {
        return this->texturas_personaje_1;

    } else if (n_personaje == NRO_PERSONAJE_VERDE) {
        return this->texturas_personaje_2;

    } else if (n_personaje == NRO_PERSONAJE_AMARILLO) {
        return this->texturas_personaje_3;

    } else {
        return this->texturas_personaje_4;

    }
}

SDL_Texture* CargadorTexturasUIPersonaje::getTexturaBarra(int n_personaje){
    if (n_personaje == NRO_PERSONAJE_ROJO) {
        return this->texturas_barras_vidas[(unsigned )n_personaje];

    } else if (n_personaje == NRO_PERSONAJE_VERDE) {
        return this->texturas_barras_vidas[(unsigned )n_personaje];

    } else if (n_personaje == NRO_PERSONAJE_AMARILLO) {
        return this->texturas_barras_vidas[(unsigned )n_personaje];

    } else {
        return this->texturas_barras_vidas[(unsigned )n_personaje];

    }
}

SDL_Texture* CargadorTexturasUIPersonaje::getTexturaBarraTest(){
    return this->texturas_barras_vidas[POS_BARRA_VIDA_TEST];
}

CargadorTexturasUIPersonaje::~CargadorTexturasUIPersonaje(){
    for (auto &i: this->texturas_personaje_1) {
        SDL_DestroyTexture(i);
    }
    for (auto &i: this->texturas_personaje_2) {
        SDL_DestroyTexture(i);
    }
    for (auto &i: this->texturas_personaje_3) {
        SDL_DestroyTexture(i);
    }
    for (auto &i: this->texturas_personaje_4) {
        SDL_DestroyTexture(i);
    }

    for (auto &i: this->texturas_barras_vidas) {
        SDL_DestroyTexture(i);
    }

}