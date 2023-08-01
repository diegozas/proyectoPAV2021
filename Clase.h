#ifndef CLASE_H
#define CLASE_H
#include <string>
#include <map>
#include <list>
#include "TimeStamp.h"
#include "Participacion.h"
#include "DtParticipacion.h"
#include "DtInfoClase.h"
#include "Docente.h"
#include "AsistenteEnVivo.h"
using namespace std;

class AsistenteEnVivo;
class AsisteEnDiferido;
class Docente;

class Clase{
    private:
        int id;
        string codigoAsignatura;
        string nombre;
        TimeStamp inicio;
        TimeStamp final;
        string rutaVideo;
        map<string,Docente*> docentes;
        //list<AsisteEnDiferido*> diferido;
        list<AsistenteEnVivo*> vivo;
        map<int,Participacion*> coleccionParticipaciones;
    public:
        Clase();
        Clase(int,string,TimeStamp,Docente*,string);
        void setID(int);
        void setInicio(TimeStamp);
        void setFinal(TimeStamp);
        void setRuta(string);
        int getId();
        string getNombre();
        TimeStamp getInicio();
        TimeStamp getFinal();
        string getRuta();
        virtual ~Clase();

        
        void agregarParticipacion(Participacion*);
        void agregarAsistencia(AsistenteEnVivo*);
        int getAsistencias();
        
        list<AsistenteEnVivo*> getAsistencia();
        bool existeDocente(string);
        bool existeParticipacion(int);
        map<int,Participacion*> getColeccionParticipacion();
        Participacion* getParticipacion(int);
        void agregarDocente(Docente*);
        void eliminarParticipacion();//NUEVO
        void eliminarAsisteEnVivo();//NUEVO
        void eliminarDocentes();//NUEVO
        DtInfoClase *getDtInfoClase();
        map<string,Docente*> getDocentes();
        int getCantParticipaciones();

};



#endif
