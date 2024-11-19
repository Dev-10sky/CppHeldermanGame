#ifndef PARSEXEC_H
#define PARSEXEC_H

#include <iostream>
#include <string>

class Parser
{
    std::string _verb;
    std::string _noun;

public:
    Parser(){}
    ~Parser(){}
    bool parseAndExecute(const std::string input);
};

#endif