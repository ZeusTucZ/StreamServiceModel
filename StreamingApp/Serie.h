#include <string>
#include <vector>
#include <iostream>
#include "Video.h"
#include "Episodio.h"

using namespace std;

class Serie : public Video {
private:
    int temporadas;
    int episodiosPorTemporada;
    vector<vector<vector<int>>> calificaciones;
    vector<int> calificacionesGenerales;
    string trailerURL; // URL del tráiler de la serie

public:
    // Constructor
    Serie(string titulo, string genero, string creador, int duracion,
          int temporadas, int episodiosPorTemporada, string trailerURL);

    float calcularPromedio() const override;
    void agregarCalificacion(int calificacion) override; // No se usará directamente
    void agregarCalificacion(int temporada, int episodio, int calificacion); // Método para series
    void mostrarInformacion() const override;
    void reproducir() const override;
    void mostrarEpisodiosConCalificacion() const;


    // Método para reproducir tráiler
    void reproducirTrailer() const override;

    void agregarCalificacionGeneral(int calificacion);
    float calcularPromedioGeneral() const;
};