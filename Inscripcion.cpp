#include "Inscripcion.h"
#include <iostream>

Inscripcion::Inscripcion(Alumno* a, Curso* c){
    alumno = a;
    curso = c;
    notas = new ListaNotas();
}

void Inscripcion::agregarNota(float calificacion){
    notas -> agregarNota(calificacion);
}

float Inscripcion::calcularPromedio(){
    return notas -> calcularPromedio();
}

Alumno* Inscripcion::getAlumno(){
    return alumno;
}

Curso* Inscripcion::getCurso(){
    return curso;
}

int Inscripcion::getCantidadNotas(){
    return notas -> getCantidadNotas();
}




