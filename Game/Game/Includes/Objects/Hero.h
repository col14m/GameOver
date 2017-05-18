#pragma once

#include "Objects\Object.h"

int PrevPress = 0;

class Hero : public Object
{
public:
	Hero(Vector coordinate, Vector velocity, size_t weight, sf::Sprite sprite, size_t level);
	void Control( sf::Event event);
	Object_Condition Logic();
	//void Physic();
	void Draw();
private:

};

Hero::Hero(Vector coordinate, Vector velocity, size_t weight, sf::Sprite sprite, size_t level) :
	Object(coordinate, velocity, weight, sprite, level)
{}

void Hero::Control(sf::Event event)
{
	//static int PrevPress;
	if (sf::Keyboard::isKeyPressed(sf::Keyboard::Up))
	{
		if (!PrevPress)
		{
			if (coordinate_.GetY() == LINE1_BEGIN.GetY())
				;
			else if (coordinate_.GetY() == LINE2_BEGIN.GetY())
				coordinate_.SetY(LINE1_BEGIN.GetY());
			else if (coordinate_.GetY() == LINE3_BEGIN.GetY())
				coordinate_.SetY(LINE2_BEGIN.GetY());
		}
		PrevPress = 1;
	}
	else if (sf::Keyboard::isKeyPressed(sf::Keyboard::Down))
	{
		if (!PrevPress)
		{
			if (coordinate_.GetY() == LINE3_BEGIN.GetY())
				;
			else if (coordinate_.GetY() == LINE2_BEGIN.GetY())
				coordinate_.SetY(LINE3_BEGIN.GetY());
			else if (coordinate_.GetY() == LINE1_BEGIN.GetY())
				coordinate_.SetY(LINE2_BEGIN.GetY());
		}
		PrevPress = 1;
	}
	else
		PrevPress = 0;

	
	/*
	if (event.type == sf::Event::Closed)
		engine_->getEngineWindow()->close();
	if (event.type == sf::Event::KeyPressed)
	{
		printf("EFUHEIO");
		if (event.key.code == sf::Keyboard::Up)
		{
			if (coordinate_.GetY() == LINE1_BEGIN.GetY())
				;
			else if (coordinate_.GetY() == LINE2_BEGIN.GetY())
				coordinate_.SetY(LINE1_BEGIN.GetY());
			else if (coordinate_.GetY() == LINE3_BEGIN.GetY())
				coordinate_.SetY(LINE2_BEGIN.GetY());
		}
		else if (event.key.code == sf::Keyboard::Down)
		{
			if (coordinate_.GetY() == LINE3_BEGIN.GetY())
				;
			else if (coordinate_.GetY() == LINE2_BEGIN.GetY())
				coordinate_.SetY(LINE3_BEGIN.GetY());
			else if (coordinate_.GetY() == LINE1_BEGIN.GetY())
				coordinate_.SetY(LINE2_BEGIN.GetY());
		}
	
	*/
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