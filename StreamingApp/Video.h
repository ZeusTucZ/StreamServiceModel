#pragma once

#include <iostream>
#include <vector>
using namespace std;

class Video {
protected:
    string id, nombre, genero;
    vector<int> calificaciones;
    int duracion;
    string trailerURL; // 🔹 NUEVO: enlace del tráiler

public:
    // 🔹 Constructor actualizado
    Video(string id, string nombre, string genero, int duracion, string trailerURL);

    // Métodos virtuales puros
    virtual float calcularPromedio() const = 0;
    virtual void agregarCalificacion(int) = 0;
    virtual void mostrarInformacion() const = 0;
    virtual void reproducir() const = 0;
    virtual void reproducirTrailer() const = 0; // 🔹 NUEVO: método para reproducir tráiler

    // Getters
    string getNombre();
    string getGenero();
    int getDuracion();
    const vector<int>& getCalificaciones();
    string getTrailerURL(); // 🔹 NUEVO getter

    virtual ~Video() {}; // Destructor virtual
};