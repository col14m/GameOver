#pragma once

#include "Objects\Object.h"

class Train : public Object
{
public:
	Train(Vector coordinate, Vector velocity, size_t weight, sf::Sprite sprite, size_t level);

	void Control();
	ObjectCondition Logic();
	ObjectCondition Intersection(Object *interation);
	void Draw();
private:

};

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
	if ((coordinate_.GetX() <= (-1)*width_) || (coordinate_.GetX() >= 1200))
	{
		return DEAD;
	}
	
	return LIVE;
}

ObjectCondition Train::Intersection(Object *interation)
{
	assert(interation);

	return LIVE;
}



void Train::Draw()
{
	sprite_.setPosition((float) coordinate_.GetX(), (float) coordinate_.GetY());
	engine_->getEngineWindow()->draw(sprite_);
}