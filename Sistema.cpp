#include "Sistema.h"
#include <iostream>
#include <string>

Sistema::Sistema(){
    alumnos = new ListaAlumnos();
    cursos = new ListaCursos();
    inscripciones = new ListaInscripciones();
}

void Sistema::registrarAlumno(std::string id, std::string nombre, std::string apellido, std::string carrera, std::string email){
    if(alumnos -> buscarAlumnoId(id) != nullptr){
        std::cout << "El alumno con ID " << id << " ya está registrado." << std::endl;
        return;
    }
    Alumno* nuevoAlumno = new Alumno(id, nombre, apellido, carrera, email);
    alumnos -> agregarAlumno(nuevoAlumno);
    std::cout << "Alumno registrado exitosamente." << std::endl;
}

void Sistema::buscarAlumno(std::string id){
    NodoAlumno* nodo = alumnos -> buscarAlumnoId(id);
    if(nodo != nullptr){
        nodo -> alumno.toString();
    } else {
        std::cout << "Alumno con ID " << id << " no encontrado." << std::endl;
    }
}

void Sistema::buscarAlumnoNombre(std::string nombre){
    NodoAlumno* actual = alumnos->getCabeza();
    bool encontrado = false;
        std::string nombreBuscado = nombre;
        std::transform(nombreBuscado.begin(), nombreBuscado.end(), nombreBuscado.begin(), ::tolower);
        while(actual != nullptr){
            std::string nombreAlumno = actual->alumno.getNombre();
            std::transform(nombreAlumno.begin(), nombreAlumno.end(), nombreAlumno.begin(), ::tolower);
            if(nombreAlumno == nombreBuscado){
                actual->alumno.toString();
                std::cout << "------------------------" << std::endl;
                encontrado = true;
            }
            actual = actual->siguiente;
        }
        if(!encontrado){
            std::cout << "No se encontraron alumnos con el nombre " << nombre << "." << std::endl;
        }
}

void Sistema::eliminarAlumno(std::string id){
    if(alumnos -> buscarAlumnoId(id) == nullptr){
        std::cout << "El alumno con ID " << id << " no está registrado." << std::endl;
        return;
    }
    // Eliminar inscripciones asociadas al alumno
    NodoInscripcion* actual = inscripciones->getCabeza();
    while(actual != nullptr){
        if(actual->inscripcion.getAlumno().getId() == id){
            inscripciones->eliminarInscripcion(actual->inscripcion.getAlumnoId(), actual->inscripcion.getCursoCodigo());
            actual = inscripciones->getCabeza(); // Reiniciar desde el inicio
        } else {
            actual = actual->siguiente;
        }
    }
    
    // Buscar el alumno para eliminarlo
    NodoAlumno* alumnoAEliminar = alumnos -> buscarAlumnoId(id);
    if(alumnoAEliminar != nullptr){
        alumnos -> eliminarAlumno(&(alumnoAEliminar -> alumno));
    }
    std::cout << "Alumno eliminado exitosamente." << std::endl;
}

void Sistema::registrarCurso(std::string codigo, std::string nombre, int capacidad, std::string carrera, std::string profesor){
    if(cursos -> buscarCurso(codigo) != nullptr){
        std::cout << "El curso con código " << codigo << " ya está registrado." << std::endl;
        return;
    }
    Curso* nuevoCurso = new Curso(codigo, nombre, capacidad, carrera, profesor);
    cursos -> agregarCurso(nuevoCurso);
    std::cout << "Curso registrado exitosamente." << std::endl;
}

void Sistema::buscarCurso(std::string codigo){
    NodoCurso* nodo = cursos -> buscarCurso(codigo);
    if(nodo != nullptr){
        nodo -> curso.toString();
    } else {
        std::cout << "Curso con código " << codigo << " no encontrado." << std::endl;
    }
}
void Sistema::buscarCursoNombre(std::string nombre){
    NodoCurso* actual = cursos->getCabeza();
    bool encontrado = false;
        std::string nombreBuscado = nombre;
        std::transform(nombreBuscado.begin(), nombreBuscado.end(), nombreBuscado.begin(), ::tolower);
        while(actual != nullptr){
            std::string nombreCurso = actual->curso.getNombre();
            std::transform(nombreCurso.begin(), nombreCurso.end(), nombreCurso.begin(), ::tolower);
            if(nombreCurso == nombreBuscado){
                actual->curso.toString();
                std::cout << "------------------------" << std::endl;
                encontrado = true;
            }
            actual = actual->siguiente;
        }
        if(!encontrado){
            std::cout << "No se encontraron cursos con el nombre " << nombre << "." << std::endl;
        }
}

void Sistema::eliminarCurso(std::string codigo){
    if(cursos -> buscarCurso(codigo) == nullptr){
        std::cout << "El curso con código " << codigo << " no está registrado." << std::endl;
        return;
    }
    
    NodoInscripcion* actual = inscripciones->getCabeza();
    while(actual != nullptr){
        if(actual->inscripcion.getCurso().getCodigo() == codigo){
            inscripciones->eliminarInscripcion(actual->inscripcion.getAlumnoId(), actual->inscripcion.getCursoCodigo());
            actual = inscripciones->getCabeza(); 
        } else {
            actual = actual->siguiente;
        }
    }
    
    cursos -> eliminarCurso(codigo);
    std::cout << "Curso eliminado exitosamente." << std::endl;
}

void Sistema::inscribirAlumno(std::string idAlumno, std::string codigoCurso) {
    NodoAlumno* alumno = alumnos->buscarAlumnoId(idAlumno);
    NodoCurso* curso = cursos->buscarCurso(codigoCurso);
    
    if (alumno == nullptr || curso == nullptr) {
        std::cout << "Error: Alumno o curso no encontrado." << std::endl;
        return;
    }
    
    
    std::string carreraAlumno = alumno->alumno.getCarrera();
    std::string carreraCurso = curso->curso.getCarrera();
    
    std::transform(carreraAlumno.begin(), carreraAlumno.end(), carreraAlumno.begin(), ::tolower);
    std::transform(carreraCurso.begin(), carreraCurso.end(), carreraCurso.begin(), ::tolower);
    if (carreraAlumno != carreraCurso) {
        std::cout << "Error: El alumno y el curso deben ser de la misma carrera." << std::endl;
        return;
    }

    NodoInscripcion* existente = inscripciones->buscarInscripcion(idAlumno, codigoCurso);
    if (existente != nullptr) {
        std::cout << "Error: El alumno ya está inscrito en este curso." << std::endl;
        return;
    }

    int cantidadInscripciones = inscripciones->contarInscripciones(codigoCurso);
    if (cantidadInscripciones >= curso->curso.getCapacidad()) {
        std::cout << "Error: El curso ha alcanzado su capacidad máxima." << std::endl;
        return;
    }

    
    Inscripcion nuevaInscripcion(alumno->alumno, curso->curso);
    inscripciones->agregarInscripcion(nuevaInscripcion);
    std::cout << "Alumno inscrito exitosamente." << std::endl;
    std::cout << "Cupos disponibles: " << (curso->curso.getCapacidad() - (cantidadInscripciones + 1)) << std::endl;
}

void Sistema::eliminarInscripcion(std::string id, std::string codigo){
    NodoInscripcion* nodo = inscripciones->buscarInscripcion(id, codigo);
    if(nodo == nullptr){
        std::cout << "La inscripción no existe." << std::endl;
        return;
    }
    inscripciones->eliminarInscripcion(id, codigo);
    std::cout << "Inscripción eliminada exitosamente." << std::endl;
}

void Sistema::agregarNota(std::string id, std::string codigo, float calificacion){
    NodoInscripcion* nodo = inscripciones -> buscarInscripcion(id, codigo);
    if(nodo == nullptr){
        std::cout << "La inscripción no existe." << std::endl;
        return;
    }
    nodo -> inscripcion.agregarNota(calificacion);
    std::cout << "Nota agregada exitosamente." << std::endl;
}

void Sistema::mostrarNotasCurso(std::string id, std::string codigo){
    NodoInscripcion* nodo = inscripciones -> buscarInscripcion(id, codigo);
    if(nodo == nullptr){
        std::cout << "La inscripción no existe." << std::endl;
        return;
    }
    std::cout << "Notas del alumno " << nodo->inscripcion.getAlumno().getNombre()
              << " en el curso " << nodo->inscripcion.getCurso().getNombre() << ": ";
    nodo->inscripcion.mostrarNotas();
}

void Sistema::reporteAlumno(std::string id){
    NodoAlumno* nodoAlumno = alumnos -> buscarAlumnoId(id);
    if(nodoAlumno == nullptr){
        std::cout << "El alumno con ID " << id << " no está registrado." << std::endl;
        return;
    }
    std::cout << "Reporte del alumno: " << std::endl;
    nodoAlumno -> alumno.toString();
    std::cout << "Inscripciones:" << std::endl;
    NodoInscripcion* actual = inscripciones->getCabeza();
    bool tieneInscripciones = false;
    while(actual != nullptr){
        if(actual->inscripcion.getAlumno().getId() == id){
            tieneInscripciones = true;
            std::cout << "Curso: " << actual->inscripcion.getCurso().getNombre()
                      << " | Promedio: " << actual->inscripcion.calcularPromedio()
                      << " | Cantidad de Notas: " << actual->inscripcion.getCantidadNotas()
                      << std::endl;
        }
        actual = actual->siguiente;
    }
    if(!tieneInscripciones){
        std::cout << "El alumno no tiene inscripciones." << std::endl;
    }
}

void Sistema::reporteCurso(std::string codigo){
    NodoCurso* nodoCurso = cursos -> buscarCurso(codigo);
    if(nodoCurso == nullptr){
        std::cout << "El curso con código " << codigo << " no está registrado." << std::endl;
        return;
    }
    std::cout << "Reporte del curso: " << std::endl;
    nodoCurso -> curso.toString();
    std::cout << "Inscripciones:" << std::endl;
    NodoInscripcion* actual = inscripciones->getCabeza();
    bool tieneInscripciones = false;
    while(actual != nullptr){
        if(actual->inscripcion.getCurso().getCodigo() == codigo){
            tieneInscripciones = true;
            std::cout << "Alumno: " << actual->inscripcion.getAlumno().getNombre()
                      << " | Promedio: " << actual->inscripcion.calcularPromedio()
                      << " | Cantidad de Notas: " << actual->inscripcion.getCantidadNotas()
                      << std::endl;
        }
        actual = actual->siguiente;
    }
    if(!tieneInscripciones){
        std::cout << "El curso no tiene inscripciones." << std::endl;
    }
}

void Sistema::alumnosPorCarrera(std::string carrera){
    std::cout << "Alumnos de la carrera " << carrera << ":" << std::endl;
    NodoAlumno* actual = alumnos->getCabeza();
    bool tieneAlumnos = false;
    while(actual != nullptr){
        if(actual->alumno.getCarrera() == carrera){
            tieneAlumnos = true;
            actual->alumno.toString();
            std::cout << "------------------------" << std::endl;
        }
        actual = actual->siguiente;
    }
    if(!tieneAlumnos){
        std::cout << "No hay alumnos registrados en esta carrera." << std::endl;
    }
}

void Sistema::cursosPorAlumno(std::string id){
    NodoAlumno* nodoAlumno = alumnos -> buscarAlumnoId(id);
    if(nodoAlumno == nullptr){
        std::cout << "El alumno con ID " << id << " no está registrado." << std::endl;
        return;
    }
    std::cout << "Cursos del alumno " << nodoAlumno -> alumno.getNombre() << ":" << std::endl;
    NodoInscripcion* actual = inscripciones->getCabeza();
    bool tieneCursos = false;
    while(actual != nullptr){
        if(actual->inscripcion.getAlumno().getId() == id){
            tieneCursos = true;
            actual->inscripcion.getCurso().toString();
            std::cout << "------------------------" << std::endl;
        }
        actual = actual->siguiente;
    }
    if(!tieneCursos){
        std::cout << "El alumno no está inscrito en ningún curso." << std::endl;
    }
}

void Sistema::promedioAlumnoCurso(std::string id, std::string codigo){
    NodoInscripcion* nodo = inscripciones -> buscarInscripcion(id, codigo);
    if(nodo == nullptr){
        std::cout << "La inscripción no existe." << std::endl;
        return;
    }
    float promedio = nodo->inscripcion.calcularPromedio();
    std::cout << "El promedio del alumno " << nodo->inscripcion.getAlumno().getNombre()
              << " en el curso " << nodo->inscripcion.getCurso().getNombre()
              << " es: " << promedio << std::endl;
}

void Sistema::promedioAlumno(std::string id){
    NodoAlumno* nodoAlumno = alumnos -> buscarAlumnoId(id);
    if(nodoAlumno == nullptr){
        std::cout << "El alumno con ID " << id << " no está registrado." << std::endl;
        return;
    }
    NodoInscripcion* actual = inscripciones->getCabeza();
    float sumaPromedios = 0.0f;
    int cantidadCursos = 0;
    while(actual != nullptr){
        if(actual->inscripcion.getAlumno().getId() == id){
            sumaPromedios += actual->inscripcion.calcularPromedio();
            cantidadCursos++;
        }
        actual = actual->siguiente;
    }
    if(cantidadCursos == 0){
        std::cout << "El alumno no está inscrito en ningún curso." << std::endl;
        return;
    }
    float promedioGeneral = sumaPromedios / cantidadCursos;
    std::cout << "El promedio general del alumno " << nodoAlumno -> alumno.getNombre() 
              << " es: " << promedioGeneral << std::endl;
}