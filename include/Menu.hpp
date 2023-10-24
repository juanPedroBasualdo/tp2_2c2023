#ifndef MENU_H
#define MENU_H

#include "Destino.hpp"
#include "Inventario.hpp"
#include <iostream>
#include <string>

const size_t OPCION_SALIR = 0;
const size_t OPCION_DESTINO = 2;
const size_t OPCION_AGREGAR_EVENTO = 1;
const size_t OPCION_DETERMINAR_DESTINO = 2;
const size_t OPCION_INVENTARIO = 1;
const size_t OPCION_RECOGER = 1;
const size_t OPCION_SOLTAR = 2;
const size_t OPCION_CONSULTA = 3;
const size_t OPCION_GUARDAR = 4;

class Menu{
private:
    std::string evento;
    std::string tipo_jugador;
    std::string evento_final;
    Destino destino;
    Inventario inventario;
    std::string nombre_item;
    std::string tipo_item;
public:
    void imprimir_menu_destino();

    void logica_menu_destino(size_t opcion);

    void imprimir_menu_inventario();

    void logica_menu_inventario(size_t opcion);

    void imprimir_menu();

};

#endif