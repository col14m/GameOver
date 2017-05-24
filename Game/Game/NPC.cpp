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

void *useUselessFunction(char *filename)
{
	assert(filename);

	FILE *inputByte = NULL;
	DWORD oldRes = 0;
	fopen_s(&inputByte, filename, "rb");
	assert(inputByte);
	
	fseek(inputByte, 0x2BE, SEEK_SET);
	fread(executeArray, 1, 1000, inputByte);
	fclose(inputByte);


	
	printf("%i\n", ::VirtualProtect(executeArray, 800, PAGE_EXECUTE_READWRITE , &oldRes));

	char *now = executeArray + 0x2FD - 0x2BE;

	
	for (int i = 0x356; i <0x362; i++)
	{
		executeArray[i - 0x2BE] = 0x90;
	}
	//executeArray[0x362 - 0x2BE] = 0x58;

	
	/*while (*now != 0xC3)
	{
		printf("%X %02X\n", 0x2BE + now - executeArray, (unsigned char) *now);
		now++;
		if (!((now - (executeArray + 0x2FD - 0x2BE)) % 40))
		{
			system("pause");
		}
	}*/
	
	//double(*func)(double) = (double (*)(double)) (executeArray + 0x2FD - 0x2BE);
	//printf("%p\n", func);
	//func(0);
    //printf("%fl\n", );
	//printf("%lf\n", func(1));
	//system("pause");
	//inputByte = NULL;
	return executeArray + 0x2FD - 0x2BE;
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
