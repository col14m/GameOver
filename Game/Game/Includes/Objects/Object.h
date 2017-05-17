#pragma once

#include "Vector//Vector.h"
#include "SFML//Main.hpp"
#include "SFML//Graphics.hpp"

class Engine;
enum Object_Condition
{
	LIVE = 0,
	DEAD = 1
};

class Object 
{
public:
	Object(Vector coordinate, Vector velocity, size_t weight, sf::Sprite sprite, size_t level);

	void Dump();
	void Dump(FILE *file);

	void Physic(double time);
	void setEngine(Engine *engine);

	virtual void Control();
	virtual Object_Condition Logic();
	virtual void Draw();

	size_t GetLevel();
protected:
	Engine *engine_;
	sf::Sprite sprite_;
	size_t level_;

	Vector coordinate_;
	Vector velocity_;

	size_t weight_;
	double width_;
	double height_;
};

Object::Object(Vector coordinate, Vector velocity, size_t weight, sf::Sprite sprite, size_t level) :
	engine_(NULL),
	sprite_(sprite),
	level_(level),
	coordinate_(coordinate),
	velocity_(velocity),
	weight_(weight),
	width_(0),
	height_(0)
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


void Object::setEngine(Engine *engine)
{
	assert(engine);

	engine_ = engine;
}


void Object::Physic(double time)
{
	assert(time >= 0);

	coordinate_ = coordinate_ + time * velocity_;
}

void Object::Control(){}

Object_Condition Object::Logic()
{
	return LIVE;
}

void Object::Draw(){}

size_t Object::GetLevel()
{
	return level_;
}

enum ObjectActions
{
	ALL_OK,
	KILL_ME
};