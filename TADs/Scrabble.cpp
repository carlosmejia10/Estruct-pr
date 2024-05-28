#include "scrabble.h"
#include <algorithm>
#include <iostream>

// Constructor
Scrabble::Scrabble() : trieInicializado(false), trieInversoInicializado(false) {}

// Destructor
Scrabble::~Scrabble() {}

// Funciones relacionadas con el Trie
void Scrabble::insertar_en_trie(const std::string &palabra)
{
    trie.insertar(palabra);
}

bool Scrabble::buscar_en_trie(const std::string &palabra) const
{
    return trie.buscar(palabra);
}

int Scrabble::obtener_puntaje_en_trie(const std::string &palabra) const
{
    return trie.obtener_puntaje(palabra);
}

std::vector<std::string> Scrabble::buscar_prefijo_en_trie(const std::string &prefijo) const
{
    return trie.buscar_prefijo(prefijo);
}

bool Scrabble::cargar_diccionario_en_trie(const std::string &archivo)
{
    trieInicializado = true;
    return trie.cargar_diccionario(archivo);
}

// Funciones relacionadas con el TrieInverso
void Scrabble::insertar_en_trie_inverso(const std::string &palabra)
{
    trie.insertarInverso(palabra);
}

bool Scrabble::buscar_en_trie_inverso(const std::string &palabra) const
{
    return trie.existe(palabra);
}

int Scrabble::obtener_puntaje_en_trie_inverso(const std::string &palabra) const
{
    return trie.obtener_puntajeInverso(palabra);
}

std::vector<std::string> Scrabble::buscar_sufijo_en_trie_inverso(const std::string &sufijo) const
{
    return trie.buscar_sufijo(sufijo);
}

bool Scrabble::cargar_diccionario_en_trie_inverso(const std::string &archivo)
{
    trieInversoInicializado = true;
    return trie.cargar_diccionarioInverso(archivo);
}

// Funciones relacionadas con el Diccionario
void Scrabble::insertar_en_diccionario(const std::string &palabra)
{
    diccionario.insertarNormal(palabra);
}

bool Scrabble::buscar_en_diccionario(const std::string &palabra) const
{
    return diccionario.buscarNormal(palabra);
}

int Scrabble::obtener_puntaje_en_diccionario(const std::string &palabra) const
{
    return diccionario.obtenerPuntajeNormal(palabra);
}

bool Scrabble::cargar_diccionario(const std::string &archivo)
{
    return diccionario.cargarDiccionarioNormal(archivo);
}

// Funciones relacionadas con el DiccionarioInverso
void Scrabble::insertar_en_diccionario_inverso(const std::string &palabra)
{
    diccionario.insertarInverso(palabra);
}

bool Scrabble::buscar_en_diccionario_inverso(const std::string &palabra) const
{
    return diccionario.buscarInverso(palabra);
}

int Scrabble::obtener_puntaje_en_diccionario_inverso(const std::string &palabra) const
{
    return diccionario.obtenerPuntajeInverso(palabra);
}

bool Scrabble::cargar_diccionario_inverso(const std::string &archivo)
{
    return diccionario.cargarDiccionarioInverso(archivo);
}

// Funciones relacionadas con el Grafo
void Scrabble::generar_palabras(const std::string &letras)
{
    std::string letras_sin_comodin = letras;
    letras_sin_comodin.erase(std::remove(letras_sin_comodin.begin(), letras_sin_comodin.end(), '?'), letras_sin_comodin.end());
    std::sort(letras_sin_comodin.begin(), letras_sin_comodin.end());
    do
    {
        if (grafo.buscar(letras_sin_comodin))
        {
            std::cout << "Palabra: " << letras_sin_comodin << ", longitud: " << letras_sin_comodin.length() << ", Puntaje: " << obtenerPuntaje(letras_sin_comodin) << '\n';
        }
    } while (std::next_permutation(letras_sin_comodin.begin(), letras_sin_comodin.end()));

    if (letras.find('?') != std::string::npos)
    {
        std::string letras_copia = letras;
        std::replace(letras_copia.begin(), letras_copia.end(), '?', ' ');
        std::sort(letras_copia.begin(), letras_copia.end());
        do
        {
            for (char c = 'A'; c <= 'Z'; c++)
            {
                std::string reemplazo = letras_copia;
                std::replace(reemplazo.begin(), reemplazo.end(), ' ', c);
                if (grafo.buscar(reemplazo))
                {
                    std::cout << "Palabra: " << reemplazo << ", longitud: " << reemplazo.length() << ", Puntaje: " << obtenerPuntaje(reemplazo) << '\n';
                }
            }
        } while (std::next_permutation(letras_copia.begin(), letras_copia.end()));
    }
}

void Scrabble::construir_grafo_palabras(const std::string &nombreArchivo)
{
    grafo.construir_grafo(nombreArchivo);
}

int Scrabble::calcularPuntaje(char letra)
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
        return 1;
    case 'D':
    case 'd':
    case 'G':
    case 'g':
        return 2;
    case 'B':
    case 'b':
    case 'C':
    case 'c':
    case 'M':
    case 'm':
    case 'P':
    case 'p':
        return 3;
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
        return 4;
    case 'K':
    case 'k':
        return 5;
    case 'J':
    case 'j':
    case 'X':
    case 'x':
        return 8;
    case 'Q':
    case 'q':
    case 'Z':
    case 'z':
        return 10;
    default:
        return 0;
    }
}

int Scrabble::obtenerPuntaje(const std::string &palabra)
{
    int sum = 0;
    for (char c : palabra)
    {
        sum += calcularPuntaje(c);
    }
    return sum;
}
