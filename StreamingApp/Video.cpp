#include "Video.h"

Video::Video(string id_video, string nom, string gen, int dur, string trailer)
    : id(id_video), nombre(nom), genero(gen), duracion(dur), trailerURL(trailer) {}

string Video::getNombre() {
    return nombre;
}

string Video::getGenero() {
    return genero;
}

int Video::getDuracion() {
    return duracion;
}

const vector<int>& Video::getCalificaciones() {
    return calificaciones;
}

string Video::getTrailerURL() {
    return trailerURL;
}
