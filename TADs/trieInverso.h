#ifndef TRIE_INVERSO_H
#define TRIE_INVERSO_H

#include <unordered_map>
#include <string>
#include <vector>
#include "nodo.h"

class TrieInverso
{
private:
    Nodo *raiz;
    int calcular_puntaje(char letra) const;

public:
    TrieInverso();
    ~TrieInverso();
    bool existe(const std::string &palabra) const;
    void insertar(const std::string &palabra);
    void buscar_palabras(Nodo *nodo, const std::string &palabra, std::vector<std::string> &palabras)const;
    std::vector<std::string> buscar_sufijo(const std::string &sufijo)const;
    int obtener_puntaje(const std::string &palabra) const;
    bool cargar_diccionarioInverso(const std::string &archivo);
};

#endif