#ifndef CLIENTE_CONSTANTESMUSICA_H
#define CLIENTE_CONSTANTESMUSICA_H

static constexpr char *RUTA_MUSICA_NIVEL_1 = (char *) ("../data/music/nivel_1.mp3");
static constexpr char *RUTA_MUSICA_NIVEL_2 = (char *) ("../data/music/nivel_2.mp3");
static constexpr char *RUTA_MUSICA_NIVEL_3 = (char *) ("../data/music/nivel_3.mp3");
static constexpr char *RUTA_MUSICA_FIN_NIVEL = (char *) ("../data/music/fin_nivel.mp3");
static constexpr char *RUTA_MUSICA_GAME_OVER = (char *) ("../data/music/game_over.mp3");
static constexpr char *RUTA_MUSICA_DISPARO = (char *) ("../data/sfx/disparo.wav");
static constexpr char *RUTA_MUSICA_IMPACTO_ENEMIGO = (char *) ("../data/sfx/impacto_enemigo.wav");
static constexpr char *RUTA_MUSICA_IMPACTO_PERSONAJE = (char *) ("../data/sfx/impacto_personaje.wav");
static constexpr char *RUTA_MUSICA_EXPLOSION = (char *) ("../data/sfx/explosion_enemigo.wav");
static constexpr char *RUTA_MUSICA_MENU = (char *) ("../data/music/menu.mp3");
static constexpr char *RUTA_MUSICA_STAGES = (char *) ("../data/music/stages.mp3");
static constexpr char *RUTA_MUSICA_OPCION_MENU_ARRIBA = (char *) ("../data/sfx/opcion_menu_arriba.wav");
static constexpr char *RUTA_MUSICA_OPCION_MENU_ABAJO = (char *) ("../data/sfx/opcion_menu_abajo.wav");
static constexpr char *RUTA_MUSICA_OPCION_MENU_SELECCIONAR = (char *) ("../data/sfx/opcion_menu_seleccionar.wav");
static constexpr char *RUTA_MUSICA_MENU_TECLA_LOGIN = (char *) ("../data/sfx/input_tecla_login.wav");
static constexpr char *RUTA_MUSICA_PROPULSION = (char *) ("../data/sfx/propulsion.wav");
static constexpr char *RUTA_MUSICA_AGARRAR_ITEM = (char *) ("../data/sfx/agarrar_item.wav");

static constexpr char *RUTA_MUSICA_JEFE_1 = (char *) ("../data/music/jefe_1.mp3");
static constexpr char *RUTA_MUSICA_JEFE_2 = (char *) ("../data/music/jefe_2.mp3");
static constexpr char *RUTA_MUSICA_JEFE_3 = (char *) ("../data/music/jefe_3.mp3");

//Considerando que tenemos 3 nivel (0, 1, 2)
static const unsigned long POSICION_RUTA_MUSICA_FIN_NIVEL = 3;
static const unsigned long POSICION_RUTA_MUSICA_GAME_OVER = 4;
static const unsigned long POSICION_RUTA_MUSICA_STAGES = 5;

static const unsigned int DJ_NO_TRACK = 0;
static const unsigned int DJ_TRACK_NIVEL = 1;
static const unsigned int DJ_TRACK_JEFE_1 = 2;
static const unsigned int DJ_TRACK_JEFE_2 = 3;
static const unsigned int DJ_TRACK_JEFE_3 = 4;
static const unsigned int DJ_TRACK_MENU = 5;
static const unsigned int DJ_DIE = 6;
static const unsigned int DJ_STOP_STAGE = 7;

static const unsigned int FRECUENCIA = 44100;
static const unsigned int CHUNKSIZE = 2048;
static const unsigned int CANT_CANALES = 4;

static const unsigned int VOLUMEN = 64;
static const unsigned int VOLUMEN_UNMUTE = 20;
static const unsigned int CHUNKVOLUME = 128;

static const unsigned int MSEG_FADEINMUSIC = 500;
static const unsigned int MSEG_FADEOUTMUSIC = 1000;
static const unsigned int MSEG_FADEOUTMUSIC_JEFE = 800;

static const unsigned int CANAL_PLAY = -1;

#endif //CLIENTE_CONSTANTESMUSICA_H
