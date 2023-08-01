#ifndef TIMESTAMP_H
#define TIMESTAMP_H
#include <iostream>
using namespace std;
#include "Fecha.h"

class TimeStamp{
    private:
        Fecha fecha;
        int hora;
        int minuto;
        int segundo;
    public:
        TimeStamp();
        TimeStamp(Fecha,int,int,int);
        Fecha getFecha();
        int getHora();
        int getMinuto();
        int getSegundo();
        ~TimeStamp();
        friend ostream& operator<<(ostream&,const TimeStamp&);
};

#endif 
