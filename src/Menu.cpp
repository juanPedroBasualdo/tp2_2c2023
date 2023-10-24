#include "Menu.hpp"

using namespace std;

void Menu::imprimir_menu_destino() {
    cout << "[ ]Menu destino: " << endl
    << "[1] Agregar eventos." << endl
    << "[2] Determinar perfil de jugador." << endl
    << "[0] Salir" << endl
    << "[ ]Opcion: ";
}

void Menu::logica_menu_destino(size_t opcion){
    switch(opcion){
        case OPCION_AGREGAR_EVENTO:
            evento.clear();
            while(evento != "salir"){
                evento.clear();
                cout << "Escriba un evento ('salir' para salir): ";
                cin >> evento;
                if(evento != "salir"){
                    destino.acolar(evento);
                    evento.clear();
                }
            }
            break;
        case OPCION_DETERMINAR_DESTINO:
            tipo_jugador = destino.desacolar();
            cout << "El tipo de jugador es: " << tipo_jugador << endl;
            evento_final = destino.determinar_destino(tipo_jugador);
            cout << "El evento a ejecutar es: " << evento_final << endl;
            break;
        case 0:
            break;
    }
}

void Menu::imprimir_menu_inventario() {
    cout << "[ ] Menu Inventario: " << endl
    << "[1] Recoger item" << endl
    << "[2] Soltar item" << endl
    << "[3] Consulta inventario" << endl
    << "[4] Guardar" << endl
    << "[0] Salir" << endl
    << "Opcion: ";
}

void Menu::logica_menu_inventario(size_t opcion) {
    switch(opcion){
        case OPCION_RECOGER:
            nombre_item.clear();
            while(nombre_item != "salir"){
                nombre_item.clear();
                tipo_item.clear();
                cout << "Escribe el nombre del item ('salir' para salir): ";
                cin >> nombre_item;
                cout << endl;
                if(nombre_item != "salir"){
                    cout << "Escribe el tipo de item: ";
                    cin >> tipo_item;
                    cout << endl;
                    inventario.recoger_objeto(nombre_item,tipo_item);
                }
            }
            break;
        case OPCION_SOLTAR:
            nombre_item.clear();
            while(nombre_item != "salir"){
                nombre_item.clear();
                cout << "Escribe el nombre del item a soltar/usar ('salir' para salir): ";
                cin >> nombre_item;
                cout << endl;
                if(nombre_item != "salir"){
                    inventario.soltar_objeto(nombre_item);
                }
            }
            break;
        case OPCION_CONSULTA:
            inventario.consultar_inventario();
            break;
        case OPCION_GUARDAR:
            inventario.guardar("save_file.csv");
            break;
        default:
            break;
    }
}

void Menu::imprimir_menu() {
    inventario.cargar("save_file.csv");
    cout << "James Sunderland - 25 HP" << endl
    << "[1] Acceder inventario" << endl
    << "[2] Acceder al simulador de eventos" << endl
    << "[0] Salir" << endl;
}
