#ifndef ICASISTEENVIVO_H
#define ICASISTEENVIVO_H
#include <list>
#include <string>
#include "DtAsistir.h"
using namespace std;
class ICAsisteEnVivo{
    public:
    virtual list <string> asignaturasInscripto(string)=0;
    virtual list <int> clasesOnlineDisplonibles(string)=0;
    virtual DtAsistir selectClase(int)=0;
    virtual void asistirClaseVivo()=0;
    virtual void cancelar()=0;
    virtual list<string> getEmailsEstudiantes()=0;
};

#endif