#pragma once
#include "Inscripcion.h"

class NodoInscripcion{
    public:
        Inscripcion inscripcion;
        NodoInscripcion* siguiente;

        NodoInscripcion(Inscripcion inscripcion): inscripcion(inscripcion), siguiente(nullptr) {}
        ~NodoInscripcion(){};
};
