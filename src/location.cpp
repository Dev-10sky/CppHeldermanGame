#include "../include/location.h"
#include "../include/object.h"
#include "../include/misc.h"
#include "../include/noun.h"

void executeLook(const std::string noun)
{
    if (noun.length() > 0 && !noun.compare("around"))
    {
        std::cout << "You are in " << player->getLocation()->getDescription() << "." << std::endl;
        listObjectsAtLocation(player->getLocation());
    }
    else
    {
        std::cout << "I don't understand what you want to see." << std::endl;
    }
}

void executeGo(const std::string noun)
{
    OBJECT *obj = getVisible("where you want to go", noun);
    if (obj == NULL)
    {
        // redundant due to getVisible()
    }
    else if (obj->getLocation() == NULL && obj != player->getLocation())
    {
        std::cout << "Ok." << std::endl;
        player->setLocation(obj);
        executeLook("around");
    }
    else
    {
        std::cout << "You can't get much closer than this." << std::endl;
    }
}