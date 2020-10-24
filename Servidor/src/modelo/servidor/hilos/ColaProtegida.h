#ifndef SERVIDOR_COLAPROTEGIDA_H
#define SERVIDOR_COLAPROTEGIDA_H

#include <vector>
#include <mutex>

/**
 * Clase que se representa un cola con metodos bloqueantes para ser usada de forma seguro por hilos concurrentes
 **/

template<class T>
class ColaProtegida {

private:

    /// Atributo que representa a la cola
    std::vector<T> cola;

    std::mutex mutex;

public:

    /// Constructor de la clase
    ColaProtegida();

    /// Destructor de la clase
    ~ColaProtegida();

    /// Desencola un elemento de la cola y lo devuelve
    /// Si la cola esta vacia devuelve el valor recibido por paramatro
    T desencolar(T valor_invalido);


    /// Encola el elemento recibido por parametro en la cola de forma thread safe
    void encolar(T element);
};

/**
 * Definicion del constructor de la clase
 * Inicializo los atributos en el stack con una initialization list
 * no reciben nada porque los constructores de cada atributo no reciben nada.
 */
template<class T>
ColaProtegida<T>::ColaProtegida(): cola(), mutex() {}

/**
 * Definicion del destructor de la clase
 **/
template<class T>
ColaProtegida<T>::~ColaProtegida() {}

/**
 * Definicion del metodo desencolar (bloqueante)
 **/
template<class T>
T ColaProtegida<T>::desencolar(T valor_invalido){
    std::unique_lock<std::mutex> lock(this->mutex);
    if (this->cola.empty()){
        return valor_invalido;
    }
    T elem = this->cola[0];
    this->cola.erase(this->cola.begin());
    return elem;
}

/**
 * Definicion del metodo encolar (bloqueante)
 **/
template<class T>
void ColaProtegida<T>::encolar(T elemento) {
    //Bloqueo con mutex el uso de la cola para insertar el elemento correctamente
    std::unique_lock<std::mutex> lock(this->mutex);
    this->cola.push_back(elemento);
}

#endif //SERVIDOR_COLAPROTEGIDA_H
