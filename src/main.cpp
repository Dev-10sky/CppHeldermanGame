#include <iostream>
#include <string>
#include "../include/parsexec.h"

static std::string input = "look around";

static bool getInput(void)
{
    std::cout << "\n--> ";
    std::getline(std::cin , input);
    if (input.length() > 0)
    {
        return true;
    }
    else
    {
        return false;
    }
}

int main()
{
    const std::string welcome = "Welcome to Telev's Labryinth.";
    const std::string dark = "It is very dark in here.";
    Parser tempParser;
    
    std::cout << welcome << std::endl;
    while (tempParser.parseAndExecute(input) && getInput())
    {

    }
    std::cout << std::endl << "Bye!" << std::endl;


    // bool chk = getInput();
    // chk = tempParser.parseAndExecute(input);
    // std::cout << chk << std::endl;


    return 0;    
}