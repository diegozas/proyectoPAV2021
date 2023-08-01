#ifndef DTINFOMONITOREO_H
#define DTINFOMONITOREO_H
#include"DtInfoClase.h"
#include<iostream>
#include<list>

using namespace std;

class DtInfoMonitoreo:public DtInfoClase{
    private:
        list<string> estudiantes;
    public:
        DtInfoMonitoreo();
        DtInfoMonitoreo(int,string,list<string>,list<string>);
        list<string> getEstudiantes();
        ~DtInfoMonitoreo();
};

#endif 