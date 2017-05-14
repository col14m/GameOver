#pragma once

#include "Objects\Object.h"

class Hero : public Object
{
public:
	void Control();
	int Logic();
	void Physic();
	void Draw();
private:

};

void Hero::Control()
{

}

int Hero::Logic()
{
	return 0;
}

void Hero::Physic()
{

}

void Hero::Draw()
{

}