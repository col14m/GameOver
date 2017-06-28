#include <assert.h>

#include "Engine.h"
#include "Objects\Conductor.h"


Conductor::Conductor(Vector coordinate, Vector velocity, size_t weight, sf::Sprite sprite, size_t level) :
	Object(coordinate, velocity, weight, sprite, level)
{
	sprite_.setOrigin(sf::Vector2f((float)0, (float)height_));

	type_ = Conductor_t;
	rate_ = 1;
}

Conductor::Conductor(Vector coordinate, Vector velocity, size_t weight, sf::Sprite sprite, size_t level, int rate) :
	Object(coordinate, velocity, weight, sprite, level)
{
	sprite_.setOrigin(sf::Vector2f((float)0, (float)height_));

	type_ = Conductor_t;
	rate_ = rate;
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
	sprite_.setPosition((float)coordinate_.GetX(), (float)coordinate_.GetY());
	engine_->getEngineWindow()->draw(sprite_);
}
