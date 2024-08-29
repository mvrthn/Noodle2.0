#pragma once


#include "Ingredient.hpp"


class Naruto : Ingredient {
public:
    inline std::string getName() {return "Naruto";};
    inline int getId() {return 5;};
    inline bool isVege() {return false;};
    inline bool isProtein() {return true;};
};