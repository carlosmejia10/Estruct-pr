#ifndef LISTA_INVERSO_H
#define LISTA_INVERSO_H

#include <string>
#include <vector>
#include "NodoLista.h"

using namespace std;

class DiccionarioInverso
{
private:
    NodoLista *lista; // Vector de listas enlazadas

public:
    DiccionarioInverso();
    ~DiccionarioInverso();

    void insertar(const string &palabra);
    bool buscar(const string &palabra) const;
    int obtenerPuntaje(const string &palabra) const;
    bool cargarDiccionario(const string &archivo);
    bool estaVacia() const
    {
        return lista == nullptr;
    }
};

#endif // LISTA_INVERSO_H
