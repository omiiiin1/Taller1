#include "Inscripcion.h"
#include <iostream>
#include <string>

Inscripcion::Inscripcion(Alumno& alumno, Curso& curso) : alumno(alumno), curso(curso) {

}

void Inscripcion::agregarNota(float calificacion){
    
    notas.agregarNota(calificacion);
}

float Inscripcion::calcularPromedio(){
    return notas.calcularPromedio();
}

Alumno Inscripcion::getAlumno(){
    return alumno;
}

Curso Inscripcion::getCurso(){
    return curso;
}

std::string Inscripcion::getAlumnoId() {
    return alumno.getId();
}

std::string Inscripcion::getCursoCodigo() {
    return curso.getCodigo();
}


int Inscripcion::getCantidadNotas(){
    return notas.getCantidad();
}

void Inscripcion::mostrarNotas() {
    std::cout << "\n--- Notas de " << alumno.getNombre() << " " << alumno.getApellido() 
              << " en " << curso.getNombre() << " ---" << std::endl;
    notas.mostrarNotas();
    std::cout << "Promedio final: " << calcularPromedio() << std::endl;
}




