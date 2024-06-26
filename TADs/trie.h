#ifndef TRIE_H
#define TRIE_H

#include "nodo.h"
#include <vector>
#include <string>

class Trie
{
private:
    Nodo *raiz;
    Nodo *raizInverso;
    int calcular_puntaje(char letra) const;

public:
    Trie();
    ~Trie();
    void insertar(const std::string &palabra);
    bool buscar(const std::string &palabra) const;
    int obtener_puntaje(const std::string &palabra) const;
    std::vector<std::string> buscar_prefijo(const std::string &prefijo) const;
    void buscar_palabras(Nodo *nodo, const std::string &palabra, std::vector<std::string> &palabras) const;
    bool cargar_diccionario(const std::string &archivo);

    // inverso
    void insertarInverso(const string &palabra);
    vector<string> buscar_sufijo(const string &sufijo) const;
    void buscar_palabrasInverso(Nodo *nodo, const string &palabra, vector<string> &palabras) const;
    bool existe(const string &palabra) const;
    bool cargar_diccionarioInverso(const string &archivo);
    int obtener_puntajeInverso(const string &palabra) const;
};

#endif