#include "Inventario.hpp"

using namespace std;

void Inventario::cargar(std::string archivo_carga) {
    ifstream archivo(archivo_carga);
    if(archivo.is_open()){
        string linea;
        string lineas[2] = {};
        while(getline(archivo,linea)) {
            string carga;
            for (char caracterLinea: linea) {
                if (caracterLinea == ',') {
                    lineas[0] = carga;
                    carga.clear();
                } else {
                    carga += caracterLinea;
                }
                lineas[1] = carga;
            }
            Item item_carga(lineas[0],lineas[1]);
            inventario.alta(item_carga);
        }
    } else{
      cout << "El archivo no pudo abrirse" << endl;
    }
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
    size_t i = 0;
    while(!item_encontrado && i <= inventario.tamanio()){
        if(i <= inventario.tamanio() - 1){
            Item item_actual = inventario.elemento(i);
            if(item_actual == nombre_item_objetivo){
                Item baja = inventario.baja(i);
                cout << "El item " << nombre_item_objetivo << " se ha soltado/usado." << endl;
                item_encontrado = true;
            } else {
                i += 1;
            }
        } else{
            cout << "El item " << nombre_item_objetivo << " no se encuentra dentro del inventario" << endl;
            item_encontrado = true;
        }
    }
}

void Inventario::consultar_inventario() {
    for(size_t i = 0 ; i < inventario.tamanio() ; i++){
        Item item_actual = inventario.elemento(i);
        item_actual.listar_informacion();
        cout << endl;
    }
}

void Inventario::guardar(const std::string& archivo_guardado) {
    fstream archivo(archivo_guardado);
    if(archivo.is_open()){
        cout << "Guardando partida... No apague el sistema Playstation 2 mientras se realiza el guardado" << endl;
        for (size_t i = 0; i <= (inventario.tamanio() - 1); i++) {
            Item item_actual = inventario.elemento(i);
            archivo << item_actual;
            archivo << '\n';
        }
        cout << "Partida guardada con exito!" << endl;
    }else{
        cout << "El archivo de guardado no pudo abrirse" << endl;
    }
    archivo.close();
}





