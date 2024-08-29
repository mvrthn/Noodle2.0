#pragma once


#include "Flavor.hpp"


class ShrimpFlavor : Flavor {
public:
    inline std::string getName() {return "Shrimp Flavor";};
    inline int getId() {return 9;};
    int evaluate(Card*[], int);
};