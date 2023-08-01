#ifndef DTINICIARCLASEFULL_H
#define DTINICIARCLASEFULL_H

#include "DtIniciarClase.h"
#include "TimeStamp.h"
#include<list>
#include<iostream>
using namespace std;

class DtIniciarClaseFull:public DtIniciarClase{
    protected:
        int id;
    public:
        DtIniciarClaseFull();
        DtIniciarClaseFull(string,string,TimeStamp,int);
        int getId();
        friend ostream& operator<<(ostream&,const DtIniciarClaseFull&);// Nuevo Carlos
        ~DtIniciarClaseFull();

};
#endif 