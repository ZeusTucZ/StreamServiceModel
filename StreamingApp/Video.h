#pragma once

#include <iostream>
#include <vector>
using namespace std;

class Video {
    protected:
        string id, nombre, genero;
        vector<int> calificaciones;
        int duracion;
    public:
        Video(string, string, string, int); // Método constructor

        // métodos
        virtual float calcularPromedio() const = 0; // Cálcula el promedio de las calificaciones
        virtual void agregarCalificacion(int) = 0; // Califica una serie o pelicula
        virtual void mostrarInformacion() const = 0; // Muestra información de la serie o película
        virtual void reproducir() const = 0; // Reproduce el video pasando el link del mismo

        // getters
        string getNombre();
        string getGenero();
        int getDuracion();
        const vector<int>& getCalificaciones();

        virtual ~Video() {}; // Destructor virtual
};