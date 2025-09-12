#include "Alumno.h"
#include <string>
#include <iostream>


Alumno::Alumno(std::string id, std::string nombre, std::string apellido, std::string carrera, std::string fechaIngreso){
    this -> id = id;
    this -> nombre = nombre;
    this -> apellido = apellido;
    this -> carrera = carrera;
    this -> fechaIngreso = fechaIngreso;
}

std::string Alumno::getId(){return id;}
std::string Alumno::getNombre(){return nombre;}
std::string Alumno::getApellido(){return apellido;}
std::string Alumno::getCarrera(){return carrera;}
std::string Alumno::getFechaIngreso(){return fechaIngreso;}
void Alumno::setId(std::string id){this -> id = id;}
void Alumno::setNombre(std::string nombre){this -> nombre = nombre;}
void Alumno::setApellido(std::string apellido){this -> apellido = apellido;}
void Alumno::setCarrera(std::string carrera){this -> carrera = carrera;}
void Alumno::setFechaIngreso(std::string fechaIngreso){this -> fechaIngreso = fechaIngreso;}
void Alumno::toString(){
    std::cout << "ID: " << id << std::endl;
    std::cout << "Nombre: " << nombre << " " << apellido << std::endl;
    std::cout << "Carrera: " << carrera << std::endl;
    std::cout << "Fecha de ingreso: " << fechaIngreso << std::endl;
}


