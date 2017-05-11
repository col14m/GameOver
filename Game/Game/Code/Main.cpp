#include <stdio.h>
#include <stdlib.h>

#include "Engine.h"
//#include "Objects//Object.h"

#include "SFML//Main.hpp"
#include "SFML//Graphics.hpp"

#include "Objects//Background.h"



int main()
{
	Engine engine;
	sf::Texture BackgroundT;
	BackgroundT.loadFromFile("Resourses/BackGround_long.png");
	Background BackG(sf::Sprite(BackgroundT));
	engine.addObject( (Object *) &BackG );
	engine.run();
	//Object test(coord, veloc, 10, sprite, 2);
	//Object test2(coord, veloc, 12, sprite, 4);
	//test.Dump();
	//test2.Dump();
	//engine.addObject(&test);
	//engine.addObject(&test2);
	//engine.Dump();
/*
	sf::RenderWindow window(sf::VideoMode(400, 400), "Test");
	sf::CircleShape shape(100.f);
	shape.setFillColor(sf::Color::Red);

	while (window.isOpen())
	{
		sf::Event event;
		while (window.pollEvent(event))
		{
			if (event.type == sf::Event::Closed)
				window.close();
		}

		window.clear();
		window.draw(shape);
		window.display();
	}
*/
	system("pause");
	
	return 0;
}