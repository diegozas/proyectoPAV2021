#ifndef DTINFOCLASE_H
#define DTINFOCLASE_H

#include<iostream>
#include<list>

using namespace std;

class DtInfoClase{
    protected:
        int id;
        string nombre;
        list<string> docentes;
    public:
        DtInfoClase();
        DtInfoClase(int,string,list<string>);
        DtInfoClase(int,string,list<string>,int);
        int getId();
        string getNombre();
        list<string> getDocentes();
        virtual ~DtInfoClase();
    friend ostream& operator <<(ostream &,const DtInfoClase*);
};

#endif 