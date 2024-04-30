// #include "trie.h"
// #include <iostream>

// void testTrie() {
//     Trie trie;

//     // Insert the word "alma" into the trie
//     trie.insertar("ALMA");
//     std::cout << "Inserted the word 'alma' into the trie." << std::endl;

//     // Calculate the total score of the word "alma"
//     int puntaje = trie.obtener_puntaje("ALMA");
//     std::cout << "The total score of the word 'alma' is: " << puntaje << std::endl;

//     // Search for the word "alma"
//     if (trie.buscar("ALMA")) {
//         std::cout << "The word 'alma' was found in the trie." << std::endl;
//     } else {
//         std::cout << "Error: The word 'alma' was not found in the trie." << std::endl;
//     }

//     // Search for a word that was not inserted
//     if (trie.buscar("notfound")) {
//         std::cout << "Error: The word 'notfound' was found in the trie." << std::endl;
//     } else {
//         std::cout << "The word 'notfound' was not found in the trie." << std::endl;
//     }
// }

// int main() {
//     testTrie();
//     return 0;
// }

#include "TADs/trie.cpp"
#include <iostream>
#include <vector> // Include the necessary header file for std::vector

int main()
{
    Trie trie;

    // Insertar palabras en el Trie
    trie.insertar("almacen");
    trie.insertar("almohada");
    trie.insertar("algoritmo");

    trie.insertar("alquiler");
    trie.insertar("sol");
    trie.insertar("soldado");
    trie.insertar("solvente");

    // Buscar palabras con el prefijo 'al'
    std::vector<std::string> palabras = trie.buscar_prefijo("al");
    std::cout << "Palabras con el prefijo 'al':\n";
    for (const std::string &palabra : palabras)
    {
        std::cout << palabra << "\n";
    }

    // Buscar palabras con el prefijo 'sol'
    palabras = trie.buscar_prefijo("sol");
    std::cout << "\nPalabras con el prefijo 'sol':\n";
    for (const std::string &palabra : palabras)
    {
        std::cout << palabra << "\n";
    }

    return 0;
}