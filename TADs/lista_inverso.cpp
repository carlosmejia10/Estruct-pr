#include "lista_inverso.h"
#include <fstream>
#include <algorithm>

DiccionarioInverso::DiccionarioInverso() {}

DiccionarioInverso::~DiccionarioInverso()
{
    // Liberar la memoria de todos los nodos
    for (NodoPalabra *lista : listas)
    {
        NodoPalabra *actual = lista;
        while (actual != nullptr)
        {
            NodoPalabra *siguiente = actual->siguiente;
            delete actual;
            actual = siguiente;
        }
    }
}

void DiccionarioInverso::insertar(const string &palabra)
{
    int longitud = palabra.length();

    // Asegurarse de que haya suficientes elementos en el vector
    if (longitud >= listas.size())
    {
        listas.resize(longitud + 1, nullptr);
    }

    // Insertar la palabra al inicio de la lista correspondiente a su longitud
    NodoPalabra *nuevoNodo = new NodoPalabra(palabra);
    nuevoNodo->siguiente = listas[longitud];
    listas[longitud] = nuevoNodo;
}

bool DiccionarioInverso::buscar(const string &palabra) const
{
    // Iterar sobre todas las listas en el vector
    for (const auto &lista : listas)
    {
        // Verificar si la lista es nula
        if (lista == nullptr)
        {
            continue; // Saltar a la siguiente iteración si la lista es nula
        }

        // Buscar la palabra en la lista actual
        NodoPalabra *actual = lista;
        while (actual != nullptr)
        {
            if (actual->palabra == palabra)
            {
                return true; // La palabra existe en la lista
            }
            actual = actual->siguiente;
        }
    }

    return false; // La palabra no existe en ninguna de las listas
}

int DiccionarioInverso::obtenerPuntaje(const string &palabra) const
{
    // Calcular el puntaje de la palabra
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
            // Si la letra no es válida, se ignora
            break;
        }
    }
    return puntajeTotal;
}

bool DiccionarioInverso::cargarDiccionario(const string &archivo)
{
    ifstream archivo_dicc(archivo);
    if (!archivo_dicc)
    {
        return false; // Devuelve false si no se pudo abrir el archivo
    }

    string palabra;
    while (archivo_dicc >> palabra)
    {
        // Invierte la palabra
        std::reverse(palabra.begin(), palabra.end());

        // Insertar la palabra invertida en el diccionario inverso
        insertar(palabra);
    }

    return true; // Devuelve true si la carga del diccionario fue exitosa
}

