#include "AsistenteEnVivo.h"
    AsistenteEnVivo::AsistenteEnVivo(){}
    AsistenteEnVivo::AsistenteEnVivo(TimeStamp inicio, TimeStamp fin,Estudiante* estudiante){
        this->inicio=inicio;
        this->fin=fin;
        this->e=estudiante;
    }
    TimeStamp AsistenteEnVivo::getInicio(){
        return this->inicio;
    }
    void AsistenteEnVivo::setInicio(TimeStamp inicio){
        this->inicio=inicio;
    }

    TimeStamp AsistenteEnVivo::getfin(){
        return this->fin;
    }
    void AsistenteEnVivo::setfin(TimeStamp fin){
        this->fin=fin;
    }

    Estudiante* AsistenteEnVivo::getEstudiante(){
        return this->e;
    }

    void AsistenteEnVivo::setEstudiante(Estudiante* estudiante){
        this->e=estudiante;
    }

    AsistenteEnVivo::~AsistenteEnVivo(){}