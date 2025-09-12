#pragma once

class Nota{
    public:
        float calificacion;
        Nota* siguiente;

        Nota(float calificacion) : calificacion(calificacion), siguiente(nullptr) {}
        ~Nota(){};

};