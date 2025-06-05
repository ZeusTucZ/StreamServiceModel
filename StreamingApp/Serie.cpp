#include "Serie.h"

Serie::Serie(std::string id, std::string nombre, std::string genero, int duracion,
             int temporadas, int episodiosPorTemporada)
    : Video(id, nombre, genero, duracion),
      temporadas(temporadas),
      episodiosPorTemporada(episodiosPorTemporada),
      calificaciones(temporadas, std::vector<std::vector<int>>(episodiosPorTemporada)) {}

void Serie::mostrarInformacion() const {
    cout << "ID: " << id << endl;
    cout << "Nombre de la serie: " << nombre << endl;
    cout << "Género: " << genero << endl;
    cout << "Duración promedio por episodio: " << duracion << " minutos" << endl;
    cout << "Temporadas: " << temporadas << endl;
    cout << "Episodios por temporada: " << episodiosPorTemporada << endl;
    cout << "Promedio de calificaciones: " << calcularPromedio() << endl;
}

float Serie::calcularPromedio() const {
    int suma = 0;
    int total = 0;
    for (const auto& temporada : calificaciones) {
        for (const auto& episodio : temporada) {
            for (int cal : episodio) {
                suma += cal;
                total++;
            }
        }
    }
    return total > 0 ? static_cast<float>(suma) / total : 0.0;
}

void Serie::agregarCalificacion(int calificacion) {
    // No se usa en Series; solo se incluye por la herencia
}

void Serie::agregarCalificacion(int temporada, int episodio, int calificacion) {
    if (calificacion < 1 || calificacion > 5) {
        cout << "La calificación debe estar entre 1 y 5." << endl;
        return;
    }
    if (temporada >= 0 && temporada < temporadas &&
        episodio >= 0 && episodio < episodiosPorTemporada) {
        calificaciones[temporada][episodio].push_back(calificacion);
    } else {
        cout << "Número de temporada o episodio inválido." << endl;
    }
}

void Serie::reproducir() const {
    cout << "Reproduciendo la serie: " << nombre << endl;
}
