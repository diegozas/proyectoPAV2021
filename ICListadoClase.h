#ifndef ICLISTADOCLASE_H
#define ICLISTADOCLASE_H
#include<list>
#include<iostream>
#include "DtInfoClase.h"
using namespace std;
class ICListadoClase
{
public:
    virtual list<string> asignaturasAsignadas(string)=0;
    virtual list<DtInfoClase*> selectAsignatura(string)=0;
    virtual list<string> getEmailsDocentes()=0;
};
#endif