#ifndef DTCLASE_H
#define DTCLASE_H
#include<iostream>
#include "TipoRol.h"
#include "TimeStamp.h"
using namespace std;

class DtClase{
    private:
        int id;
        string nombre;
        TipoRol tipo;
        TimeStamp inicio;
    public:
        DtClase();
        DtClase(int,string,TipoRol,TimeStamp);
        int getId();
        string getNombre();
        TipoRol getTipo();
        TimeStamp getInicio();
        ~DtClase();
};
#endif 