#pragma once 


#include "Card.hpp"

#include <functional>


class Deck {
public:
    Deck();

    Card* drawCard();
private:
    int cards[11]; 
    int n = 66;
    std::function<Card*()> constructors[11];
};