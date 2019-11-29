#include <vector>
#include "Unit.h"

class Map {
public:
    Map();
    ~Map();
    std::vector<std::vector<Unit> > const& getMap(){
        return map;
    }

private:
    std::vector<std::vector<Unit> > map;
};
