#pragma once


#include "Game.hpp"

class App {
public:
    App() = default;
    ~App();
    
    void newGame(int);
private:
    Game* game;
};