#ifndef DTASISTIR_H
#define DTASISTIR_H
#include<iostream>
using namespace std;

class DtAsistir{
    private:
        string codigo;
        int id;
    public:
        DtAsistir();
        DtAsistir(string,int);
        string getCodigo();
        int getId();
        ~DtAsistir();
        friend ostream& operator <<(ostream&,const DtAsistir&);
};
#endif 