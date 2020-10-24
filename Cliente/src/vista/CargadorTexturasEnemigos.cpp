#include "CargadorTexturasEnemigos.h"



CargadorTexturasEnemigos::CargadorTexturasEnemigos(SDL_Renderer *renderizador) {
    /// TEXTURAS ENEMIGO 1
    this->texturas_enemigo_1.emplace_back(crearTextura(getRutaImagenEnemigo1(), renderizador));
    this->texturas_enemigo_1.emplace_back(crearTextura(RUTA_IMAGEN_TIPO_ENEMIGO_1_DERECHA, renderizador));
    this->texturas_enemigo_1.emplace_back(crearTextura(RUTA_IMAGEN_TIPO_ENEMIGO_1_DANIADO, renderizador));
    this->texturas_enemigo_1.emplace_back(crearTextura(RUTA_IMAGEN_TIPO_ENEMIGO_1_DERECHA_DANIADO, renderizador));


    /// TEXTURAS ENEMIGO 2

    this->texturas_enemigo_2.emplace_back(crearTextura(getRutaImagenEnemigo2(), renderizador));
    this->texturas_enemigo_2.emplace_back(crearTextura(getRutaImagenEnemigo2(), renderizador));
    this->texturas_enemigo_2.emplace_back(crearTextura(RUTA_IMAGEN_TIPO_ENEMIGO_2_DANIADO, renderizador));
    this->texturas_enemigo_2.emplace_back(crearTextura(RUTA_IMAGEN_TIPO_ENEMIGO_2_DANIADO, renderizador));

    /// JEFE 1
    this->texturas_jefe_1.emplace_back(crearTextura(RUTA_IMAGEN_TIPO_JEFE_1_1, renderizador));
    this->texturas_jefe_1.emplace_back(crearTextura(RUTA_IMAGEN_TIPO_JEFE_1_2, renderizador));
    this->texturas_jefe_1.emplace_back(crearTextura(RUTA_IMAGEN_TIPO_JEFE_1_3, renderizador));
    this->texturas_jefe_1.emplace_back(crearTextura(RUTA_IMAGEN_TIPO_JEFE_1_4, renderizador));
    this->texturas_jefe_1.emplace_back(crearTextura(RUTA_IMAGEN_TIPO_JEFE_1_5, renderizador));
    this->texturas_jefe_1.emplace_back(crearTextura(RUTA_IMAGEN_TIPO_JEFE_1_6, renderizador));
    this->texturas_jefe_1.emplace_back(crearTextura(RUTA_IMAGEN_TIPO_JEFE_1_7, renderizador));
    this->texturas_jefe_1.emplace_back(crearTextura(RUTA_IMAGEN_TIPO_JEFE_1_8, renderizador));
    this->texturas_jefe_1.emplace_back(crearTextura(RUTA_IMAGEN_TIPO_JEFE_1_1_DANIADO, renderizador));
    this->texturas_jefe_1.emplace_back(crearTextura(RUTA_IMAGEN_TIPO_JEFE_1_2_DANIADO, renderizador));
    this->texturas_jefe_1.emplace_back(crearTextura(RUTA_IMAGEN_TIPO_JEFE_1_3_DANIADO, renderizador));
    this->texturas_jefe_1.emplace_back(crearTextura(RUTA_IMAGEN_TIPO_JEFE_1_4_DANIADO, renderizador));
    this->texturas_jefe_1.emplace_back(crearTextura(RUTA_IMAGEN_TIPO_JEFE_1_5_DANIADO, renderizador));
    this->texturas_jefe_1.emplace_back(crearTextura(RUTA_IMAGEN_TIPO_JEFE_1_6_DANIADO, renderizador));
    this->texturas_jefe_1.emplace_back(crearTextura(RUTA_IMAGEN_TIPO_JEFE_1_7_DANIADO, renderizador));
    this->texturas_jefe_1.emplace_back(crearTextura(RUTA_IMAGEN_TIPO_JEFE_1_8_DANIADO, renderizador));


    /// JEFE 2
    this->texturas_jefe_2.emplace_back(crearTextura(RUTA_IMAGEN_TIPO_JEFE_2_ROT1, renderizador));
    this->texturas_jefe_2.emplace_back(crearTextura(RUTA_IMAGEN_TIPO_JEFE_2_ROT2, renderizador));
    this->texturas_jefe_2.emplace_back(crearTextura(RUTA_IMAGEN_TIPO_JEFE_2_ROT3, renderizador));
    this->texturas_jefe_2.emplace_back(crearTextura(RUTA_IMAGEN_TIPO_JEFE_2_ROT4, renderizador));
    this->texturas_jefe_2.emplace_back(crearTextura(RUTA_IMAGEN_TIPO_JEFE_2_ROT5, renderizador));
    this->texturas_jefe_2.emplace_back(crearTextura(RUTA_IMAGEN_TIPO_JEFE_2_ROT6, renderizador));
    this->texturas_jefe_2.emplace_back(crearTextura(RUTA_IMAGEN_TIPO_JEFE_2_ROT7, renderizador));
    this->texturas_jefe_2.emplace_back(crearTextura(RUTA_IMAGEN_TIPO_JEFE_2_ROT8, renderizador));
    this->texturas_jefe_2.emplace_back(crearTextura(RUTA_IMAGEN_TIPO_JEFE_2_ROT1_DANIADO, renderizador));
    this->texturas_jefe_2.emplace_back(crearTextura(RUTA_IMAGEN_TIPO_JEFE_2_ROT2_DANIADO, renderizador));
    this->texturas_jefe_2.emplace_back(crearTextura(RUTA_IMAGEN_TIPO_JEFE_2_ROT3_DANIADO, renderizador));
    this->texturas_jefe_2.emplace_back(crearTextura(RUTA_IMAGEN_TIPO_JEFE_2_ROT4_DANIADO, renderizador));
    this->texturas_jefe_2.emplace_back(crearTextura(RUTA_IMAGEN_TIPO_JEFE_2_ROT5_DANIADO, renderizador));
    this->texturas_jefe_2.emplace_back(crearTextura(RUTA_IMAGEN_TIPO_JEFE_2_ROT6_DANIADO, renderizador));
    this->texturas_jefe_2.emplace_back(crearTextura(RUTA_IMAGEN_TIPO_JEFE_2_ROT7_DANIADO, renderizador));
    this->texturas_jefe_2.emplace_back(crearTextura(RUTA_IMAGEN_TIPO_JEFE_2_ROT8_DANIADO, renderizador));

    /// JEFE 3


    this->texturas_jefe_3.emplace_back(crearTextura(RUTA_IMAGEN_TIPO_JEFE_3_1, renderizador));
    this->texturas_jefe_3.emplace_back(crearTextura(RUTA_IMAGEN_TIPO_JEFE_3_2, renderizador));
    this->texturas_jefe_3.emplace_back(crearTextura(RUTA_IMAGEN_TIPO_JEFE_3_3, renderizador));
    this->texturas_jefe_3.emplace_back(crearTextura(RUTA_IMAGEN_TIPO_JEFE_3_4, renderizador));
    this->texturas_jefe_3.emplace_back(crearTextura(RUTA_IMAGEN_TIPO_JEFE_3_5, renderizador));
    this->texturas_jefe_3.emplace_back(crearTextura(RUTA_IMAGEN_TIPO_JEFE_3_6, renderizador));
    this->texturas_jefe_3.emplace_back(crearTextura(RUTA_IMAGEN_TIPO_JEFE_3_7, renderizador));
    this->texturas_jefe_3.emplace_back(crearTextura(RUTA_IMAGEN_TIPO_JEFE_3_8, renderizador));
    this->texturas_jefe_3.emplace_back(crearTextura(RUTA_IMAGEN_TIPO_JEFE_3_1_DANIADO, renderizador));
    this->texturas_jefe_3.emplace_back(crearTextura(RUTA_IMAGEN_TIPO_JEFE_3_2_DANIADO, renderizador));
    this->texturas_jefe_3.emplace_back(crearTextura(RUTA_IMAGEN_TIPO_JEFE_3_3_DANIADO, renderizador));
    this->texturas_jefe_3.emplace_back(crearTextura(RUTA_IMAGEN_TIPO_JEFE_3_4_DANIADO, renderizador));
    this->texturas_jefe_3.emplace_back(crearTextura(RUTA_IMAGEN_TIPO_JEFE_3_5_DANIADO, renderizador));
    this->texturas_jefe_3.emplace_back(crearTextura(RUTA_IMAGEN_TIPO_JEFE_3_6_DANIADO, renderizador));
    this->texturas_jefe_3.emplace_back(crearTextura(RUTA_IMAGEN_TIPO_JEFE_3_7_DANIADO, renderizador));
    this->texturas_jefe_3.emplace_back(crearTextura(RUTA_IMAGEN_TIPO_JEFE_3_8_DANIADO, renderizador));

    /// TEXTURAS ENEMIGO DEFAULT
    this->texturas_enemigo_default.emplace_back(crearTextura(RUTA_IMG_DEFECTO, renderizador));
    this->texturas_enemigo_default.emplace_back(this->texturas_enemigo_default[0]);
    this->texturas_enemigo_default.emplace_back(this->texturas_enemigo_default[0]);
    this->texturas_enemigo_default.emplace_back(this->texturas_enemigo_default[0]);
    this->texturas_enemigo_default.emplace_back(this->texturas_enemigo_default[0]);
    this->texturas_enemigo_default.emplace_back(this->texturas_enemigo_default[0]);
    this->texturas_enemigo_default.emplace_back(this->texturas_enemigo_default[0]);
    this->texturas_enemigo_default.emplace_back(this->texturas_enemigo_default[0]);
    this->texturas_enemigo_default.emplace_back(this->texturas_enemigo_default[0]);
    this->texturas_enemigo_default.emplace_back(this->texturas_enemigo_default[0]);
    this->texturas_enemigo_default.emplace_back(this->texturas_enemigo_default[0]);
    this->texturas_enemigo_default.emplace_back(this->texturas_enemigo_default[0]);
    this->texturas_enemigo_default.emplace_back(this->texturas_enemigo_default[0]);
    this->texturas_enemigo_default.emplace_back(this->texturas_enemigo_default[0]);
    this->texturas_enemigo_default.emplace_back(this->texturas_enemigo_default[0]);
    this->texturas_enemigo_default.emplace_back(this->texturas_enemigo_default[0]);
    
}

std::vector<SDL_Texture *> CargadorTexturasEnemigos::getTexturas(std::string tipo_enemigo) {
    if (tipo_enemigo == getTipoEnemigo1()) {
        return this->texturas_enemigo_1;
    }
    else if (tipo_enemigo == getTipoEnemigo2()){
        return this->texturas_enemigo_2;
    }
    else if (tipo_enemigo == TIPO_JEFE_1){
        return this->texturas_jefe_1;
    }
    else if (tipo_enemigo == TIPO_JEFE_2){
        return this->texturas_jefe_2;
    }
    else if(tipo_enemigo == TIPO_JEFE_3){
        return this->texturas_jefe_3;
    }

    return this->texturas_enemigo_default;
}

CargadorTexturasEnemigos::~CargadorTexturasEnemigos() {
    for (auto &i: this->texturas_enemigo_1) {
        SDL_DestroyTexture(i);
    }

    for (auto &i: this->texturas_enemigo_2) {
        SDL_DestroyTexture(i);
    }

    for (auto &i: this->texturas_jefe_1) {
        SDL_DestroyTexture(i);
    }

    for (auto &i: this->texturas_jefe_2) {
        SDL_DestroyTexture(i);
    }

    for (auto &i: this->texturas_jefe_3) {
        SDL_DestroyTexture(i);
    }

    SDL_DestroyTexture(this->texturas_enemigo_default[0]);
}
