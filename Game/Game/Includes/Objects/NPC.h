#pragma once

//#include "Objects\Object.h"

class NPC : public Object
{
public:
	NPC(Vector coordinate, Vector velocity, size_t weight, sf::Sprite sprite, size_t level);
	
	void Control();
	void Draw();

	void Physic(double time);
	ObjectCondition Logic();
	ObjectCondition Intersection(Object *interation);
	double time_;
private:

};