#include "JuegoSonido.h"
#include "../tools/Log.h"


JuegoSonido::JuegoSonido(){
    if (Mix_OpenAudio(FRECUENCIA, MIX_DEFAULT_FORMAT, CANT_CANALES, CHUNKSIZE) < 0) {
        loguearError(LOG_FALLA_MIXER);
    }
    this->menu = nullptr;
    this->nivel = nullptr;
    this->muted = false;
    this->sfx_muted = false;

    // TODO ENTREGA: Dejo el juego muteado de base para que no moleste al probar con varios clientes de
    // forma local
    //this->unmute();
    this->mute();

    this->rutas_musicas_nivel.push_back(RUTA_MUSICA_NIVEL_1);
    this->rutas_musicas_nivel.push_back(RUTA_MUSICA_NIVEL_2);
    this->rutas_musicas_nivel.push_back(RUTA_MUSICA_NIVEL_3);
    this->rutas_musicas_nivel.push_back(RUTA_MUSICA_FIN_NIVEL);
    this->rutas_musicas_nivel.push_back(RUTA_MUSICA_GAME_OVER);
    this->rutas_musicas_nivel.push_back(RUTA_MUSICA_STAGES);

    this->sfx_disparo = Mix_LoadWAV(RUTA_MUSICA_DISPARO);
    this->sfx_explosion = Mix_LoadWAV(RUTA_MUSICA_EXPLOSION);
    this->sfx_impacto_enemigo = Mix_LoadWAV(RUTA_MUSICA_IMPACTO_ENEMIGO);
    this->sfx_impacto_personaje = Mix_LoadWAV(RUTA_MUSICA_IMPACTO_PERSONAJE);
    this->sfx_opcion_menu_arriba = Mix_LoadWAV(RUTA_MUSICA_OPCION_MENU_ARRIBA);
    this->sfx_opcion_menu_abajo = Mix_LoadWAV(RUTA_MUSICA_OPCION_MENU_ABAJO);
    this->sfx_opcion_menu_seleccionar = Mix_LoadWAV(RUTA_MUSICA_OPCION_MENU_SELECCIONAR);
    this->sfx_input_tecla_login = Mix_LoadWAV(RUTA_MUSICA_MENU_TECLA_LOGIN);
    this->sfx_propulsion = Mix_LoadWAV(RUTA_MUSICA_PROPULSION);
    this->sfx_agarrar_item = Mix_LoadWAV(RUTA_MUSICA_AGARRAR_ITEM);

    Mix_VolumeChunk(this->sfx_explosion, CHUNKVOLUME);

    Mix_Volume(-1, VOLUMEN);
}

JuegoSonido::~JuegoSonido(){
    if (this->menu){
        Mix_FreeMusic(this->menu);
    }

    if (this->nivel){
        Mix_FreeMusic(this->nivel);
    }

    Mix_FreeChunk(this->sfx_disparo);
    Mix_FreeChunk(this->sfx_explosion);
    Mix_FreeChunk(this->sfx_impacto_enemigo);
    Mix_FreeChunk(this->sfx_impacto_personaje);
    Mix_FreeChunk(this->sfx_opcion_menu_arriba);
    Mix_FreeChunk(this->sfx_opcion_menu_abajo);
    Mix_FreeChunk(this->sfx_opcion_menu_seleccionar);
    Mix_FreeChunk(this->sfx_input_tecla_login);
    Mix_FreeChunk(this->sfx_propulsion);
    Mix_FreeChunk(this->sfx_agarrar_item);
    Mix_CloseAudio();
    Mix_Quit();
}

void JuegoSonido::playMenu(){
    if(!Mix_PlayingMusic()){
        this->menu = Mix_LoadMUS(RUTA_MUSICA_MENU);
        Mix_FadeInMusic(this->menu, -1, MSEG_FADEINMUSIC);
    }
}

void JuegoSonido::stopMenu(){
    if (this->menu){
        Mix_FadeOutMusic(MSEG_FADEOUTMUSIC);
        Mix_FreeMusic(this->menu);
        this->menu = nullptr;
    }
}

void JuegoSonido::playNivel(int nro_nivel){
    if(!Mix_PlayingMusic()){
        if (this->nivel){
            Mix_FreeMusic(this->nivel);
        }

        this->nivel = Mix_LoadMUS(this->rutas_musicas_nivel[(unsigned long)nro_nivel].c_str());
        Mix_FadeInMusic(this->nivel, -1, MSEG_FADEINMUSIC);
    }
}

void JuegoSonido::playMusicaFinNivel() {
    if(!Mix_PlayingMusic()){
        this->nivel = Mix_LoadMUS(this->rutas_musicas_nivel[POSICION_RUTA_MUSICA_FIN_NIVEL].c_str());
        Mix_FadeInMusic(this->nivel, -1, MSEG_FADEINMUSIC);
    }
}

void JuegoSonido::playMusicaGameOver() {
    if(!Mix_PlayingMusic()){
        this->nivel = Mix_LoadMUS(this->rutas_musicas_nivel[POSICION_RUTA_MUSICA_GAME_OVER].c_str());
        Mix_FadeInMusic(this->nivel, -1, MSEG_FADEINMUSIC);
    }
}

void JuegoSonido::stopMusicaNivel(){
    if (this->nivel){
        Mix_FadeOutMusic(MSEG_FADEOUTMUSIC);
        Mix_FreeMusic(this->nivel);
        this->nivel = nullptr;
        Mix_FadeOutChannel(-1, MSEG_FADEOUTMUSIC);
    }
}

bool JuegoSonido::musicaSonando() {
    return Mix_PlayingMusic();
}

void JuegoSonido::playDisparo(){
    Mix_PlayChannel(CANAL_PLAY, this->sfx_disparo, 0);
}

void JuegoSonido::playExplosion(){
    Mix_PlayChannel(CANAL_PLAY, this->sfx_explosion, 0);
}

void JuegoSonido::playImpactoEnemigo() {
    Mix_PlayChannel(CANAL_PLAY, this->sfx_impacto_enemigo, 0);
}

void JuegoSonido::playImpactoPersonaje() {
    Mix_PlayChannel(CANAL_PLAY, this->sfx_impacto_personaje, 0);
}

void JuegoSonido::playOpcionMenuArriba() {
    Mix_PlayChannel(CANAL_PLAY, this->sfx_opcion_menu_arriba, 0);
}

void JuegoSonido::playOpcionMenuAbajo() {
    Mix_PlayChannel(CANAL_PLAY, this->sfx_opcion_menu_abajo, 0);
}

void JuegoSonido::playOpcionMenuSeleccionar() {
    Mix_PlayChannel(CANAL_PLAY, this->sfx_opcion_menu_seleccionar, 0);
}

void JuegoSonido::playTeclaLogin() {
    Mix_PlayChannel(CANAL_PLAY, this->sfx_input_tecla_login, 0);
}

void JuegoSonido::playPropulsionPersonaje() {
    Mix_PlayChannel(CANAL_PLAY, this->sfx_propulsion, 0);
}

void JuegoSonido::playAgarrarItem() {
    Mix_PlayChannel(CANAL_PLAY, this->sfx_agarrar_item, 0);
}

void JuegoSonido::mute(){
    if (!this->muted){
        Mix_VolumeMusic(0);
        // Mix_Volume(-1, 0); // Sonidos
        this->muted = true;
    }

    else{
        this->unmute();
    }
}

void JuegoSonido::muteSFX(){
    if (!this->sfx_muted){
        Mix_Volume(-1, 0); // Sonidos
        this->sfx_muted = true;
    }

    else{
        this->unmuteSFX();
    }
}

void JuegoSonido::unmute(){
    Mix_VolumeMusic(VOLUMEN_UNMUTE);
    this->muted = false;
}

void JuegoSonido::unmuteSFX(){
    Mix_Volume(-1, VOLUMEN);
    this->sfx_muted = false;
}

void JuegoSonido::playJefe(char* ruta){
    if (this->nivel){
        Mix_FadeOutMusic(MSEG_FADEOUTMUSIC_JEFE);
        Mix_FreeMusic(this->nivel);
    }

    this->nivel = Mix_LoadMUS(ruta);
    Mix_PlayMusic(this->nivel, -1);
}

void JuegoSonido::playJefe1() {
    playJefe(RUTA_MUSICA_JEFE_1);
}

void JuegoSonido::playJefe2() {
    playJefe(RUTA_MUSICA_JEFE_2);
}

void JuegoSonido::playJefe3() {
    playJefe(RUTA_MUSICA_JEFE_3);
}

void JuegoSonido::playMusicaStages() {
    if(!Mix_PlayingMusic()){
        Mix_FreeMusic(this->nivel);
        this->nivel = Mix_LoadMUS(this->rutas_musicas_nivel[POSICION_RUTA_MUSICA_STAGES].c_str());
        Mix_FadeInMusic(this->nivel, 0, MSEG_FADEINMUSIC);
    }
}
void JuegoSonido::stopMusicaStages() {
    if (this->nivel){
        Mix_FreeMusic(this->nivel);
        this->nivel = nullptr;
        Mix_FadeOutChannel(-1, MSEG_FADEINMUSIC);
    }
}
