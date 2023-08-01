#ifndef CENVIARMENSAJE_H
#define CENVIARMENSAJE_H
#include "ICEnviarMensaje.h"
#include "ManejadorPerfil.h"
#include "ManejadorClase.h"
#include "Participacion.h"
#include "DtParticipacion.h"
#include "AsistenteEnVivo.h"

#include <string>
#include <list>
#include <map>
#include <time.h>
#include <ctime>
using namespace std;

class CEnviarMensaje:public ICEnviarMensaje{
    private:
        Perfil* perfil;
        int clase;
        int participacion;
        string texto;

    public:
     CEnviarMensaje();
     ~CEnviarMensaje();   
     list<int> clasesOnlineAsistiendo(string);
     list<DtParticipacion*> selectClase(int);
     void responder(int);
     void ingresarTexto(string);
     void enviar();
     void cancelar();
     list<string> getEmails();

};

#endif