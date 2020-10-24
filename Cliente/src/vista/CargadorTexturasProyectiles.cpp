#include "CargadorTexturasProyectiles.h"


CargadorTexturasProyectiles::CargadorTexturasProyectiles(SDL_Renderer* renderizador){

    //cargo solo una textura debido a que el disparo por ahora es solo siempre hacia la derecha
    //luego agregas mas cuando sean en 8 direcciones

    /// TEXTURAS PROYECTIL PERSONAJE 1
    this->texturas_proyectil_personaje_1.emplace_back(crearTextura(RUTA_PROYECTIL_PERSONAJE_1, renderizador));

    /// TEXTURAS PROYECTIL PERSONAJE 2
    this->texturas_proyectil_personaje_2.emplace_back(crearTextura(RUTA_PROYECTIL_PERSONAJE_2, renderizador));

    /// TEXTURAS PROYECTIL PERSONAJE 3
    this->texturas_proyectil_personaje_3.emplace_back(crearTextura(RUTA_PROYECTIL_PERSONAJE_3, renderizador));

    /// TEXTURAS PROYECTIL PERSONAJE 4
    this->texturas_proyectil_personaje_4.emplace_back(crearTextura(RUTA_PROYECTIL_PERSONAJE_4, renderizador));

    /// TEXTURAS PROYECTIL ENEMIGO CLASE 1
    this->texturas_proyectil_enemigo_1.emplace_back(crearTextura(RUTA_PROYECTIL_ENEMIGO, renderizador));

    /// TEXTURAS PROYECTIL ENEMIGO CLASE 2
    this->texturas_proyectil_enemigo_2.emplace_back(crearTextura(RUTA_PROYECTIL_ENEMIGO_2, renderizador));

    /// TEXTURAS PROYECTIL JEFE
    this->texturas_proyectil_jefe.emplace_back(crearTextura(RUTA_PROYECTIL_JEFE, renderizador));


    /// Texturas Luz
    this->textura_luz_p1 = crearTextura(RUTA_LUZ_PROY_P1, renderizador);
    this->textura_luz_p2 = crearTextura(RUTA_LUZ_PROY_P2, renderizador);
    this->textura_luz_p3 = crearTextura(RUTA_LUZ_PROY_P3, renderizador);
    this->textura_luz_p4 = crearTextura(RUTA_LUZ_PROY_P4, renderizador);
    this->textura_luz_e1 = crearTextura(RUTA_LUZ_PROY_E1, renderizador);
    this->textura_luz_e2 = crearTextura(RUTA_LUZ_PROY_E2, renderizador);
    this->textura_luz_j = crearTextura(RUTA_LUZ_PROY_J, renderizador);

    SDL_SetTextureAlphaMod(this->textura_luz_p1, OPACIDAD_LUZ_PROYECTIL);
    SDL_SetTextureBlendMode(this->textura_luz_p1, SDL_BLENDMODE_BLEND );
    SDL_SetTextureAlphaMod(this->textura_luz_p2, OPACIDAD_LUZ_PROYECTIL);
    SDL_SetTextureBlendMode(this->textura_luz_p2, SDL_BLENDMODE_BLEND );
    SDL_SetTextureAlphaMod(this->textura_luz_p3, OPACIDAD_LUZ_PROYECTIL);
    SDL_SetTextureBlendMode(this->textura_luz_p3, SDL_BLENDMODE_BLEND );
    SDL_SetTextureAlphaMod(this->textura_luz_p4, OPACIDAD_LUZ_PROYECTIL);
    SDL_SetTextureBlendMode(this->textura_luz_p4, SDL_BLENDMODE_BLEND );
    SDL_SetTextureAlphaMod(this->textura_luz_e1, OPACIDAD_LUZ_PROYECTIL);
    SDL_SetTextureBlendMode(this->textura_luz_e1, SDL_BLENDMODE_BLEND );
    SDL_SetTextureAlphaMod(this->textura_luz_e2, OPACIDAD_LUZ_PROYECTIL);
    SDL_SetTextureBlendMode(this->textura_luz_e2, SDL_BLENDMODE_BLEND );
    SDL_SetTextureAlphaMod(this->textura_luz_j, OPACIDAD_LUZ_PROYECTIL);
    SDL_SetTextureBlendMode(this->textura_luz_j, SDL_BLENDMODE_BLEND );
}



std::vector<SDL_Texture*> CargadorTexturasProyectiles::getTexturas(int nro_personaje){
    if (nro_personaje == NRO_PERSONAJE_ROJO) {
        return this->texturas_proyectil_personaje_1;

    } else if (nro_personaje == NRO_PERSONAJE_VERDE) {
        return this->texturas_proyectil_personaje_2;

    } else if (nro_personaje == NRO_PERSONAJE_AMARILLO) {
        return this->texturas_proyectil_personaje_3;

    } else if (nro_personaje == NRO_PERSONAJE_AZUL) {
        return this->texturas_proyectil_personaje_4;
    }
    else if (nro_personaje == NRO_ENEMIGO_TIPO_1){
        return this->texturas_proyectil_enemigo_1;
    }
    else if (nro_personaje == NRO_ENEMIGO_TIPO_2){
        return this->texturas_proyectil_enemigo_2;
    }
    else{
        return this->texturas_proyectil_jefe;
    }
}

SDL_Texture* CargadorTexturasProyectiles::getTexturaLuz(int nro_personaje){
    if (nro_personaje == NRO_PERSONAJE_ROJO) {
        return this->textura_luz_p1;

    } else if (nro_personaje == NRO_PERSONAJE_VERDE) {
        return this->textura_luz_p2;

    } else if (nro_personaje == NRO_PERSONAJE_AMARILLO) {
        return this->textura_luz_p3;

    } else if (nro_personaje == NRO_PERSONAJE_AZUL) {
        return this->textura_luz_p4;

    } else if (nro_personaje == NRO_ENEMIGO_TIPO_1) {
        return this->textura_luz_e1;
    }
    else if (nro_personaje == NRO_ENEMIGO_TIPO_2) {
        return this->textura_luz_e2;
    }
    else{
        return this->textura_luz_j;
    }
}

CargadorTexturasProyectiles::~CargadorTexturasProyectiles(){
    for (auto &i: this->texturas_proyectil_personaje_1) {
        SDL_DestroyTexture(i);
    }
    for (auto &i: this->texturas_proyectil_personaje_2) {
        SDL_DestroyTexture(i);
    }
    for (auto &i: this->texturas_proyectil_personaje_3) {
        SDL_DestroyTexture(i);
    }
    for (auto &i: this->texturas_proyectil_personaje_4) {
        SDL_DestroyTexture(i);
    }
    for (auto &i: this->texturas_proyectil_enemigo_1) {
        SDL_DestroyTexture(i);
    }
    for (auto &i: this->texturas_proyectil_enemigo_2) {
        SDL_DestroyTexture(i);
    }
    for (auto &i: this->texturas_proyectil_jefe) {
        SDL_DestroyTexture(i);
    }

    SDL_DestroyTexture(this->textura_luz_p1);
    SDL_DestroyTexture(this->textura_luz_p2);
    SDL_DestroyTexture(this->textura_luz_p3);
    SDL_DestroyTexture(this->textura_luz_p4);
    SDL_DestroyTexture(this->textura_luz_e1);
    SDL_DestroyTexture(this->textura_luz_e2);
    SDL_DestroyTexture(this->textura_luz_j);
}
