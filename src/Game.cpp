#include "Game.hpp"

#include <cassert>


Game::Game(int _numOfPlayers) {
    assert(_numOfPlayers >= 3 && _numOfPlayers <= 5);
    numOfPlayers = _numOfPlayers;
    int turn = 0;
    deck = new Deck();
    pool = new Pool(deck);
    players = new Player[numOfPlayers];
    for(int i = 0; i < numOfPlayers; i++) {
        for(int j = 0; j < 5; j++) {
            players[i].addToHand(deck->drawCard());
        }
    } 
}

Game::~Game() {
    delete[] players;
    delete deck;
    delete pool;
}

Card* Game::highlightCard(Player& player, int cardIndex) {
    return player.takeFromHand(cardIndex);
}

bool Game::unhighlightCard(Player& player, Card** card) {
    Card* cardCopy = *card;
    *card = nullptr;
    return player.addToHand(cardCopy);
}

bool Game::addToBowl(Player& player, int bowlIndex, Card* card) {
    return player.addToBowl(bowlIndex, card);
}

bool Game::drawCard(Player& player, int index) {
    Card* card = nullptr;
    if(index == 4) card = deck->drawCard();
    else card = pool->drawCard(index, deck);
    if(!card) return false;
    player.addToHand(card);
    return true;
}

Card* Game::takeCard(Player& player, int bowlIndex) {
    if(!player.useSpoon()) return nullptr;
    Card* card = player.takeFromBowl(bowlIndex);
    if(card) return card;
    player.undoSpoon();
    return nullptr;
}

bool Game::redrawPool() {
    pool->replace(deck);
    return true;
}

bool Game::eatBowl(Player& player, int bowlIndex, int* points) {
    return player.eatBowl(bowlIndex, points);
}

bool Game::pourOutBowl(Player& player, int bowlIndex) {
    return player.pourOutBowl(bowlIndex);
}

void Game::run() {
    while(true) {
        Player& player = players[turn % numOfPlayers];
        int actions = 2;
        Card* card = nullptr;

        while(actions > 0) {
            int x = 0;

            while(!x) {
                screen.clear();
                screen.drawPlayers(players, numOfPlayers);
                screen.drawTable(pool);
                screen.drawHand(player, turn % numOfPlayers, card);

                x = screen.readAction(actions);
            }

            int points = 0;
            switch(x) {
                case 1: 
                    card = highlightCard(player, screen.readInt());
                    break;
                case 2:
                    if(card && addToBowl(player, screen.readInt(), card)) {
                        actions--;
                        card = nullptr;
                    }
                    break;
                case 3:
                    if(drawCard(player, 4)) actions--;
                    break;
                case 4:
                    if(drawCard(player, screen.readInt())) actions--;
                    break;
                case 5:
                    card = takeCard(players[screen.readInt()], screen.readInt());
                    if(card) actions--;
                    if(screen.readInt()) break;
                    addToBowl(players[screen.readInt()], screen.readInt(), card);
                    break;
                case 6:
                    redrawPool();
                    actions--;
                    break;
                case 7:
                    if(eatBowl(player, screen.readInt(), &points)) actions--;
                    screen.print("Points: " + points);
                    break;
                case 8:
                    if(pourOutBowl(player, screen.readInt())) actions--;
                    break;
            }
        }

        turn++;
    }
}