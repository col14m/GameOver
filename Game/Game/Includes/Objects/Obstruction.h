#pragma once

#include "Objects\Barrier.h"

class Obstruction : public Barrier
{
public:
	void Control();
	void Logic();
	void Physic();
	void Draw();
private:

};