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