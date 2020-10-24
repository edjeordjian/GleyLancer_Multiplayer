#include "MenuLogControlador.h"

MenuLogControlador::MenuLogControlador(SDL_Renderer* renderizador) {
    this->menu_log = new MenuLog();
    this->menu_vista = new MenuLogVista(renderizador);
}

int MenuLogControlador::actualizar(JuegoSonido *cSonido) {
    if(this->menu_log->estaActivo()) {
        int continuar = this->menu_log->actualizar(cSonido);
        this->menu_vista->actualizar(continuar);
        return continuar;
    }

    return 0;
}

bool MenuLogControlador::estaActivo(){
    return this->menu_log->estaActivo();
}

bool MenuLogControlador::estaIniciado(){
    return this->menu_log->estaIniciado();
}

bool MenuLogControlador::estaCancelado(SDL_Event *pEvent) {
    return this->menu_log->estaCancelado(pEvent);
}

void MenuLogControlador::reestablecer() {
    this->menu_log->reestablecer();
}

MenuLogControlador::~MenuLogControlador() {
    delete(this->menu_log);
    delete(this->menu_vista);
}