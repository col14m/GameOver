#pragma once

#include "Objects\Barrier.h"

class Obstruction : public Barrier
{
public:
	Obstruction(Vector coordinate, Vector velocity, size_t weight, sf::Sprite sprite, size_t level);
	void Control();
	Object_Condition  Logic();
	void Draw();
private:

};