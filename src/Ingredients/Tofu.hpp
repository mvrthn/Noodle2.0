#pragma once


#include "Ingredient.hpp"


class Tofu : Ingredient {
public:
    inline std::string getName() {return "Tofu";};
    inline int getId() {return 6;};
    inline bool isVege() {return true;};
    inline bool isProtein() {return true;};
};