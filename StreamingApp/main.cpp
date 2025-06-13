#include "Pelicula.h"
#include "Serie.h"
#include <iostream>
#include <fstream>
#include <sstream>
#include <vector>
#include <algorithm>

using namespace std;

// Cargar datos desde archivo (se espera que trailer sea el último campo en cada línea)
void cargarDesdeArchivo(const string& nombreArchivo, vector<Video*>& catalogo) {
    ifstream archivo(nombreArchivo);
    if (!archivo.is_open()) {
        cout << "No se pudo abrir el archivo.\n";
        return;
    }

    string linea;
    while (getline(archivo, linea)) {
        stringstream ss(linea);
        string tipo;
        getline(ss, tipo, ',');

        if (tipo == "PELÍCULA") {
            string id, nombre, genero, trailer;
            int duracion;

            getline(ss, id, ',');
            getline(ss, nombre, ',');
            getline(ss, genero, ',');
            ss >> duracion; ss.ignore();
            getline(ss, trailer);

            catalogo.push_back(new Pelicula(id, nombre, genero, duracion, trailer));
        }
        else if (tipo == "SERIE") {
            string id, nombre, genero, trailer;
            int duracion, temporadas, episodios;

            getline(ss, id, ',');
            getline(ss, nombre, ',');
            getline(ss, genero, ',');
            ss >> duracion; ss.ignore();
            ss >> temporadas; ss.ignore();
            ss >> episodios; ss.ignore();
            getline(ss, trailer);

            catalogo.push_back(new Serie(id, nombre, genero, duracion, temporadas, episodios, trailer));
        }
        else if (tipo == "CALIFICACION") {
            string id;
            getline(ss, id, ',');

            vector<string> campos;
            string campo;
            while (getline(ss, campo, ',')) {
                campos.push_back(campo);
            }   

            auto it = find_if(catalogo.begin(), catalogo.end(), [&](Video* v) {
                return v->getNombre() == id;
            });

            if (it != catalogo.end()) {
                Serie* serie = dynamic_cast<Serie*>(*it);
                if (serie && campos.size()== 3) {
                    int temp = stoi(campos[0]);
                    int epi = stoi(campos[1]);
                    int calif = stoi(campos[2]);
                    
                    serie->agregarCalificacion(temp, epi, calif);
                } else if (campos.size() == 1){
                    int calif = stoi(campos[0]);
                    (*it)->agregarCalificacion(calif);
                }
            } else {
                cout << "Formato de calificacion invalido para  '" << id << "'.\n";

                
            }
        }
    }

    archivo.close();
    cout << "Datos cargados desde archivo correctamente.\n";
}

int main() {
    vector<Video*> catalogo;
    int opcion;

    do {
        cout << "\n===== MENÚ =====\n";
        cout << "1. Cargar archivo de datos\n";
        cout << "2. Mostrar videos por calificación o género\n";
        cout << "3. Mostrar episodios de una serie con calificación\n";
        cout << "4. Mostrar películas con cierta calificación\n";
        cout << "5. Calificar un video\n";
        cout << "6. Reproducir tráiler de un video\n";
        cout << "0. Salir\n";
        cout << "Elige una opción: ";
        cin >> opcion;

        switch (opcion) {
            case 1: {
                string nombreArchivo;
                cout << "Nombre del archivo (ej. datos.txt): ";
                cin >> nombreArchivo;
                cargarDesdeArchivo(nombreArchivo, catalogo);
                break;
            }

            case 2: {
                int subop;
                cout << "Buscar por:\n1. Género\n2. Calificación mínima\nOpción: ";
                cin >> subop;
                if (subop == 1) {
                    string genero;
                    cout << "Género a buscar: ";
                    cin >> genero;
                    for (Video* v : catalogo) {
                        if (v->getGenero() == genero) {
                            v->mostrarInformacion();
                            cout << "------------------\n";
                        }
                    }
                } else if (subop == 2) {
                    int calif;
                    cout << "Calificación mínima: ";
                    cin >> calif;
                    for (Video* v : catalogo) {
                        if (v->calcularPromedio() >= calif) {
                            v->mostrarInformacion();
                            cout << "------------------\n";
                        }
                    }
                }
                break;
            }

            case 3: {
                string nombreSerie;
                int califMin;
                cout << "Nombre de la serie: ";
                cin.ignore();
                getline(cin, nombreSerie);
                cout << "Calificación mínima: ";
                cin >> califMin;

                for (Video* v : catalogo) {
                    Serie* serie = dynamic_cast<Serie*>(v);
                    if (serie && serie->getNombre() == nombreSerie) {
                        if (serie->calcularPromedio() >= califMin) {
                            serie->mostrarInformacion();
                        } else {
                            cout << "La serie no cumple con la calificación mínima.\n";
                        }
                        break;
                    }
                }
                break;
            }

            case 4: {
                int califMin;
                cout << "Calificación mínima: ";
                cin >> califMin;
                for (Video* v : catalogo) {
                    Pelicula* peli = dynamic_cast<Pelicula*>(v);
                    if (peli && peli->calcularPromedio() >= califMin) {
                        peli->mostrarInformacion();
                        cout << "------------------\n";
                    }
                }
                break;
            }

            case 5: {
                string titulo;
                int cal;
                cout << "Título del video a calificar: ";
                cin.ignore();
                getline(cin, titulo);
                cout << "Valor otorgado (1 a 5): ";
                cin >> cal;

                bool encontrado = false;
                for (Video* v : catalogo) {
                    if (v->getNombre() == titulo) {
                        Serie* serie = dynamic_cast<Serie*>(v);
                        if (serie) {
                            int temp, epi;
                            cout << "Es una serie. Ingresa temporada (0-based): ";
                            cin >> temp;
                            cout << "Número de episodio (0-based): ";
                            cin >> epi;
                            serie->agregarCalificacion(temp, epi, cal);
                            cout << "Calificación agregada.\n";
                            cout << "Promedio actualizado: " << serie->calcularPromedio() << endl;
                        } else {
                            v->agregarCalificacion(cal);
                            cout << "Calificación agregada.\n";
                            cout << "Promedio actualizado: " << v->calcularPromedio() << endl;
                        }
                        encontrado = true;
                        break;
                    }
                }

                if (!encontrado) {
                    cout << "No se encontró ese video.\n";
                }
                break;
            }

            case 6: {
                string titulo;
                cout << "Título del video para ver tráiler: ";
                cin.ignore();
                getline(cin, titulo);
                bool encontrado = false;
                for (Video* v : catalogo) {
                    if (v->getNombre() == titulo) {
                        v->reproducirTrailer();
                        encontrado = true;
                        break;
                    }
                }
                if (!encontrado) {
                    cout << "No se encontró ese video.\n";
                }
                break;
            }

            case 0:
                cout << "Saliendo del programa...\n";
                break;

            default:
                cout << "Opción inválida.\n";
        }

    } while (opcion != 0);

    // Liberar memoria
    for (Video* v : catalogo) {
        delete v;
    }

    return 0;
}