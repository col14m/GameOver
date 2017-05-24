#pragma once

#include <stdio.h>
#include <assert.h>

#include <list>
#include <map>

#include "Objects\Object.h"

#define LINE_BEGIN_X 1105
#define LINE1_BEGIN Vector(LINE_BEGIN_X, 201) 
#define LINE2_BEGIN Vector(LINE_BEGIN_X, 330)
#define LINE3_BEGIN Vector(LINE_BEGIN_X, 440)
//#define LINE4_BEGIN Vector(1100, 488) // нафиг 4 линию, она плохо смотрится

#define LINE_END_X -400
#define LINE1_END Vector(LINE_END_X, 201)
#define LINE2_END Vector(LINE_END_X, 330)
#define LINE3_END Vector(LINE_END_X, 201)

#define BG_VELOCITY Vector(-200, 0)

#define WIN_H 530
#define WIN_L 1060




#define SET_ON_LINE(Name, line, k) \
	addObject(new Name(LINE##line##_BEGIN, k * BGVelocity_, 100, sf::Sprite(*(texturesMap[#Name])), line));

class Engine
{
public:
	Engine();
	~Engine();

	void Dump();
	void Dump(FILE *file);

	void addObject(Object *newObject);
	void removeObject(Object *oldObject);

	void logic();
	void tick();
	void run();

	sf::RenderWindow *getEngineWindow();

private:
	sf::Clock clock_;
	sf::RenderWindow *engineWindow_;
	Vector BGVelocity_;
	std::list<Object *> objectList_;

};

extern std::map<char *, sf::Texture *> texturesMap;

