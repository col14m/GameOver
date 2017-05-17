#pragma once
#include <Windows.h>
#include "Objects\Object.h"

#define SIZE_X 105
#define SIZE_Y 125

class Hero : public Object
{
public:
	
	Hero(Vector coordinate, Vector velocity, size_t weight, sf::Sprite sprite, size_t level);
	void Control();
	int Logic();
	void Physic();
	void Draw();
private:
	size_t frames_;
	size_t  countFrames_;
};

Hero::Hero(Vector coordinate, Vector velocity, size_t weight, sf::Sprite sprite, size_t level) :
	Object(coordinate, velocity, weight, sprite, level),
	frames_ (0),
	countFrames_(0)
{}


void Hero::Control()
{
	if (sf::Keyboard::isKeyPressed(sf::Keyboard::Left))
	{
		velocity_ = 1.01 * velocity_;
	}
	if (sf::Keyboard::isKeyPressed(sf::Keyboard::Right))
	{
		velocity_ = 0.99 * velocity_;
	}
}

int Hero::Logic()
{
	sprite_.setTextureRect(sf::IntRect((12 - frames_ % 13) * SIZE_X, 0, SIZE_X, SIZE_Y));
	//Sleep(500);
	countFrames_++;
	if (countFrames_ == 7)
	{
		printf("%lu\n", frames_);
		frames_++;
		frames_ %= 13;
		countFrames_ = 0;
	}

	return 0;
}

void Hero::Physic()
{

}

void Hero::Draw()
{
	sprite_.setPosition((float)coordinate_.GetX(), (float)coordinate_.GetY());
	engine_->getEngineWindow()->draw(sprite_);
}