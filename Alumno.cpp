#include "Alumno.h"
#include <iostream>

Alumno::Alumno(string id, string nombre, string apellido, string carrera, string fechaIngreso){
    this -> id = id;
    this -> nombre = nombre;
    this -> apellido = apellido;
    this -> carrera = carrera;
    this -> fechaIngreso = fechaIngreso;
}

string Alumno::getId(){return id;}
string Alumno::getNombre(){return nombre;}
string Alumno::getApellido(){return apellido;}
string Alumno::getCarrera(){return carrera;}
string Alumno::getFechaIngreso(){return fechaIngreso;}
void Alumno::setId(string id){this -> id = id;}
void Alumno::setNombre(string nombre){this -> nombre = nombre;}
void Alumno::setApellido(string apellido){this -> apellido = apellido;}
void Alumno::setCarrera(string carrera){this -> carrera = carrera;}
void Alumno::setFechaIngreso(string fechaIngreso){this -> fechaIngreso = fechaIngreso;}
void Alumno::toString(){
    std::cout << "ID: " << id << std::endl;
    std::cout << "Nombre: " << nombre << " " << apellido << std::endl;
    std::cout << "Carrera: " << carrera << std::endl;
    std::cout << "Fecha de ingreso: " << fechaIngreso << std::endl;
}

