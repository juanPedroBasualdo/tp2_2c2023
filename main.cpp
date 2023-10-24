#include "Menu.hpp"
#include <iostream>

using namespace std;

int main() {
    size_t opcion = 8;
    Menu menu;
    menu.imprimir_menu();
    cout << "Elija su opcion: " << endl;
    cin >> opcion;
    if(opcion == OPCION_INVENTARIO){
        menu.imprimir_menu_inventario();
        cin >> opcion;
        while(opcion != OPCION_SALIR){
            menu.logica_menu_inventario(opcion);
            menu.imprimir_menu_inventario();
            cin >> opcion;
            if(opcion != OPCION_SALIR){
                menu.logica_menu_inventario(opcion);
                menu.imprimir_menu_inventario();
                cin >> opcion;
            }
        }
    } else if(opcion == OPCION_DESTINO){
        menu.imprimir_menu_destino();
        cin >> opcion;
        while(opcion != 0){
            menu.logica_menu_destino(opcion);
            menu.imprimir_menu_destino();
            cin >> opcion;
            if(opcion != 0){
                menu.logica_menu_destino(opcion);
                menu.imprimir_menu_destino();
                cin >> opcion;
            }
        }
    } else if(opcion == OPCION_SALIR) {
        menu.imprimir_menu();
        cin >> opcion;
    } else {
        return 0;
    }
    return 0;
}