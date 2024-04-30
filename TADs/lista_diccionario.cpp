#include "lista_diccionario.h"

ListaDiccionario::ListaDiccionario() : cabeza(nullptr) {}

ListaDiccionario::~ListaDiccionario()
{
    // Liberar la memoria de todos los nodos
    NodoLista *actual = cabeza;
    while (actual != nullptr)
    {
        NodoLista *siguiente = actual->siguiente;
        delete actual;
        actual = siguiente;
    }
}

void ListaDiccionario::insertar(const string &palabra)
{
    // Insertar al inicio de la lista
    NodoLista *nuevoNodo = new NodoLista(palabra);
    nuevoNodo->siguiente = cabeza;
    cabeza = nuevoNodo;
}

bool ListaDiccionario::buscar(const string &palabra) const
{
    // Buscar la palabra en la lista
    NodoLista *actual = cabeza;
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

int ListaDiccionario::obtener_puntaje(const string &palabra) const
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

bool ListaDiccionario::cargar_diccionario(const string &archivo)
{
    ifstream archivo_dicc(archivo);
    if (!archivo_dicc)
    {
        return false; // Devuelve false si no se pudo abrir el archivo
    }

    string palabra;
    while (archivo_dicc >> palabra)
    {
        insertar(palabra);
    }

    return true; // Devuelve true si la carga del diccionario fue exitosa
}
