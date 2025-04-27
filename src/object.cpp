#include "../include/object.h"

OBJECT objs[] = 
{
    OBJECT("a dirty disordered room with paper on the floor", "startroom", NULL,NULL),
    OBJECT("a long dark hallway", "hallway", NULL, NULL),
    OBJECT("a room with red paint on walls","redroom",NULL ,NULL),
    OBJECT("a dirty old faded map","map", startroom, NULL),
    OBJECT("a shiny silver bowl","bowl", redroom, NULL),
    OBJECT("a robed red priest","priest", hallway, NULL),
    OBJECT("yourself","yourself", startroom, NULL),
    OBJECT("a hallway entrance", "entrance", startroom, hallway),
    OBJECT("a startroom entrance", "exit", hallway, startroom)
};

const std::string OBJECT::getDescription()
{
    return _descritpion;
}
const std::string OBJECT::getTag()
{
    return _tag;
}
OBJECT *OBJECT::getLocation()
{
    return _location;
}

OBJECT *OBJECT::getDestination()
{
    return _destination;
}

void OBJECT::setLocation(OBJECT *loc)
{
    _location = loc;
}