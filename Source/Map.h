#pragma once
#include <vector>
#include "Unit.h"

class Map {
public:
    Map() : map(std::vector<std::vector<Unit> >(width, std::vector<Unit> (height))) {
          std::srand(unsigned(std::time(0)));
    };

    std::vector<std::vector<Unit> > const& getMap() const {
        return map;
    }

private:
    const int width = 10;
    const int height = 10;
    std::vector<std::vector<Unit> > map;
};
