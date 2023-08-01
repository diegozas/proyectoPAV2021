#ifndef ICENVIARMENSAJE_H
#define ICENVIARMENSAJE_H
#include <list>
#include <string>
#include "DtParticipacion.h"
using namespace std;

class ICEnviarMensaje{
    public:
    virtual list<int> clasesOnlineAsistiendo(string)=0;
    virtual list<DtParticipacion*> selectClase(int)=0;
    virtual void responder(int)=0;
    virtual void ingresarTexto(string)=0;
    virtual void enviar()=0;
    virtual void cancelar()=0;
    virtual list<string> getEmails()=0;

};


#endif