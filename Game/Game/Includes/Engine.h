#pragma once

#include <stdio.h>
#include <assert.h>

#include <list>
#include <map>

#include "Objects//Object.h"

#define WIN_H 530
#define WIN_L 1060


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
		train->loadFromFile("Resourses/Train.png");

		texturesMap["Train"] = train;
	}
	{
		sf::Texture *conductor = new sf::Texture;
		conductor->loadFromFile("Resourses/Conductor.png");

		texturesMap["Conductor"] = conductor;
	}
	{
		sf::Texture *hero = new sf::Texture;
		hero->loadFromFile("Resourses/Hero.png");

		texturesMap["Hero"] = hero;
	}

	return 0;
}


Engine::Engine()
{
	engineWindow_ = new sf::RenderWindow(sf::VideoMode(WIN_L, WIN_H), "Runner-Hyaner");
	assert(engineWindow_);

	loadTexture();
	engineWindow_->setFramerateLimit(100);
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
	int objectState = ALL_OK;

	logic();
	for (auto &now: objectList_)
	{
		now->Physic(time);
		now->Control();
		objectState = now->Logic();
		
		if (objectState == ALL_OK)
		{
		
		}
		else if (objectState == KILL_ME)
		{
			//removeObject(now);
			continue;
		}
		
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

	objectList_.remove(oldObject);
	free(oldObject);
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