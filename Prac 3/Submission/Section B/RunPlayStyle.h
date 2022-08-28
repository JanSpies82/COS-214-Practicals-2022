#ifndef RUNPLAYSTYLE_H
#define RUNPLAYSTYLE_H
#include "PlayStyle.h"

class RunPlayStyle : public PlayStyle
{
public:
	RunPlayStyle();
	~RunPlayStyle();
	std::string attack();
};

#endif
