#pragma once
#include <iostream>
#include <string>
#include <vector>
#include "videos.h"
#include "episodio.h"

using namespace std;

class Serie : public Video {
public:
    vector<Episodio*> temporada;
    Serie();
    Serie(int, double, double, string, string);
    ~Serie();

    Episodio* get_episodio (int );

    void agregar_episodio(Episodio *episodio);
    void cal_promedio_serie(Episodio *episodio);
    void duracion_serie(Episodio *episodio);
    string tipo ();

    Episodio *get_episodio();
};
