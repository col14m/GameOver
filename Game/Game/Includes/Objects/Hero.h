#pragma once

#include "Objects\Object.h"

extern int PrevPress;

class Hero : public Object
{
public:
	Hero(Vector coordinate, Vector velocity, size_t weight, sf::Sprite sprite, size_t level);
	
	void Control();
	//void Physic();
	void Draw();

	ObjectCondition Logic();
	ObjectCondition Intersection(Object *interation);

private:
	sf::IntRect* Animation_;
};
