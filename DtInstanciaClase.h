#ifndef DTINSTANCIACLASE_H
#define DTINSTANCIACLASE_H
#include <iostream>
using namespace std;
class DtInstanciaClase{
    private:
        bool monitoreo;
        bool practico;
        bool teorico;
    public:
        DtInstanciaClase();
        DtInstanciaClase(bool,bool,bool);
        bool getMonitoreo();
        bool getPractico();
        bool getTeorico();
        ~DtInstanciaClase();
        friend ostream& operator <<(ostream&,const DtInstanciaClase&);

};




#endif