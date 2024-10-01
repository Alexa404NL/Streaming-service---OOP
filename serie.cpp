#include "serie.h"
#include "episodio.h"
#include "videos.h"
#include <vector>
#include <iomanip>


Serie::Serie(): Video(){
  //  std::cout << "Se creó una serie" << std::endl;
}

Serie::Serie(int id, double cal, double length, std::string gen, std::string title)
        : Video(id,cal,length,gen,title){
   // std::cout << "Se creó una serie llamada: "<< title  << " ID: " << id << std::endl;
}


Serie::~Serie() {
   // std::cout << "Se eliminó una serie" << std::endl;
}

void Serie::agregar_episodio(Episodio *episodio) {
    temporada.push_back(episodio);
   // std::cout << "Se agrego el episodio " << episodio->get_titulo() << " a serie "<< titulo<< std::endl;
}

Episodio* Serie::get_episodio(int index){
    if (index >= 0 && index < temporada.size()) {
        return temporada[index];
    } else {
        cerr << "Índice fuera de rango para obtener episodio." << endl;
        return nullptr;
    }
}

void Serie::cal_promedio_serie(Episodio *episodio) {
    double rating = 0.0;
    int episodeCount = 0;

    for (const auto& ep : temporada) {
        rating += ep->get_calificacion();
        episodeCount++;
    }

    rating += episodio->get_calificacion();
    episodeCount++;
    double averageRating = rating / episodeCount;
    calificacion = averageRating;
    //cout << "Se agrego el episodio " << episodio->get_titulo() << " con calificación " << episodio->get_calificacion()
   // << ". Ahora la calificación media de la serie es " << std::fixed << std::setprecision(2) << averageRating << std::endl;

}

void Serie::duracion_serie(Episodio *episodio) {
    double duracion_t=0;

    for (const auto& ep : temporada) {
        duracion_t += ep->get_duracion();
    }

    duracion_t += episodio->get_duracion();
    duracion = duracion_t;
}

string Serie::tipo() {
    return "SERIE" ;
}

/*void Serie::display() {
    cout << "ID: " << ID << endl << "Titulo: " << titulo << endl << "Genero: " << genero << endl;
    cout << "Calificacion: " << calificacion << endl;
}*/