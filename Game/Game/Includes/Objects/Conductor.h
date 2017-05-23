#pragma once

#include "Objects\Barrier.h"

class Conductor : public Object
{
public:
	Conductor(Vector coordinate, Vector velocity, size_t weight, sf::Sprite sprite, size_t level);

	void Control();
	ObjectCondition Logic();
	ObjectCondition Intersection(Object *interation);
	void Draw();
private:

};

Conductor::Conductor(Vector coordinate, Vector velocity, size_t weight, sf::Sprite sprite, size_t level) :
	Object(coordinate, velocity, weight, sprite, level)
{
	type_ = Conductor_t;
}

void Conductor::Control()
{

}

ObjectCondition Conductor::Logic()
{
	if (coordinate_.GetX() <= LINE_END_X)
		return DEAD;
	return LIVE;
}

ObjectCondition Conductor::Intersection(Object *interation)
{
	assert(interation);

	return LIVE;
}

void Conductor::Draw()
{
	sprite_.setPosition( (float) coordinate_.GetX(), (float)coordinate_.GetY());
	engine_->getEngineWindow()->draw(sprite_);
}
