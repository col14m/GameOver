#pragma once

#include "Objects\Object.h"

class Hero : public Object
{
public:
	Hero(Vector coordinate, Vector velocity, size_t weight, sf::Sprite sprite, size_t level);
	void Control();
	Object_Condition Logic();
	//void Physic();
	void Draw();
private:

};

Hero::Hero(Vector coordinate, Vector velocity, size_t weight, sf::Sprite sprite, size_t level) :
	Object(coordinate, velocity, weight, sprite, level)
{}

void Hero::Control()
{
	if (sf::Keyboard::isKeyPressed(sf::Keyboard::Up))
	{
		if (coordinate_.GetY() == LINE1_BEGIN.GetY())
			;
		else if (coordinate_.GetY() == LINE2_BEGIN.GetY())
			coordinate_.SetY(LINE1_BEGIN.GetY());
		else if (coordinate_.GetY() == LINE3_BEGIN.GetY())
			coordinate_.SetY(LINE2_BEGIN.GetY());
	}
	if (sf::Keyboard::isKeyPressed(sf::Keyboard::Down))
	{
		if (coordinate_.GetY() == LINE3_BEGIN.GetY())
			;
		else if (coordinate_.GetY() == LINE2_BEGIN.GetY())
			coordinate_.SetY(LINE3_BEGIN.GetY());
		else if (coordinate_.GetY() == LINE1_BEGIN.GetY())
			coordinate_.SetY(LINE2_BEGIN.GetY());
	}
}

Object_Condition Hero::Logic()
{
	return LIVE;
}


void Hero::Draw()
{
	sprite_.setPosition((float)coordinate_.GetX(), (float)coordinate_.GetY());
	engine_->getEngineWindow()->draw(sprite_);
}