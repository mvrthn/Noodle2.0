#include "Deck.hpp"

#include "Ingredients/Bacon.hpp"
#include "Ingredients/Chives.hpp"
#include "Ingredients/Corn.hpp"
#include "Ingredients/Egg.hpp"
#include "Ingredients/Mushrooms.hpp"
#include "Ingredients/Naruto.hpp"
#include "Ingredients/Tofu.hpp"
#include "Flavors/BeafFlavor.hpp"
#include "Flavors/ChickenFlavor.hpp"
#include "Flavors/ShrimpFlavor.hpp"
#include "Flavors/SoySouceFlavor.hpp"

#include <ctime>
#include <cstdlib>


Deck::Deck() {
    constructors[0] = [](){return (Card*) new Bacon();};
    constructors[1] = [](){return (Card*) new Chives();};
    constructors[2] = [](){return (Card*) new Corn();};
    constructors[3] = [](){return (Card*) new Egg();};
    constructors[4] = [](){return (Card*) new Mushrooms();};
    constructors[5] = [](){return (Card*) new Naruto();};
    constructors[6] = [](){return (Card*) new Tofu();};
    constructors[7] = [](){return (Card*) new BeafFlavor();};
    constructors[8] = [](){return (Card*) new ChickenFlavor();};
    constructors[9] = [](){return (Card*) new ShrimpFlavor();};
    constructors[10] = [](){return (Card*) new SoySouceFlavor();};

    srand(time(0));

    for(int& c : cards) {
        c = 6;
    }
}

Card* Deck::drawCard() {
    if(n == 0) return nullptr;
    int x = rand() % n;
    int i;
    for(i = 0; i < 11; i++) {
        x -= cards[i];
        if(x < 0) break;
    }
    cards[i]--;
    n--;
    return constructors[i]();
}