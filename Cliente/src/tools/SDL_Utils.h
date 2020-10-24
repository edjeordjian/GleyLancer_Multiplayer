#ifndef CLIENTE_SDL_UTILS_H
#define CLIENTE_SDL_UTILS_H

#include <SDL2/SDL.h>
#include <SDL2/SDL_image.h>
#include <vector>
#include <string>
#include "ConstantesVentana.h"
#include "ConstantesLog.h"
#include "Log.h"

extern SDL_Texture* crearTextura(char* ruta, SDL_Renderer* renderizador);
extern void cargarIcono(char* ruta, SDL_Window* ventana);
extern void initRect(SDL_Rect *rect, int x, int y, int w, int h);

#endif //CLIENTE_SDL_UTILS_H
