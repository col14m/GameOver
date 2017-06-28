#include <assert.h>

#include "Engine.h"
#include "Objects\Object.h"


Object::Object(Vector coordinate, Vector velocity, size_t weight, sf::Sprite sprite, size_t level) :
	engine_(NULL),
	sprite_(sprite),
	level_(level),
	coordinate_(coordinate),
	velocity_(velocity),
	weight_(weight),
	width_(0),
	height_(0),
	type_(Object_t),
	rate_(0)
{
	width_ = sprite_.getTextureRect().width;
	height_ = sprite_.getTextureRect().height;
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
	fprintf(file, "\tcoordinate : "); coordinate_.Dump(file);
	fprintf(file, "\tvelocity   : "); velocity_.Dump(file);
	fprintf(file, "\tweight     : %zu\n", weight_);
	fprintf(file, "}\n");
}


void Object::Physic(double time)
{
	assert(time >= 0);
	velocity_ = rate_ * engine_->getBGVelocity();
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

Vector Object::GetVelocity()
{
	return velocity_;
}

Vector Object::SetVelocity(Vector v)
{
	velocity_ = v;
	return v;
}