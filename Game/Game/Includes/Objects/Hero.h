#pragma once

#include "Objects\Object.h"

int PrevPress = 0;

class Hero : public Object
{
public:
	Hero(Vector coordinate, Vector velocity, size_t weight, sf::Sprite sprite, size_t level);
	
	void Control();
	//void Physic();
	void Draw();

	Object_Condition Logic();
	Object_Condition Intersection(Object *interation);
private:

};

Hero::Hero(Vector coordinate, Vector velocity, size_t weight, sf::Sprite sprite, size_t level) :
	Object(coordinate, velocity, weight, sprite, level)
{}

void Hero::Control()
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

}

Object_Condition Hero::Logic()
{
	return LIVE;
}

Object_Condition Hero::Intersection(Object *interation)
{
	assert(interation);

	if (fabs(coordinate_.GetY() - interation->GetCoordinate().GetY()) > 10)
	{
		return LIVE;
	}

	double distanceX = interation->GetCoordinate().GetX() - coordinate_.GetX() - width_;
	
	if ((distanceX < 0) && (distanceX > (-1)*(interation->GetWidth() + width_)))
	{

		printf("%lf +\n", distanceX);
	}


	return LIVE;
}


void Hero::Draw()
{
	sprite_.setPosition((float)coordinate_.GetX(), (float)coordinate_.GetY());
	engine_->getEngineWindow()->draw(sprite_);
}