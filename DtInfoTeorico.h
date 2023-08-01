#ifndef DTINFOTEORICO_H
#define DTINFOTEORICO_H
#include"DtInfoClase.h"
#include<iostream>

using namespace std;

class DtInfoTeorico:public DtInfoClase{
    private:
        int cantAsistentes;
    public:
        DtInfoTeorico();
        DtInfoTeorico(int,string,list<string>,int);
        int getCantAsistentes();
        ~DtInfoTeorico();
};
#endif 
