#pragma once


#include "Flavor.hpp"


class SoySouceFlavor : Flavor {
public:
    inline std::string getName() {return "Soy Souce Flavor";};
    inline int getId() {return 10;};
    int evaluate(Card*[], int);
};