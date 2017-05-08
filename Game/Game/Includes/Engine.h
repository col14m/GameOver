#pragma once

#include <stdio.h>

#include <list>

#include "Object.h"

class Engine
{
public:
	Engine();
	~Engine();

	void Dump();
	void Dump(FILE *file);

	void addObject(Object *newObject);

	void logic();
	void tick();
private:

	std::list<Object *> objectList_;
};

Engine::Engine()
{
}

Engine::~Engine()
{
}

void Engine::tick()
{
	logic();
	for (auto &now: objectList_)
	{
		now->Physic();
		now->Control();
		now->Logic();
		now->Draw();
	}
}

void Engine::logic()
{}

void Engine::addObject(Object *newObject)
{
	newObject->setEngine(this);
	objectList_.push_back(newObject);
}


void Engine::Dump()
{
	printf("Engine [0x%p] {\n", this);
	for (auto &now : objectList_)
	{
		now->Dump();
	}
	printf("}\n");
}

void Engine::Dump(FILE *file)
{
	fprintf(file, "Engine [0x%p] {\n", this);
	for (auto &now : objectList_)
	{
		now->Dump();
	}
	fprintf(file, "}\n");
}