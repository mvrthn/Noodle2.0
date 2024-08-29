#pragma once


#include "Card.hpp"
#include "Deck.hpp"

class Pool {
public:
    Pool(Deck*);
    ~Pool();

    Card* drawCard(int, Deck*);
    void replace(Deck*);

    Card** getCards();
private:
    Card* cards[4];
};