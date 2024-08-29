#pragma once


#include "Ingredient.hpp"


class Mushrooms : Ingredient {
public:
    inline std::string getName() {return "Mushrooms";};
    inline int getId() {return 4;};
    inline bool isVege() {return true;};
    inline bool isProtein() {return false;};
};