#include <iostream>
#include "ListaInscripciones.h"
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

NodoInscripcion* ListaInscripciones::buscarInscripcion(std::string idAlumno, std::string codigoCurso) {
    NodoInscripcion* actual = cabeza;
    while (actual != nullptr) {
        if (actual->inscripcion.getAlumnoId() == idAlumno && 
            actual->inscripcion.getCursoCodigo() == codigoCurso) {
            return actual;
        }
        actual = actual->siguiente;
    }
    return nullptr;
}

void ListaInscripciones::eliminarInscripcion(std::string idAlumno, std::string codigoCurso) {
    if (cabeza == nullptr) return;

    if (cabeza->inscripcion.getAlumnoId() == idAlumno && 
        cabeza->inscripcion.getCursoCodigo() == codigoCurso) {
        NodoInscripcion* temp = cabeza;
        cabeza = cabeza->siguiente;
        delete temp;
        cantidad--;
        if (cabeza == nullptr) cola = nullptr;
        return;
    }
    
    NodoInscripcion* actual = cabeza;
    while (actual->siguiente != nullptr && 
            !(actual->siguiente->inscripcion.getAlumnoId() == idAlumno && 
            actual->siguiente->inscripcion.getCursoCodigo() == codigoCurso)) {
        actual = actual->siguiente;
    }
    
    if (actual->siguiente != nullptr) {
        NodoInscripcion* temp = actual->siguiente;
        actual->siguiente = temp->siguiente;
        
        if (temp == cola) {
            cola = actual;
        }
        
        delete temp;
        cantidad--;
    }
}


int ListaInscripciones::getCantidad(){
    return cantidad;
}

void ListaInscripciones::mostrarInscripciones(){
    NodoInscripcion* actual = cabeza;
    while(actual != nullptr){
        std::cout << "Alumno: " << actual->inscripcion.getAlumno().getNombre() 
                  << " | Curso: " << actual->inscripcion.getCurso().getNombre() 
                  << " | Promedio: " << actual->inscripcion.calcularPromedio() 
                  << " | Cantidad de Notas: " << actual->inscripcion.getCantidadNotas() 
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
        if(actual->inscripcion.getCursoCodigo() == codigoCurso){
            contador++;
        }
        actual = actual->siguiente;
    }
    return contador;
}

