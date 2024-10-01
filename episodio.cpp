#include "episodio.h"

Episodio::Episodio(): Video(){
   // std::cout << "Se creó un episodio" << std::endl;
}

Episodio::Episodio(int id, int ep, int season, double cal, double length, std::string gen, std::string title, string nom_series)
        : Video(id,cal,length,gen,title){
    temporada=season;
    n_episodio=ep;
    nombre_serie=nom_series;
   // std::cout << "Se creó un episodio llamado: "<< title  << " de la serie: " << nom_series<< " ID: " << id << std::endl;
}


Episodio::~Episodio(){
   //std::cout << "Se eliminó un episodio" << std::endl;
}

string Episodio::tipo() {
    return  "EPISODIO" ;
}


/*void Episodio::display(){
    cout<< "ID: " << ID << endl << "Titulo: " << titulo << endl << "Genero: " << genero << endl;
    cout<< "Calificacion: " << calificacion << " Temporada: " << temporada << " Episodio: "<< n_episodio << endl;
}*/