#ifndef DICCIONARIO_INVERSO_LISTA_H
#define DICCIONARIO_INVERSO_LISTA_H

#include "NodoLista.h"
#include <fstream>

class DiccionarioInversoLista
{
private:
    NodoLista *cabeza; // Puntero al primer nodo de la lista

public:
    // Constructor
    DiccionarioInversoLista();

    // Destructor
    ~DiccionarioInversoLista();

    // Método para insertar una palabra en el diccionario inverso
    void insertar(const string &palabra);

    // Método para buscar una palabra en el diccionario inverso
    bool buscar(const string &palabra) const;

    // Método para cargar el diccionario inverso desde un archivo
    bool cargarDiccionario(const string &archivo);

    // Método para obtener el puntaje de una palabra en el diccionario inverso
    int obtenerPuntaje(const string &palabra) const;

    bool estaVacia() const;
};

#endif // DICCIONARIO_INVERSO_LISTA_H
