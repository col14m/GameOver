#pragma once

#include "Objects\Object.h"

class Train : public Object
{
public:
	Train(Vector coordinate, Vector velocity, size_t weight, sf::Sprite sprite, size_t level);

	void Control();
	Object_Condition Logic();
	void Draw();
private:

};

Train::Train(Vector coordinate, Vector velocity, size_t weight, sf::Sprite sprite, size_t level) :
	Object(coordinate, velocity, weight, sprite, level)
{}


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

Object_Condition Train::Logic()
{
	if (coordinate_.GetX() <= 0)
	{
		velocity_ = (-1) * velocity_;
	}

	if (coordinate_.GetX() >= 1200)
	{
		velocity_ = (-1) * velocity_;
	}
	
	return LIVE;
}



void Train::Draw()
{
	sprite_.setPosition((float) coordinate_.GetX(), (float) coordinate_.GetY());
	engine_->getEngineWindow()->draw(sprite_);
}