#include <vector>
#include <sstream>
#include "parsexec.h"
#include "../include/location.h"
#include "../include/inventory.h"



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
            executeLook(_noun);
        }
        else if (!_verb.compare("go"))
        {
            executeGo(_noun);
        }
        else if (!_verb.compare("get"))
        {
            executeGet(_noun);
        }
        else if (!_verb.compare("drop"))
        {
            executeDrop(_noun);
        }
        else if (!_verb.compare("give"))
        {
            executeGive(_noun);
        }
        else if (!_verb.compare("ask"))
        {
            executeAsk(_noun);
        }
        else if (!_verb.compare("inventory"))
        {
            executeInventory();
        }
        else
        {
            std::cout << "I don't know how to '"<< _verb << "'." << std::endl;
        }
    }
    return true;
}