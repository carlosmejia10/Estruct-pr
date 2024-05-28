#ifndef GRAFO_H
#define GRAFO_H

#include <map>
#include <vector>
#include <string>
#include "trie.h"

class Grafo {
private:
    std::map<std::string, std::vector<std::string>> adjacencias;
    Trie trie;

public:
    void construir_grafo(const std::string& nombre_archivo) ;
    std::vector<std::string> obtener_adjacencias(const std::string& palabra) const;
    bool buscar(const std::string& palabra) const;
};

#endif // GRAFO_H