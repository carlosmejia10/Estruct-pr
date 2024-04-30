#ifndef LISTA_DICCIONARIO_H
#define LISTA_DICCIONARIO_H

#include <string>
#include <fstream>
#include "NodoLista.h"

using namespace std;

class ListaDiccionario
{
private:
    NodoLista *lista;

public:
    ListaDiccionario();
    ~ListaDiccionario();

    void insertar(const string &palabra);
    bool buscar(const string &palabra) const;
    int obtener_puntaje(const string &palabra) const;
    bool cargar_diccionario(const string &archivo);
    bool estaVacia() const
    {
        return lista == nullptr;
    }
};

#endif // LISTA_DICCIONARIO_H
