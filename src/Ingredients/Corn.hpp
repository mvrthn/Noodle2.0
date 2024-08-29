#pragma once


#include "Ingredient.hpp"


class Corn : Ingredient {
public:
    inline std::string getName() {return "Corn";};
    inline int getId() {return 2;};
    inline bool isVege() {return true;};
    inline bool isProtein() {return false;};
};