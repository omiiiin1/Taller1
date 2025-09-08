#pragma once
#include <string>


class Alumno {
    private: 
    std::string id;
    std::string nombre;
    std::string apellido;
    std::string carrera;
    std::string fechaIngreso;

    public:
        Alumno(std::string id, std::string nombre, std::string apellido, 
               std::string carrera, std::string fechaIngreso);
        std::string getId();
        std::string getNombre();
        std::string getApellido();
        std::string getCarrera();
        std::string getFechaIngreso();
        void setId(string);
        void setNombre(string);
        void setApellido(string);
        void setCarrera(string);
        void setFechaIngreso(string);
        void toString();
        ~Alumno(){};

};