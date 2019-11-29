#pragma once
#include "../JuceLibraryCode/JuceHeader.h"
#include <cstdlib>
#include <ctime>

class Unit {
public:
    Unit(){
        std::srand(unsigned(std::time(0)));
        colour = Colour::fromRGB(std::rand(), std::rand(), std::rand());
    }

    Colour const& getColour(){
        return colour;
    }

private:
    Colour colour;
};
