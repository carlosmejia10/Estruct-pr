#ifndef SCRABBLE_H
#define SCRABBLE_H

#include "trie.h"
#include <string>
#include <vector>

class Scrabble
{
public:
    Scrabble();
    ~Scrabble();

    // Funciones relacionadas con el Trie
    void insertar_en_trie(const std::string &palabra);
    bool buscar_en_trie(const std::string &palabra) const;
    int obtener_puntaje_en_trie(const std::string &palabra) const;
    std::vector<std::string> buscar_prefijo_en_trie(const std::string &prefijo) const;
    bool cargar_diccionario_en_trie(const std::string &archivo);

    // Funciones relacionadas con el TrieInverso
    void insertar_en_trie_inverso(const std::string &palabra);
    bool buscar_en_trie_inverso(const std::string &palabra) const;
    int obtener_puntaje_en_trie_inverso(const std::string &palabra) const;
    std::vector<std::string> buscar_sufijo_en_trie_inverso(const std::string &sufijo) const;
    bool cargar_diccionario_en_trie_inverso(const std::string &archivo);

    bool trieInicializado;
    bool trieInversoInicializado;

private:
    Trie trie;    
};

#endif // SCRABBLE_H
