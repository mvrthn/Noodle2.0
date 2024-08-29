#pragma once


#include "Ingredient.hpp"


class Bacon : Ingredient {
public:
    inline std::string getName() {return "Bacon";};
    inline int getId() {return 0;};
    inline bool isVege() {return false;};
    inline bool isProtein() {return true;};
};