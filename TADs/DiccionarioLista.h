#ifndef DICCIONARIO_H
#define DICCIONARIO_H

#include "NodoLista.h"
#include <fstream>
#include <string>

class Diccionario
{
private:
    NodoLista *cabezaNormal;  // Puntero al inicio de la lista normal
    NodoLista *cabezaInverso; // Puntero al inicio de la lista inversa

public:
    // Constructor
    Diccionario();

    // Destructor
    ~Diccionario();

    // Método para insertar una palabra en el diccionario normal
    void insertarNormal(const std::string &palabra);

    // Método para insertar una palabra en el diccionario inverso
    void insertarInverso(const std::string &palabra);

    // Método para buscar una palabra en el diccionario normal
    bool buscarNormal(const std::string &palabra) const;

    // Método para buscar una palabra en el diccionario inverso
    bool buscarInverso(const std::string &palabra) const;

    // Método para obtener el puntaje de una palabra en el diccionario normal
    int obtenerPuntajeNormal(const std::string &palabra) const;

    // Método para obtener el puntaje de una palabra en el diccionario inverso
    int obtenerPuntajeInverso(const std::string &palabra) const;

    // Método para cargar el diccionario normal desde un archivo
    bool cargarDiccionarioNormal(const std::string &archivo);

    // Método para cargar el diccionario inverso desde un archivo
    bool cargarDiccionarioInverso(const std::string &archivo);

    bool estaVaciaNormal() const;
    bool estaVaciaInverso() const;
};

#endif // DICCIONARIO_H
