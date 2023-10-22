#ifndef DESTINO_H
#define DESTINO_H

#include "cola.hpp"
#include "evento.hpp"
#include <iostream>
#include <string>


class Destino{
private:
    Cola<Evento> eventos{};
    size_t cantidad_guardados;
    size_t cantidad_aperturas;
    const std::string DESORIENTADO = "Desorientado";
    const std::string PRECAVIDO = "Precavido";
    const std::string ASUSTADO = "Asustado";
    const std::string NO_DETERMINADO = "No determinado";
public:

    Destino();

    //pre: Debe recibir un nombre de evento entre los eventos basicos (Guardado y apertura mapa).
    //post: Acola el evento a la cola de eventos.
    void acolar(const std::string& nombre_evento);

    //pre: Toma la cola de eventos.
    //post: Desacola el ultimo evento y lo guarda.
    std::string desacolar();

    //pre: Recibe un tipo de jugador;
    //post: determina el destino del jugador;
    std::string determinar_destino(const std::string& tipo_jugador);

};

#endif