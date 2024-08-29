#pragma once


#include "../Card.hpp"


class Flavor : public Card {
public:
    virtual std::string getName() = 0;
    virtual int getId() = 0;
    inline bool isFlavor() {return true;};
    virtual int evaluate(Card*[], int) = 0;
};