#pragma once


#include "Flavor.hpp"


class BeafFlavor : Flavor {
public:
    inline std::string getName() {return "Beaf Flavor";};
    inline int getId() {return 7;};
    int evaluate(Card*[], int);
};  