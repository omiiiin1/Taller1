#pragma once
#include "NodoAlumno.h"
#include "Alumno.h"

class ListaAlumnos{
    private:
        NodoAlumno* cabeza;
        NodoAlumno* cola;
        int cantidad;
    public:
        ListaAlumnos();
        ~ListaAlumnos();

        void agregarAlumno(Alumno*);
        void eliminarAlumno(Alumno*);
        
        NodoAlumno* buscarAlumnoId(std::string);
        void mostrarPorNombre(std::string); 
        int getCantidad();
        void mostrarAlumnos();

        NodoAlumno* getCabeza();


};
