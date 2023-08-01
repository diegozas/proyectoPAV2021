#ifndef LOG_H
#define LOG_H
#include "TimeStamp.h"
class Log{
    private:
        TimeStamp inicio;
        TimeStamp fin;
    public:
        Log();
        Log(TimeStamp,TimeStamp);
        TimeStamp getInicio();
        TimeStamp getFin();
        ~Log();
};
#endif 