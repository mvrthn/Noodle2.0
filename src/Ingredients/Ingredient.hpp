#pragma once


#include "../Card.hpp"

class Ingredient : Card {
public:
    virtual std::string getName() = 0;
    virtual int getId() = 0;
    inline bool isFlavor() {return false;};
    virtual bool isVege() = 0;
    virtual bool isProtein() = 0;
};