#include "NodoInscripcion.h"

class ListaInscripciones{
    private:
        NodoInscripcion* cabeza;
        NodoInscripcion* cola;
        int cantidad;
    public:
        ListaInscripciones();
        ~ListaInscripciones();
        void agregarInscripcion(Inscripcion);
        void eliminarInscripcion(Inscripcion);
        NodoInscripcion* buscarInscripcion(std::string, std::string);
        int getCantidad();
        void mostrarInscripciones();

        int contarInscripciones(std::string);

        NodoInscripcion* getCabeza();
        NodoInscripcion* getCola();
};
