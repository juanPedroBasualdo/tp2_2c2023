#include <utility>

#include "Evento.hpp"

Evento::Evento(std::string accion) {
    this->accion_ejecutada = std::move(accion);
}

bool Evento::operator==(const std::string& accion) {
    return this->accion_ejecutada == accion;
}

