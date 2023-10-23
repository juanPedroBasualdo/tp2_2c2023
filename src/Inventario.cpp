#include "Inventario.hpp"

using namespace std;

void Inventario::cargar(std::string archivo_carga) {

}

void Inventario::recoger_objeto(std::string nombre_item_objetivo, const std::string& tipo_item_objetivo) {
    if(tipo_item_objetivo == TIPO_MUNICION || tipo_item_objetivo == TIPO_PUZZLE || tipo_item_objetivo == TIPO_CURATIVO){
        Item item_actual(nombre_item_objetivo,tipo_item_objetivo);
        inventario.alta(item_actual);
    } else{
        cout << "Escriba un tipo de item correcto (CURATIVO, PUZZLE, MUNICION)." << endl;
    }
}

void Inventario::soltar_objeto(const std::string& nombre_item_objetivo) {
    bool item_encontrado = false;
    Item item_actual;
    while(!item_encontrado){
        int i = 0;
        item_actual = inventario.elemento(static_cast<size_t>(i));
        if(item_actual == nombre_item_objetivo){
            Item baja = inventario.baja(static_cast<size_t>(i));
            cout << "El item" << nombre_item_objetivo << "se ha soltado/usado." << endl;
            item_encontrado = true;
        }
        if(i == (inventario.tamanio() - 1)){
            item_encontrado = true;
            cout << "El item" << nombre_item_objetivo << "no se encuentra dentro del inventario." << endl;
        }
    }

}

void Inventario::consultar_inventario() {
    for(size_t i = 0 ; i < inventario.tamanio() ; i++){
        Item item_actual = inventario.elemento(i);
        item_actual.listar_informacion();
    }
}

void Inventario::guardar(const std::string& archivo_guardado) {
    /*ostream archivo_csv;
    Item item_actual;
    for(size_t i = 0 ; i < (inventario.tamanio() -1) ; i++){
        item_actual = inventario.elemento(i);
        archivo_csv << item_actual;
    }
    */
}





