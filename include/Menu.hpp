#ifndef MENU_H
#define MENU_H

#include "Destino.hpp"
#include <iostream>
#include <string>

const size_t OPCION_SALIR = 0;
const size_t OPCION_DESTINO = 1;
const size_t OPCION_AGREGAR_EVENTO = 1;
const size_t OPCION_DETERMINAR_DESTINO = 2;

class Menu{
private:
    std::string evento;
    std::string tipo_jugador;
    std::string evento_final;
    Destino destino;
public:
    void imprimir_menu_destino();

    void logica_menu_destino(size_t opcion);
};

#endif