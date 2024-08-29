#include "BeafFlavor.hpp"

#include "../Ingredients/Ingredient.hpp"


int BeafFlavor::evaluate(Card* cards[], int n) {
    int points[5] = {0, 2, 5, 9, 14};
    int index = 0;
    bool ids[7] = {false};
    for(int i = 0; i < n; i++) {
        Card* card = cards[i];
        if(card->isFlavor()) continue;
        if(!((Ingredient*) card)->isProtein()) continue;
        if(ids[card->getId()]) continue;
        ids[card->getId()] = true;
        index++;
    }
    return points[index];
}