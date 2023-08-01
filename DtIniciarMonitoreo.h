#ifndef DTINICIARMONITOREO_H
#define DTINICIARMONITOREO_H
#include<list>
#include<iostream>
#include"TimeStamp.h"
#include"DtIniciarClaseFull.h"
#include"DtIniciarClase.h"
using namespace std;

class DtIniciarMonitoreo:public DtIniciarClaseFull{
    protected:
        list<string> habilitados;
    public:
        DtIniciarMonitoreo();
        DtIniciarMonitoreo(string,string,TimeStamp,int,list<string>);
        list<string> getHabilitados();
        ~DtIniciarMonitoreo();
};
#endif 