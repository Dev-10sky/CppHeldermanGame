#ifndef NOUN_H
#define NOUN_H

#include <iostream>
#include <string>
#include "../include/object.h"

extern OBJECT *getVisible(const std::string intention, const std::string noun);
extern OBJECT *getPosession(OBJECT * from, const std::string verb, const std::string noun);

#endif

