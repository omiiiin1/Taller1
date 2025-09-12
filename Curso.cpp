#include "Curso.h"

#include <iostream>

using namespace std;

Curso::Curso(string codigo, string nombre, int capacidad, string carrera, string profesor){
    this -> codigo = codigo;
    this -> nombre = nombre;
    this -> capacidad = capacidad;
    this -> carrera = carrera;
    this -> profesor = profesor;
}

string Curso::getCodigo(){return codigo;}
string Curso::getNombre(){return nombre;}
int Curso::getCapacidad(){return capacidad;}
string Curso::getCarrera(){return carrera;}
string Curso::getProfesor(){return profesor;}
void Curso::setCodigo(string codigo){this -> codigo = codigo;}
void Curso::setNombre(string nombre){this -> nombre = nombre;}
void Curso::setCapacidad(int capacidad){this -> capacidad = capacidad;}
void Curso::setCarrera(string carrera){this -> carrera = carrera;}
void Curso::setProfesor(string profesor){this -> profesor = profesor;}
void Curso::toString(){
    cout << "Codigo: " << codigo << endl;
    cout << "Nombre: " << nombre << endl;
    cout << "Capacidad: " << capacidad << endl;
    cout << "Carrera: " << carrera << endl;
    cout << "Profesor: " << profesor << endl;
}

~Curso(){};