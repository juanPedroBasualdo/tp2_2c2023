#ifndef LISTA_DE_HPP
#define LISTA_DE_HPP

#include <exception>
#include <cstdlib>
#include "Nodo_de.hpp"

class Lista_exception : public std::exception {
    // Excepcion especifica y exclusivamente para errores dentro de la lista.
    // Usar de la forma "throw lista_exception();" cuando una precondicion no se cumpla.

    // Ejemplo:
    //     if (condicion_de_error()){
    //         throw Lista_exception();
    //     }
};

template<typename T>
class Lista_de {
private:
    Nodo_de<T>* primer_nodo;
    Nodo_de<T>* ultimo_nodo;
    Nodo_de<T>* cursor;
    // Nota: pueden no utilizar el índice. Estado inicial / no válido = -1.
    // La lista es 0-indexed.
    int indice_cursor;
    size_t cantidad_datos;

    // Pre: El índice debe ser menor que la cantidad de datos.
    // Post: Devuelve un puntero al nodo asociado al índice deseado.
    Nodo_de<T>* obtener_nodo(size_t indice);
/*
    // Pre: El indice debe ser menor a la cantidad de datos
    // Post: Apunta el cursor en el nodo cuya posicion se encuentre en el indice deseado
    Nodo_de<T> apuntar(size_t indice);
*/

public:
    // Constructor.
    Lista_de();

    // Pre: -
    // Post: Agrega el dato al final de la lista.
    void alta(T dato);

    // Pre: La lista no puede estar vacía.
    // Post: Elimina el último dato.
    // NOTA: Considerar que se puede dar de baja el nodo cursor.
    T baja();

    // Pre: El índice debe ser menor o igual que la cantidad de datos.
    // Post: Agrega el dato antes del dato en la posición indicada.
    // Si el índice es igual a la cantidad de datos, simplemente agrega al final.
    void alta(T dato, size_t indice);

    // Pre: El índice debe ser menor que la cantidad de datos.
    // Post: Elimina el dato en la posición indicada.
    // Si el índice es igual a la cantidad de datos - 1, simplemente elimina el último dato.
    // NOTA: Considerar que se puede dar de baja el nodo cursor.
    T baja(size_t indice);

    // Pre: La lista no puede estar vacía.
    // Post: Devuelve el primer dato en la lista.
    T primero();

    // Pre: La lista no puede estar vacía.
    // Post: Devuelve el último dato en la lista.
    T ultimo();

    // Pre: El índice debe ser menor que la cantidad de datos.
    // Post: Devuelve el dato en la posición deseada.
    T elemento(size_t indice);

    // Pre: -
    // Post: Devuelve true si se puede avanzar (esto es, que el cursor no sea nullptr).
    bool puede_avanzar();

    // Pre: Se debe poder avanzar.
    // Post: Devuelve el dato del cursor actual y luego lo mueve una posición en la dirección deseada.
    T avanzar(bool siguiente);

    // Pre: -
    // Post: Reinicia el cursor al principio o al final, según lo indicado.
    // Si la lista está vacía, se reinicia el cursor al estado inicial
    // (esto es, cursor = nullptr e indice_cursor = -1).
    void reiniciar_cursor(bool principio);

    // Pre: -
    // Post: Devuelve la cantidad de datos de la lista.
    size_t tamanio();

    // Pre: -
    // Post: Devuelve true si la lista esta vacía (es decir, si no hay datos).
    bool vacio();

    // El constructor de copia está deshabilitado.
    Lista_de(const Lista_de& l) = delete;

    // El operador = (asignación) está deshabilitado.
    void operator=(const Lista_de& l) = delete;

    // Destructor.
    ~Lista_de();
};

template<typename T>
Lista_de<T>::Lista_de() {
    primer_nodo = nullptr;
    ultimo_nodo = nullptr;
    cursor = nullptr;
    indice_cursor = -1;
    cantidad_datos = 0;
}


template<typename T>
Nodo_de<T>* Lista_de<T>::obtener_nodo(size_t indice){
    if(cantidad_datos < indice || cantidad_datos == 0){
        throw Lista_exception();
    }
    else if(cantidad_datos == 1 || indice == 0){
        return primer_nodo;
    } else if(cantidad_datos - 1 == indice){
        return ultimo_nodo;
    } else{
        Nodo_de<T>* nodo_aux = cursor->obtener_siguiente();
        while(indice_cursor != indice){
            if(puede_avanzar()) {
                cursor = nodo_aux;
                indice_cursor++;
                nodo_aux = cursor->obtener_siguiente();
            } else{
                reiniciar_cursor(true);
                indice_cursor = 0;
            }
        }
        return nodo_aux;
    }
}

template<typename T>
void Lista_de<T>::alta(T dato) {
    if(cantidad_datos == 0){
        Nodo_de<T>* nuevo_nodo = new Nodo_de(dato);
        primer_nodo = nuevo_nodo;
        ultimo_nodo = nuevo_nodo;
    } else{
        Nodo_de<T>* nuevo_nodo = new Nodo_de(dato);
        nuevo_nodo->cambiar_anterior(ultimo_nodo);
        ultimo_nodo->cambiar_siguiente(nuevo_nodo);
        ultimo_nodo = nuevo_nodo;
    }
    cantidad_datos++;
}

template<typename T>
void Lista_de<T>::alta(T dato, size_t indice) {
    if(cantidad_datos < indice){
        throw Lista_exception();
    } else{
        if(cantidad_datos == 0){
            Nodo_de<T>* nuevo_nodo = new Nodo_de(dato);
            primer_nodo = nuevo_nodo;
            ultimo_nodo = nuevo_nodo;
        } else if(cantidad_datos == indice){
            Nodo_de<T>* nodo_nuevo = new Nodo_de(dato);
            nodo_nuevo->cambiar_anterior(ultimo_nodo);
            ultimo_nodo->cambiar_siguiente(nodo_nuevo);
            ultimo_nodo = nodo_nuevo;
        } else {
            Nodo_de<T>* nodo_nuevo = new Nodo_de(dato);
            Nodo_de<T> *nodo_anterior = obtener_nodo((indice - 1));
            Nodo_de<T> *nodo_siguiente = obtener_nodo(indice);
            nodo_nuevo->cambiar_anterior(nodo_anterior);
            nodo_nuevo->cambiar_siguiente(nodo_siguiente);
            nodo_anterior->cambiar_siguiente(nodo_nuevo);
            nodo_siguiente->cambiar_anterior(nodo_nuevo);
        }
        cantidad_datos++;
    }
}

template<typename T>
T Lista_de<T>::baja() {
    if(cantidad_datos == 0){
        throw Lista_exception();
    } else{
        Nodo_de<T>* baja = ultimo_nodo;
        T dato_baja = baja->obtener_dato();
        Nodo_de<T>* anterior = baja->obtener_anterior();
        ultimo_nodo = anterior;
        cantidad_datos--;
        return dato_baja;
    }
}

template<typename T>
T Lista_de<T>::baja(size_t indice) {
    if(cantidad_datos == 0 || cantidad_datos < indice){
        throw Lista_exception();
    }
    else{
        Nodo_de<T>* baja = obtener_nodo(indice);
        T dato_baja = baja->obtener_dato();
        if(indice == 0){
            Nodo_de<T>* siguiente = baja->obtener_siguiente();
            siguiente = primer_nodo;
            delete baja;
            cantidad_datos--;
            return dato_baja;
        } else if(indice == cantidad_datos){
            Nodo_de<T>* anterior = baja->obtener_anterior();
            ultimo_nodo = anterior;
            delete baja;
            cantidad_datos--;
            return dato_baja;
        } else{
            Nodo_de<T>* anterior = baja->obtener_anterior();
            Nodo_de<T>* siguiente = baja->obtener_siguiente();
            siguiente->cambiar_anterior(anterior);
            anterior->cambiar_siguiente(siguiente);
            delete baja;
            cantidad_datos--;
            return dato_baja;
        }
    }
}

template<typename T>
T Lista_de<T>::primero() {
    if (cantidad_datos == 0) {
        throw Lista_exception();
    }
    else {
        T dato_objetivo = primer_nodo->obtener_dato();
        return dato_objetivo;
    }
}

template<typename T>
T Lista_de<T>::ultimo() {
    if (cantidad_datos == 0) {
        throw Lista_exception();
    }
    else{
        //T dato_objetivo = ultimo_nodo->obtener_dato();
        return ultimo_nodo->obtener_dato(); //dato_objetivo;
    }
}

template<typename T>
T Lista_de<T>::elemento(size_t indice) {
    if(indice > cantidad_datos){
        throw Lista_exception();
    } else{
        Nodo_de<T>* nodo_elemento = obtener_nodo(indice);
        T elemento = nodo_elemento->obtener_dato();
        nodo_elemento = nullptr;
        return elemento;
    }
}

template<typename T>
bool Lista_de<T>::puede_avanzar(){
    return indice_cursor != -1;
}

template<typename T>
T Lista_de<T>::avanzar(bool siguiente){
    if(siguiente) {
        if(puede_avanzar()){
            Nodo_de<T>* nodo_actual = obtener_nodo(indice_cursor);
            indice_cursor++;
            Nodo_de<T>* nodo_siguiente = obtener_nodo(indice_cursor);
            cursor = nodo_siguiente;
            return nodo_actual->obtener_dato();
        }
        else{
            throw Lista_exception();
        }
    } else{
        if(puede_avanzar()){
            Nodo_de<T>* nodo_actual = obtener_nodo(indice_cursor);
            indice_cursor--;
            Nodo_de<T>* nodo_anterior = obtener_nodo(indice_cursor);
            cursor = nodo_anterior;
            return nodo_actual->obtener_dato();
        }
        else{
            throw Lista_exception();
        }
    }
}

template<typename T>
void Lista_de<T>::reiniciar_cursor(bool principio) {
    if(principio){
        if(cantidad_datos == 0){
            indice_cursor = -1;
            cursor = 0;
        } else{
            indice_cursor = 0;
            cursor = primer_nodo;
        }
    } else {
        if (cantidad_datos == 0) {
            indice_cursor = -1;
            cursor = 0;
        } else{
            indice_cursor = (cantidad_datos - 1);
            cursor = ultimo_nodo;
        }
    }
}

template<typename T>
size_t Lista_de<T>::tamanio() {
    return cantidad_datos;
}

template<typename T>
bool Lista_de<T>::vacio() {
    return cantidad_datos == 0;
}

template<typename T>
Lista_de<T>::~Lista_de() {
    primer_nodo = nullptr;
    ultimo_nodo = nullptr;
    cursor = nullptr;
}

#endif