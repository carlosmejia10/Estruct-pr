#include "Scrabble.h"

Scrabble::Scrabble() : trieInicializado(false), trieInversoInicializado(false) {}

Scrabble::~Scrabble() {}

// Funciones relacionadas con el Trie
void Scrabble::insertar_en_trie(const std::string &palabra)
{
    trie.insertar(palabra);
}

bool Scrabble::buscar_en_trie(const std::string &palabra) const
{
    return trie.buscar(palabra);
}

int Scrabble::obtener_puntaje_en_trie(const std::string &palabra) const
{
    return trie.obtener_puntaje(palabra);
}

std::vector<std::string> Scrabble::buscar_prefijo_en_trie(const std::string &prefijo) const
{
    return trie.buscar_prefijo(prefijo);
}

bool Scrabble::cargar_diccionario_en_trie(const std::string &archivo)
{
    trieInicializado = true;
    return trie.cargar_diccionario(archivo);
}

// Funciones relacionadas con el TrieInverso
void Scrabble::insertar_en_trie_inverso(const std::string &palabra)
{
    trie.insertarInverso(palabra);
}

int Scrabble::obtener_puntaje_en_trie_inverso(const std::string &palabra) const
{
    return trie.obtener_puntajeInverso(palabra);
}

std::vector<std::string> Scrabble::buscar_sufijo_en_trie_inverso(const std::string &sufijo) const
{
    return trie.buscar_sufijo(sufijo);
}

bool Scrabble::buscar_en_trie_inverso(const std::string &palabra) const{
    return trie.existe(palabra);
}

bool Scrabble::cargar_diccionario_en_trie_inverso(const std::string &archivo)
{
    trieInversoInicializado = true;
    return trie.cargar_diccionarioInverso(archivo);
}
int calcularPuntaje(char letra)
{
    switch (letra)
    {
    case 'E':
    case 'e':
    case 'A':
    case 'a':
    case 'I':
    case 'i':
    case 'O':
    case 'o':
    case 'N':
    case 'n':
    case 'R':
    case 'r':
    case 'T':
    case 't':
    case 'L':
    case 'l':
    case 'S':
    case 's':
    case 'U':
    case 'u':
        return 1;
    case 'D':
    case 'd':
    case 'G':
    case 'g':
        return 2;
    case 'B':
    case 'b':
    case 'C':
    case 'c':
    case 'M':
    case 'm':
    case 'P':
    case 'p':
        return 3;
    case 'F':
    case 'f':
    case 'H':
    case 'h':
    case 'V':
    case 'v':
    case 'W':
    case 'w':
    case 'Y':
    case 'y':
        return 4;
    case 'K':
    case 'k':
        return 5;
    case 'J':
    case 'j':
    case 'X':
    case 'x':
        return 8;
    case 'Q':
    case 'q':
    case 'Z':
    case 'z':
        return 10;
    default:
        return 0;
    }
}

int obtenerPuntaje (const std::string &palabra){
    int sum = 0;
    for (char c : palabra){
         sum += calcularPuntaje(c);
    }
    return sum;
}

void Scrabble::posibles_palabras(const std::string& letras) {
    std::string letras_ordenadas = letras;
    std::sort(letras_ordenadas.begin(), letras_ordenadas.end());

    do {
        std::string palabra = letras_ordenadas;
        size_t pos = palabra.find('?');
        if (pos != std::string::npos) {
            for (char c = 'a'; c <= 'z'; c++) {
                palabra[pos] = c;
                if (grafo.buscar(palabra)) {
                    int longitud = palabra.size();
                    int puntaje = obtenerPuntaje(palabra);
                    std::cout << "Palabra: " << palabra << ", Longitud: " << longitud << ", Puntaje: " << puntaje << std::endl;
                }
            }
        } else if (grafo.buscar(palabra)) {
            int longitud = palabra.size();
            int puntaje = obtenerPuntaje(palabra);
            std::cout << "Palabra: " << palabra << ", Longitud: " << longitud << ", Puntaje: " << puntaje << std::endl;
        }
    } while (std::next_permutation(letras_ordenadas.begin(), letras_ordenadas.end()));
}