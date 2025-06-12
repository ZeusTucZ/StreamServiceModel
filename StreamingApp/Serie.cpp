#include "Serie.h"

// Constructor actualizado con trailerURL
Serie::Serie(std::string id, std::string nombre, std::string genero, int duracion,
             int temporadas, int episodiosPorTemporada, std::string trailerURL)
    : Video(id, nombre, genero, duracion,trailerURL),
    //string id, string nombre, string genero, int duracion, string trailerUR
      temporadas(temporadas),
      episodiosPorTemporada(episodiosPorTemporada),
      trailerURL(trailerURL) // Guardamos la URL
{
    // Inicialización de matriz 2D de vectores
    calificaciones.resize(temporadas);
    for (int i = 0; i < temporadas; ++i) {
        calificaciones[i].resize(episodiosPorTemporada);
    }
}

void Serie::mostrarInformacion() const {
    cout << "ID: " << id << endl;
    cout << "Nombre de la serie: " << nombre << endl;
    cout << "Género: " << genero << endl;
    cout << "Duración promedio por episodio: " << duracion << " minutos" << endl;
    cout << "Temporadas: " << temporadas << endl;
    cout << "Episodios por temporada: " << episodiosPorTemporada << endl;
    cout << "Promedio de calificaciones: " << calcularPromedio() << endl;
    cout << "Tráiler disponible en: " << trailerURL << endl; // Mostrar URL
}

float Serie::calcularPromedio() const {
    int suma = 0;
    int total = 0;
    for (const auto& temporada : calificaciones) {
        for (const auto& episodio : temporada) {
            for (int calificacion : episodio) {
                suma += calificacion;
                total++;
            }
        }
    }
    return total > 0 ? static_cast<float>(suma) / total : 0.0;
}

void Serie::agregarCalificacion(int calificacion) {
    cout << "Para series, usa agregarCalificacion(temporada, episodio, calificación)\n";
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

// NUEVO: Método para reproducir el tráiler
void Serie::reproducirTrailer() const {
    cout << "Reproduciendo tráiler de la serie \"" << nombre << "\": " << trailerURL << endl;
    string comando = "open " + trailerURL; // start en windows y open en mac
    system(comando.c_str());
}