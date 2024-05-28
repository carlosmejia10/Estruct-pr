#include "DiccionarioLista.h"

// Constructor
Diccionario::Diccionario() : cabezaNormal(nullptr), cabezaInverso(nullptr) {}

// Destructor
Diccionario::~Diccionario()
{
    // Liberar la memoria de todos los nodos de la lista normal
    NodoLista *actual = cabezaNormal;
    while (actual != nullptr)
    {
        NodoLista *siguiente = actual->siguiente;
        delete actual;
        actual = siguiente;
    }

    // Liberar la memoria de todos los nodos de la lista inversa
    actual = cabezaInverso;
    while (actual != nullptr)
    {
        NodoLista *siguiente = actual->siguiente;
        delete actual;
        actual = siguiente;
    }
}

// Método para insertar una palabra en el diccionario normal
void Diccionario::insertarNormal(const std::string &palabra)
{
    NodoLista *nuevoNodo = new NodoLista(palabra);
    nuevoNodo->siguiente = cabezaNormal;
    cabezaNormal = nuevoNodo;
}

// Método para insertar una palabra en el diccionario inverso
void Diccionario::insertarInverso(const std::string &palabra)
{
    NodoLista *nuevoNodo = new NodoLista(palabra);
    nuevoNodo->siguiente = cabezaInverso;
    cabezaInverso = nuevoNodo;
}

// Método para buscar una palabra en el diccionario normal
bool Diccionario::buscarNormal(const std::string &palabra) const
{
    NodoLista *actual = cabezaNormal;
    while (actual != nullptr)
    {
        if (actual->palabra == palabra)
        {
            return true;
        }
        actual = actual->siguiente;
    }
    return false;
}

// Método para buscar una palabra en el diccionario inverso
bool Diccionario::buscarInverso(const std::string &palabra) const
{
    NodoLista *actual = cabezaInverso;
    while (actual != nullptr)
    {
        if (actual->palabra == palabra)
        {
            return true;
        }
        actual = actual->siguiente;
    }
    return false;
}

// Método para obtener el puntaje de una palabra en el diccionario normal
int Diccionario::obtenerPuntajeNormal(const std::string &palabra) const
{
    int puntajeTotal = 0;
    for (char letra : palabra)
    {
        switch (letra)
        {
        case 'E':
        case 'e':
        case 'A':
        case 'a':
        case 'I':
        case 'i':
        case 'O':
        case 'o':
        case 'N':
        case 'n':
        case 'R':
        case 'r':
        case 'T':
        case 't':
        case 'L':
        case 'l':
        case 'S':
        case 's':
        case 'U':
        case 'u':
            puntajeTotal += 1;
            break;
        case 'D':
        case 'd':
        case 'G':
        case 'g':
            puntajeTotal += 2;
            break;
        case 'B':
        case 'b':
        case 'C':
        case 'c':
        case 'M':
        case 'm':
        case 'P':
        case 'p':
            puntajeTotal += 3;
            break;
        case 'F':
        case 'f':
        case 'H':
        case 'h':
        case 'V':
        case 'v':
        case 'W':
        case 'w':
        case 'Y':
        case 'y':
            puntajeTotal += 4;
            break;
        case 'K':
        case 'k':
            puntajeTotal += 5;
            break;
        case 'J':
        case 'j':
        case 'X':
        case 'x':
            puntajeTotal += 8;
            break;
        case 'Q':
        case 'q':
        case 'Z':
        case 'z':
            puntajeTotal += 10;
            break;
        default:
            break;
        }
    }
    return puntajeTotal;
}

// Método para obtener el puntaje de una palabra en el diccionario inverso
int Diccionario::obtenerPuntajeInverso(const std::string &palabra) const
{
    int puntajeTotal = 0;
    for (char letra : palabra)
    {
        switch (letra)
        {
        case 'E':
        case 'e':
        case 'A':
        case 'a':
        case 'I':
        case 'i':
        case 'O':
        case 'o':
        case 'N':
        case 'n':
        case 'R':
        case 'r':
        case 'T':
        case 't':
        case 'L':
        case 'l':
        case 'S':
        case 's':
        case 'U':
        case 'u':
            puntajeTotal += 1;
            break;
        case 'D':
        case 'd':
        case 'G':
        case 'g':
            puntajeTotal += 2;
            break;
        case 'B':
        case 'b':
        case 'C':
        case 'c':
        case 'M':
        case 'm':
        case 'P':
        case 'p':
            puntajeTotal += 3;
            break;
        case 'F':
        case 'f':
        case 'H':
        case 'h':
        case 'V':
        case 'v':
        case 'W':
        case 'w':
        case 'Y':
        case 'y':
            puntajeTotal += 4;
            break;
        case 'K':
        case 'k':
            puntajeTotal += 5;
            break;
        case 'J':
        case 'j':
        case 'X':
        case 'x':
            puntajeTotal += 8;
            break;
        case 'Q':
        case 'q':
        case 'Z':
        case 'z':
            puntajeTotal += 10;
            break;
        default:
            break;
        }
    }
    return puntajeTotal;
}

// Método para cargar el diccionario normal desde un archivo
bool Diccionario::cargarDiccionarioNormal(const std::string &archivo)
{
    std::ifstream archivo_dicc(archivo);
    if (!archivo_dicc)
    {
        return false;
    }

    std::string palabra;
    while (archivo_dicc >> palabra)
    {
        insertarNormal(palabra);
    }

    return true;
}

// Método para cargar el diccionario inverso desde un archivo
bool Diccionario::cargarDiccionarioInverso(const std::string &archivo)
{
    std::ifstream archivo_dicc(archivo);
    if (!archivo_dicc)
    {
        return false;
    }

    std::string palabra;
    while (archivo_dicc >> palabra)
    {
        insertarInverso(palabra);
    }

    return true;
}

bool Diccionario::estaVaciaNormal() const
{
    return cabezaNormal == nullptr;
}

bool Diccionario::estaVaciaInverso() const
{
    return cabezaInverso == nullptr;
}
