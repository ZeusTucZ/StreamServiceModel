#include "Episodio.h"

Episodio::Episodio(std::string id, std::string nombre, std::string genero, int duracion,
                   int temporada, int numero)
    : Video(id, nombre, genero, duracion), temporada(temporada), numero(numero) {}

void Episodio::mostrarInformacion() const {
    cout<<"ID: "<<id<<endl;
    cout<<"Nombre del episodio: "<<nombre<<endl;
    cout<<"Temporada: "<<temporada<<", Episodio: "<<numero<<endl;
    cout<<"Género: "<<genero<<endl;
    cout<<"Duración:" <<duracion<<" minutos"<<endl;
    cout<<"Promedio de calificaciones: "<<calcularPromedio()<<endl;
}

float Episodio::calcularPromedio() const {
    if (calificaciones.empty()) return 0.0;
    int suma = 0;
    for (int cal : calificaciones) {
        suma += cal;
    }
    return static_cast<float>(suma) / calificaciones.size();
}

void Episodio::agregarCalificacion(int calificacion) {
    if (calificacion >= 1 && calificacion <= 5) {
        calificaciones.push_back(calificacion);
    } else {
        cout << "La calificación debe estar entre 1 y 5." << endl;
    }
}

void Episodio::reproducir() const {
    cout << "Reproduciendo episodio: " << nombre << " (Temporada " << temporada
         << ", Episodio " << numero << ")" << endl;
}
