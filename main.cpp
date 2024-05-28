#include <iostream>
#include "TADs/grafoPalabras.cpp"
#include "TADs/trie.cpp"
#include "TADs/nodo.cpp"

    Trie trie;
    Grafo grafo;
    string prefijo = "DAD";
    string letras = "ads?";
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

void generar_palabras(Grafo& grafo, const std::string& letras) {
    std::string letras_sin_comodin = letras;
    letras_sin_comodin.erase(std::remove(letras_sin_comodin.begin(), letras_sin_comodin.end(), '?'), letras_sin_comodin.end());
    std::sort(letras_sin_comodin.begin(), letras_sin_comodin.end());
    do {
        if (grafo.buscar(letras_sin_comodin)) {
            std::cout << "Palabra: " << letras_sin_comodin << ", longitud: " << letras_sin_comodin.length() << '\n';
        }
    } while (std::next_permutation(letras_sin_comodin.begin(), letras_sin_comodin.end()));

    if (letras.find('?') != std::string::npos) {
        std::string letras_copia = letras;
        std::replace(letras_copia.begin(), letras_copia.end(), '?', ' ');
        std::sort(letras_copia.begin(), letras_copia.end());
        do {
            for (char c = 'A'; c <= 'Z'; c++) {
                std::string reemplazo = letras_copia;
                std::replace(reemplazo.begin(), reemplazo.end(), ' ', c);
                if (grafo.buscar(reemplazo)) {
                    std::cout << "Palabra: " << reemplazo << ", longitud: " << reemplazo.length() << '\n';
                }
            }
        } while (std::next_permutation(letras_copia.begin(), letras_copia.end()));
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

    generar_palabras( grafo,  letras);

    return 0;
}

