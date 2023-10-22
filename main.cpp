#include "Menu.hpp"
#include <iostream>

using namespace std;

int main() {
    size_t opcion = 8;
    while(opcion != 0){
        Menu menu;
        menu.imprimir_menu_destino();
        cin >> opcion;
        while (opcion != 0){
            menu.logica_menu_destino(opcion);
            menu.imprimir_menu_destino();
            cin >> opcion;
            if(opcion != 0){
                menu.logica_menu_destino(opcion);
            }
            menu.imprimir_menu_destino();
            cin>> opcion;
        }
    }
    return 0;
}