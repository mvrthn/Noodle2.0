#include "ChickenFlavor.hpp"


int ChickenFlavor::evaluate(Card* cards[], int n) {
    int points[5] = {0, 0, 6, 10, 10};
    int max = 0;
    int ids[7] = {0};
    for(int i = 0; i < n; i++) {
        Card* card = cards[i];
        if(card->isFlavor()) continue;
        ids[card->getId()]++;
        if(ids[card->getId()] > max) max++;
    }
    return points[max];
}