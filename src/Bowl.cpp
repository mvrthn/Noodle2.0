#include "Bowl.hpp"


Bowl::~Bowl() {
    for(int i = 0; i < size; i++) {
        delete cards[i];
    }
}

bool Bowl::add(Card* card) {
    if(isEaten) return false;
    if(size == 5) return false;
    if(!card->isFlavor()) {
        cards[size++] = card;
        return true;
    }
    if(flavor != nullptr) return false;
    cards[size++] = card;
    flavor = (Flavor*) card;
    return true;
}

Card* Bowl::pop() {
    if(isEaten) return nullptr;
    if(size == 0) return nullptr;
    if(cards[size]->isFlavor()) flavor = nullptr;
    Card* card = cards[size];
    cards[size--] = nullptr;
    return card;
}

bool Bowl::pourOut() {
    if(isEaten) return false;
    if(size == 0) return false;
    for(int i = 0; i < size; i++) {
        delete cards[i];
    }
    size = 0;
    flavor = nullptr;
    return true;
}

bool Bowl::eat(int* points) {
    if(isEaten) return false;
    if(!flavor) return false;
    isEaten = true;
    *points = flavor->evaluate(cards, size);
    return true;
}

Card** Bowl::getCards(int* n) {
    *n = size;
    return cards;
}
