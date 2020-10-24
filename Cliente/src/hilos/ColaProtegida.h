
#ifndef CLIENTE_COLAPROTEGIDA_H
#define CLIENTE_COLAPROTEGIDA_H

#include <vector>
#include <mutex>
#include <condition_variable>

//Puede ser usada de forma segura por hilos concurrentes
template<class T>
class ColaProtegida {
private:
    std::vector<T> cola;
    std::mutex mutex;
    std::condition_variable cv;

public:
    ColaProtegida();

    //Recibe un objeto invalido que será devuelto por la funcion en caso de que la cola se encuentre vacia
    T desencolar(T valor_invalido);

    T desencolarBloqueante();

    void encolar(T element);

    ~ColaProtegida();
};

template<class T>
ColaProtegida<T>::ColaProtegida(): cola(), mutex() {
    //Inicializo los atributos en el stack con una initialization list, no reciben nada porque los constructores
    //de cada atributo no reciben nada.
}

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


template<class T>
T ColaProtegida<T>::desencolarBloqueante(){
    std::unique_lock<std::mutex> lock(this->mutex);
    if (this->cola.empty()){
        cv.wait(lock);
    }
    T elem = this->cola[0];
    this->cola.erase(this->cola.begin());
    return elem;
}

template<class T>
void ColaProtegida<T>::encolar(T elemento) {
    //Bloqueo con mutex el uso de la cola para insertar el elemento correctamente
    std::unique_lock<std::mutex> lock(this->mutex);
    this->cola.push_back(elemento);
    cv.notify_all();
}

template<class T>
ColaProtegida<T>::~ColaProtegida() {
    //no hace nada
}


#endif //CLIENTE_COLAPROTEGIDA_H
