#include <string>
#include <vector>
#include <iostream>
#include "Video.h"

using namespace std;

class Serie : public Video {
private:
    int temporadas;
    int episodiosPorTemporada;
    vector<vector<vector<int>>> calificaciones;

public:
    Serie(string titulo, string genero, string creador, int duracion,
          int temporadas, int episodiosPorTemporada);

    float calcularPromedio() const override;
    void agregarCalificacion(int calificacion) override; // No se usará directamente
    void agregarCalificacion(int temporada, int episodio, int calificacion); // Método útil para series
    void mostrarInformacion() const override;
    void reproducir() const override;
};
