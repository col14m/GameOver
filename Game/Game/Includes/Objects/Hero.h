#pragma once

#include "Objects\Object.h"

class Hero : public Object
{
public:
	void Control();
	Object_Condition Logic();
	//void Physic();
	void Draw();
private:

};

void Hero::Control()
{
	if (sf::Keyboard::isKeyPressed(sf::Keyboard::Up))
	{
		coordinate_.SetY(LINE1_BEGIN.GetY());
	}
	if (sf::Keyboard::isKeyPressed(sf::Keyboard::Down))
	{
		velocity_ = 0.99 * velocity_;
	}
}

Object_Condition Hero::Logic()
{
	return LIVE;
}

/*void Hero::Physic()
{

}*/

void Hero::Draw()
{
	sprite_.setPosition((float)coordinate_.GetX(), (float)coordinate_.GetY());
	engine_->getEngineWindow()->draw(sprite_);
}