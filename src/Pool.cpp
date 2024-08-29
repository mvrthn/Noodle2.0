#include "Pool.hpp"


Pool::Pool(Deck* deck) {
    for(int i = 0; i < 4; i++) {
        cards[i] = deck->drawCard();
    }
}

Pool::~Pool() {
    for(int i = 0; i < 4; i++) {
        if(cards[i]) delete cards[i];
    }
}

Card* Pool::drawCard(int i, Deck* deck) {
    Card* card = cards[i];
    cards[i] = deck->drawCard();
    return card;
}

void Pool::replace(Deck* deck) {
    for(int i = 0; i < 4; i++) {
        if(cards[i]) delete cards[i];
        cards[i] = deck->drawCard();
    }
}

Card** Pool::getCards() {
    return cards;
}