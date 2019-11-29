#pragma once
#include "../JuceLibraryCode/JuceHeader.h"
#include <cstdlib>
#include <ctime>

class Unit {
public:
    Unit(){
        colour = Colour::fromRGB(std::rand(), std::rand(), std::rand());
    }

    Unit(Unit const& u) {
        colour = Colour::fromRGB(std::rand(), std::rand(), std::rand());
    }

    Colour const& getColour() const {
        return colour;
    }

	void move() {
		colour = Colour::fromRGB(std::rand(), std::rand(), std::rand());
	}

private:
    Colour colour;
};
