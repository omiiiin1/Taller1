#pragma once
#include "NodoInscripcion.h"

class ListaInscripciones{
    private:
        NodoInscripcion* cabeza;
        NodoInscripcion* cola;
        int cantidad;
    public:
        ListaInscripciones();
        ~ListaInscripciones();
        void agregarInscripcion(Inscripcion inscripcion);
        void eliminarInscripcion(std::string idAlumno, std::string codigoCurso);
        NodoInscripcion* buscarInscripcion(std::string idAlumno, std::string codigoCurso);
        int getCantidad();
        void mostrarInscripciones();

        int contarInscripciones(std::string);

        NodoInscripcion* getCabeza();
        NodoInscripcion* getCola();
};
