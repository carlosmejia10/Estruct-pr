#ifndef NODO_LISTA_H
#define NODO_LISTA_H

#include <string>

using namespace std;

struct NodoLista
{
    string palabra;
    NodoLista *siguiente;

    // Constructor
    NodoLista(const string &pal) : palabra(pal), siguiente(nullptr) {}
};

#endif // NODO_LISTA_H
