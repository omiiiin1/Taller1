#include <iostream>
#include "ListaInscripciones.h"


ListaInscripciones::ListaInscripciones(){
    cabeza = nullptr;
    cola = nullptr;
    cantidad = 0;
}

ListaInscripciones::~ListaInscripciones(){
    NodoInscripcion* actual = cabeza;
    while(actual != nullptr){
        NodoInscripcion* temp = actual -> siguiente;
        delete actual;
        actual = temp;
    }
}

void ListaInscripciones::agregarInscripcion(Inscripcion inscripcion){
    NodoInscripcion* nuevoNodo = new NodoInscripcion(inscripcion);
    if(cabeza == nullptr){
        cabeza = nuevoNodo;
        cola = nuevoNodo;
    } else {
        cola -> siguiente = nuevoNodo;
        cola = nuevoNodo;
    }
    cantidad++;
}

void ListaInscripciones::eliminarInscripcion(Inscripcion inscripcion){
    if(cabeza == nullptr) return;

    
    if(cabeza -> inscripcion.getAlumno() == inscripcion.getAlumno() &&
       cabeza -> inscripcion.getCurso() == inscripcion.getCurso()){
        NodoInscripcion* temp = cabeza;
        cabeza = cabeza -> siguiente;
        delete temp;
        cantidad--;
        if(cabeza == nullptr) cola = nullptr;
        return;
    }

    NodoInscripcion* actual = cabeza;
    while(actual -> siguiente != nullptr && 
          !(actual -> siguiente -> inscripcion.getAlumno() == inscripcion.getAlumno() &&
            actual -> siguiente -> inscripcion.getCurso() == inscripcion.getCurso())){
        actual = actual -> siguiente;
    }

    if(actual -> siguiente != nullptr){
        NodoInscripcion* temp = actual -> siguiente;
        actual ->siguiente = actual -> siguiente -> siguiente;
        if(temp == cola) cola = actual;
        delete temp;
        cantidad--;
    }
}

NodoInscripcion* ListaInscripciones::buscarInscripcion(std::string idAlumno, std::string codigoCurso){
    NodoInscripcion* actual = cabeza;
    while(actual != nullptr){
        if(actual -> inscripcion.getAlumno() -> getId() == idAlumno &&
           actual -> inscripcion.getCurso() -> getCodigo() == codigoCurso){
            return actual;
        }
        actual = actual -> siguiente;
    }
    return nullptr;
}

int ListaInscripciones::getCantidad(){
    return cantidad;
}

void ListaInscripciones::mostrarInscripciones(){
    NodoInscripcion* actual = cabeza;
    while(actual != nullptr){
        std::cout << "Alumno: " << actual -> inscripcion.getAlumno() -> getNombre() 
                  << " | Curso: " << actual -> inscripcion.getCurso() -> getNombre() 
                  << " | Promedio: " << actual -> inscripcion.calcularPromedio() 
                  << " | Cantidad de Notas: " << actual -> inscripcion.getCantidadNotas() 
                  << std::endl;
        actual = actual -> siguiente;
    }
}
NodoInscripcion* ListaInscripciones::getCabeza(){
    return cabeza;
}

NodoInscripcion* ListaInscripciones::getCola(){
    return cola;
}

int ListaInscripciones::contarInscripciones(std::string codigoCurso){
    int contador = 0;
    NodoInscripcion* actual = cabeza;
    while(actual != nullptr){
        if(actual -> inscripcion.getCurso() -> getCodigo() == codigoCurso){
            contador++;
        }
        actual = actual -> siguiente;
    }
    return contador;
}

