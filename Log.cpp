#include "Log.h"
#include "TimeStamp.h"

Log::Log(){}
Log::Log(TimeStamp inicio,TimeStamp fin){
    this->inicio=inicio;
    this->fin=fin;
}

TimeStamp Log::getInicio(){
    return this->inicio;    
}

TimeStamp Log::getFin(){
    return this->fin;
}

Log::~Log(){}