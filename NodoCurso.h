#pragma once
#include "Curso.h"

class NodoCurso{
    public:
        Curso curso;
        NodoCurso* siguiente;

        NodoCurso(Curso curso): curso(curso), siguiente(nullptr) {}
        ~NodoCurso(){};
};
