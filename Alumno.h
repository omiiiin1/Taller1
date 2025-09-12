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
        void setId(std::string);
        void setNombre(std::string);
        void setApellido(std::string);
        void setCarrera(std::string);
        void setFechaIngreso(std::string);
        void toString();
        ~Alumno(){};

};