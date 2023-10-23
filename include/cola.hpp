#ifndef COLA_HPP
#define COLA_HPP

#include <exception>
#include "Nodo.hpp"

class Cola_exception : public std::exception {
    // Excepcion especifica y exclusivamente para errores dentro de la cola.
    // Usar de la forma "throw Cola_exception();" cuando una precondicion no se cumpla.

    // Ejemplo:
    //     if (condicion_de_error()){
    //         throw cola_exception();
    //     }
};

template<typename T>
class Cola {
private:
    Nodo<T>* primer_nodo;
    Nodo<T>* ultimo_nodo;
    size_t cantidad_datos;
public:
    // Constructor.
    Cola();

    // Pre: -
    // Post: Agrega el dato al final de la cola.
    void alta(T dato);

    // Pre: La cola no puede estar vacía.
    // Post: Elimina el primer dato.
    T baja();

    // Pre: La cola no puede estar vacía.
    // Post: Devuelve el primer dato en la cola.
    T primero();

    // Pre: La cola no puede estar vacía.
    // Post: Devuelve el último dato en la cola.
    T ultimo();

    // Pre: -
    // Post: Devuelve la cantidad de datos de la cola.
    size_t tamanio();

    // Pre: -
    // Post: Devuelve true si la cola esta vacía (es decir, si no hay datos).
    bool vacio();

    // El constructor de copia está deshabilitado.
    Cola(const Cola& l) = delete;

    // El operador = (asignación) está deshabilitado.
    void operator=(const Cola& l) = delete;

    // Destructor.
    ~Cola();
};

template<typename T>
Cola<T>::Cola() {
    primer_nodo = nullptr;
    ultimo_nodo = nullptr;
    cantidad_datos = 0;
}

template<typename T>
void Cola<T>::alta(T dato) {
    Nodo<T>* nodo_nuevo = new Nodo<T>(dato);
    if(cantidad_datos == 0){
        primer_nodo = nodo_nuevo;
        ultimo_nodo = nodo_nuevo;
    } else{
        ultimo_nodo->cambiar_siguiente(nodo_nuevo);
        ultimo_nodo = nodo_nuevo;
    }
    cantidad_datos++;
}

template<typename T>
T Cola<T>::baja() {
    if(cantidad_datos == 0){
        throw Cola_exception();
    } else{
        Nodo<T>* baja = primer_nodo;
        T dato_baja = baja->obtener_dato();
        Nodo<T>* siguiente = baja->obtener_siguiente();
        primer_nodo = siguiente;
        cantidad_datos--;
        return dato_baja;
    }
}

template<typename T>
T Cola<T>::primero() {
    if(cantidad_datos == 0){
        throw Cola_exception();
    } else {
        T dato_objetivo = primer_nodo->obtener_dato();
        return dato_objetivo;
    }
}

template<typename T>
T Cola<T>::ultimo() {
    if(cantidad_datos == 0){
        throw Cola_exception();
    } else {
        T dato_objetivo = ultimo_nodo->obtener_dato();
        return dato_objetivo;
    }
}

template<typename T>
size_t Cola<T>::tamanio() {
    return cantidad_datos;
}

template<typename T>
bool Cola<T>::vacio() {
    if(cantidad_datos == 0){
        return true;
    } else{
        return false;
    };
}

template<typename T>
Cola<T>::~Cola() {
    primer_nodo = nullptr;
    ultimo_nodo = nullptr;
}

#endif