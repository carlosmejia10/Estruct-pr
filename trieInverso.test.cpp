#include "TADs/trieInverso.cpp"
#include <iostream>
#include <string>

using namespace std;

int main()
{
    TrieInverso trie;

    // Insertar palabras en el Trie
    trie.insertar("hola");
    trie.insertar("adios");
    trie.insertar("bien");
    trie.insertar("caen");
    trie.insertar("bienvenido");
    trie.insertar("hombre");
    trie.insertar("mujer");

    // Buscar palabras que terminan con un sufijo
    vector<string> palabras = trie.buscar_sufijo("en");
    cout << "Palabras que terminan con 'en':\n";
    for (const string &palabra : palabras)
    {
        cout << palabra << '\n';
    }

    // Obtener el puntaje de una palabra
    string palabra = "bienvenido";
    int puntaje = trie.obtener_puntaje(palabra);
    cout << "Puntaje de " << palabra << ":" << puntaje << '\n';

    return 0;
}