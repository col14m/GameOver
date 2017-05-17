#pragma once

#include "Objects\Object.h"

class Barrier : public Object
{
public:
	void Control();
	Object_Condition Logic();
	//void Physic();
	void Draw();
private:

};