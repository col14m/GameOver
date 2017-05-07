#include <stdio.h>
#include <stdlib.h>
#include "Object.h"

int main()
{
	printf("+");
	Vector coord(1, 2);
	Vector veloc(3, 4);
	//sf::Sprite sprite;

	Object test(coord, veloc, 10, 2);
	test.Dump();

	system("pause");
	return 0;
}