#include <iostream>
#include "TADs/grafoPalabras.cpp"
#include "TADs/trie.cpp"
#include "TADs/nodo.cpp"

    Trie trie;
    Grafo grafo;
    string prefijo = "DAD";
    void palabrasPorPrefijo(const string &prefijo)
{
    vector<string> palabras = trie.buscar_prefijo(prefijo);
    if (palabras.empty())
    {
        cout << "(Prefijo inválido) El prefijo '" << prefijo << "' no pudo encontrarse en el diccionario." << endl;
    }
    else
    {
        cout << "(Resultado exitoso) Las palabras que inician con el prefijo '" << prefijo << "' son:" << endl;
        for (const auto &palabra : palabras)
        {
            cout << palabra << endl;
            trie.obtener_puntaje(palabra);
            cout << endl;
        }
    }
}


int main() {

   


    // Construye el grafo a partir de un archivo de texto
    grafo.construir_grafo("dictionary.txt");

    // Busca las palabras en el grafo
    std::string palabra = "DAG";
    if (grafo.buscar(palabra)) {
        std::cout << "La palabra '" << palabra << "' se encontró en el grafo.\n";
    } else {
        std::cout << "La palabra '" << palabra << "' no se encontró en el grafo.\n";
    }
    std::vector<std::string> adjacencias = grafo.obtener_adjacencias(palabra);
if (!adjacencias.empty()) {
    std::cout << "Las palabras adyacentes a '" << palabra << "' son:\n";
    for (const auto& adjacente : adjacencias) {
        std::cout << adjacente << '\n';
    }
} else {
    std::cout << "La palabra '" << palabra << "' no tiene palabras adyacentes en el grafo.\n";
}

    palabra = "adios";
    if (grafo.buscar(palabra)) {
        std::cout << "La palabra '" << palabra << "' se encontró en el grafo.\n";
    } else {
        std::cout << "La palabra '" << palabra << "' no se encontró en el grafo.\n";
    }

    return 0;
}

