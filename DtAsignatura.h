#ifndef DTASIGNATURA_H
#define DTASIGNATURA_H
#include "DtInstanciaClase.h"
#include <string>
#include <iostream>
using namespace std;
class DtAsignatura{
    private:
        string codigo;
        string nombre;
        DtInstanciaClase tipoClase ;
    public:
        DtAsignatura();
        DtAsignatura(string,string,DtInstanciaClase);
        string getCodigo();
        string getNombre();
        DtInstanciaClase getTipo();
        ~DtAsignatura();
        friend ostream& operator <<(ostream&,const DtAsignatura&);
};


#endif