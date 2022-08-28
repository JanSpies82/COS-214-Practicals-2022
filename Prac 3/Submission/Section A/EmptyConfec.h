#ifndef EMPTYCONFEC_H
#define EMPTYCONFEC_H

#include "Confectionary.h"

class EmptyConfec : public Confectionary
{
public:
    EmptyConfec();
    ~EmptyConfec();
    std::string getDescription();
};

#endif
