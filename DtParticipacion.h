#ifndef DTPARTICIPACION_H
#define DTPARTICIPACION_H
#include "TimeStamp.h"
#include<iostream>
#include<list>
using namespace std;

class DtParticipacion{
    private:
        int id;
        TimeStamp fecha;
        string mensaje;
        string email;
        DtParticipacion* responde;
        bool respuesta;
    public:
        DtParticipacion();
        DtParticipacion(int,TimeStamp,string,string);
        DtParticipacion(int,TimeStamp,string,string,DtParticipacion*);
        int getId();
        TimeStamp getFecha();
        string getMensaje();
        DtParticipacion* getRespuesta();
        bool tieneRespuesta();
        friend ostream& operator<<(ostream&,const DtParticipacion*);
        ~DtParticipacion();
};
#endif 