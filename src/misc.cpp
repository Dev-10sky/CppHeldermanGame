#include <iostream>
#include "../include/misc.h"

int listObjectsAtLocation(OBJECT *location)
{
    int count = 0;
    OBJECT *obj;
    for (obj = objs; obj < endOfObjs; obj++)
    {
        if (obj != player && obj->getLocation() == location)
        {
            if (count++ == 0 )
            {
                std::cout << "You see:" << std::endl;
            }
            std::cout << obj->getDescription() << std::endl;
        }
    }
    return count;
}