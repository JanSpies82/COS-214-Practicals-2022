#ifndef ATTAKPLAYSTYLE_H
#define ATTAKPLAYSTYLE_H
#include "PlayStyle.h"
class AttackPlayStyle : public PlayStyle
{
public:
	AttackPlayStyle();
	~AttackPlayStyle();
	std::string attack();
};

#endif
