
#include "Engine.h"
#include "Objects\Train.h"

Train::Train(Vector coordinate, Vector velocity, size_t weight, sf::Sprite sprite, size_t level) :
	Object(coordinate, velocity, weight, sprite, level)
{
	type_ = Train_t;
}


void Train::Control()
{
	if (sf::Keyboard::isKeyPressed(sf::Keyboard::Left))
	{
		velocity_ = 1.01 * velocity_;
	}
	if (sf::Keyboard::isKeyPressed(sf::Keyboard::Right))
	{
		velocity_ = 0.99 * velocity_;
	}

}


ObjectCondition Train::Logic()
{
	if (coordinate_.GetX() <= LINE_END_X)
		return DEAD;

	return LIVE;
}

ObjectCondition Train::Intersection(Object *interation)
{
	assert(interation);

	return LIVE;
}



void Train::Draw()
{
	sprite_.setPosition((float)coordinate_.GetX(), (float)coordinate_.GetY());
	engine_->getEngineWindow()->draw(sprite_);
}