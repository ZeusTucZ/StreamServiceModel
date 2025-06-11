#pragma once
#include <string>
#include "Video.h"

class Pelicula : public Video {
private:
    std::string trailerURL; // Nuevo atributo

public:
    // Nuevo constructor con trailerURL
    Pelicula(std::string id, std::string nombre, std::string genero, int duracion, std::string trailerURL);

    float calcularPromedio() const override;
    void agregarCalificacion(int) override;
    void mostrarInformacion() const override;
    void reproducir() const override;

    void reproducirTrailer() const; // Nuevo método para reproducir el tráiler
};
