#pragma once
#include <string>


class Alumno {
    private: 
    string id;
    string nombre;
    string apellido;
    string carrera;
    string fechaIngreso;

    public:
        Alumno(string, string, string, string, string);
        string getId();
        string getNombre();
        string getApellido();
        string getCarrera();
        string getFechaIngreso();
        void setId(string);
        void setNombre(string);
        void setApellido(string);
        void setCarrera(string);
        void setFechaIngreso(string);
        void toString();
        ~Alumno(){};

};