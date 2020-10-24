#include "TextoSDL.h"



TextoSDL::TextoSDL(SDL_Renderer* renderizador, TTF_Font* fuente_nueva, SDL_Color color, int tam, char *msj,
                   int x, int y){
    this->renderizador = renderizador;

    initRect(&this->rectangulo, x, y, tam * (int) strlen(msj), tam);

    this->fuente = fuente_nueva;

    this->color = color;
    this->mensaje = msj;

    SDL_Surface* sup_aux = ::TTF_RenderText_Blended(this->fuente, msj, this->color);
    this->texto = SDL_CreateTextureFromSurface(this->renderizador, sup_aux);
    SDL_FreeSurface(sup_aux);
}

SDL_Texture* TextoSDL::getTexto() {
    return this->texto;
}

char *TextoSDL::getMensaje() {
    return this->mensaje;
}

void TextoSDL::setTexto(const char *msj) {
    setTexto(msj, this->color);
}

void TextoSDL::setTexto(const char *msj, SDL_Color c) {
    this->mensaje = const_cast<char *>(msj);
    SDL_DestroyTexture(this->texto);

    SDL_Surface* sup_aux = ::TTF_RenderText_Solid(this->fuente, msj, c);
    this->texto = SDL_CreateTextureFromSurface(this->renderizador, sup_aux);
    SDL_FreeSurface(sup_aux);

    this->rectangulo.w = this->rectangulo.h * (int) strlen(msj);
}

SDL_Rect* TextoSDL::getRectangulo() {
    return &this->rectangulo;
}

SDL_Color TextoSDL::getColor() {
    return this->color;
}

TextoSDL::~TextoSDL() {

    SDL_DestroyTexture(this->texto);
}