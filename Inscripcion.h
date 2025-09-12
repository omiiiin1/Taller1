#pragma once
#include "Alumno.h"
#include "Curso.h"
#include "ListaNotas.h"
#include <string>

class Inscripcion{
    private :
        Alumno alumno;
        Curso curso;
        ListaNotas notas;
    public: 
        Inscripcion(Alumno& alumno, Curso& curso);
        void agregarNota(float);
        float calcularPromedio();

        Alumno getAlumno();
        Curso getCurso();
        int getCantidadNotas();
        std::string getAlumnoId();
        std::string getCursoCodigo();
        void mostrarNotas();
        
};