#pragma once
#include <string>
#include "Video.h"

class Pelicula : public Video {
private:
    std::string trailerURL; // atributo

public:
    // constructor 
    Pelicula(std::string id, std::string nombre, std::string genero, int duracion, std::string trailerURL);

    float calcularPromedio() const override;
    void agregarCalificacion(int) override;
    void mostrarInformacion() const override;
    void reproducir() const override;

    void reproducirTrailer() const override; // método para reproducir el tráiler
};
