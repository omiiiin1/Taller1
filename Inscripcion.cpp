#include "Inscripcion.h"
#include <iostream>

Inscripcion::Inscripcion(Alumno* a, Curso* c){
    alumno = a;
    curso = c;
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
    return notas->getCantidad();
}

void Inscripcion::mostrarNotas() {
    std::cout << "\n--- Notas de " << alumno->getNombre() << " " << alumno->getApellido() 
              << " en " << curso->getNombre() << " ---" << std::endl;
    notas->mostrarNotas();
    std::cout << "Promedio final: " << calcularPromedio() << std::endl;
}




