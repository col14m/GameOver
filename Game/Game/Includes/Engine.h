#pragma once

#include <stdio.h>
#include <assert.h>
#include <list>

#include "Objects//Object.h"

#define WIN_H 530
#define WIN_L 1060

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
	void run();

	sf::RenderWindow *getEngineWindow();

private:
	sf::RenderWindow *engineWindow_;
	std::list<Object *> objectList_;
};

Engine::Engine()
{
	engineWindow_ = new sf::RenderWindow(sf::VideoMode(WIN_L, WIN_H), "Runner-Hyaner");
	assert(engineWindow_);
}

Engine::~Engine()
{
	delete engineWindow_;
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

void Engine::run()
{
	while (engineWindow_->isOpen())
	{
		sf::Event event;
		while (engineWindow_->pollEvent(event))
		{
			if (event.type == sf::Event::Closed)
				engineWindow_->close();
		}
		
		engineWindow_->clear();
		tick();
		engineWindow_->display();
	}
}

void Engine::addObject(Object *newObject)
{
	assert(newObject);

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
	assert(file);

	fprintf(file, "Engine [0x%p] {\n", this);
	for (auto &now : objectList_)
	{
		now->Dump();
	}
	fprintf(file, "}\n");
}


sf::RenderWindow *Engine::getEngineWindow()
{
	return engineWindow_;
}