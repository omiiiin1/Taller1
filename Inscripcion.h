#pragma once
#include "Alumno.h"
#include "Curso.h"
#include "ListaNotas.h"

class Inscripcion{
    private :
        Alumno* alumno;
        Curso* curso;
        ListaNotas* notas;
    public: 
        Inscripcion(Alumno*, Curso*);
        void agregarNota(float);
        float calcularPromedio();

        Alumno* getAlumno();
        Curso* getCurso();
        int getCantidadNotas();
        void mostrarNotas();
        
};