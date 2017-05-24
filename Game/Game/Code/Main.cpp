#include <stdio.h>
#include <stdlib.h>

#include <Windows.h>

#include "Engine.h"
#include "Vector\Vector.h"
#include "Objects\Conductor.h"
#include "Objects\Background.h"
#include "Objects\Train.h"
#include "Objects\Hero.h"
#include "Objects\NPC.h"

#include "SFML\Main.hpp"
#include "SFML\Graphics.hpp"


int main()
{

	

	Engine engine;
	// јхтунг! я поставил Origin каждого спрайта в нижний левый угол!!!!
	// ≈сли будете добавл€ть спрайты и героев, это будет сделано автоматом

	engine.addObject(new Background(Vector(-100, WIN_H), BG_VELOCITY, 1000, sf::Sprite(*(texturesMap["Background"])), 0));
	//engine.addObject(new Train(LINE2_BEGIN, 2 * BG_VELOCITY, 100, sf::Sprite(*(texturesMap["Train"])), 2));
	//engine.addObject(new Train(LINE3_BEGIN, BG_VELOCITY, 100, sf::Sprite(*(texturesMap["Train"])), 3));
	//SET_ON_LINE(Train, 2, 2)
	engine.addObject(new NPC(Vector(WIN_L/2, 70), Vector(0,0), 1000, sf::Sprite(*(texturesMap["NPC"])), 4));

	//engine.addObject(new Conductor(LINE1_BEGIN, BG_VELOCITY, 1000, sf::Sprite(*(texturesMap["Conductor"])), 1));
	//engine.addObject(new Conductor(LINE3_BEGIN, BG_VELOCITY, 1000, sf::Sprite(*(texturesMap["Conductor"])), 3));
	engine.addObject(new Hero(Vector(50, LINE3_BEGIN.GetY()), Vector(0,0), 1000, sf::Sprite(*(texturesMap["Hero"])), 3));


	engine.run();
	
	system("pause");
	
	return 0;
}