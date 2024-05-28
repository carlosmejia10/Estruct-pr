#ifndef SCRABBLE_H
#define SCRABBLE_H

#include "trie.h"
#include "DiccionarioLista.h"
#include "grafoPalabras.h"
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

    // Funciones relacionadas con el Diccionario
    void insertar_en_diccionario(const std::string &palabra);
    bool buscar_en_diccionario(const std::string &palabra) const;
    int obtener_puntaje_en_diccionario(const std::string &palabra) const;
    bool cargar_diccionario(const std::string &archivo);

    // Funciones relacionadas con el DiccionarioInverso
    void insertar_en_diccionario_inverso(const std::string &palabra);
    bool buscar_en_diccionario_inverso(const std::string &palabra) const;
    int obtener_puntaje_en_diccionario_inverso(const std::string &palabra) const;
    bool cargar_diccionario_inverso(const std::string &archivo);

    // Funciones relacionadas con el Grafo
    void generar_palabras(const std::string &letras);
    void construir_grafo_palabras(const std::string &nombreArchivo);

    int calcularPuntaje(char letra);
    int obtenerPuntaje(const std::string &palabra);

    bool trieInicializado;
    bool trieInversoInicializado;

private:
    Trie trie;
    Diccionario diccionario;
    Grafo grafo;
};

#endif // SCRABBLE_H
