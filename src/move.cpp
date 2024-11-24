#include <iostream>
#include "../include/move.h"

static void describeMove(OBJECT *obj, OBJECT *to)
{
	if (to == player->getLocation())
	{
		std::cout << "You drop " << obj->getDescription() << "." << std::endl;
	}
	else if (to != player)
	{
		std::cout <<  (to == priest ? "You give " : "You put ") << obj->getDescription() << (to == priest ? " to " : " in ") << to->getDescription() << "." << std::endl;
	}
	else if (obj->getLocation() == player->getLocation())
	{
		std::cout << "You pick up " << obj->getDescription() << "." << std::endl;
	}
	else
	{
		std::cout << "You get " << obj->getDescription() << " from " << obj->getLocation()->getDescription() << "." << std::endl;
	}
}

void moveObject(OBJECT *obj, OBJECT *to)
{
	if (obj == NULL)
	{
		// redundant due to getVisible() or getPossesion()
	}
	else if (to == NULL)
	{
		std::cout << "There is nobody here to give that to." << std::endl;
	}
	else if (obj->getLocation() == NULL)
	{
		std::cout << " That is way too heavy." << std::endl;
	}
	else
	{
		describeMove(obj, to);
		obj->setLocation(to);
	}
}
