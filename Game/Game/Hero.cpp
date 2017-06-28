
#include "Engine.h"
#include "Objects\Object.h"
#include "Objects\Hero.h"

int PrevPress = 0;

Hero::Hero(Vector coordinate, Vector velocity, size_t weight, sf::Sprite sprite, size_t level) :
	Object(coordinate, velocity, weight, sprite, level)
{
	Animation_ = new sf::IntRect[6];
	for (int i = 0; i < 6; i++)
	{
		Animation_[0].height = 110;
		Animation_[0].width = 94;
	}

	Animation_[0].left = 380;
	Animation_[0].top = 340.5 ;
	width_ = 94;
	height_ = 110;

	sprite_.setOrigin(sf::Vector2f((float)0, (float)height_));

	type_ = Hero_t;
}

void Hero::Control()
{
	if (sf::Keyboard::isKeyPressed(sf::Keyboard::Up))
	{
		if (!PrevPress)
		{
			if (coordinate_.GetY() == LINE1_BEGIN.GetY())
				;
			else if (coordinate_.GetY() == LINE2_BEGIN.GetY())
			{
				level_ = 1;
				coordinate_.SetY(LINE1_BEGIN.GetY());
			}
			else if (coordinate_.GetY() == LINE3_BEGIN.GetY())
			{
				level_ = 2;
				coordinate_.SetY(LINE2_BEGIN.GetY());
			}
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
			{
				level_ = 3;
				coordinate_.SetY(LINE3_BEGIN.GetY());
			}
			else if (coordinate_.GetY() == LINE1_BEGIN.GetY())
			{
				level_ = 2;
				coordinate_.SetY(LINE2_BEGIN.GetY());
			}
		}
		PrevPress = 1;
	}
	else
	{
		PrevPress = 0;
	}
}

ObjectCondition Hero::Logic()
{
	return LIVE;
}

ObjectCondition Hero::Intersection(Object *interation)
{
	assert(interation);

	if (fabs(coordinate_.GetY() - interation->GetCoordinate().GetY()) > 10)
	{
		return LIVE;
	}

	double distanceX = interation->GetCoordinate().GetX() - coordinate_.GetX() - width_;

	if ((distanceX < 0) && (distanceX >(-1)*(interation->GetWidth() + width_)))
	{
		switch (interation->GetType()) //оепедекюрэ!!!
		{
		case Object_t:
			break;
		case Background_t:
			break;
		case Barrier_t:
			break;
		case Conductor_t:
			printf("CONDUCTOR\n");
			return DEAD;
			break;
		case Hero_t:
			break;
		case NPS_t:
			break;
		case Obstruction_t:
			break;
		case PowerUP_t:
			break;
		case Train_t:
			printf("TRAIN\n");
			return DEAD;
			break;
		default:
			break;
		}

		printf("%lf +\n", distanceX);
	}


	return LIVE;
}


void Hero::Draw()
{
	width_ = Animation_[0].width;
	height_ = Animation_[0].height;

	sprite_.setTextureRect(Animation_[0]);

	//prite_.setTextureRect(sf::IntRect(380, 340.5, 94, 110));

	sprite_.setPosition((float)coordinate_.GetX(), (float)coordinate_.GetY());
	engine_->getEngineWindow()->draw(sprite_);
}