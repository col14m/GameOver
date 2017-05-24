#pragma once

#include <assert.h>
#include "Objects\Object.h"

class Train : public Object
{
public:
	Train(Vector coordinate, Vector velocity, size_t weight, sf::Sprite sprite, size_t level);
	Train(Vector coordinate, Vector velocity, size_t weight, sf::Sprite sprite, size_t level, int rate);

	void Control();
	ObjectCondition Logic();
	ObjectCondition Intersection(Object *interation);
	void Draw();
private:

};
