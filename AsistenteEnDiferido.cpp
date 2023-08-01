#include "AsistenteEnDiferido.h"
    AsistenteEnDiferido::AsistenteEnDiferido(){}
    AsistenteEnDiferido::AsistenteEnDiferido(TimeStamp acceso){
        this->acceso= acceso;
    }

    TimeStamp AsistenteEnDiferido::getAcceso(){
        return this->acceso;
    }
    void AsistenteEnDiferido::setAcceso(TimeStamp acceso){
        this->acceso=acceso;
    }
    AsistenteEnDiferido::~AsistenteEnDiferido(){}