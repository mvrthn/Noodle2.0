#include "Screen.hpp"

#include <iostream>
#include <cstdlib>


Screen::Screen() {
    actionList[0] = "Highlight card\n";
    actionList[1] = "Add card to Bowl\n";
    actionList[2] = "Draw card from deck\n";
    actionList[3] = "Draw card from pool\n";
    actionList[4] = "Take card from bowl\n";
    actionList[5] = "Replace pool\n";
    actionList[6] = "Eat bowl\n";
    actionList[7] = "Pour out bowl\n";
}

void Screen::clear() {
    system("clear");
}

void Screen::drawPlayers(Player* players, int n) {
    for(int i = 0; i < n; i++) {
        std::cout << "Player " << i + 1 << ":\n";
        Bowl* bowls = players[i].getBowls();
        for(int j = 0; j < 3; j++) {
            std::cout << "  " << j + 1 << ": ";
            int len;
            Card** cards = bowls[j].getCards(&len);
            for(int k = 0; k < len; k++) {
                std::cout << "[" << cards[k]->getName() << "] ";
            }
            std::cout << "\n";
        }
        std::cout << "\n";
    }
}

void Screen::drawTable(Pool* pool) {
    Card** cards = pool->getCards();
    std::cout << "Pool: ";
    for(int i = 0; i < 4; i++) {
        if(!cards[i]) {
            std::cout << "[-] ";
            continue;
        }
        std::cout << "[" << cards[i]->getName() << "] ";
    }
    std::cout << "\n\n";
}

void Screen::drawHand(Player& player, int n, Card* card) {
    int len;
    Card** hand = player.getHand(&len);
    std::cout << n + 1 << ": Your hand: ";
    for(int i = 0; i < len; i++) {
        std::cout << "[" << hand[i]->getName() << "] ";
    }
    if(card) std::cout << "[[" << card->getName() << "]]";
    std::cout << "\n\n";
}

int Screen::readAction(int actions) {
    std::cout << "Actions left: " << actions << "\n";
    for(int i = 0; i < 8; i++) {
        std::cout << i + 1 << ": " << actionList[i];
    }
    int x;
    std::cin >> x;
    if(x >= 1 && x <= 8) return x;
    return 0;
}

int Screen::readInt() {
    int x;
    std::cin >> x;
    return x;
}

void Screen::print(std::string s) {
    std::cout << s << "\n";
}