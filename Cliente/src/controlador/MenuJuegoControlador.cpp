#include "MenuJuegoControlador.h"


MenuJuegoControlador::MenuJuegoControlador(SDL_Renderer* renderizador) {
    this->menu_vista = new MenuJuegoVista(renderizador);
    this->menu = new MenuJuego();
}

MenuJuegoControlador::~MenuJuegoControlador() {
    delete(this->menu_vista);
    delete(this->menu);
}

void MenuJuegoControlador::iniciar() {
    this->menu->inicializar();
}

bool MenuJuegoControlador::actualizar(JuegoSonido* cSonido) {
    if(this->menu->estaActivo()) {
        int continuar = this->menu->actualizar(cSonido);
        this->menu_vista->actualizar(continuar);
        return continuar > 0;
    }

    return false;
}

bool MenuJuegoControlador::estaIniciado() {
    return this->menu->estaIniciado();
}

bool MenuJuegoControlador::estaCancelado(SDL_Event *evento) {
    return this->menu->estaCancelado(evento);
}

void MenuJuegoControlador::reestablecer() {
    this->menu->reestablecer();
}
