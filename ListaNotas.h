#pragma once
#include "Nota.h"

class ListaNotas{
    private:
        Nota* cabeza;
        Nota* cola;
        int cantidad;
    public:
        ListaNotas();
        void agregarNota(float);
        float calcularPromedio();
        int getCantidad();
        void mostrarNotas();
        bool notaValida(float); 

        ~ListaNotas(){};
        
};