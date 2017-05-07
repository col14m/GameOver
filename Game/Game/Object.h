#pragma once

extern class Vector {};
extern class Sprite {};

class Object 
{
public:
	Object();
	Object(Vector coordinate, Vector velocity, size_t weight, Sprite sprite);

private:
	virtual void Control();
	virtual void Logic();
	virtual void Physic();
	virtual void Draw();
	
	Sprite sprite_;
	
	Vector coordinate_;
	Vector velocity_;

	size_t weight_;
};