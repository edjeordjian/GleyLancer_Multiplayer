#include "SDL_Utils.h"

void initRect(SDL_Rect *rect, int x, int y, int w, int h) {
    rect->x = x;
    rect->y = y;
    rect->w = w;
    rect->h = h;
}

bool doblesIguales(double a, double b) {
    return fabs(a - b) < EPSILON_DOUBLE;
}
