#include "peliculas.h"

Pelicula::Pelicula(): Video(){
    //std::cout << "Se creó una película" << std::endl;
}

Pelicula::Pelicula(int id, double cal, double length, std::string gen, std::string title)
        : Video(id,cal,length,gen,title){
    //std::cout << "Se creó la película llamada: "<< title  << " ID: " << id << std::endl;
}


Pelicula::~Pelicula(){
    //std::cout << "Se eliminó una película" << std::endl;
}


string Pelicula::tipo() {
   return "PELÍCULA";
}

/*
void Pelicula::display(){
    cout<< "ID: " << ID << endl << "Titulo: " << titulo << endl << "Genero: " << genero << endl;
    cout<< "Calificacion: " << calificacion <<endl;
}*/