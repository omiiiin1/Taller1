#include "ListaNotas.h"
#include <iostream>

ListaNotas::ListaNotas(){
    cabeza = nullptr;
    cola = nullptr;
    cantidad = 0;
}

ListaNotas::~ListaNotas(){
    Nota* actual = cabeza;
    while(actual != nullptr){
        Nota* temp = actual -> siguiente;
        delete actual;
        actual = temp;
    }
}

void ListaNotas::agregarNota(float calificacion){
    Nota* nuevoNodo = new Nota(calificacion);
    if(cabeza == nullptr){
        cabeza = nuevoNodo;
        cola = nuevoNodo;
    } else {
        cola -> siguiente = nuevoNodo;
        cola = nuevoNodo;
    }
    cantidad++;
}

float ListaNotas::calcularPromedio(){
    if(cantidad == 0) return 0.0f;
    float suma = 0.0f;
    Nota* actual = cabeza;
    while(actual != nullptr){
        suma += actual -> calificacion;
        actual = actual -> siguiente;
    }
    return suma / cantidad;
}

int ListaNotas::getCantidad(){
    return cantidad;
}


void ListaNotas::mostrarNotas(){
    Nota* actual = cabeza;
    while(actual != nullptr){
        std::cout << actual -> calificacion << " ";
        actual = actual -> siguiente;
    }
    std::cout << std::endl;
}

