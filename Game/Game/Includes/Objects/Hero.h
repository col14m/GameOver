#pragma once

#include "Objects\Object.h"

class Hero : public Object
{
public:
	void Control();
	void Logic();
	void Physic();
	void Draw();
private:

};
