#include "Destino.hpp"

#include <utility>

using namespace std;

Destino::Destino() {
    cantidad_aperturas = 0;
    cantidad_guardados = 0;
}

void Destino::acolar(const string& nombre_evento){
    if(nombre_evento == ACCION_GUARDADO){
        Evento evento(ACCION_GUARDADO);
        eventos.alta(evento);
    } else if(nombre_evento == ACCION_APERTURA_MAPA){
        Evento evento(ACCION_APERTURA_MAPA);
        eventos.alta(evento);
    } else{
        cout << "El evento " << nombre_evento << " no es un evento correcto (GUARDADO, APERTURA_MAPA)." << endl;
    }
}

string Destino::desacolar(){
    string tipo_jugador;
    while(!eventos.vacio()){
        Evento evento_actual = eventos.baja();
        if(evento_actual == ACCION_GUARDADO){
            cantidad_guardados++;
        } else{
            cantidad_aperturas++;
        }
    }
    if((cantidad_aperturas > cantidad_guardados) && (cantidad_aperturas > 5) && (cantidad_guardados < 8)){
        tipo_jugador = DESORIENTADO;
    } else if((cantidad_guardados > cantidad_aperturas) && (cantidad_guardados > 5) && (cantidad_guardados < 8)){
        tipo_jugador = PRECAVIDO;
    } else if (cantidad_guardados >= 8){
        tipo_jugador = ASUSTADO;
    } else{
        tipo_jugador = NO_DETERMINADO;
    }
    return tipo_jugador;
}

string Destino::determinar_destino(const string& tipo_jugador) {
    string destino;
    if(tipo_jugador == DESORIENTADO){
        destino = "Aumento de factores ambientales";
    }else if (tipo_jugador == PRECAVIDO){
        destino = "Aumento en la cantidad de enemigos";
    } else if(tipo_jugador == ASUSTADO){
        destino = "Evento Pyramid Head adelantado";
    } else{
        destino = "Comportamiento aun no definido";
    }
    return destino;
}

