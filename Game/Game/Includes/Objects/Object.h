#pragma once

#include "Vector//Vector.h"
#include "SFML//Main.hpp"
#include "SFML//Graphics.hpp"

class Engine;


enum ObjectCondition;
enum ObjectType;

class Object 
{
public:
	Object(Vector coordinate, Vector velocity, size_t weight, sf::Sprite sprite, size_t level);

	void Dump();
	void Dump(FILE *file);

	
	void setEngine(Engine *engine);

	virtual void Physic(double time);
	virtual void Draw();
	virtual void Control();
	virtual ObjectCondition Logic();
	virtual ObjectCondition Intersection(Object *interation);

	ObjectType GetType();
	size_t GetLevel();
	Vector GetCoordinate();
	Vector GetVelocity();
	Vector SetVelocity( Vector v);
	double GetWidth();

protected:
	Engine *engine_;
	sf::Sprite sprite_;
	size_t level_;

	Vector coordinate_;
	Vector velocity_;

	size_t weight_;
	double width_;
	double height_;

	ObjectType type_;
};

enum ObjectType
{
	Object_t,
	Background_t,
	Barrier_t,
	Conductor_t,
	Hero_t,
	NPS_t,
	Obstruction_t,
	PowerUP_t,
	Train_t
};

enum ObjectCondition
{
	LIVE = 0,
	DEAD = 1
};


