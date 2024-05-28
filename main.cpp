#include <iostream>
#include <string>
#include <vector>
#include <fstream>
#include "TADs/scrabble.h"

using namespace std;

// Funciones para gestionar diccionario con listas
void inicializarDiccionarioLista(Scrabble &scrabble, const string &archivo)
{
    if (scrabble.cargar_diccionario(archivo))
    {
        cout << "(Diccionario ya inicializado) El diccionario ya ha sido inicializado." << endl;
        return;
    }
    bool exito = scrabble.cargar_diccionario(archivo);
    if (exito)
    {
        cout << "(Resultado exitoso) El diccionario se ha inicializado correctamente." << endl;
    }
    else
    {
        cout << "(Archivo no existe) El archivo no existe o no puede ser leído." << endl;
    }
}

void inicializarDiccionarioInversoLista(Scrabble &scrabble, const string &archivo)
{
    if (scrabble.cargar_diccionario_inverso(archivo))
    {
        cout << "(Diccionario inverso ya inicializado) El diccionario inverso ya ha sido inicializado." << endl;
        return;
    }
    bool exito = scrabble.cargar_diccionario_inverso(archivo);
    if (exito)
    {
        cout << "(Resultado exitoso) El diccionario inverso se ha inicializado correctamente." << endl;
    }
    else
    {
        cout << "(Archivo no existe) El archivo no existe o no puede ser leído." << endl;
    }
}

// Funciones para gestionar diccionario con tries
void inicializarDiccionarioTrie(Scrabble &scrabble, const string &archivo)
{
    if (scrabble.trieInicializado)
    {
        cout << "(Diccionario ya inicializado) El diccionario ya ha sido inicializado." << endl;
        return;
    }
    bool exito = scrabble.cargar_diccionario_en_trie(archivo);
    if (exito)
    {
        cout << "(Resultado exitoso) El diccionario se ha inicializado correctamente." << endl;
    }
    else
    {
        cout << "(Archivo no existe) El archivo no existe o no puede ser leído." << endl;
    }
}

void inicializarDiccionarioInversoTrie(Scrabble &scrabble, const string &archivo)
{
    if (scrabble.trieInversoInicializado)
    {
        cout << "(Diccionario inverso ya inicializado) El diccionario inverso ya ha sido inicializado." << endl;
        return;
    }
    bool exito = scrabble.cargar_diccionario_en_trie_inverso(archivo);
    if (exito)
    {
        cout << "(Resultado exitoso) El diccionario inverso se ha inicializado correctamente." << endl;
    }
    else
    {
        cout << "(Archivo no existe) El archivo no existe o no puede ser leído." << endl;
    }
}

// Funciones para gestionar puntaje en Trie
void calcularPuntajeEnTrie(const Scrabble &scrabble, const string &palabra)
{
    if (palabra.find_first_not_of("ABCDEFGHIJKLMNOPQRSTUVWXYZabcdefghijklmnopqrstuvwxyz") != string::npos)
    {
        cout << "(Letras invalidas) La palabra contiene símbolos inválidos." << endl;
        return;
    }

    if (scrabble.buscar_en_trie(palabra))
    {
        int puntaje = scrabble.obtener_puntaje_en_trie(palabra);
        cout << "(Resultado exitoso) La palabra tiene un puntaje de " << puntaje << "." << endl;
    }
    else
    {
        cout << "(Palabra no existe) La palabra no existe en el diccionario." << endl;
    }
}

void calcularPuntajeInversoEnTrie(const Scrabble &scrabble, const string &palabra)
{
    if (palabra.find_first_not_of("ABCDEFGHIJKLMNOPQRSTUVWXYZabcdefghijklmnopqrstuvwxyz") != string::npos)
    {
        cout << "(Letras invalidas) La palabra contiene símbolos inválidos." << endl;
        return;
    }

    if (scrabble.buscar_en_trie_inverso(palabra))
    {
        int puntaje = scrabble.obtener_puntaje_en_trie_inverso(palabra);
        cout << "(Resultado exitoso) La palabra tiene un puntaje de " << puntaje << "." << endl;
    }
    else
    {
        cout << "(Palabra no existe) La palabra no existe en el diccionario inverso." << endl;
    }
}

// Funciones para gestionar puntaje en Listas
void calcularPuntajeEnListas(const Scrabble &scrabble, const string &palabra)
{
    if (palabra.find_first_not_of("ABCDEFGHIJKLMNOPQRSTUVWXYZabcdefghijklmnopqrstuvwxyz") != string::npos)
    {
        cout << "(Letras invalidas) La palabra contiene símbolos inválidos." << endl;
        return;
    }

    if (scrabble.buscar_en_diccionario(palabra))
    {
        int puntaje = scrabble.obtener_puntaje_en_diccionario(palabra);
        cout << "(Resultado exitoso) La palabra tiene un puntaje de " << puntaje << "." << endl;
    }
    else
    {
        cout << "(Palabra no existe) La palabra no existe en el diccionario." << endl;
    }
}

void calcularPuntajeInversoEnListas(const Scrabble &scrabble, const string &palabra)
{
    if (palabra.find_first_not_of("ABCDEFGHIJKLMNOPQRSTUVWXYZabcdefghijklmnopqrstuvwxyz") != string::npos)
    {
        cout << "(Letras invalidas) La palabra contiene símbolos inválidos." << endl;
        return;
    }

    if (scrabble.buscar_en_diccionario_inverso(palabra))
    {
        int puntaje = scrabble.obtener_puntaje_en_diccionario_inverso(palabra);
        cout << "(Resultado exitoso) La palabra tiene un puntaje de " << puntaje << "." << endl;
    }
    else
    {
        cout << "(Palabra no existe) La palabra no existe en el diccionario inverso." << endl;
    }
}

// Funciones para búsqueda de palabras
void palabrasPorPrefijo(const Scrabble &scrabble, const string &prefijo)
{
    vector<string> palabras = scrabble.buscar_prefijo_en_trie(prefijo);
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
            calcularPuntajeEnTrie(scrabble, palabra);
            cout << endl;
        }
    }
}

void palabrasPorSufijo(const Scrabble &scrabble, const string &sufijo)
{
    vector<string> palabras = scrabble.buscar_sufijo_en_trie_inverso(sufijo);
    if (palabras.empty())
    {
        cout << "(Sufijo inválido) El sufijo '" << sufijo << "' no pudo encontrarse en el diccionario inverso." << endl;
    }
    else
    {
        cout << "(Resultado exitoso) Las palabras que terminan con el sufijo '" << sufijo << "' son:" << endl;
        for (const auto &palabra : palabras)
        {
            cout << palabra << endl;
            calcularPuntajeInversoEnTrie(scrabble, palabra);
            cout << endl;
        }
    }
}

// Funciones para gestión del grafo
void construirGrafoPalabras(Scrabble &scrabble, const string &archivo)
{
    scrabble.construir_grafo_palabras(archivo);
    cout << "(Resultado exitoso) Grafo construído correctamente." << endl;
}

void generarPosiblesPalabras(Scrabble &scrabble, const string &letras)
{
    if (letras.find_first_not_of("ABCDEFGHIJKLMNOPQRSTUVWXYZabcdefghijklmnopqrstuvwxyz?") != string::npos)
    {
        cout << "(Letras inválidas) La cadena contiene símbolos inválidos." << endl;
        return;
    }
    scrabble.generar_palabras(letras);
}

// Función para mostrar ayuda
void mostrarAyuda()
{
    string ayudaComponente1 = "Comandos disponibles del Componente 1:\n"
                              "  - inicializar <nombre_archivo>: Inicializa el diccionario con el contenido del archivo <nombre_archivo>.\n"
                              "  - iniciar_inverso <nombre_archivo>: Inicializa el diccionario inverso con el contenido del archivo <nombre_archivo>.\n"
                              "  - puntaje_lista <palabra>: Obtiene el puntaje de la palabra especificada utilizando Listas.\n"
                              "  - puntaje_inverso_lista <palabra>: Obtiene el puntaje de la palabra especificada utilizando Listas inverso.\n";
    string ayudaComponente2 = "Comandos disponibles del Componente 2:\n"
                              "  - iniciar_arbol <nombre_archivo>: Inicializa el árbol del diccionario con el contenido del archivo <nombre_archivo>.\n"
                              "  - iniciar_arbol_inverso <nombre_archivo>: Inicializa el árbol del diccionario inverso con el contenido del archivo <nombre_archivo>.\n"
                              "  - palabras_por_prefijo <prefijo>: Busca y muestra las palabras que inician con el prefijo especificado.\n"
                              "  - palabras_por_sufijo <sufijo>: Busca y muestra las palabras que terminan con el sufijo especificado.\n";
    string ayudaComponente3 = "Comandos disponibles del Componente 3:\n"
                              "  - grafo_de_palabras <nombre_archivo>: Construye un grafo de palabras.\n"
                              "  - posibles_palabras <letras>: Muestra las posibles palabras a construir con las letras especificadas.\n";

    cout << ayudaComponente1 << endl;
    cout << ayudaComponente2 << endl;
    cout << ayudaComponente3 << endl;
    cout << "  - salir: Termina la ejecución del programa.\n"
         << endl;
}

// Función principal
int main()
{
    Scrabble scrabble;

    string comando;
    string archivoDiccionario;

    cout << "Bienvenido al sistema de apoyo para el juego Scrabble." << endl;
    mostrarAyuda();

    while (true)
    {
        cout << "$ ";
        getline(cin, comando);

        size_t espacio = comando.find(' ');
        string token = comando.substr(0, espacio);

        if (token == "ayuda")
        {
            mostrarAyuda();
            continue;
        }

        string argumento = "";
        if (espacio != string::npos)
        {
            argumento = comando.substr(espacio + 1);
        }

        if (token == "inicializar")
        {
            inicializarDiccionarioLista(scrabble, argumento);
        }
        else if (token == "iniciar_inverso")
        {
            inicializarDiccionarioInversoLista(scrabble, argumento);
        }
        else if (token == "iniciar_arbol")
        {
            inicializarDiccionarioTrie(scrabble, argumento);
        }
        else if (token == "iniciar_arbol_inverso")
        {
            inicializarDiccionarioInversoTrie(scrabble, argumento);
        }
        else if (token == "puntaje_trie")
        {
            if (argumento.empty())
            {
                cout << "Error: Falta la palabra para obtener el puntaje." << endl;
                continue;
            }
            calcularPuntajeEnTrie(scrabble, argumento);
        }
        else if (token == "puntaje_lista")
        {
            if (argumento.empty())
            {
                cout << "Error: Falta la palabra para obtener el puntaje." << endl;
                continue;
            }
            calcularPuntajeEnListas(scrabble, argumento);
        }
        else if (token == "puntaje_inverso_trie")
        {
            if (argumento.empty())
            {
                cout << "Error: Falta la palabra para obtener el puntaje." << endl;
                continue;
            }
            calcularPuntajeInversoEnTrie(scrabble, argumento);
        }
        else if (token == "puntaje_inverso_lista")
        {
            if (argumento.empty())
            {
                cout << "Error: Falta la palabra para obtener el puntaje." << endl;
                continue;
            }
            calcularPuntajeInversoEnListas(scrabble, argumento);
        }
        else if (token == "palabras_por_prefijo")
        {
            palabrasPorPrefijo(scrabble, argumento);
        }
        else if (token == "palabras_por_sufijo")
        {
            palabrasPorSufijo(scrabble, argumento);
        }
        else if (token == "grafo_de_palabras")
        {
            construirGrafoPalabras(scrabble, argumento);
        }
        else if (token == "posibles_palabras")
        {
            generarPosiblesPalabras(scrabble, argumento);
        }
        else if (token == "salir")
        {
            cout << "Gracias por utilizar el sistema de apoyo para el juego Scrabble. ¡Hasta luego!" << endl;
            break;
        }
        else
        {
            cout << "Comando no válido. Por favor, ingrese un comando válido o escriba 'salir' para terminar el programa." << endl;
        }
    }

    return 0;
}
