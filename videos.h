#pragma once
#include <iostream>
#include <string>

using namespace std;

class Video {
protected:
    int ID;
    double calificacion, duracion;
    string genero, titulo;
public:
    Video();
    Video(int, double, double, string, string);
    virtual ~Video();

    virtual string tipo()=0;
    //virtual void display()=0;

    void set_ID(int);
    void set_calificacion(double);
    void set_titulo(string);
    void set_genero(string);
    void set_duracion(double);


    int get_ID();
    double get_calificacion();
    string get_genero();
    string get_titulo();
    double get_duracion();
};
