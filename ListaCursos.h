#pragma once
#include "NodoCurso.h"

class ListaCursos{
    private:
        NodoCurso* cabeza;
        NodoCurso* cola;
        int cantidad;
    public:
        ListaCursos();
        ~ListaCursos();

        void agregarCurso(Curso*);
        void eliminarCurso(std::string);
        
        NodoCurso* buscarCurso(std::string);
        NodoCurso* mostrarPorNombre(std::string);

        int getCantidad();
        void mostrarCurso(NodoCurso*);
        void mostrarCursos();

        NodoCurso* getCabeza();
        
};
