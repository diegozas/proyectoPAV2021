#ifndef CASISTEENVIVO_H
#define CASISTEENVIVO_H
#include <list>
#include <string>
#include <ctime>
#include "ICAsisteEnVivo.h"
#include "Clase.h"
#include "Perfil.h"
#include "Asignatura.h"
#include "AsistenteEnVivo.h"
#include "ManejadorPerfil.h"
#include "ManejadorAsignatura.h"
#include "ManejadorClase.h"

using namespace std;
class CAsisteEnVivo:public ICAsisteEnVivo{
    private:
        Perfil* p;        
        string codigo;
        int id;
    public:
        CAsisteEnVivo();
        ~CAsisteEnVivo();
        list <string> asignaturasInscripto(string);
        list <int> clasesOnlineDisplonibles(string);
        DtAsistir selectClase(int);
        void asistirClaseVivo();
        void cancelar();
        list<string> getEmailsEstudiantes();

};






#endif