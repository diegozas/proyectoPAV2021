#ifndef ASISTENTEENDIDERIDO
#define ASISTENTEENDIDERIDO
#include "TimeStamp.h"

class AsistenteEnDiferido{
    private:
        TimeStamp acceso;
    public:
        AsistenteEnDiferido();
        AsistenteEnDiferido(TimeStamp acceso);
        TimeStamp getAcceso();
        void setAcceso(TimeStamp acceso);
        ~AsistenteEnDiferido();
};
#endif