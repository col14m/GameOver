#pragma once

#include "Objects\Object.h"

class Train : public Object
{
public:
	Train(sf::Sprite sprite);

	void Control();
	void Logic();
	void Physic(double time);
	void Draw();
private:

};

Train::Train(sf::Sprite sprite) :
	Object(Vector(1100, 306), Vector(-100, 0), 100, sprite, 0)
{}

void Train::Control()
{

}

void Train::Logic()
{

}

void Train::Physic(double time)
{
	coordinate_ = coordinate_ + time * velocity_;
}

void Train::Draw()
{
	sprite_.setPosition(coordinate_.GetX(), coordinate_.GetY());
	engine_->getEngineWindow()->draw(sprite_);
	
}