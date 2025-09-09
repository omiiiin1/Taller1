#pragma once
#include <string>

class Curso{

    private:
    std::string codigo;
    std::string nombre;
    int capacidad;
    std::string carrera;
    std::string profesor;

    public:
        Curso(std::string, std::string, int, std::string, std::string);
        std::string getCodigo();
        std::string getNombre();
        int getCapacidad();
        std::string getCarrera();
        std::string getProfesor();
        void setCodigo(std::string);
        void setNombre(std::string);
        void setCapacidad(int);
        void setCarrera(std::string);
        void setProfesor(std::string);
        void toString();
        ~Curso(){};
};