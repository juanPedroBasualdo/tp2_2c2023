#include "Menu.hpp"

using namespace std;

void Menu::imprimir_menu_destino() {
    cout << "Menu destino: " << endl
    << "1) Agregar eventos." << endl
    << "2) Determinar perfil de jugador." << endl
    << "0) Salir." << endl;
}

void Menu::logica_menu_destino(size_t opcion){
    switch(opcion){
        case OPCION_AGREGAR_EVENTO:
            while(evento != "salir"){
                evento.clear();
                cout << "Escriba un evento: ('salir' para salir) ";
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
        default:
            break;
    }
}