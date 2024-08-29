#pragma once


#include "Card.hpp"
#include "Flavors/Flavor.hpp"

class Bowl {
public:
    ~Bowl();

    bool add(Card*);
    Card* pop();
    bool pourOut();
    bool eat(int*);

    Card** getCards(int*);
private:
    Card* cards[5] = {nullptr};
    Flavor* flavor = nullptr;
    int size = 0;
    int points = 0;
    bool isEaten = false;
};