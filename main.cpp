#include <iostream>
#include "Sistema.h"
#include <string>

using namespace std;

void mostrarMenuPrincipal();
void mostrarMenuAlumnos();
void mostrarMenuCursos();
void mostrarMenuInscripciones();
void mostrarMenuReportes();

int main() {
    Sistema sistema;
    int opcion;
    string id, nombre, apellido, carrera, fechaIngreso, profesor, codigoAlumno, codigoCurso;
    int capacidad;
    float calificacion;

    do {
        mostrarMenuPrincipal();
        cout << "Seleccione una opción: ";
        cin >> opcion;
        cin.ignore();

        switch (opcion) {
            case 1: {
                int opcionAlumnos;
                do {
                    mostrarMenuAlumnos();
                    cout << "Seleccione una opción: ";
                    cin >> opcionAlumnos;
                    cin.ignore();

                    switch (opcionAlumnos) {
                        case 1:
                            cout << "Ingrese ID: ";
                            getline(cin, id);
                            cout << "Ingrese Nombre: ";
                            getline(cin, nombre);
                            cout << "Ingrese Apellido: ";
                            getline(cin, apellido);
                            cout << "Ingrese Carrera: ";
                            getline(cin, carrera);
                            cout << "Ingrese Fecha de Ingreso: ";
                            getline(cin, fechaIngreso);
                            sistema.registrarAlumno(id, nombre, apellido, carrera, fechaIngreso);
                            break;
                        case 2:
                            cout << "Ingrese ID del alumno a buscar: ";
                            getline(cin, id);
                            sistema.buscarAlumno(id);
                            break;
                        case 3:
                            cout << "Ingrese ID del alumno a eliminar: ";
                            getline(cin, id);
                            sistema.eliminarAlumno(id);
                            break;
                        case 0:
                            break;
                        default:
                            cout << "Opción inválida. Intente nuevamente." << endl;
                    }
                } while (opcionAlumnos != 0);
                break;
            }
            case 2: {
                int opcionCursos;
                do {
                    mostrarMenuCursos();
                    cout << "Seleccione una opción: ";
                    cin >> opcionCursos;
                    cin.ignore();

                    switch (opcionCursos) {
                        case 1:
                            cout << "Ingrese Código del curso: ";
                            getline(cin, codigoCurso);
                            cout << "Ingrese Nombre del curso: ";
                            getline(cin, nombre);
                            cout << "Ingrese Capacidad del curso: ";
                            cin >> capacidad;
                            cin.ignore();
                            cout << "Ingrese Carrera del curso: ";
                            getline(cin, carrera);
                            cout << "Ingrese Nombre del profesor: ";
                            getline(cin, profesor);
                            sistema.registrarCurso(codigoCurso, nombre, capacidad, carrera, profesor);
                            break;
                        case 2:
                            cout << "Ingrese Código del curso: ";
                            getline(cin, codigoCurso);
                            sistema.buscarCurso(codigoCurso);
                            break;
                        case 3:
                            cout << "Ingrese Código del curso a eliminar: ";
                            getline(cin, codigoCurso);
                            sistema.eliminarCurso(codigoCurso);
                            break;
                        case 0:
                            break;
                        default:
                            cout << "Opción inválida. Intente nuevamente." << endl;
                            break;
                    }
                } while (opcionCursos != 0);
                break;
            }
            case 3: {
                int opcionInscripciones;
                do {
                    mostrarMenuInscripciones();
                    cout << "Seleccione una opción: ";
                    cin >> opcionInscripciones;
                    cin.ignore();

                    switch (opcionInscripciones) {
                        case 1:
                            cout << "Ingrese ID del alumno: ";
                            getline(cin, codigoAlumno);
                            cout << "Ingrese Código del curso: ";
                            getline(cin, codigoCurso);
                            sistema.inscribirAlumno(codigoAlumno, codigoCurso);
                            break;
                        case 2:
                            cout << "Ingrese ID del alumno: ";
                            getline(cin, codigoAlumno);
                            cout << "Ingrese Código del curso: ";
                            getline(cin, codigoCurso);
                            sistema.eliminarInscripcion(codigoAlumno, codigoCurso);
                            break;
                        case 3:
                            cout << "Ingrese ID del alumno: ";
                            getline(cin, codigoAlumno);
                            cout << "Ingrese Código del curso: ";
                            getline(cin, codigoCurso);
                            cout << "Ingrese la calificación (1.0 - 7.0): ";
                            cin >> calificacion;
                            cin.ignore();
                            sistema.agregarNota(codigoAlumno, codigoCurso, calificacion);
                            break;
                        case 4:
                            cout << "Ingrese ID del alumno: ";
                            getline(cin, codigoAlumno);
                            cout << "Ingrese Código del curso: ";
                            getline(cin, codigoCurso);
                            sistema.mostrarNotasCurso(codigoAlumno, codigoCurso);
                            break;
                        case 0:
                            break;
                        default:
                            cout << "Opción inválida. Intente nuevamente." << endl;
                    }
                } while (opcionInscripciones != 0);
                break;
            }
            case 4: {
                int opcionReportes;
                do {
                    mostrarMenuReportes();
                    cout << "Seleccione una opción: ";
                    cin >> opcionReportes;
                    cin.ignore();

                    switch (opcionReportes) {
                        case 1:
                            cout << "Ingrese ID del alumno: ";
                            getline(cin, codigoAlumno);
                            sistema.reporteAlumno(codigoAlumno);
                            break;
                        case 2:
                            cout << "Ingrese Código del curso: ";
                            getline(cin, codigoCurso);
                            sistema.reporteCurso(codigoCurso);
                            break;
                        case 3:
                            cout << "Ingrese Carrera: ";
                            getline(cin, carrera);
                            sistema.alumnosPorCarrera(carrera);
                            break;
                        case 4:
                            cout << "Ingrese ID del alumno: ";
                            getline(cin, codigoAlumno);
                            sistema.cursosPorAlumno(codigoAlumno);
                            break;
                        case 5:
                            cout << "Ingrese ID del alumno: ";
                            getline(cin, codigoAlumno);
                            cout << "Ingrese Código del curso: ";
                            getline(cin, codigoCurso);
                            sistema.promedioAlumnoCurso(codigoAlumno, codigoCurso);
                            break;
                        case 6:
                            cout << "Ingrese ID del alumno: ";
                            getline(cin, codigoAlumno);
                            sistema.promedioAlumno(codigoAlumno);
                            break;
                        case 0:
                            break;
                        default:
                            cout << "Opción inválida. Intente nuevamente." << endl;
                    }
                } while (opcionReportes != 0);
                break;
            }
            case 0:
                cout << "Saliendo del sistema." << endl;
                break;
            default:
                cout << "Opción inválida. Intente nuevamente." << endl;
                break;
        }
    } while (opcion != 0);
    return 0;
}

void mostrarMenuPrincipal() {
    cout << "\n=== SISTEMA DE GESTION ACADEMICA ===" << endl;
    cout << "1. Gestion de Alumnos" << endl;
    cout << "2. Gestion de Cursos" << endl;
    cout << "3. Inscripciones y Notas" << endl;
    cout << "4. Reportes" << endl;
    cout << "0. Salir" << endl;
    cout << "====================================" << endl;
}

void mostrarMenuAlumnos() {
    cout << "\n--- GESTION DE ALUMNOS ---" << endl;
    cout << "1. Registrar alumno" << endl;
    cout << "2. Buscar alumno" << endl;
    cout << "3. Eliminar alumno" << endl;
    cout << "0. Volver al menu principal" << endl;
    cout << "--------------------------" << endl;
}

void mostrarMenuCursos() {
    cout << "\n--- GESTION DE CURSOS ---" << endl;
    cout << "1. Registrar curso" << endl;
    cout << "2. Buscar curso" << endl;
    cout << "3. Eliminar curso" << endl;
    cout << "0. Volver al menu principal" << endl;
    cout << "--------------------------" << endl;
}

void mostrarMenuInscripciones() {
    cout << "\n--- INSCRIPCIONES Y NOTAS ---" << endl;
    cout << "1. Inscribir alumno en curso" << endl;
    cout << "2. Eliminar inscripcion" << endl;
    cout << "3. Agregar nota" << endl;
    cout << "0. Volver al menu principal" << endl;
    cout << "-----------------------------" << endl;
}

void mostrarMenuReportes() {
    cout << "\n--- REPORTES " << endl;
    cout << "1. Reporte de alumno" << endl;
    cout << "2. Reporte de curso" << endl;
    cout << "3. Alumnos por carrera" << endl;
    cout << "4. Cursos por alumno" << endl;
    cout << "5. Promedio alumno en curso" << endl;
    cout << "6. Promedio general alumno" << endl;
    cout << "7. Mostrar notas de curso" << endl;
    cout << "0. Volver al menu principal" << endl;
    cout << "----------------" << endl;
}
