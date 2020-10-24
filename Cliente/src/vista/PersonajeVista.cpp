#include "PersonajeVista.h"


PersonajeVista::PersonajeVista(int pos_x, int pos_y, int nro_personaje_nuevo, CargadorTexturasPersonajes* cargador){

    this->texturas = cargador->getTexturas(nro_personaje_nuevo);

    this->textura_actual = this->texturas[DIRECCION_PERSONAJE_DERECHA];

    this->efecto_velocidad= new EfectoVelocidadVista(cargador->getTexturaEfectoVelocidad());

    this->efecto_escudo = new EfectoEscudoVista(cargador->getTexturaEscudo(nro_personaje_nuevo));

    initRect(&this->posicion, pos_x, pos_y, ANCHO_PERSONAJE, ALTO_PERSONAJE);
    initRect(&this->sprite_actual, 0, 0, ANCHO_PERSONAJE, ALTO_PERSONAJE);

    this->nro_personaje = nro_personaje_nuevo;

    this->contador_brillo_disparo = LIMITE_DISP;
    this->a_derecha = true;
    this->contador_brillo_nave = 0;
    this->contador_daniado = 0;
    this->escudo = false;
    this->propulsionando = false;
}


PersonajeVista::~PersonajeVista() {
    delete(this->efecto_velocidad);
    delete(this->efecto_escudo);
}


int PersonajeVista::getNumeroPersonaje(){
    return this->nro_personaje;
}

SDL_Rect* PersonajeVista::getPosicion(){
    return &this->posicion;
}

SDL_Texture* PersonajeVista::getTextura(){
    return this->textura_actual;
}

SDL_Rect* PersonajeVista::getSpriteActual(){
    return &this->sprite_actual;
}


void PersonajeVista::actualizar(int pos_x, int pos_y,int direccion, int disparando, int herido, int escudo_nuevo, int esta_propulsionando){

    unsigned pos_vec = (unsigned)( POS_VEC_TEXTURA * direccion);

    this->posicion.x = pos_x;
    this->posicion.y = pos_y;
    this->escudo = (bool)escudo_nuevo;
    this->propulsionando = (bool)esta_propulsionando;

    this->efecto_velocidad->actualizar(pos_x,pos_y, esta_propulsionando);
    this->efecto_escudo->actualizar(pos_x, pos_y);

    if (this->nro_personaje == NRO_PERSONAJE_DESCONECTADO) {
        if (herido) this->textura_actual = this->texturas[1];
        else this->textura_actual = this->texturas[0];
        return;
    }

    if (herido){
        this->contador_daniado = MAX_VALOR_CONTADOR_DANIADO;
    }
    if (this->contador_daniado > 0){
        if (this->contador_daniado % CANT_ESTADOS) this->textura_actual = this->texturas[POS_VISTA_PERSONAJE_DANIADO + pos_vec];
        else this->textura_actual = this->texturas[POS_VISTA_PERSONAJE_OSCURO + pos_vec];
        this->contador_daniado--;
        return;
    }

    int pos;
    if (disparando) {
        if (this->contador_brillo_disparo >= MAX_VALOR_CONTADOR_BRILLO) {
            this->contador_brillo_disparo = 0;
        }
        if (this->contador_brillo_disparo < LIMITE_DISP_MEDIO) pos=POS_BRILLOS_3;
        else if (this->contador_brillo_disparo < LIMITE_DISP) pos= POS_BRILLOS_3 + 1;
        else pos = 0;
        this->contador_brillo_disparo++;

    } else if (this->contador_brillo_disparo < MAX_VALOR_CONTADOR_BRILLO) {
        if (this->contador_brillo_disparo < LIMITE_DISP_MEDIO) pos=POS_BRILLOS_3;
        else if (this->contador_brillo_disparo < LIMITE_DISP) pos= POS_BRILLOS_3 + 1;
        else pos=0;
        this->contador_brillo_disparo++;
        this->contador_brillo_nave = 0;

    } else {
        if (this->a_derecha) this->contador_brillo_nave++;
        else this->contador_brillo_nave--;

        if (this->contador_brillo_nave >= CONST_BRILLOS_1) {
            this->a_derecha = false;
        } else if ((int) contador_brillo_nave < 0) {
            this->a_derecha = true;
        }

        pos = (int) (this->contador_brillo_nave / CONST_BRILLOS_2);
    }

    this->textura_actual = this->texturas[(unsigned long)BRILLOS[(unsigned) pos]+pos_vec];
}

void PersonajeVista::actualizarTexturas(int nro_personaje_nuevo, CargadorTexturasPersonajes* cargador){
    this->texturas = cargador->getTexturas(nro_personaje_nuevo);
    this->efecto_escudo->setTextura(cargador->getTexturaEscudo(nro_personaje_nuevo));
    this->nro_personaje = nro_personaje_nuevo;
}

void PersonajeVista::mostrarEfectoVelocidad(SDL_Renderer* renderizador){
    if( this->nro_personaje == NRO_PERSONAJE_DESCONECTADO ){
        return;
    }

    SDL_RenderCopy(renderizador,
                   this->efecto_velocidad->getTextura(),
                   NULL,
                   this->efecto_velocidad->getRectangulo()
    );
}

void PersonajeVista::mostrarEfectoEscudo(SDL_Renderer* renderizador){
    if (this->escudo) {
        SDL_RenderCopy(renderizador,
                       this->efecto_escudo->getTextura(),
                       NULL,
                       this->efecto_escudo->getRectangulo()
        );
    }
}

bool PersonajeVista::estaPropulsionando(){
    return this->propulsionando;
}

