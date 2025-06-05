#include <string>
#include "Video.h"

class Pelicula: public Video {
    public:
        Pelicula(std::string, std::string, std::string, int);

        float calcularPromedio() const override;
        void agregarCalificacion(int) override;
        void mostrarInformacion() const override;
        void reproducir() const override;
};