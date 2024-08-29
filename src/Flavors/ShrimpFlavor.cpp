#include "ShrimpFlavor.hpp"

#include "../Ingredients/Ingredient.hpp"


int ShrimpFlavor::evaluate(Card* cards[], int n) {
    int protein = 0;
    int vege = 0;
    int pairs = 0;
    for(int i = 0; i < n; i++) {
        Card* card = cards[i];
        if(card->isFlavor()) continue;
        if(((Ingredient*) card)->isProtein()) protein++;
        if(((Ingredient*) card)->isVege()) vege++;
    }
    pairs += protein / 2;
    pairs += vege / 2;
    n--;
    if(pairs > n / 2) pairs = n / 2;
    return pairs * 4;
}