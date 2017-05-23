#pragma once

#include "Objects\Object.h"

class Barrier : public Object
{
public:
	void Control();
	ObjectCondition Logic();
	//void Physic();
	void Draw();
private:

};