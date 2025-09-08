#pragma once
#include <string>

class Curso{
    private:
    string codigo;
    string nombre;
    int capacidad;
    string carrera;
    string profesor;

    public:
        Curso(string, string, int, string, string);
        string getCodigo();
        string getNombre();
        int getCapacidad();
        string getCarrera();
        string getProfesor();
        void setCodigo(string);
        void setNombre(string);
        void setCapacidad(int);
        void setCarrera(string);
        void setProfesor(string);
        void toString();
        ~Curso(){};
};