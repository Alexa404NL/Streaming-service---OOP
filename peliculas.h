#pragma once
#include <iostream>
#include <string>
#include "videos.h"

using namespace std;

class Pelicula : public Video{
public:
    Pelicula();
    Pelicula(int, double, double, string, string);
    ~Pelicula();

    string tipo ();
};
