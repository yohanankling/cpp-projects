
#ifndef COUPB_CAPTAIN_HPP
#define COUPB_CAPTAIN_HPP


//
// Created by yohanan on 26/04/22.
//
#include <iostream>
#include <string>
#include "Player.hpp"
using namespace std;
using namespace coup;


class Captain : public Player{
public:
    Captain(Game &game, string name);
    static void block(Player &player);
    void steal(Player &player);
    Player *stoleFrom;
};


#endif //COUPB_CAPTAIN_HPP
