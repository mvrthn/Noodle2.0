#pragma once


#include "Flavor.hpp"


class ChickenFlavor : Flavor {
public:
    inline std::string getName() {return "Chicken Flavor";};
    inline int getId() {return 8;};
    int evaluate(Card*[], int);
};