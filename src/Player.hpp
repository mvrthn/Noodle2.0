#pragma once


#include "Bowl.hpp"
#include "Deck.hpp"

#include <vector>


class Player {
public:
    ~Player();

    bool addToBowl(int, Card*);
    Card* takeFromBowl(int);
    bool addToHand(Card*);
    Card* takeFromHand(int);
    bool useSpoon();
    void undoSpoon();
    bool eatBowl(int, int*);
    bool pourOutBowl(int);

    Bowl* getBowls();
    Card** getHand(int*);
private:
    Bowl bowls[3];
    std::vector<Card*> hand;
    int spoons = 2;
    int score = 0;
};