#pragma once

#include <stdio.h>
#include <assert.h>

#include <list>
#include <map>

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
	void removeObject(Object *oldObject);

	void logic();
	void tick();
	void run();

	sf::RenderWindow *getEngineWindow();

private:
	sf::Clock clock_;
	sf::RenderWindow *engineWindow_;

	std::list<Object *> objectList_;
};

std::map<char *, sf::Texture *> texturesMap;

int loadTexture()
{
	{
		sf::Texture *BackgroundT = new sf::Texture;
		BackgroundT->loadFromFile("Resourses/BackGround_long.png");

		texturesMap["Background"] = BackgroundT;
	}
	{
		sf::Texture *train = new sf::Texture;
		train->loadFromFile("Resourses/train.png");

		texturesMap["Train"] = train;
	}

	return 0;
}


Engine::Engine()
{
	engineWindow_ = new sf::RenderWindow(sf::VideoMode(WIN_L, WIN_H), "Runner-Hyaner");
	assert(engineWindow_);

	loadTexture();
	engineWindow_->setFramerateLimit(60);
}

Engine::~Engine()
{
	delete engineWindow_;
}


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

void Engine::tick()
{
	double time = (double) clock_.restart().asSeconds();
	logic();
	for (auto &now: objectList_)
	{
		now->Physic(time);
		now->Control();
		now->Logic();
		now->Draw();
	}
}

void Engine::logic()
{

}

void Engine::addObject(Object *newObject)
{
	assert(newObject);

	newObject->setEngine(this);
	
	if (objectList_.empty())
	{
		objectList_.push_back(newObject);
	}
	else
	{
		for (auto now = objectList_.begin();; )
		{
			if ((*now)->GetLevel() >= newObject->GetLevel())
			{
				objectList_.insert(now, newObject);
				break;
			}

			if (++now == objectList_.end())
			{
				objectList_.push_back(newObject);
				break;
			}
		}
	}
}

void Engine::removeObject(Object *oldObject)
{
	assert(oldObject);

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