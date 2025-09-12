#include <iostream>
#include "ListaCursos.h"

ListaCursos::ListaCursos(){
    cabeza = nullptr;
    cola = nullptr;
    cantidad = 0;
}
ListaCursos::~ListaCursos(){
    NodoCurso* actual = cabeza;
    while(actual != nullptr){
        NodoCurso* temp = actual -> siguiente;
        delete actual;
        actual = temp;
    }
}
void ListaCursos::agregarCurso(Curso* c){
    NodoCurso* nuevoNodo = new NodoCurso(*c);
    if(cabeza == nullptr){
        cabeza = nuevoNodo;
        cola = nuevoNodo;
    } else {
        cola -> siguiente = nuevoNodo;
        cola = nuevoNodo;
    }
    cantidad++;
}

void ListaCursos::eliminarCurso(std::string codigo){
    if(cabeza == nullptr) return;

    if(cabeza -> curso.getCodigo() == codigo){
        NodoCurso* temp = cabeza;
        cabeza = cabeza -> siguiente;
        delete temp;
        cantidad--;
        if(cabeza == nullptr) cola = nullptr;
        return;
    }

    NodoCurso* actual = cabeza;
    while(actual -> siguiente != nullptr && actual -> siguiente -> curso.getCodigo() != codigo){
        actual = actual -> siguiente;
    }

    if(actual -> siguiente != nullptr){
        NodoCurso* temp = actual -> siguiente;
        actual ->siguiente = actual -> siguiente -> siguiente;
        if(temp == cola) cola = actual;
        delete temp;
        cantidad--;
    }
}
NodoCurso* ListaCursos::buscarCurso(std::string codigo){
    NodoCurso* actual = cabeza;
    while(actual != nullptr){
        if(actual -> curso.getCodigo() == codigo){
            return actual;
        }
        actual = actual -> siguiente;
    }
    return nullptr;
}
void ListaCursos::mostrarPorNombre(std::string nombre){
    NodoCurso* actual = cabeza;
    while(actual != nullptr){
        if(actual -> curso.getNombre() == nombre){
            actual -> curso.toString();
            std::cout << "------------------------" << std::endl;
        }
        actual = actual -> siguiente;
    }
}

int ListaCursos::getCantidad(){
    return cantidad;
}
void ListaCursos::mostrarCurso(NodoCurso* nodo){
    if(nodo != nullptr){
        nodo -> curso.toString();
    } else {
        std::cout << "Curso no encontrado." << std::endl;
    }
}
void ListaCursos::mostrarCursos(){
    NodoCurso* actual = cabeza;
    while(actual != nullptr){
        actual -> curso.toString();
        std::cout << "------------------------" << std::endl;
        actual = actual -> siguiente;
    }
}
NodoCurso* ListaCursos::getCabeza(){
    return cabeza;
}
