#include "CargadorTexturasPersonajes.h"

CargadorTexturasPersonajes::CargadorTexturasPersonajes(SDL_Renderer* renderizador){
    /// TEXTURAS PERSONAJE 1
    this->texturas_personaje_1.emplace_back(crearTextura(RUTA_PERSONAJE_1_DER_CLARO, renderizador));
    this->texturas_personaje_1.emplace_back(crearTextura(RUTA_PERSONAJE_1_DER_NORMAL, renderizador));
    this->texturas_personaje_1.emplace_back(crearTextura(RUTA_PERSONAJE_1_DER_OSCURO, renderizador));
    this->texturas_personaje_1.emplace_back(crearTextura(RUTA_PERSONAJE_1_DER_DISP1, renderizador));
    this->texturas_personaje_1.emplace_back(crearTextura(RUTA_PERSONAJE_1_DER_DISP2, renderizador));
    this->texturas_personaje_1.emplace_back(crearTextura(RUTA_PERSONAJE_1_DER_DANIADO, renderizador));
    this->texturas_personaje_1.emplace_back(crearTextura(RUTA_PERSONAJE_1_ARR_CLARO, renderizador));
    this->texturas_personaje_1.emplace_back(crearTextura(RUTA_PERSONAJE_1_ARR_NORMAL, renderizador));
    this->texturas_personaje_1.emplace_back(crearTextura(RUTA_PERSONAJE_1_ARR_OSCURO, renderizador));
    this->texturas_personaje_1.emplace_back(crearTextura(RUTA_PERSONAJE_1_ARR_DISP1, renderizador));
    this->texturas_personaje_1.emplace_back(crearTextura(RUTA_PERSONAJE_1_ARR_DISP2, renderizador));
    this->texturas_personaje_1.emplace_back(crearTextura(RUTA_PERSONAJE_1_ARR_DANIADO, renderizador));
    this->texturas_personaje_1.emplace_back(crearTextura(RUTA_PERSONAJE_1_ABA_CLARO, renderizador));
    this->texturas_personaje_1.emplace_back(crearTextura(RUTA_PERSONAJE_1_ABA_NORMAL, renderizador));
    this->texturas_personaje_1.emplace_back(crearTextura(RUTA_PERSONAJE_1_ABA_OSCURO, renderizador));
    this->texturas_personaje_1.emplace_back(crearTextura(RUTA_PERSONAJE_1_ABA_DISP1, renderizador));
    this->texturas_personaje_1.emplace_back(crearTextura(RUTA_PERSONAJE_1_ABA_DISP2, renderizador));
    this->texturas_personaje_1.emplace_back(crearTextura(RUTA_PERSONAJE_1_ABA_DANIADO, renderizador));

    /// TEXTURAS PERSONAJE 2

    this->texturas_personaje_2.emplace_back(crearTextura(RUTA_PERSONAJE_2_DER_CLARO, renderizador));
    this->texturas_personaje_2.emplace_back(crearTextura(RUTA_PERSONAJE_2_DER_NORMAL, renderizador));
    this->texturas_personaje_2.emplace_back(crearTextura(RUTA_PERSONAJE_2_DER_OSCURO, renderizador));
    this->texturas_personaje_2.emplace_back(crearTextura(RUTA_PERSONAJE_2_DER_DISP1, renderizador));
    this->texturas_personaje_2.emplace_back(crearTextura(RUTA_PERSONAJE_2_DER_DISP2, renderizador));
    this->texturas_personaje_2.emplace_back(crearTextura(RUTA_PERSONAJE_2_DER_DANIADO, renderizador));
    this->texturas_personaje_2.emplace_back(crearTextura(RUTA_PERSONAJE_2_ARR_CLARO, renderizador));
    this->texturas_personaje_2.emplace_back(crearTextura(RUTA_PERSONAJE_2_ARR_NORMAL, renderizador));
    this->texturas_personaje_2.emplace_back(crearTextura(RUTA_PERSONAJE_2_ARR_OSCURO, renderizador));
    this->texturas_personaje_2.emplace_back(crearTextura(RUTA_PERSONAJE_2_ARR_DISP1, renderizador));
    this->texturas_personaje_2.emplace_back(crearTextura(RUTA_PERSONAJE_2_ARR_DISP2, renderizador));
    this->texturas_personaje_2.emplace_back(crearTextura(RUTA_PERSONAJE_2_ARR_DANIADO, renderizador));
    this->texturas_personaje_2.emplace_back(crearTextura(RUTA_PERSONAJE_2_ABA_CLARO, renderizador));
    this->texturas_personaje_2.emplace_back(crearTextura(RUTA_PERSONAJE_2_ABA_NORMAL, renderizador));
    this->texturas_personaje_2.emplace_back(crearTextura(RUTA_PERSONAJE_2_ABA_OSCURO, renderizador));
    this->texturas_personaje_2.emplace_back(crearTextura(RUTA_PERSONAJE_2_ABA_DISP1, renderizador));
    this->texturas_personaje_2.emplace_back(crearTextura(RUTA_PERSONAJE_2_ABA_DISP2, renderizador));
    this->texturas_personaje_2.emplace_back(crearTextura(RUTA_PERSONAJE_2_ABA_DANIADO, renderizador));

    /// TEXTURAS PERSONAJE 3

    this->texturas_personaje_3.emplace_back(crearTextura(RUTA_PERSONAJE_3_DER_CLARO, renderizador));
    this->texturas_personaje_3.emplace_back(crearTextura(RUTA_PERSONAJE_3_DER_NORMAL, renderizador));
    this->texturas_personaje_3.emplace_back(crearTextura(RUTA_PERSONAJE_3_DER_OSCURO, renderizador));
    this->texturas_personaje_3.emplace_back(crearTextura(RUTA_PERSONAJE_3_DER_DISP1, renderizador));
    this->texturas_personaje_3.emplace_back(crearTextura(RUTA_PERSONAJE_3_DER_DISP2, renderizador));
    this->texturas_personaje_3.emplace_back(crearTextura(RUTA_PERSONAJE_3_DER_DANIADO, renderizador));
    this->texturas_personaje_3.emplace_back(crearTextura(RUTA_PERSONAJE_3_ARR_CLARO, renderizador));
    this->texturas_personaje_3.emplace_back(crearTextura(RUTA_PERSONAJE_3_ARR_NORMAL, renderizador));
    this->texturas_personaje_3.emplace_back(crearTextura(RUTA_PERSONAJE_3_ARR_OSCURO, renderizador));
    this->texturas_personaje_3.emplace_back(crearTextura(RUTA_PERSONAJE_3_ARR_DISP1, renderizador));
    this->texturas_personaje_3.emplace_back(crearTextura(RUTA_PERSONAJE_3_ARR_DISP2, renderizador));
    this->texturas_personaje_3.emplace_back(crearTextura(RUTA_PERSONAJE_3_ARR_DANIADO, renderizador));
    this->texturas_personaje_3.emplace_back(crearTextura(RUTA_PERSONAJE_3_ABA_CLARO, renderizador));
    this->texturas_personaje_3.emplace_back(crearTextura(RUTA_PERSONAJE_3_ABA_NORMAL, renderizador));
    this->texturas_personaje_3.emplace_back(crearTextura(RUTA_PERSONAJE_3_ABA_OSCURO, renderizador));
    this->texturas_personaje_3.emplace_back(crearTextura(RUTA_PERSONAJE_3_ABA_DISP1, renderizador));
    this->texturas_personaje_3.emplace_back(crearTextura(RUTA_PERSONAJE_3_ABA_DISP2, renderizador));
    this->texturas_personaje_3.emplace_back(crearTextura(RUTA_PERSONAJE_3_ABA_DANIADO, renderizador));


    /// TEXTURAS PERSONAJE 4

    this->texturas_personaje_4.emplace_back(crearTextura(RUTA_PERSONAJE_4_DER_CLARO, renderizador));
    this->texturas_personaje_4.emplace_back(crearTextura(RUTA_PERSONAJE_4_DER_NORMAL, renderizador));
    this->texturas_personaje_4.emplace_back(crearTextura(RUTA_PERSONAJE_4_DER_OSCURO, renderizador));
    this->texturas_personaje_4.emplace_back(crearTextura(RUTA_PERSONAJE_4_DER_DISP1, renderizador));
    this->texturas_personaje_4.emplace_back(crearTextura(RUTA_PERSONAJE_4_DER_DISP2, renderizador));
    this->texturas_personaje_4.emplace_back(crearTextura(RUTA_PERSONAJE_4_DER_DANIADO, renderizador));
    this->texturas_personaje_4.emplace_back(crearTextura(RUTA_PERSONAJE_4_ARR_CLARO, renderizador));
    this->texturas_personaje_4.emplace_back(crearTextura(RUTA_PERSONAJE_4_ARR_NORMAL, renderizador));
    this->texturas_personaje_4.emplace_back(crearTextura(RUTA_PERSONAJE_4_ARR_OSCURO, renderizador));
    this->texturas_personaje_4.emplace_back(crearTextura(RUTA_PERSONAJE_4_ARR_DISP1, renderizador));
    this->texturas_personaje_4.emplace_back(crearTextura(RUTA_PERSONAJE_4_ARR_DISP2, renderizador));
    this->texturas_personaje_4.emplace_back(crearTextura(RUTA_PERSONAJE_4_ARR_DANIADO, renderizador));
    this->texturas_personaje_4.emplace_back(crearTextura(RUTA_PERSONAJE_4_ABA_CLARO, renderizador));
    this->texturas_personaje_4.emplace_back(crearTextura(RUTA_PERSONAJE_4_ABA_NORMAL, renderizador));
    this->texturas_personaje_4.emplace_back(crearTextura(RUTA_PERSONAJE_4_ABA_OSCURO, renderizador));
    this->texturas_personaje_4.emplace_back(crearTextura(RUTA_PERSONAJE_4_ABA_DISP1, renderizador));
    this->texturas_personaje_4.emplace_back(crearTextura(RUTA_PERSONAJE_4_ABA_DISP2, renderizador));
    this->texturas_personaje_4.emplace_back(crearTextura(RUTA_PERSONAJE_4_ABA_DANIADO, renderizador));


    /// TEXTURAS PERSONAJE DESCONECTADO
    this->texturas_personaje_desconectado.emplace_back(crearTextura(RUTA_PERSONAJE_DESCONECTADO, renderizador));
    this->texturas_personaje_desconectado.emplace_back(crearTextura(RUTA_PERSONAJE_DESCONECTADO_DANIADO, renderizador));

    this->textura_efecto_velocidad=crearTextura(RUTA_IMAGEN_EFECTO_VELOCIDAD, renderizador);

    this->texturas_escudo.emplace_back(crearTextura(RUTA_PERSONAJE_1_ESCUDO, renderizador));
    this->texturas_escudo.emplace_back(crearTextura(RUTA_PERSONAJE_2_ESCUDO, renderizador));
    this->texturas_escudo.emplace_back(crearTextura(RUTA_PERSONAJE_3_ESCUDO, renderizador));
    this->texturas_escudo.emplace_back(crearTextura(RUTA_PERSONAJE_4_ESCUDO, renderizador));
    this->texturas_escudo.emplace_back(crearTextura(RUTA_PERSONAJE_DESCONECTADO_ESCUDO, renderizador));

    SDL_SetTextureAlphaMod(this->texturas_escudo[0], OPACIDAD_TEXTURA_ESCUDO);
    SDL_SetTextureBlendMode(this->texturas_escudo[0], SDL_BLENDMODE_BLEND );
    SDL_SetTextureAlphaMod(this->texturas_escudo[1], OPACIDAD_TEXTURA_ESCUDO);
    SDL_SetTextureBlendMode(this->texturas_escudo[1], SDL_BLENDMODE_BLEND );
    SDL_SetTextureAlphaMod(this->texturas_escudo[2], OPACIDAD_TEXTURA_ESCUDO);
    SDL_SetTextureBlendMode(this->texturas_escudo[2], SDL_BLENDMODE_BLEND );
    SDL_SetTextureAlphaMod(this->texturas_escudo[3], OPACIDAD_TEXTURA_ESCUDO);
    SDL_SetTextureBlendMode(this->texturas_escudo[3], SDL_BLENDMODE_BLEND );
    SDL_SetTextureAlphaMod(this->texturas_escudo[4], OPACIDAD_TEXTURA_ESCUDO);
    SDL_SetTextureBlendMode(this->texturas_escudo[4], SDL_BLENDMODE_BLEND );

}

std::vector<SDL_Texture*> CargadorTexturasPersonajes::getTexturas(int n_personaje){
    if (n_personaje == NRO_PERSONAJE_ROJO) {
        return this->texturas_personaje_1;

    }

    else if (n_personaje == NRO_PERSONAJE_VERDE) {
        return this->texturas_personaje_2;

    }

    else if (n_personaje == NRO_PERSONAJE_AMARILLO) {
        return this->texturas_personaje_3;

    }

    else if (n_personaje == NRO_PERSONAJE_AZUL){
        return this->texturas_personaje_4;
    }

    //else if (n_personaje == NRO_PERSONAJE_DESCONECTADO)
    return  this->texturas_personaje_desconectado;
}

SDL_Texture* CargadorTexturasPersonajes::getTexturaEfectoVelocidad() {
    return this->textura_efecto_velocidad;
}

SDL_Texture* CargadorTexturasPersonajes::getTexturaEscudo(int n_personaje) {
    return this->texturas_escudo[(long unsigned) n_personaje];
}

CargadorTexturasPersonajes::~CargadorTexturasPersonajes(){
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

    SDL_DestroyTexture(this->textura_efecto_velocidad);

    for (auto &i: this->texturas_escudo) {
        SDL_DestroyTexture(i);
    }

    for (auto &i: this->texturas_personaje_desconectado) {
        SDL_DestroyTexture(i);
    }

}