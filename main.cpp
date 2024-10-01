#include <iostream>
#include <fstream>
#include <string>
#include <vector>
#include <set>
#include <cstring>
#include <filesystem>
using namespace std;
#include "videos.h"
#include "serie.h"
#include "episodio.h"
#include "peliculas.h"

vector<Video*> videos;
vector<Pelicula*> peliculas;
vector<Serie*> col_series;
set<string> generos;

void destruir(){
    for (int i = 0; i < videos.size(); i++) {
        if(videos[i] != nullptr) {
            delete videos[i];
            videos[i] = nullptr;
        }
    }
    videos.clear();
    videos.resize(0);
}

void leerArchivo(string&file) {
    string l, tipo, titulo, genero, tituloSerie;
    int idVideo, duracion, episodio, temporada;
    double calificacion;
    destruir();
    ifstream f(file);
    getline(f, l); // lee la primera linea de titulos
    do {
        f >> tipo >> idVideo >> titulo >> genero >> duracion >> calificacion;
        if (tipo == "e") {
            // leer Titulo de Serie episodio temporada
            f >> tituloSerie >> episodio >> temporada;
            Episodio *e = new Episodio(idVideo, episodio, temporada, calificacion, duracion, genero, titulo,
                                       tituloSerie);
            bool found = false;
            for (int i = 0; i < col_series.size(); i++) {
                if (col_series[i]->get_titulo() == tituloSerie) {
                    col_series[i]->agregar_episodio(e);
                    col_series[i]->cal_promedio_serie(e);
                    col_series[i]->duracion_serie(e);
                    videos.push_back(e);
                    found = true;
                    break;
                }
            }
            if (!found) {
                Serie* s = new Serie();
                s->set_titulo(tituloSerie);
                s->set_genero(genero);
                s->agregar_episodio(e);
                col_series.push_back(s);
                videos.push_back(s);
            }
        } else {
            Pelicula *m = new Pelicula(idVideo, calificacion, duracion, genero, titulo);
            videos.push_back(m);
            peliculas.push_back(m);
        }

    } while (!f.eof());
}

void imprimir_videos(int opcion) {
    int contador = 1;
    if (opcion == 1) {
        double rang_min, rang_max;

        if (videos.empty()) {
            cout << "No hay videos disponibles. Carga un archivo" << endl;
            return;
        } else {
            cout << "Rango menor de calificación: ";
            cin >> rang_min;
            cout << "Rango mayor de calificación: ";
            cin >> rang_max;
            for (int i = 0; i < videos.size(); i++) {
                if (videos[i]->get_calificacion() >= rang_min && videos[i]->get_calificacion() <= rang_max) {
                    cout << contador << ") Tipo: " << videos[i]->tipo() << " Título: " << videos[i]->get_titulo()
                         << endl;
                    contador++;
                }
            }
        }
        cout << "Regresando al menu... " << endl;
    } else if (opcion == 2) {

        if (videos.empty()) {
            cout << "No hay videos disponibles. Carga un archivo" << endl;
            return;
        } else {
            bool gen_enocntrado = false;
            do {
                cout << "¿Cuál género quieres ver? Hay los siguientes: " << endl;
                for (int i = 0; i < videos.size(); i++) {
                    generos.insert(videos[i]->get_genero());
                }
                for (auto itr: generos) {
                    cout << itr << endl;
                }
                string genero;
                cin >> genero;
                genero[0] = toupper(genero[0]);
                try {
                    for (int i = 0; i < videos.size(); i++) {
                        if (videos[i]->get_genero() == genero) {
                            gen_enocntrado = true;
                            std::cout << contador << ") Tipo: " << videos[i]->tipo() << " Título: "
                                      << videos[i]->get_titulo() << std::endl;
                            contador++;
                        }
                    }
                    if (!gen_enocntrado) {
                        cout << "El género " << genero << " no existe" << endl;
                    }

                } catch (const std::exception &e) {
                    std::cout << "Error: " << e.what() << std::endl;
                }
            } while (!gen_enocntrado);
            cout << "Regresando al menu... " << endl;
        }
    }
}

void imprimir_eps_series(string title, int cal){
    int contador=1;
    for (int i=0; i<col_series.size(); i++) {
        if(col_series[i]->get_titulo()==title){
            for (int j=0; j < col_series[i]->temporada.size(); j++){
                if ((col_series[i]->temporada[j])->get_calificacion() >= cal){
                    cout << contador<< ") "<< (col_series[i]->temporada[j])->get_titulo() << endl;
                    contador++;
                }
            }
        }
    }
}

void imprimir_pelis(double min, double max){
    int contador=1;
    for (int i=0; i<peliculas.size(); i++) {
        if (peliculas[i]->get_calificacion()>=min && peliculas[i]->get_calificacion()<=max) {
            cout << contador<< ") " << peliculas[i] ->get_titulo() << endl;
            contador++;
        }
    }
}

void calificar_video(int id, double calificacion){
    for (int i=0; i<videos.size(); i++) {
        if (videos[i]->get_ID()==id) {
            cout << "La calificación vieja de "<< videos[i]->get_titulo() << " era " << videos[i]->get_calificacion();
            videos[i]->set_calificacion(calificacion);
            cout << " ahora la calificación es "<< videos[i]->get_calificacion() << endl;
            break;
        }
    }
}

int main() {
    string filename = "Ejemplo.txt";
    ifstream f(filename);
    bool exit=false;
    while (exit!=true){
        cout << "----------------- Menu -----------------" << endl;
        cout << "Selecciona un opción: " << endl;
        cout << endl;
        cout << "1) Agregar archivos (se eliminarán los archivos anteriores)" << endl;
        cout << "2) Mostrar los videos en general con una cierta calificación o de un cierto género" <<endl;
        cout << "3) Mostrar los episodios de una determinada serie con una calificacion determinada"<<endl;
        cout << "4) Mostrar las películas con cierta calificacion" <<endl;
        cout << "5) Calificar un video" <<endl;
        cout << "0) Salir" <<endl;
        cout << endl;
        int select;
        string name;
        cin >> select;

        switch (select) {
            case 1:
                do {
                    cout<< "Dame el nombre del archivo (en formato txt): " <<endl;
                    string nombre="";
                    cin>> nombre;
                    filename= "../"+nombre + ".txt";
                    try {
                        if (std::filesystem::exists(filename))
                            leerArchivo(filename);
                        else {
                            cout << "El archivo " << filename << " no existe" << endl ;
                        }

                    } catch (std::exception exp){
                        cerr<< exp.what() << endl;
                    }
                } while (!std::filesystem::exists(filename));
                break;
            case 2:
                cout << "¿Quieres ver los videos por calificación o por género? 1->calificación  2->género" << endl;
                int opcion;
                cin>>opcion;
                imprimir_videos(opcion);
                break;
            case 3:
                int cal;
                if (col_series.empty()) {
                    cout << "No hay series disponibles. Carga un archivo" << endl;
                } else {
                    bool serieEncontrada = false;
                    do{
                        cout << "¿De cuál serie quieres ver los episodios? Hay las siguientes opciones:" << endl;
                        for (int i=0; i<col_series.size(); i++) {
                            cout << col_series[i] ->get_titulo() << endl;
                        }
                        cout << "Nombre serie: ";
                        cin>> name;
                        cout << "Calificación a partir de la cual quieres ver los episodios: ";
                        cin>> cal;

                        try {
                            for (const auto& serie : col_series) {
                                if (serie->get_titulo() == name) {
                                    serieEncontrada = true;
                                    break;
                                }
                            }

                            if (serieEncontrada)
                                imprimir_eps_series(name, cal);
                            else {
                                cout << "La serie " << name << " no existe" << endl ;
                            }

                        } catch (const exception& e) {
                            cerr << "Error: " << e.what() << endl;
                        }
                    } while (!serieEncontrada);
                }
                break;
            case 4:
                if (peliculas.empty()) {
                    cout << "No hay películas disponibles. Carga un archivo" << endl;
                } else {
                    cout << "Dime los rangos de calificaciones que quieres ver:" << endl;
                    double rang_min, rang_max;
                    cout << "Rango menor de calificación: ";
                    cin >> rang_min;
                    cout << "Rango mayor de calificación: ";
                    cin >> rang_max;
                    imprimir_pelis(rang_min, rang_max);
                }
                    break;
            case 5:
                if (videos.empty()) {
                    cout << "No hay videos disponibles. Carga un archivo" << endl;
                } else {
                    bool id_encontrada = false;
                    do{
                        cout << "Dime el ID del video que quieres valorar y su valoración" << endl;
                        double val;
                        int ide;
                        cout << "ID: ";
                        cin >> ide;
                        cout << "Calificación: ";
                        cin >> val;

                        try {
                            for (const auto &video: videos) {
                                if (video->get_ID() == ide) {
                                    id_encontrada = true;
                                    break;
                                }
                            }

                            if (id_encontrada) {
                                calificar_video(ide, val);
                            } else {
                                cout << "El ID " << ide << " no existe" << endl;
                            }

                        } catch (std::exception exp) {
                            cerr << "Error: " << exp.what() << endl;
                        }
                    } while (!id_encontrada);
                }
                break;
            case 0:
                    exit = true;
                    destruir();
                break;
            default:
                cout << "Opción inválida" << endl;
                break;
        }
    }
    return 0;
}