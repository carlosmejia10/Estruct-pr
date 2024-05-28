#include <map>
#include <vector>
#include <string>
#include "grafoPalabras.h"
#include <iostream>
#include <fstream>

void Grafo::construir_grafo(const std::string& nombre_archivo) {



    std::ifstream archivo(nombre_archivo);
    if (!archivo) {
        std::cerr << "No se pudo abrir el archivo " << nombre_archivo << std::endl;
        return;
    }
    trie.cargar_diccionario(nombre_archivo);
    std::string palabra;
while (std::getline(archivo, palabra)) {
    adjacencias[palabra] = std::vector<std::string>();
    for (int i = 0; i < palabra.size(); i++) {
        std::string palabra_generada = palabra;
        for (char c = 'A'; c <= 'Z'; c++) {
    palabra_generada[i] = c;
    if (palabra_generada != palabra && trie.buscar(palabra_generada)) {
        adjacencias[palabra].push_back(palabra_generada);
    }
}
    }
}
archivo.close();
}

std::vector<std::string> Grafo::obtener_adjacencias(const std::string& palabra) const {
    if (adjacencias.count(palabra) > 0) {
        return adjacencias.at(palabra);
    } else {
        return std::vector<std::string>();
    }
}

bool Grafo::buscar(const std::string& palabra) const {
    std::string palabra_mayusculas = palabra;
    std::cout << "Buscando palabra en el mapa: " << palabra_mayusculas << std::endl;
    return adjacencias.count(palabra_mayusculas) > 0;
}