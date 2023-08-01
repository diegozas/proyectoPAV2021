#ifndef TEORICO_H
#define TEORICO_H
#include "Clase.h"

class Teorico : public Clase
{
private:
public:
    Teorico();
    Teorico(int, string, TimeStamp, Docente *, string);
    ~Teorico();
    DtInfoClase *getDtInfoClase();
};

#endif