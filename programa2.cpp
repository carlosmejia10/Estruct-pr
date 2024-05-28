#include <iostream>
#include <string>
#include <vector>
#include <fstream>
#include "TADs/Scrabble.h"

using namespace std;

Grafo grafo;

void inicializarDiccionario(Scrabble &scrabble, const string &archivo)
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

void inicializarDiccionarioInverso(Scrabble &scrabble, const string &archivo)
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

void obtenerPuntaje(const Scrabble &scrabble, const string &palabra)
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
void obtenerPuntajeInverso(const Scrabble &scrabble, const string &palabra)
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
        cout << "(Palabra no existe) La palabra no existe en el diccionario." << endl;
    }
}

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
            obtenerPuntaje(scrabble, palabra);
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
            obtenerPuntajeInverso(scrabble, palabra);
            cout << endl;
        }
    }
}


void mostrarAyuda()
{
    // Texto de ayuda para los comandos del componente 1
    string ayudaComponente1 = "Comandos disponibles del Componente 1:\n"
                              "  - inicializar <nombre_archivo>: Inicializa el diccionario con el contenido del archivo <nombre_archivo>.\n"
                              "  - iniciar_inverso <nombre_archivo>: Inicializa el diccionario inverso con el contenido del archivo <nombre_archivo>.\n"
                              "  - puntaje <palabra>: Obtiene el puntaje de la palabra especificada.\n"
                              "  - puntaje_inverso <palabra>: Obtiene el puntaje de la palabra especificada en el diccionario inverso.\n"
                              "  - salir: Termina la ejecución del programa.\n";
    // Texto de ayuda para los comandos del componente 2
    string ayudaComponente2 = "Comandos disponibles del Componente 2:\n"
                              "  - iniciar_arbol <nombre_archivo>: Inicializa el árbol del diccionario con el contenido del archivo <nombre_archivo>.\n"
                              "  - iniciar_arbol_inverso <nombre_archivo>: Inicializa el árbol del diccionario inverso con el contenido del archivo <nombre_archivo>.\n"
                              "  - palabras_por_prefijo <prefijo>: Busca y muestra las palabras que inician con el prefijo especificado.\n"
                              "  - palabras_por_sufijo <sufijo>: Busca y muestra las palabras que terminan con el sufijo especificado.\n";
    // Texto de ayuda para los comandos del componente 3
    string ayudaComponente3 = "Comandos disponibles del componente 3:\n"
                          "  - grafo_de_palabras <nombre_archivo>: Inicializa el grafo de palabras con el diccionario de nombre de archivo puesto. \n"
                          "  - posibles_palabras <letras> \n";
    cout << ayudaComponente1 << endl;
    cout << ayudaComponente2 << endl;
    cout << ayudaComponente3 << endl;
}

int main()
{
    Scrabble scrabble;

    string comando;
    string archivoDiccionario;
    bool ayudaMostrada = false; // Variable booleana para controlar si se ha mostrado la ayuda

    cout << "Bienvenido al sistema de apoyo para el juego Scrabble." << endl;
    mostrarAyuda(); // Mostrar ayuda al principio del programa

    while (true)
    {
        cout << "$ ";
        getline(cin, comando); // Lee toda la línea, incluidos los espacios

        // Buscar el primer espacio en blanco para dividir el comando y el argumento
        size_t espacio = comando.find(' ');
        string token = comando.substr(0, espacio); // Token es el comando

        if (token == "ayuda")
        {
            mostrarAyuda(); // Mostrar ayuda cada vez que se solicite
            continue;       // Vuelve al principio del bucle para leer otro comando
        }

        string argumento = ""; // Inicializar el argumento como una cadena vacía
        if (espacio != string::npos)
        {
            // Si se encontró un espacio en blanco, hay un argumento después del comando
            argumento = comando.substr(espacio + 1); // El argumento es la parte después del espacio
        }

        if (token == "inicializar" || token == "iniciar_inverso")
        {
            if (argumento.empty())
            {
                cout << "Error: Falta el nombre del archivo." << endl;
                continue; // Vuelve al principio del bucle para leer otro comando
            }
        }

        if (token == "inicializar" || token == "iniciar_arbol")
        {
            inicializarDiccionario(scrabble, argumento);
        }
        else if (token == "iniciar_inverso" || token == "iniciar_arbol_inverso")
        {
            inicializarDiccionarioInverso(scrabble, argumento);
        }
        else if (token == "grafo_de_palabras")
        {
            scrabble.construir_grafo_palabras(argumento);
        }
        else if (token == "puntaje")
        {
            if (argumento.empty())
            {
                cout << "Error: Falta la palabra para obtener el puntaje." << endl;
                continue; // Vuelve al principio del bucle para leer otro comando
            }
            obtenerPuntaje(scrabble, argumento);
        }
        else if (token == "puntaje_inverso")
        {
            if (argumento.empty())
            {
                cout << "Error: Falta la palabra para obtener el puntaje inverso." << endl;
                continue; // Vuelve al principio del bucle para leer otro comando
            }
            obtenerPuntajeInverso(scrabble, argumento);
        }
        else if (token == "palabras_por_prefijo")
        {
            palabrasPorPrefijo(scrabble, argumento);
        }
        else if (token == "palabras_por_sufijo")
        {
            palabrasPorSufijo(scrabble, argumento);
        }
        else if (token == "posibles_palabras"){
            scrabble.generar_palabras(argumento);
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
