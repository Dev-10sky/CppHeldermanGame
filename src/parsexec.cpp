#include <vector>
#include <sstream>
#include "parsexec.h"



bool Parser::parseAndExecute(const std::string input)
{
    std::vector<std::string> tokens;

    std::stringstream varTok(input);

    std::string temp;

    while (std::getline(varTok,temp))
    {
        std::size_t previous = 0;
        std::size_t position;

        while ((position = temp.find_first_of(" \n", previous)) != std::string::npos)
        {
            if (position > previous)
            {
                tokens.push_back(temp.substr(previous, position - previous));
            }
            previous = position + 1;
        }
        if (previous < temp.length())
        {
            tokens.push_back(temp.substr(previous, std::string::npos));
        }
    }

    // for (std::string s: tokens)
    // {
    //     std::cout << s << std::endl;
    // }

    _verb = tokens[0];
    if (tokens.size()> 1)
        _noun = tokens[1];

    if (!_verb.empty())
    {
        if (!_verb.compare("quit"))
        {
            return false;
        }
        else if (!_verb.compare("look"))
        {
            std::cout << "It is very dark in here." << std::endl;
        }
        else if (!_verb.compare("go"))
        {
            std::cout << "It's too dark to go anywhere." << std::endl;
        }
        else
        {
            std::cout << "I don't know how to '"<< _verb << "'." << std::endl;
        }
    }
    return true;
}