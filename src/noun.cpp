#include "noun.h"


static bool objectHasTag(OBJECT *obj, const std::string noun)
{
    return noun.length() > 0 && noun[0] != '\0' && !noun.compare(obj->getTag());
}

static OBJECT *getObject(const std::string noun)
{
    OBJECT *obj, *res = NULL;
    for (obj = objs; obj < endOfObjs; obj++)
    {
        if (objectHasTag(obj, noun))
        {
            res = obj;
        }
    }
    return res;
}

OBJECT *getVisible(const std::string intention, const std::string noun)
{
    OBJECT *obj = getObject(noun);
    OBJECT *playerLoc = player->getLocation();
    if (obj == NULL)
    {
        std::cout << "I don't understand " << intention << "." << std::endl;
    }
    else if (!(obj == player ||
                obj == playerLoc ||
                obj->getLocation() == player ||
                obj->getLocation() == playerLoc ||
                obj->getLocation() == NULL ||
                obj->getLocation()->getLocation() == player ||
                obj->getLocation()->getLocation() == playerLoc))
    {
        std::cout << "You don't see any " << noun << "here." << std::endl;
        obj = NULL;
    }
    return obj;
}

OBJECT *getPosession(OBJECT *from, const std::string verb, const std::string noun)
{
	OBJECT *obj = NULL;
	if (from == NULL)
	{
		std::cout << "I don't understand who you want to " << verb << "." << std::endl;
	}
    else if ((obj = getObject(noun)) == NULL)
    {
        std::cout << "I don't understand what you want to " << verb << "." << std::endl; 
    }
    else if (obj == from)
    {
        std::cout << "You should not be doing that to " << obj->getDescription() << "." << std::endl;
        obj = NULL;
    }
    else if (obj->getLocation() != from)
    {
        if (from == player)
        {
            std::cout << "You are not holding any " << noun << "." << std::endl;
        }
        else 
        {
            std::cout << "There appears to be no " << noun << " you can get from " << from->getDescription() << "." << std::endl;
        }
        obj = NULL;
    }
    return obj;
}
