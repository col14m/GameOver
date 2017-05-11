#pragma once

#include "Objects\Object.h"

class Train : public Object
{
public:
	Train(sf::Sprite sprite);

	void Control();
	void Logic();
	void Draw();
private:

};

Train::Train(sf::Sprite sprite) :
	Object(Vector(1100, 306), Vector(-300, 0), 100, sprite, 0)
{}

void Train::Control()
{

}

void Train::Logic()
{

}



void Train::Draw()
{
	sprite_.setPosition(coordinate_.GetX(), coordinate_.GetY());
	engine_->getEngineWindow()->draw(sprite_);
	
}