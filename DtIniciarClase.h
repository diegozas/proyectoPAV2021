#ifndef DTINICIARCLASE_H
#define DTINICIARCLASE_H

#include<iostream>
#include"TimeStamp.h"

using namespace std;

class DtIniciarClase{
    protected:
        string codigo;//CODIGO DE ASiGNATURA
        string nombre;//NOMBRE DE LA CLASE
        TimeStamp fechaHora;
    public:
        DtIniciarClase();
        DtIniciarClase(string,string,TimeStamp);
        string getCodigo();
        string getNombre();
        TimeStamp getFechaHora();
        ~DtIniciarClase();
};
#endif 