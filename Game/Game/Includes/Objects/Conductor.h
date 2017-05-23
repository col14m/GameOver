#pragma once

#include "Objects\Barrier.h"

class Conductor : public Object
{
public:
	Conductor(Vector coordinate, Vector velocity, size_t weight, sf::Sprite sprite, size_t level);

	void Control();
	Object_Condition Logic();
	Object_Condition Intersection(Object *interation);
	void Draw();
private:

};

Conductor::Conductor(Vector coordinate, Vector velocity, size_t weight, sf::Sprite sprite, size_t level) :
	Object(coordinate, velocity, weight, sprite, level)
{}

void Conductor::Control()
{

}

Object_Condition Conductor::Logic()
{
	if (coordinate_.GetX() <= LINE_END_X)
		return DEAD;
	return LIVE;
}

Object_Condition Conductor::Intersection(Object *interation)
{
	assert(interation);

	return LIVE;
}

void Conductor::Draw()
{
	sprite_.setPosition( (float) coordinate_.GetX(), (float)coordinate_.GetY());
	engine_->getEngineWindow()->draw(sprite_);
}
