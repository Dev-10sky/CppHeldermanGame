#ifndef OBJECT_H
#define OBJECT_H

#include <iostream>
#include <string>

class OBJECT
{
    std::string _descritpion;
    std::string _tag;
    OBJECT *_location;
public:
    const std::string getDescription();
    const std::string getTag();
    OBJECT *getLocation();
    void setLocation(OBJECT *loc);
    OBJECT(const std::string desc, const std::string tag, OBJECT * loc) 
    { 
        _descritpion = desc;
        _tag = tag;
        _location = loc;
    }
    ~OBJECT(){}

};

extern OBJECT objs[];

#define startroom (objs + 0)
#define hallway   (objs + 1)
#define redroom   (objs + 2)
#define map       (objs + 3)
#define bowl      (objs + 4)
#define priest    (objs + 5)
#define player    (objs + 6)

#define endOfObjs (objs + 7)

#endif 