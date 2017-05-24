
#include "Engine.h"
#include "Objects\Background.h"



Background::Background(Vector coordinate, Vector velocity, size_t weight, sf::Sprite sprite, size_t level) :
	Object(coordinate, velocity, weight, sprite, level)
{
	type_ = Background_t;
	rate_ = 1;
}

Background::Background(sf::Sprite sprite) :
	Object(Vector(-100, -530), Vector(-200, 0), 1000, sprite, 0)
{

}


void Background::Control()
{

}

ObjectCondition Background::Logic()
{
	if (coordinate_.GetX() <= -((2376 - 764) / 2))
	{
		coordinate_ = coordinate_ % ((2376 - 764) / 2);
	}

	return LIVE;
}

ObjectCondition Background::Intersection(Object *interation)
{
	assert(interation);

	return LIVE;
}

void Background::Draw()
{
	sprite_.setPosition((float)coordinate_.GetX() - 100/*Это просто куст*/, (float)coordinate_.GetY());
	//sprite_.setTextureRect(sf::IntRect(0, 0, 1080, 530));
	engine_->getEngineWindow()->draw(sprite_);
}