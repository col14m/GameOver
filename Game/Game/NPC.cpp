#include <assert.h>
#include <math.h>
#include "Engine.h"

#include "Objects\NPC.h"

NPC::NPC(Vector coordinate, Vector velocity, size_t weight, sf::Sprite sprite, size_t level) :
	Object(coordinate, velocity, weight, sprite, level),
	time_(0)
{
	type_ = Background_t;
}

void NPC::Control()
{

}

void NPC::Physic(double time)
{
	time_ += time;
}

ObjectCondition NPC::Logic()
{
	coordinate_.SetX(WIN_L / 2 + 150 * sin( 5 * time_));
	sprite_.rotate(1);

	if (coordinate_.GetX() <= LINE_END_X)
		return DEAD;
	return LIVE;
}

ObjectCondition NPC::Intersection(Object *interation)
{
	assert(interation);

	return LIVE;
}

void NPC::Draw()
{
	sprite_.setPosition((float)coordinate_.GetX(), (float)coordinate_.GetY());
	engine_->getEngineWindow()->draw(sprite_);
}
