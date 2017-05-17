#pragma once

#include "Objects\Object.h"

class Hero : public Object
{
public:
	void Control();
	Object_Condition Logic();
	void Physic();
	void Draw();
private:

};

void Hero::Control()
{

}

Object_Condition Hero::Logic()
{
	return LIVE;
}

void Hero::Physic()
{

}

void Hero::Draw()
{

}