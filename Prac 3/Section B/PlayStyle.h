#ifndef PLAYSTYLE_H
#define PLAYSTYLE_H
#include <iostream>
#include <string>
class PlayStyle
{
public:
	PlayStyle();
	virtual ~PlayStyle();
	virtual std::string attack() = 0;
};

#endif
