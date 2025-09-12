#include "ListaAlumnos.h"


#include <iostream>

ListaAlumnos::ListaAlumnos(){
    cabeza = nullptr;
    cola = nullptr;
    cantidad = 0;
}

ListaAlumnos::~ListaAlumnos(){
    NodoAlumno* actual = cabeza;
    while(actual != nullptr){
        NodoAlumno* temp = actual -> siguiente;
        delete actual;
        actual = temp;
    }
}
void ListaAlumnos::agregarAlumno(Alumno* a){
    NodoAlumno* nuevoNodo = new NodoAlumno(*a);
    if(cabeza == nullptr){
        cabeza = nuevoNodo;
        cola = nuevoNodo;
    } else {
        cola -> siguiente = nuevoNodo;
        cola = nuevoNodo;
    }
    cantidad++;
}

void ListaAlumnos::eliminarAlumno(Alumno* a){
    if(cabeza == nullptr) return;

    if(cabeza -> alumno.getId() == a -> getId()){
        NodoAlumno* temp = cabeza;
        cabeza = cabeza -> siguiente;
        delete temp;
        cantidad--;
        if(cabeza == nullptr) cola = nullptr;
        return;
    }

    NodoAlumno* actual = cabeza;
    while(actual -> siguiente != nullptr && actual -> siguiente -> alumno.getId() != a -> getId()){
        actual = actual -> siguiente;
    }

    if(actual -> siguiente != nullptr){
        NodoAlumno* temp = actual -> siguiente;
        actual ->siguiente = actual -> siguiente -> siguiente;
        if(temp == cola) cola = actual;
        delete temp;
        cantidad--;
    }
}

NodoAlumno* ListaAlumnos::buscarAlumnoId(std::string id){
    NodoAlumno* actual = cabeza;
    while(actual != nullptr){
        if(actual -> alumno.getId() == id){
            return actual;
        }
        actual = actual -> siguiente;
    }
    return nullptr;
}

int ListaAlumnos::getCantidad(){
    return cantidad;
}

NodoAlumno* ListaAlumnos::mostrarPorNombre(std::string nombre){
    NodoAlumno* actual = cabeza;
    while(actual != nullptr){
        if(actual -> alumno.getNombre() == nombre){
            return actual;
        }
        actual = actual -> siguiente;
    }
    return nullptr;
}

void ListaAlumnos::mostrarAlumnos(){
    NodoAlumno* actual = cabeza;
    while(actual != nullptr){
        actual -> alumno.toString();
        std::cout << "------------------------" << std::endl;
        actual = actual -> siguiente;
    }
}
NodoAlumno* ListaAlumnos::getCabeza(){
    return cabeza;
}
