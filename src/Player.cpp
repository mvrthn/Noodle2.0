#include "Player.hpp"


Player::~Player() {
    for(Card* card : hand) {
        delete card;
    }
}

bool Player::addToBowl(int bowlIndex, Card* card) {
    return bowls[bowlIndex].add(card);
}

Card* Player::takeFromBowl(int bowlIndex) {
    return bowls[bowlIndex].pop();
}

bool Player::addToHand(Card* card) {
    hand.push_back(card);
    return hand.size() <= 5;
}

Card* Player::takeFromHand(int cardIndex) {
    Card* card = hand[cardIndex];
    hand.erase(hand.begin() + cardIndex);
    return card;
}

bool Player::useSpoon() {
    if(spoons == 0) return false;
    spoons--;
    return true;
}

void Player::undoSpoon() {
    spoons++;
}

bool Player::eatBowl(int bowlIndex, int* points) {
    if(!bowls[bowlIndex].eat(points)) return false;
    score += *points;
    return true;
}

bool Player::pourOutBowl(int bowlIndex) {
    return bowls[bowlIndex].pourOut();
}

Bowl* Player::getBowls() {
    return bowls;
}

Card** Player::getHand(int* n) {
    *n = hand.size();
    return hand.data();
}