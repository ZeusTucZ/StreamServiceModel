#include "Pelicula.h"

Pelicula::Pelicula(std::string id, std::string nombre, std::string genero, int duracion)
    : Video(id, nombre, genero, duracion) {}

void Pelicula::mostrarInformacion() const {
    cout << "ID: " << id << endl;
    cout << "Nombre de la película: " << nombre << endl;
    cout << "Género: " << genero << endl;
    cout << "Duración: " << duracion << " minutos" << endl;
    cout << "Promedio de calificaciones: " << calcularPromedio() << endl;
}

float Pelicula::calcularPromedio() const {
    if (calificaciones.empty()) return 0.0;
    int suma = 0;
    for (int cal : calificaciones) {
        suma += cal;
    }
    return static_cast<float>(suma) / calificaciones.size();
}

void Pelicula::agregarCalificacion(int calificacion) {
    if (calificacion >= 1 && calificacion <= 5) {
        calificaciones.push_back(calificacion);
    } else {
        cout << "La calificación debe estar entre 1 y 5." << endl;
    }
}

void Pelicula::reproducir() const {
    cout << "Reproduciendo la película: " << nombre << endl;
}
