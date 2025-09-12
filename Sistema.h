#include "ListaInscripciones.h"
#include "ListaAlumnos.h"
#include "ListaCursos.h"

class Sistema{
    private:
        ListaAlumnos* alumnos;
        ListaCursos* cursos;
        ListaInscripciones* inscripciones;
    public:
        Sistema();
        void registrarAlumno(std::string, std::string, std::string, std::string, std::string);
        void buscarAlumno(std::string);
        void eliminarAlumno(std::string);
        
        void registrarCurso(std::string codigo, std::string nombre, int capacidad, std::string carrera, std::string profesor);
        void buscarCurso(std::string);
        void eliminarCurso(std::string);

        void inscribirAlumno(std::string, std::string);
        void eliminarInscripcion(std::string, std::string);

        void agregarNota(std::string, std::string, float);
        void mostrarNotasCurso(std::string, std::string);
        
        void reporteAlumno(std::string);
        void reporteCurso(std::string);

        void alumnosPorCarrera(std::string);
        void cursosPorAlumno(std::string);
        void promedioAlumnoCurso(std::string, std::string);
        void promedioAlumno(std::string);
        

};