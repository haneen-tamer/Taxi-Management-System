#ifndef SAVEABLE_H
#define SAVEABLE_H

#include<QString>
class Saveable
{

public:
    virtual QString get_saveable_line()=0;
};

#endif // SAVEABLE_H
