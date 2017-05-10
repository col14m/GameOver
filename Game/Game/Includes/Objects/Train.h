#pragma once

#include "Objects\Barrier.h"

class Train : public Barrier
{
public:
	void Control();
	void Logic();
	void Physic();
	void Draw();
private:

};