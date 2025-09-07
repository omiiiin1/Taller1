#include "Alumno.h"
#include <iostream>

Alumno::Alumno(string id, string nombre, string apellido, string carrera, string fechaIngreso){
    this -> id = id;
    this -> nombre = nombre;
    this -> apellido = apellido;
    this -> carrera = carrera;
    this -> fechaIngreso = fechaIngreso;
}