#include <stdio.h>
#include <stdlib.h>

#include "Engine.h"
#include "Objects//Object.h"

#include "SFML//Main.hpp"
#include "SFML//Graphics.hpp"

#include "Objects//Background.h"
#include "Objects//Train.h"
#include "Objects//Hero.h"

int main()
{
	Engine engine;

	engine.addObject(new Background(sf::Sprite(*(texturesMap["Background"]))));
	//engine.addObject(new Train(Vector(1100, 250), Vector(-200, 0), 100, sf::Sprite(*(texturesMap["Train"])), 5));
	engine.addObject(new Hero(Vector(0, 0), Vector(30 ,0), 20, sf::Sprite(*(texturesMap["Hero"])), 3));
	//engine.addObject(new Train(Vector(1000, 250), Vector(-200, 0), 100, sf::Sprite(*(texturesMap["Train"])), 3));
	engine.run();

	system("pause");

	return 0;
}