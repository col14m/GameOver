#pragma once

#include "Objects\Object.h"

class Barrier : public Object
{
public:
	void Control();
	void Logic();
	void Physic();
	void Draw();
private:

};