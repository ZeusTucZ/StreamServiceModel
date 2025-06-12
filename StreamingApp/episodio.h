#pragma once

#include <string>
#include "Video.h"

class Episodio : public Video {
private:
    int temporada;
    int numero;

public:
    Episodio(std::string id, std::string nombre, std::string genero, int duracion,
             int temporada, int numero, std::string trailerURL = "");

    float calcularPromedio() const override;
    void agregarCalificacion(int calificacion) override;
    void mostrarInformacion() const override;
    void reproducir() const override;
};

