#ifndef CLIENTE_JUEGOVISTA_H
#define CLIENTE_JUEGOVISTA_H

#include <SDL2/SDL.h>
#include "PersonajeVista.h"
#include "Enemigo1Vista.h"
#include "Enemigo2Vista.h"
#include "Jefe1Vista.h"
#include "Jefe2Vista.h"
#include "Jefe3Vista.h"
#include "CargadorTexturasCajas.h"
#include "CargadorTexturasItems.h"
#include "CargadorTexturasEfectos.h"
#include "NivelVista.h"
#include "ProyectilVista.h"
#include "EfectoExplosionVista.h"
#include "PuntajeVista.h"
#include "CajaVista.h"
#include "ItemVista.h"
#include "JuegoSonido.h"
#include <SDL2/SDL_ttf.h>
#include "../tools/ParserEstadoJuego.h"
#include "../tools/ConstantesMensajes.h"
#include "../hilos/ColaProtegida.h"

class JuegoVista{
    
    private:
        SDL_Window* ventana; /* Para agregar elementos visuales. */
        //SDL_Texture* textura_juego; /* Para poner el fondo de pantalla. */
        SDL_Renderer* renderizador; /* Permite visibilizar estructuras. */
        std::vector<PersonajeVista*> personajes_vista;
        std::map<std::string, std::vector<EnemigoVista*>*> enemigos_vista_map;
        std::map<int, std::vector<ProyectilVista*>*> proyectiles_vista_map;
        NivelVista* nivel;
        CargadorTexturasEnemigos* cargador_enemigos;
        CargadorTexturasPersonajes* cargador_personajes;
        CargadorTexturasProyectiles* cargador_proyectiles;
        CargadorTexturasCajas* cargador_cajas;
        CargadorTexturasItems* cargador_items;
        CargadorTexturasEfectos* cargador_efectos;
        PuntajeVista* puntaje_vista;
        std::vector<EfectoExplosionVista*> efectos;
        std::vector<CajaVista*> cajas;
        std::map<int, std::vector<ItemVista*>*> items_vista_map;

        uint32_t fps;
        uint32_t t_anterior_frame;

        JuegoSonido* controlador_sonido;
        int n_personaje;

        std::thread dj;
        ColaProtegida<uint16_t>* cola_dj;

    public:
        explicit JuegoVista();
        virtual ~JuegoVista();

        SDL_Renderer* getRenderizador();
        void iniciar();
        void setNumeroPersonaje(int nro_personaje);

        void crearVistaPersonajes(int cantidad);
        void eliminarVistaPersonajes(int cantidad);
        void decodificarEstadoPersonajes(std::string estado);

        void crearVistaEnemigos(std::string tipo, int cantidad);
        void actualizarVistaEnemigos(std::string tipo, int cantidad, std::stringstream* stream_estado);
        void eliminarVistaEnemigos(std::string tipo, int cantidad);
        void decodificarEstadoEnemigos(std::string estado);

        void actualizarTablaPuntajes(std::string estado);
        void decodificarEstadoEfectos(std::string estado);

        void crearVistaProyectiles(int nro_jugador, int cantidad);
        void actualizarVistaProyectiles(int nro_jugador, int cantidad, std::stringstream* stream_estado);
        void eliminarVistaProyectiles(int nro_jugador, int cantidad);
        void decodificarEstadoProyectiles(std::string estado);

        void crearVistaCajas(int cantidad);
        void actualizarVistaCajas(int cantidad, std::stringstream* stream_estado);
        void eliminarVistaCajas(int cantidad);
        void decodificarEstadoCajas(std::string estado);

        void crearVistaItems(int tipo, int cantidad);
        void actualizarVistaItems(int tipo, int cantidad, std::stringstream* stream_estado);
        void eliminarVistaItems(int tipo, int cantidad);
        void decodificarEstadoItems(std::string estado);

        void actualizar(std::string estado);
        void avanzarNivel();
        void dibujar();
        void destruir();

        void mostrarGameOver();

        void setControladorSonido(JuegoSonido* juego_sonido);

        void setNivel(int nro_nivel);
        void reiniciar();

        void reiniciarMusica();
        void actualizarSonidos();

        void avanzarCartelNivel();
        void pararMusicaNivel();
};

#endif //CLIENTE_JUEGOVISTA_H