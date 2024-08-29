#pragma once


#include "Ingredient.hpp"


class Chives : Ingredient {
public:
    inline std::string getName() {return "Chives";};
    inline int getId() {return 1;};
    inline bool isVege() {return true;};
    inline bool isProtein() {return false;};
};