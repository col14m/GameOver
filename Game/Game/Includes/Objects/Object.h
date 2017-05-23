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

	void Physic(double time);
	void setEngine(Engine *engine);

	virtual void Draw();
	virtual void Control();
	virtual ObjectCondition Logic();
	virtual ObjectCondition Intersection(Object *interation);

	ObjectType GetType();
	size_t GetLevel();
	Vector GetCoordinate();
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


Object::Object(Vector coordinate, Vector velocity, size_t weight, sf::Sprite sprite, size_t level) :
	engine_(NULL),
	sprite_(sprite),
	level_(level),
	coordinate_(coordinate),
	velocity_(velocity),
	weight_(weight),
	width_(0),
	height_(0),
	type_(Object_t)
{
	width_ = sprite_.getTextureRect().width;
	height_ = sprite_.getTextureRect().height;

	sprite_.setOrigin(sf::Vector2f((float) 0, (float) height_));
}

void Object::Dump()
{
	printf("Object [0x%p] {\n", this);
	printf("\tengine     : 0x%p;\n", engine_);
	printf("\tsprite     : 0x%p;\n", &sprite_);
	printf("\tlevel      : %zu;\n", level_);
	printf("\tcoordinate : "); coordinate_.Dump();
	printf("\tvelocity   : "); velocity_.Dump();
	printf("\tweight     : %zu\n", weight_);
	printf("}\n");
}

void Object::Dump(FILE *file)
{
	assert(file);

	fprintf(file, "Object [0x%p] {\n", this);
	fprintf(file, "\tengine     : 0x%p;\n", engine_);
	fprintf(file, "\tsprite     : 0x%p;\n", &sprite_);
	fprintf(file, "\tlevel      : %zu;\n", level_);
	fprintf(file, "\tcoordinate : "); coordinate_.Dump();
	fprintf(file, "\tvelocity   : "); velocity_.Dump();
	fprintf(file, "\tweight     : %zu\n", weight_);
	fprintf(file, "}\n");
}


void Object::Physic(double time)
{
	assert(time >= 0);

	coordinate_ = coordinate_ + time * velocity_;
}

void Object::setEngine(Engine *engine)
{
	assert(engine);

	engine_ = engine;
}



void Object::Draw() {}

void Object::Control() {}

ObjectCondition Object::Logic()
{
	return LIVE;
}

ObjectCondition Object::Intersection(Object *interation) 
{
	return LIVE;
}


size_t Object::GetLevel()
{
	return level_;
}

Vector Object::GetCoordinate()
{
	return coordinate_;
}

double Object::GetWidth()
{
	return width_;
}

ObjectType Object::GetType()
{
	return type_;
}