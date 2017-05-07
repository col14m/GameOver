#pragma once

#include "Vector//Vector.h"
#include "SFML//Main.hpp"
#include "SFML//Graphics.hpp"

extern class Engine {};

class Object 
{
public:
	Object();
	Object(Vector coordinate, Vector velocity, size_t weight, sf::Sprite sprite);

private:
	virtual void Control();
	virtual void Logic();
	virtual void Physic();
	virtual void Draw();
	
	Engine *engine;
	sf::Sprite sprite_;
	size_t level_;

	Vector coordinate_;
	Vector velocity_;

	size_t weight_;
};