#include "App.hpp"


void App::newGame(int numOfPlayers) {
    game = new Game(numOfPlayers);
    game->run();
}

App::~App() {
    delete game;
}