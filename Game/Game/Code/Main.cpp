#include <stdio.h>
#include <stdlib.h>

#include "Engine.h"
#include "Objects//Object.h"

#include "SFML//Main.hpp"
#include "SFML//Graphics.hpp"

#include "Objects//Background.h"
#include "Objects//Train.h"


int main()
{
	Engine engine;

	engine.addObject(new Background (sf::Sprite(*(texturesMap["Background"]))));
	engine.addObject(new Train (sf::Sprite(*(texturesMap["Train"]))));

	engine.run();
	
	system("pause");
	
	return 0;
}