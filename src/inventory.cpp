#include <iostream>
#include "../include/object.h"
#include "../include/misc.h"
#include "../include/noun.h"
#include "../include/move.h"
#include "../include/inventory.h"

void executeGet(const std::string noun)
{
    OBJECT *obj = getVisible("what you want to get", noun);
    if (obj == NULL)
    {
        // redundant due to getVisible()
    }
    else if (obj == player)
    {
        std::cout << "You should not be doing that to yourself." << std::endl;
    }
    else if (obj->getLocation() == player)
    {
        std::cout << "You already have " << obj->getDescription() << "." << std::endl;
    }
    else if (obj->getLocation() == priest)
    {
        std::cout << "You should ask " << obj->getLocation()->getDescription() << " nicely." << std::endl;
    }
    else
    {
        moveObject(obj,player);
    }
}

void executeDrop(const std::string noun)
{
    moveObject(getPosession(player, "drop", noun),player->getLocation());
}

void executeAsk(const std::string noun)
{
    moveObject(getPosession(actorHere(), "ask", noun), player);
}

void executeGive(const std::string noun)
{
    moveObject(getPosession(player, "give", noun), actorHere());
}

void executeInventory(void)
{
    if (listObjectsAtLocation(player) == 0)
    {
        std::cout << "You are empty-handed." << std::endl;
    }
}