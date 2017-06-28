#pragma once

#include "Objects\Object.h"

class Conductor : public Object
{
public:
	Conductor(Vector coordinate, Vector velocity, size_t weight, sf::Sprite sprite, size_t level);

	Conductor(Vector coordinate, Vector velocity, size_t weight, sf::Sprite sprite, size_t level, int rate);

	void Control();
	ObjectCondition Logic();
	ObjectCondition Intersection(Object *interation);
	void Draw();
private:

};
