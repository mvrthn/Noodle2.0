#pragma once 


#include "Player.hpp"
#include "Pool.hpp"

#include <functional>


class Screen {
public:
    Screen();

    void clear();
    void drawPlayers(Player*, int);
    void drawTable(Pool*);
    void drawHand(Player&, int, Card*);

    int readAction(int);
    int readInt();
    void print(std::string);
private:
    std::string actionList[8];
};