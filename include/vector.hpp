#ifndef VECTOR_H
#define VECTOR_H

#include <cstddef>
#include <exception>

class VectorException : public std::exception {
    // Excepcion especifica y exclusivamente para errores dentro del Vector.
    // Usar de la forma "throw VectorException();" cuando una precondicion no se cumpla.

    // Ejemplo:
    //     if (condicion_de_error()){
    //         throw VectorException();
    //     }
};

template<typename Dato>
class Vector {
private:
    Dato* datos;
    size_t cantidadDatos;
    size_t tamanioMaximo;

    // Pre: cantidadDatos no puede ser mayor a tamanioMaximo. NOTA: Esto se maneja internamente.
    // Post: Copia los datos del vector a uno nuevo con tamaño modificado y reasigna.
    void copiarDatos();

    // Pre: -
    // Post: Duplica el tamaño del vector. Si el array no esta inicializado, lo reserva.
    void aumentarTamanioVector();

    // Pre: -
    // Post: Reduce el tamaño del vector a la mitad. Si no hay ningun dato, libera la memoria.
    void reducirTamanioVector();

public:
    // Constructor.
    Vector();

    // Pre: -
    // Post: Agrega el dato al final del vector.
    void alta(Dato dato);

    // Pre: El indice debe ser menor o igual que la cantidad de datos.
    // Post: Agrega el dato antes del dato en la posicion indicada, moviendo todos los elementos siguientes. Si el
    // indice es igual a la cantidad de datos, simplemente agrega al final.
    void alta(Dato dato, size_t indice);

    // Pre: El vector no puede estar vacio.
    // Post: Elimina el ultimo dato.
    Dato baja();

    // Pre: El vector no puede estar vacio. El indice debe ser menor que la cantidad de datos.
    // Post: Elimina el dato en la posicion indicada, moviendo todos los elementos siguientes. Si el indice es igual a
    // la cantidad de datos - 1, simplemente elimina el ultimo dato.
    Dato baja(size_t indice);

    // Pre: -
    // Post: Devuelve true si el vector esta vacio (es decir, si no hay datos).
    bool vacio();

    // Pre: -
    // Post: Devuelve la cantidad de datos del vector.
    size_t tamanio();

    // Pre: El vector no puede estar vacio. El indice debe ser menor que la cantidad de datos.
    // Post: Devuelve una referencia al dato deseado.
    Dato& operator[](size_t indice);

    // Destructor.
    ~Vector();
};

template<typename Dato>
Vector<Dato>::Vector() {
    datos = nullptr;
    tamanioMaximo = 0;
    cantidadDatos = 0;
}

template<typename Dato>
void Vector<Dato>::copiarDatos() {
    Dato* nuevoVector = new Dato[tamanioMaximo];
    for (size_t i = 0; i < cantidadDatos; i++) {
        nuevoVector[i] = datos[i];
    }
    delete[] datos;
    datos = nuevoVector;
}

template<typename Dato>
void Vector<Dato>::aumentarTamanioVector() {
    if (vacio()) {
        datos = new Dato[1];
        tamanioMaximo = 1;
    } else {
        tamanioMaximo *= 2;
        copiarDatos();
    }
}

template<typename Dato>
void Vector<Dato>::reducirTamanioVector() {
    if (vacio()) {
        delete[] datos;
        datos = nullptr;
        tamanioMaximo = 0;
    } else {
        tamanioMaximo /= 2;
        copiarDatos();
    }
}

template<typename Dato>
void Vector<Dato>::alta(Dato dato) {
    if (cantidadDatos == tamanioMaximo) {
        aumentarTamanioVector();
    }
    datos[cantidadDatos] = dato;
    cantidadDatos++;
}

template<typename Dato>
void Vector<Dato>::alta(Dato dato, size_t indice) {
    if (indice > cantidadDatos) {
        throw VectorException();
    } else {
        if (cantidadDatos == tamanioMaximo) {
            aumentarTamanioVector();
        }
        for (size_t i = cantidadDatos; i > indice; i--) {
            datos[i] = datos[i - 1];
        }
        datos[indice] = dato;
        cantidadDatos++;
    }
}

template<typename Dato>
Dato Vector<Dato>::baja() {
    if (vacio()) {
        throw VectorException();
    } else {
        Dato dato = datos[cantidadDatos - 1];
        cantidadDatos--;
        if (cantidadDatos == tamanioMaximo / 2) {
            reducirTamanioVector();
        }
        return dato;
    }
}

template<typename Dato>
Dato Vector<Dato>::baja(size_t indice) {
    if (vacio() || indice >= cantidadDatos) {
        throw VectorException();
    } else {
        Dato dato = datos[indice];
        cantidadDatos--;
        for (size_t i = indice; i < cantidadDatos; i++) {
            datos[i] = datos[i + 1];
        }
        if (cantidadDatos == tamanioMaximo / 2) {
            reducirTamanioVector();
        }
        return dato;
    }
}

template<typename Dato>
bool Vector<Dato>::vacio() {
    return cantidadDatos == 0;
}

template<typename Dato>
size_t Vector<Dato>::tamanio() {
    return cantidadDatos;
}

template<typename Dato>
Dato& Vector<Dato>::operator[](size_t indice) {
    if (vacio() || indice >= cantidadDatos) {
        throw VectorException();
    } else {
        return datos[indice];
    }
}

template<typename Dato>
Vector<Dato>::~Vector() {
    delete[] datos;
}

#endif