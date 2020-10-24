#ifndef CLIENTE_CONSTANTESVENTANA_H
#define CLIENTE_CONSTANTESVENTANA_H

#include <string>
#include <SDL2/SDL.h>

/// VENTANA ///
static constexpr char *RUTA_ICONO = (char *) ("../data/imgs/icono.png");
static constexpr char *RUTA_IMG_DEFECTO = (char *) ("../data/imgs/default.png");
static constexpr char *RUTA_FONDO_1_FIN = (char *) ("../data/imgs/fondos/fondo_fin_1.png");
static constexpr char *RUTA_FONDO_2_FIN = (char *) ("../data/imgs/fondos/fondo_fin_2.png");
static constexpr char *RUTA_FONDO_3_FIN = (char *) ("../data/imgs/fondos/fondo_fin_3.png");
static constexpr char *RUTA_FONDO_GAME_OVER = (char *) ("../data/imgs/game_over.png");

static const int CANT_TITULOS_TABLA_PUNTAJES = 5;

static constexpr char *NOMBRE_JUEGO = (char *) "Gley Lancer";
static constexpr int X_VENTANA = 500;
static constexpr int Y_VENTANA = 200;
static constexpr int ANCHO_VENTANA = 800;
static constexpr int ALTO_VENTANA = 600;
static constexpr int ANCHO_FONDO = 4000;
static constexpr int ANCHO_CAPA = 3200;
static constexpr int STATE_VENTANA = SDL_WINDOW_SHOWN | SDL_WINDOW_RESIZABLE;
static constexpr int CANTIDAD_NIVELES = 3;

static const float VELOCIDAD_CAPA_5 = 2*1.0f;
static const float VELOCIDAD_CAPA_4 = 2*1.5f;
static const float VELOCIDAD_CAPA_3 = 2*2.5f;
static const float VELOCIDAD_CAPA_2 = 2*3.75f;
static const float VELOCIDAD_CAPA_1 = 2*7.0f;
static const std::string PRE_POSICION_VENTANA = "Pos_Ventana";

static constexpr uint32_t MILISEG_MIN_FPS = 8;

static std::string TEXTO_VIDA = "x";
static std::string TEXTO_SCORE = "SC ";


void setRutaFondo11(std::string ruta);
char *getRutaFondo11();
void setRutaFondo12(std::string ruta);
char *getRutaFondo12();
void setRutaFondo13(std::string ruta);
char *getRutaFondo13();
void setRutaFondo14(std::string ruta);
char *getRutaFondo14();
void setRutaFondo15(std::string ruta);
char *getRutaFondo15();
void setRutaFondo16(std::string ruta);
char *getRutaFondo16();
void setRutaFondo21(std::string ruta);
char *getRutaFondo21();
void setRutaFondo22(std::string ruta);
char *getRutaFondo22();
void setRutaFondo23(std::string ruta);
char *getRutaFondo23();
void setRutaFondo24(std::string ruta);
char *getRutaFondo24();
void setRutaFondo25(std::string ruta);
char *getRutaFondo25();
void setRutaFondo26(std::string ruta);
char *getRutaFondo26();
void setRutaFondo31(std::string ruta);
char *getRutaFondo31();
void setRutaFondo32(std::string ruta);
char *getRutaFondo32();
void setRutaFondo33(std::string ruta);
char *getRutaFondo33();
void setRutaFondo34(std::string ruta);
char *getRutaFondo34();
void setRutaFondo35(std::string ruta);
char *getRutaFondo35();
void setRutaFondo36(std::string ruta);
char *getRutaFondo36();


#endif //CLIENTE_CONSTANTESVENTANA_H
