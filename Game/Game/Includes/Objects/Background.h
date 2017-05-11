#pragma once

#include "Objects\Object.h"

class Background : public Object
{
public:
	Background(sf::Sprite sprite);
	~Background();
	void Control();
	void Logic();
	void Physic();
	void Draw();
private:

};

Background::Background(sf::Sprite sprite) :
	Object(Vector (0,0), Vector (-2, 0), 1000, sprite, 0)
{

}


void Background::Control()
{

}

void Background::Logic()
{

}

void Background::Physic()
{

}

void Background::Draw()
{
	engine_->getEngineWindow()->draw(sprite_);
}