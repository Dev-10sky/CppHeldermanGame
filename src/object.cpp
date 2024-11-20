#include "../include/object.h"

OBJECT objs[] = 
{
    OBJECT("a dirty disordered room with paper on the floor", "startroom", NULL),
    OBJECT("a long dark hallway", "hallway", NULL),
    OBJECT("a room with red paint on walls","redroom" ,NULL),
    OBJECT("a dirty old faded map","map", startroom),
    OBJECT("a shiny silver bowl","bowl", redroom),
    OBJECT("a robed red priest","priest", hallway),
    OBJECT("yourself","yourself", startroom)
};

const std::string OBJECT::getDescription()
{
    return _descritpion;
}
const std::string OBJECT::getTag()
{
    return _tag;
}
OBJECT * OBJECT::getLocation()
{
    return _location;
}

void OBJECT::setLocation(OBJECT *loc)
{
    _location = loc;
}