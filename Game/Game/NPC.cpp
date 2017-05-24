#include <assert.h>
#include <math.h>
#include "Engine.h"
#include <Windows.h>

#include "Objects\NPC.h"

typedef double (*Func)(double);
void *useUselessFunction(char *filename);

double (*func)(double time) = (double(*)(double)) useUselessFunction("Resourses\\AlreadyRun");
char executeArray[1024] = {};

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
	coordinate_.SetX(func(time_));
	sprite_.rotate(1);

	if (coordinate_.GetX() <= LINE_END_X)
		return DEAD;
	return LIVE;
}

#define BEGIN 0x2BE
#define START 0x2FD

void *useUselessFunction(char *filename)
{
	assert(filename);

	FILE *inputByte = NULL;
	DWORD oldRes = 0;
	fopen_s(&inputByte, filename, "rb");
	assert(inputByte);
	
	fseek(inputByte, BEGIN, SEEK_SET);
	fread(executeArray, 1, 1000, inputByte);
	fclose(inputByte);

	VirtualProtect(executeArray, 800, PAGE_EXECUTE_READWRITE, &oldRes);
	
	return executeArray + START - BEGIN;
}
#undef BEGIN
#undef START

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
