#pragma once
#include "Alumno.h"

class NodoAlumno{
    public:
        Alumno alumno;
        NodoAlumno* siguiente;
        

        NodoAlumno(Alumno alumno): alumno(alumno), siguiente(nullptr) {}
        ~NodoAlumno(){};
};