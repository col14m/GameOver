#pragma once

#include "Objects\Object.h"

class Background : public Object
{
public:
	Background(sf::Sprite sprite);
	~Background();
	void Control();
	void Logic();
	void Physic(double time);
	void Draw();
private:

};

Background::Background(sf::Sprite sprite) :
	Object(Vector (0,0), Vector (-200, 0), 1000, sprite, 0)
{

}


void Background::Control()
{

}

void Background::Logic()
{

}

void Background::Physic(double time)
{
	coordinate_ = coordinate_ + time * velocity_ ;
	printf("%f\n", time);
}

void Background::Draw()
{
	sprite_.setPosition(coordinate_.GetX(), coordinate_.GetY());
	//sprite_.setTextureRect(sf::IntRect(0, 0, 1080, 530));
	engine_->getEngineWindow()->draw(sprite_);
}