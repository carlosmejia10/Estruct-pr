#include <iostream>
#include <string>
#include <fstream>
#include "TADs/lista_diccionario.h"
#include "TADS/lista_inverso.h"

using namespace std;

void inicializarDiccionario(ListaDiccionario &diccionario, const string &archivo)
{
    if (!diccionario.estaVacia())
    {
        cout << "(Diccionario ya inicializado) El diccionario ya ha sido inicializado." << endl;
        return;
    }

    bool exito = diccionario.cargar_diccionario(archivo);

    if (exito)
    {
        cout << "(Resultado exitoso) El diccionario se ha inicializado correctamente." << endl;
    }
    else
    {
        cout << "(Archivo no existe) El archivo no existe o no puede ser leído." << endl;
    }
}

void inicializarDiccionarioInverso(DiccionarioInverso &diccionarioInverso, const string &archivo)
{
    if (!diccionarioInverso.estaVacia())
    {
        cout << "(Diccionario inverso ya inicializado) El diccionario inverso ya ha sido inicializado." << endl;
        return;
    }

    bool exito = diccionarioInverso.cargarDiccionario(archivo);

    if (exito)
    {
        cout << "(Resultado exitoso) El diccionario inverso se ha inicializado correctamente." << endl;
    }
    else
    {
        cout << "(Archivo no existe) El archivo no existe o no puede ser leído." << endl;
    }
}

void obtenerPuntaje(const ListaDiccionario &diccionario, const string &palabra)
{
    if (!diccionario.buscar(palabra))
    {
        cout << "(Palabra no existe) La palabra no existe en el diccionario." << endl;
        return;
    }

    int puntaje = diccionario.obtener_puntaje(palabra);
    cout << "(Resultado exitoso) La palabra tiene un puntaje de " << puntaje << "." << endl;
}

void obtenerPuntajeInverso(const DiccionarioInverso &diccionarioInverso, const string &palabra)
{
    if (!diccionarioInverso.buscar(palabra))
    {
        cout << "(Palabra no existe) La palabra no existe en el diccionario inverso." << endl;
        return;
    }

    int puntaje = diccionarioInverso.obtenerPuntaje(palabra);
    cout << "(Resultado exitoso) La palabra tiene un puntaje de " << puntaje << "." << endl;
}

void mostrarAyudaComponente1()
{
    cout << "Comandos disponibles del Componente 1:\n"
         << "  - inicializar <nombre_archivo>: Inicializa el diccionario con el contenido del archivo <nombre_archivo>.\n"
         << "  - iniciar_inverso <nombre_archivo>: Inicializa el diccionario inverso con el contenido del archivo <nombre_archivo>.\n"
         << "  - puntaje <palabra>: Obtiene el puntaje de la palabra especificada.\n"
         << "  - puntaje_inverso <palabra>: Obtiene el puntaje de la palabra especificada en el diccionario inverso.\n"
         << "  - salir: Termina la ejecución del programa.\n";
}

int main()
{
    ListaDiccionario diccionario;
    DiccionarioInverso diccionarioInverso;

    string comando;
    string archivoDiccionario;

    cout << "Bienvenido al sistema de apoyo para el juego Scrabble." << endl;
    mostrarAyudaComponente1();

    while (true)
    {
        cout << "$ ";
        string comando;
        getline(cin, comando);

        // Dividir el comando y el argumento
        size_t espacio = comando.find(' ');
        string token = comando.substr(0, espacio); // Token es el comando
        string argumento = "";                     // Inicializar el argumento como una cadena vacía
        if (espacio != string::npos)
        {
            // Si se encontró un espacio en blanco, hay un argumento después del comando
            argumento = comando.substr(espacio + 1); // El argumento es la parte después del espacio
        }

        if (token == "inicializar")
        {
            inicializarDiccionario(diccionario, argumento);
        }
        else if (token == "iniciar_inverso")
        {
            inicializarDiccionarioInverso(diccionarioInverso, argumento);
        }
        else if (token == "puntaje")
        {
            obtenerPuntaje(diccionario, argumento);
        }
        else if (token == "puntaje_inverso")
        {
            obtenerPuntajeInverso(diccionarioInverso, argumento);
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