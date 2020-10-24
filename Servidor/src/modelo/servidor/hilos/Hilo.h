#ifndef SERVIDOR_HILO_H
#define SERVIDOR_HILO_H

#include <thread>

/**
 * Clase abstracta que representa a un hilo de ejecucion
 **/

class Hilo {

protected:

    /// Atributo que representa al hilo (thread)
    std::thread hilo;

public:
    virtual ~Hilo() = default;

    /// Ejecuta en forma concurrente una funcion/metodo
    virtual void ejecutar() = 0;

    /// Si el hilo esta siendo ejecutado, detiene la ejecucion de forma ordenada
    virtual void matar() = 0;

    ///Devuelve true si el hilo esta siendo ejecutado
    virtual bool estaActivo() = 0;
};

#endif //SERVIDOR_HILO_H
