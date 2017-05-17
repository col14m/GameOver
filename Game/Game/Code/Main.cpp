#include <stdio.h>
#include <stdlib.h>

#include "Engine.h"
#include "Objects//Object.h"

#include "SFML//Main.hpp"
#include "SFML//Graphics.hpp"

#include "Objects//Background.h"
#include "Objects//Train.h"
#include "Objects//Hero.h"
#include "Objects//Conductor.h"

int main()
{
	Engine engine;
	// јхтунг! я поставил Origin каждого спрайта в нижний левый угол!!!!
	// ≈сли будете добавл€ть спрайты и героев, это будет сделано автоматом

	engine.addObject(new Background(Vector(-100, WIN_H), BG_VELOCITY, 1000, sf::Sprite(*(texturesMap["Background"])), 0));
	engine.addObject(new Train(LINE2_BEGIN, 2 * BG_VELOCITY, 100, sf::Sprite(*(texturesMap["Train"])), 2));
	engine.addObject(new Train(LINE3_BEGIN, BG_VELOCITY, 100, sf::Sprite(*(texturesMap["Train"])), 3));
	engine.addObject(new Conductor(LINE1_BEGIN, BG_VELOCITY, 1000, sf::Sprite(*(texturesMap["Conductor"])), 1));
	engine.addObject(new Conductor(LINE3_BEGIN, BG_VELOCITY, 1000, sf::Sprite(*(texturesMap["Conductor"])), 4));


	engine.run();
	
	system("pause");
	
	return 0;
}