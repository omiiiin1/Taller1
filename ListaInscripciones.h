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
        NodoInscripcion* buscarInscripcion(std::string);
        int getCantidad();
        void mostrarInscripciones();

        NodoInscripcion* getCabeza();
        NodoInscripcion* getCola();
};
