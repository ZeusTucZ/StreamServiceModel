#include "Video.h"
#include "string.h"

Video::Video(string id_video, string nom, string gen, vector<int> cal, int dur) {
    id = id_video;
    nombre = nom;
    genero = gen;
    calificaciones = cal;
    duracion = dur;
}

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