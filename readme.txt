
DESCRIPCION
------------
Sistema de gestion academica desarrollado en C++ que utiliza listas enlazadas manuales para administrar alumnos, cursos, inscripciones y calificaciones.

CARACTERISTICAS PRINCIPALES
---------------------------
- Gestion de alumnos (registro, busqueda, eliminacion)
- Gestion de cursos (creacion, busqueda, eliminacion)  
- Inscripciones de alumnos en cursos
- Registro de calificaciones (1.0 - 7.0)
- Reportes academicos y consultas
- Validacion de reglas academicas

ESTRUCTURA DE ARCHIVOS
----------------------
Alumno.h/cpp           - Clase Alumno
Curso.h/cpp            - Clase Curso
Inscripcion.h/cpp      - Clase Inscripcion
ListaAlumnos.h/cpp     - Lista enlazada de alumnos
ListaCursos.h/cpp      - Lista enlazada de cursos
ListaInscripciones.h/cpp - Lista enlazada de inscripciones
ListaNotas.h/cpp       - Lista enlazada de notas
Sistema.h/cpp          - Logica principal del sistema
main.cpp               - Programa principal con menus
NodoAlumno.h           - Nodo para lista de alumnos  
NodoCurso.h            - Nodo para lista de cursos
NodoInscripcion.h      - Nodo para lista de inscripciones
NodoNota.h             - Nodo para lista de notas

COMPILACION
-----------
Compilar con C++11:
g++ -std=c++11 -o sistema main.cpp Alumno.cpp Curso.cpp Inscripcion.cpp ListaAlumnos.cpp ListaCursos.cpp ListaInscripciones.cpp ListaNotas.cpp Sistema.cpp

EJECUCION
---------
./sistema

REQUISITOS
----------
- Compilador C++11 (g++ 4.8.1 o superior)
- Sistema operativo Linux, macOS o Windows con WSL
- Terminal que soporte caracteres UTF-8

USO DEL SISTEMA
---------------
1. Seleccionar opcion del menu principal
2. Seguir instrucciones en pantalla
3. Ingresar datos en los formatos solicitados
4. Las fechas deben usar formato dd-mm-aaaa
5. Las notas deben estar entre 1.0 y 7.0

VALIDACIONES INCLUIDAS
----------------------
- Formato de fecha valido
- Rango de notas (1.0 - 7.0)
- Capacidad maxima de cursos
- Misma carrera para inscripciones
- IDs unicos para alumnos y cursos
- Entradas numericas validadas
