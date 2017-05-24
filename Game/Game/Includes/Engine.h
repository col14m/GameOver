#pragma once

#include <stdio.h>
#include <assert.h>

#include <map>
#include <list>

#include "Objects\Object.h"

#define LINE_BEGIN_X 1105
#define LINE1_BEGIN Vector(LINE_BEGIN_X, 201) 
#define LINE2_BEGIN Vector(LINE_BEGIN_X, 330)
#define LINE3_BEGIN Vector(LINE_BEGIN_X, 440)

#define LINE_END_X -400
#define LINE1_END Vector(LINE_END_X, 201)
#define LINE2_END Vector(LINE_END_X, 330)
#define LINE3_END Vector(LINE_END_X, 201)

#define BG_VELOCITY Vector(-200, 0)

#define WIN_H 530
#define WIN_L 1060

#define SET_ON_LINE(name, line, k) \
	addObject(new name(LINE##line##_BEGIN, k * BGVelocity_, 100, sf::Sprite(*(texturesMap[#name])), line, k));
#define SET_ON_LINE_OFFSET(name, line, k, offset) \
	addObject(new name(LINE##line##_BEGIN + Vector(offset, 0), k * BGVelocity_, 100, sf::Sprite(*(texturesMap[#name])), line));
class Engine
{
public:
	Engine();
	~Engine();

	void Dump();
	void Dump(FILE *file);

	void addObject(Object *newObject);
	void removeObject(Object *oldObject);

	void logic(double time);
	void tick();
	void run();

	sf::RenderWindow *getEngineWindow();

	Vector getBGVelocity();

private:
	sf::Clock clock_;
	double time_;
	sf::RenderWindow *engineWindow_;
	Vector BGVelocity_;
	std::list<Object *> objectList_;

};

extern std::map<char *, sf::Texture *> texturesMap;

