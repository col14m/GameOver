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

	engine.addObject(new Background(Vector(-100, texturesMap["Background"]->getSize().y), Vector(-200, 0), 1000, sf::Sprite(*(texturesMap["Background"])), 0));
	engine.addObject(new Train(Vector(1100, 250), Vector(-200, 0), 100, sf::Sprite(*(texturesMap["Train"])), 5));
	//engine.addObject(new Train(Vector(1000, 250), Vector(-200, 0), 100, sf::Sprite(*(texturesMap["Train"])), 3));
	engine.addObject(new Conductor(Vector(1000, 250), Vector(-200, 0), 1000, sf::Sprite(*(texturesMap["Conductor"])), 1));
	

	engine.run();
	
	system("pause");
	
	return 0;
}