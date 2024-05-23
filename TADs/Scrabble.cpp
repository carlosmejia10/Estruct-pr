#include "Scrabble.h"

Scrabble::Scrabble() : trieInicializado(false), trieInversoInicializado(false) {}

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

int Scrabble::obtener_puntaje_en_trie_inverso(const std::string &palabra) const
{
    return trie.obtener_puntajeInverso(palabra);
}

std::vector<std::string> Scrabble::buscar_sufijo_en_trie_inverso(const std::string &sufijo) const
{
    return trie.buscar_sufijo(sufijo);
}

bool Scrabble::buscar_en_trie_inverso(const std::string &palabra) const{
    return trie.existe(palabra);
}

bool Scrabble::cargar_diccionario_en_trie_inverso(const std::string &archivo)
{
    trieInversoInicializado = true;
    return trie.cargar_diccionarioInverso(archivo);
}
