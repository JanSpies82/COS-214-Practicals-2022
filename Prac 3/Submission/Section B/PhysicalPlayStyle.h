#ifndef PHYSICALPLAYSTYLE_H
#define PHYSICALPLAYSTYLE_H

#include "PlayStyle.h"
class PhysicalPlayStyle : public PlayStyle
{
public:
	PhysicalPlayStyle();
	~PhysicalPlayStyle();
	std::string attack();
};

#endif
