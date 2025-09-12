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
    if(notaValida(calificacion)){
        Nota* nuevaNota = new Nota(calificacion);
        if(cabeza == nullptr){
            cabeza = nuevaNota;
            cola = nuevaNota;
        } else {
            cola -> siguiente = nuevaNota;
            cola = nuevaNota;
        }
        cantidad++;
    } else {
        std::cout << "Nota fuera de rango. Debe estar entre 1.0 y 7.0" << std::endl;
        return;
    }
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

bool ListaNotas::notaValida(float calificacion){
    return (calificacion >= 1.0f && calificacion <= 7.0f);
}
void ListaNotas::mostrarNotas(){
    Nota* actual = cabeza;
    while(actual != nullptr){
        std::cout << actual -> calificacion << " ";
        actual = actual -> siguiente;
    }
    std::cout << std::endl;
}

