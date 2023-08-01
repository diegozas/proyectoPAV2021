#ifndef CLISTADOCLASE_H
#define CLISTADOCLASE_H
#include<iostream>
#include<list>
#include "DtInfoClase.h"
#include "ICListadoClase.h"
using namespace std;

class CListadoClase:public ICListadoClase{
    private:
        string codigoAsignatura;
        string emailDocente;
    public:
        CListadoClase();
        ~CListadoClase();

        list<string> asignaturasAsignadas(string);
        list<DtInfoClase*> selectAsignatura(string);
        list<string> getEmailsDocentes();
};

#endif