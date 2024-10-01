#pragma once
#include <iostream>
#include <string>
#include "videos.h"

using namespace std;

class Episodio : public Video{
protected:
    int temporada, n_episodio;
    string nombre_serie;
public:
    Episodio();
    Episodio(int, int, int, double, double, string, string, string);
    ~Episodio();

    string tipo ();
};
