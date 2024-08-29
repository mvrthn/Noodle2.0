#pragma once 


#include "Deck.hpp"
#include "Pool.hpp"
#include "Player.hpp"
#include "Screen.hpp"


class Game {
public:
    Game(int);
    ~Game();

    Card* highlightCard(Player&, int);
    bool unhighlightCard(Player&, Card**);

    bool addToBowl(Player&, int, Card*);
    bool drawCard(Player&, int);
    Card* takeCard(Player&, int);
    bool redrawPool();
    bool eatBowl(Player&, int, int*);
    bool pourOutBowl(Player&, int);

    void run();
private:
    Deck* deck;
    Pool* pool;
    Player* players;
    Screen screen;
    int numOfPlayers;
    int turn;
};