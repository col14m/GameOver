#pragma once

#include "Objects\Object.h"


class Background : public Object
{
public:
	Background(sf::Sprite sprite);
	Background(Vector coordinate, Vector velocity, size_t weight, sf::Sprite sprite, size_t level);

	void Control();
	ObjectCondition Logic();
	ObjectCondition Intersection(Object *interation);
	void Draw();
private:

};
