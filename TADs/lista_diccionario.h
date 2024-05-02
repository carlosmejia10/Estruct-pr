#ifndef DICCIONARIO_LISTA_H
#define DICCIONARIO_LISTA_H

#include "NodoLista.h"
#include <fstream>

class DiccionarioLista
{
private:
    NodoLista *cabeza; // Puntero al inicio de la lista

public:
    // Constructor
    DiccionarioLista();

    // Destructor
    ~DiccionarioLista();

    // Método para insertar una palabra en el diccionario
    void insertar(const string &palabra);

    // Método para buscar una palabra en el diccionario
    bool buscar(const string &palabra) const;

    // Método para obtener el puntaje de una palabra en el diccionario
    int obtenerPuntaje(const string &palabra) const;

    // Método para cargar el diccionario desde un archivo
    bool cargarDiccionario(const string &archivo);

    bool estaVacia() const;
};

#endif // DICCIONARIO_LISTA_H
