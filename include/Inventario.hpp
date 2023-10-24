#ifndef INVENTARIO_H
#define INVENTARIO_H

#include "lista_de.hpp"
#include "Item.hpp"
#include <string>
#include <iostream>
#include <fstream>

class Inventario{
private:
    Lista_de<Item> inventario{};
public:
    Inventario() = default;

    void cargar(std::string archivo_carga);

    void recoger_objeto(std::string nombre_item_objetivo, const std::string& tipo_item_objetivo);

    void soltar_objeto(const std::string& nombre_item_objetivo);

    void consultar_inventario();

    void guardar(const std::string& archivo_guardado);

};


#endif