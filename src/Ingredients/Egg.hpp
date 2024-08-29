#pragma once


#include "Ingredient.hpp"


class Egg : Ingredient {
public:
    inline std::string getName() {return "Egg";};
    inline int getId() {return 3;};
    inline bool isVege() {return false;};
    inline bool isProtein() {return true;};
};