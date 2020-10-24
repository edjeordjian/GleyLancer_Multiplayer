project(Servidor)

set(CMAKE_CXX_STANDARD 11)

set(GCC_COVERAGE_COMPILE_FLAGS "-Wall -Wextra -Wpedantic -Wconversion -Wfloat-equal -Wmissing-include-dirs -Wredundant-decls -Wunused -Werror")
set(CMAKE_C_FLAGS "-std=c++11")
set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} ${GCC_COVERAGE_COMPILE_FLAGS}")

add_executable(Servidor
        main.cpp
        src/tools/constantes/ConstantesJson.h
        src/tools/constantes/ConstantesJson.cpp
        src/tools/constantes/ConstantesComunicacion.h
        src/tools/constantes/ConstantesMensajes.h
        src/tools/constantes/ConstantesTeclas.h
        src/tools/constantes/ConstantesGenerales.h
        src/tools/constantes/ConstantesLog.h
        src/tools/constantes/ConstantesModelo.h
        src/tools/constantes/ConstantesVentana.h
        src/tools/constantes/ConstantesEnemigos.h
        src/tools/constantes/ConstantesPersonaje.h
        src/tools/CargadorDeConfiguracion.cpp
        src/tools/CargadorDeConfiguracion.h
        src/tools/Log.cpp
        src/tools/Log.h
        src/tools/Utils.cpp
        src/tools/Utils.h
        src/tools/SDL_Utils.cpp
        src/tools/SDL_Utils.h
        src/tools/Timestamp.cpp
        src/tools/Timestamp.h
        src/controlador/ControladorServidor.cpp
        src/controlador/ControladorServidor.h
        src/controlador/ControladorJuego.cpp
        src/controlador/ControladorJuego.h
        src/modelo/servidor/hilos/Hilo.h
        src/modelo/servidor/hilos/ColaProtegida.h
        src/modelo/servidor/hilos/HiloRecibir.cpp
        src/modelo/servidor/hilos/HiloRecibir.h
        src/modelo/servidor/hilos/HiloAceptador.cpp
        src/modelo/servidor/hilos/HiloAceptador.h
        src/modelo/servidor/hilos/HiloEnviar.cpp
        src/modelo/servidor/hilos/HiloEnviar.h
        src/modelo/servidor/Servidor.cpp
        src/modelo/servidor/Servidor.h
        src/modelo/juego/Juego.cpp
        src/modelo/juego/Juego.h
        src/modelo/juego/Nivel.h
        src/modelo/juego/Nivel.cpp
        src/modelo/juego/Personaje.h
        src/modelo/juego/Personaje.cpp
        src/modelo/juego/Posicion.h
        src/modelo/juego/Posicion.cpp
        src/modelo/juego/Ventana.h
        src/modelo/juego/Ventana.cpp
        src/modelo/juego/estado_personaje/IEstadoPersonaje.h
        src/modelo/juego/estado_personaje/PersonajeMoviendose.cpp
        src/modelo/juego/estado_personaje/PersonajeMoviendose.h
        src/modelo/juego/estado_personaje/PersonajeQuieto.cpp
        src/modelo/juego/estado_personaje/PersonajeQuieto.h
        src/modelo/juego/Enemigo.cpp
        src/modelo/juego/Enemigo.h
        src/modelo/juego/estado_enemigo/IEstadoEnemigo.h
        src/modelo/juego/estado_enemigo/EnemigoQuieto.h
        src/modelo/juego/estado_enemigo/EnemigoQuieto.cpp
        src/modelo/juego/Colisionador.cpp
        src/modelo/juego/Colisionador.h
        src/modelo/servidor/Cliente.cpp
        src/modelo/servidor/Cliente.h
        src/modelo/juego/Armamento.cpp
        src/modelo/juego/Armamento.h
        src/modelo/juego/IChocable.h
        src/modelo/juego/Proyectil.cpp
        src/modelo/juego/Proyectil.h
        src/modelo/juego/Item.cpp
        src/modelo/juego/Item.h
        src/modelo/juego/Caja.cpp
        src/modelo/juego/Caja.h
        src/modelo/juego/JefeBase.cpp
        src/modelo/juego/JefeBase.h
        src/modelo/juego/Jefe1.cpp
        src/modelo/juego/Jefe1.h
        src/modelo/juego/Jefe2.cpp
        src/modelo/juego/Jefe2.h
        src/modelo/juego/Jefe3.cpp
        src/modelo/juego/Jefe3.h
        src/modelo/juego/estado_enemigo/Jefe1Moviendose.cpp
        src/modelo/juego/estado_enemigo/Jefe1Moviendose.h
        src/modelo/juego/estado_enemigo/Jefe2Moviendose.cpp
        src/modelo/juego/estado_enemigo/Jefe2Moviendose.h
        src/modelo/juego/estado_enemigo/Jefe3Moviendose.cpp
        src/modelo/juego/estado_enemigo/Jefe3Moviendose.h
        src/modelo/juego/ArmamentoJefe1.cpp
        src/modelo/juego/ArmamentoJefe1.h
        src/modelo/juego/ArmamentoJefe2.cpp
        src/modelo/juego/ArmamentoJefe2.h
        src/modelo/juego/ArmamentoJefe3.cpp
        src/modelo/juego/ArmamentoJefe3.h
        src/modelo/juego/ArmamentoEnemigo.cpp
        src/modelo/juego/ArmamentoEnemigo.h
        src/modelo/juego/estado_enemigo/EnemigoTipo1Moviendose.cpp
        src/modelo/juego/estado_enemigo/EnemigoTipo1Moviendose.h
        src/modelo/juego/estado_enemigo/EnemigoTipo2Moviendose.cpp
        src/modelo/juego/estado_enemigo/EnemigoTipo2Moviendose.h
        src/modelo/juego/ItemVida.cpp src/modelo/juego/ItemVida.h
        src/modelo/juego/ItemPuntos.cpp src/modelo/juego/ItemPuntos.h
        src/modelo/juego/ItemEnergia.cpp src/modelo/juego/ItemEnergia.h
        src/modelo/juego/ItemEscudo.cpp src/modelo/juego/ItemEscudo.h
        src/tools/SerializadorEstado.cpp src/tools/SerializadorEstado.h)

target_link_libraries(Servidor SDL2 SDL2_image SDL2_ttf SDL2_mixer jsoncpp pthread)