#pragma once

#include "Objects\Object.h"

class Background : public Object
{
public:
	Background(sf::Sprite sprite);
	~Background();
	void Control();
	int Logic();
	void Draw();
private:

};

Background::Background(sf::Sprite sprite) :
	Object(Vector(-100, -530), Vector(-200, 0), 1000, sprite, 0)
{

}


void Background::Control()
{

}

int Background::Logic()
{
	coordinate_ = coordinate_ % ((2376 - 764) / 2);
	return 0;
}

void Background::Draw()
{
	sprite_.setPosition((float) coordinate_.GetX() - 100/*��� ������ ����*/, (float) coordinate_.GetY());
	//sprite_.setTextureRect(sf::IntRect(0, 0, 1080, 530));
	engine_->getEngineWindow()->draw(sprite_);
}