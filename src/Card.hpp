#pragma once 


#include <string>


class Card {
public:
    virtual std::string getName() = 0;
    virtual int getId() = 0; 
    virtual bool isFlavor() = 0;
};