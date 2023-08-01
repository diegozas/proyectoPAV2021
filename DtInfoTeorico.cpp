#include"DtInfoClase.h"
#include"DtInfoTeorico.h"
#include<iostream>

using namespace std;

DtInfoTeorico::DtInfoTeorico(){};
DtInfoTeorico::DtInfoTeorico(int id,string nombre,list<string> docentes,int cantAsistentes){
    this->id=id;
    this->nombre=nombre;
    this->docentes=docentes;
    this->cantAsistentes=cantAsistentes;
};

int DtInfoTeorico::getCantAsistentes(){
    return this->cantAsistentes;
};
DtInfoTeorico::~DtInfoTeorico(){};