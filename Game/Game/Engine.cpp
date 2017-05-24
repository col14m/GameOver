#include "SFML\Audio.hpp"
#include "Engine.h"
#include "Objects\Conductor.h"
#include "Objects\Background.h"
#include "Objects\Train.h"
#include "Objects\Hero.h"

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
	{
		sf::Texture *NPC = new sf::Texture;
		NPC->loadFromFile("Resourses/Losyash.png");

		texturesMap["NPC"] = NPC;
	}

	return 0;
}


Engine::Engine()
{
	engineWindow_ = new sf::RenderWindow(sf::VideoMode(WIN_L, WIN_H), "Runner-Hyaner");
	assert(engineWindow_);
	BGVelocity_ = BG_VELOCITY;

	loadTexture();
	engineWindow_->setFramerateLimit(100);
}

Engine::~Engine()
{
	delete engineWindow_;
}


void Engine::run()
{
	sf::Music music;
	music.openFromFile("Resourses/HTF.wav");
	music.setLoop(true);
	music.play();

	while (engineWindow_->isOpen())
	{
		sf::Event event;

		engineWindow_->pollEvent(event);
		if (event.type == sf::Event::Closed)
		{
			engineWindow_->close();
		}

		engineWindow_->clear();
		tick();
		engineWindow_->display();
	}
}

void Engine::tick()
{
	double time = (double)clock_.restart().asSeconds();
	ObjectCondition objectState = LIVE;
	size_t ObjCounter = 0;
	std::list<Object *> listOnDelete;

	logic();
	for (auto &nowA : objectList_)
	{
		nowA->Physic(time);
		nowA->Control();
		objectState = nowA->Logic();
		nowA->SetVelocity(1.0001 * nowA->GetVelocity());

		for (auto &nowB : objectList_)
		{
			if (nowA != nowB)
			{
				if (nowA->Intersection(nowB) == DEAD) //оепедекюрэ!!!
				{
					objectState = DEAD;
				}
			}
		}

		if (objectState == LIVE)
		{

		}
		else if (objectState == DEAD)
		{
			listOnDelete.push_back(nowA);
		}

		nowA->Draw();
		ObjCounter++;
	}
	//printf("%lu\n", ObjCounter);
	for (auto &nowC : listOnDelete)
	{
		removeObject(nowC);
	}
}

void Engine::logic()
{
	//SET_ON_LINE(Train, 2, 2)
	//addObject(new Train(LINE2_BEGIN, 2 * BGVelocity_, 100, sf::Sprite(*(texturesMap["Train"])), 2));
	//addObject(new Train(LINE2_BEGIN, 2 * BG_VELOCITY, 100, sf::Sprite(*(texturesMap["Train"])), 2));
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
	delete oldObject;
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


