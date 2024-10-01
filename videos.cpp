#include "videos.h"

Video::Video() {
    ID=0;
    calificacion=0.0;
    duracion=0;
    genero="...";
    titulo="no title";
}
Video::Video(int id, double cal, double length, std::string gen, std::string title) : ID(id),
    calificacion(cal),
    duracion(length),
    genero(gen),
    titulo(title){ }

Video::~Video(){
    //std::cout << "Destructor de video" << std::endl;
}


void Video::set_ID(int ID){
    this->ID= ID;
}

void Video::set_calificacion(double cal){
    calificacion=cal;
}

void Video::set_titulo(string title){
    titulo=title;
}

void Video::set_genero(string gen){
    genero=gen;
}

void Video::set_duracion(double length){
    duracion=length;
}

int Video::get_ID(){
    return ID;
}

double Video::get_calificacion(){
    return calificacion;
}

string Video::get_genero(){
    return genero;
}

string Video::get_titulo(){
    return titulo;
}

double Video::get_duracion(){
    return duracion;
}

