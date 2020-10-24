#ifndef CLIENTE_PUNTAJEVISTA_H
#define CLIENTE_PUNTAJEVISTA_H

#include <vector>
#include <map>
#include <string>
#include "TextoSDL.h"
#include "../tools/Utils.h"
#include "UIPersonajeVista.h"
#include "CargadorTexturasUIPersonaje.h"
#include "../tools/ConstantesFuente.h"
#include "../tools/ConstantesMenu.h"
#include "../tools/ConstantesPersonaje.h"
#include <algorithm>

class PuntajeVista {
private:

    SDL_Renderer* renderizador;
    // ( nombre ,[("puntaje", puntaje),("vida", vidas ),("energia",energia)])
    std::map<std::string,std::map<std::string,std::string>> tabla_puntaje_vida;
    std::vector<TextoSDL*> puntajes_vista;
    std::vector<TextoSDL*> mejor_puntaje;
    std::vector<TextoSDL*> tabla_puntajes;
    TTF_Font* fuente_puntajes;
    std::vector<SDL_Texture*> carteles;
    size_t opcion_cartel;
    CargadorTexturasUIPersonaje* cargador_ui;
    std::vector<UIPersonajeVista*> ui_personajes;


public:
    PuntajeVista(SDL_Renderer* renderizador_vista);
    void actualizarPuntajes(std::string estado);
    void crearPuntajes(int cantidad);
    void mostrarPuntaje();
    void mostrarTablaPuntaje();
    void avanzarCartelNivel();
    void reiniciar();
    void mostrarGameOver();
    void setTextoTablaPuntajes(unsigned int i,  const char* texto);
    ~PuntajeVista();
};


#endif //CLIENTE_PUNTAJEVISTA_H
