#ifndef ASISTENTEENVIVO_H
#define ASISTENTEENVIVO_H
//#include "Estudiante.h"
#include "TimeStamp.h"

class Estudiante;

class AsistenteEnVivo{
    private:
        TimeStamp inicio;
        TimeStamp fin;
        Estudiante* e;

    public:
        AsistenteEnVivo();
        AsistenteEnVivo(TimeStamp inicio, TimeStamp fin,Estudiante*);
        TimeStamp getInicio();
        void setInicio(TimeStamp inicio);

        TimeStamp getfin();
        void setfin(TimeStamp fin);

        void setEstudiante(Estudiante*);
        Estudiante* getEstudiante();
        ~AsistenteEnVivo();
};
#endif
