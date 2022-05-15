
#ifndef COUPB_DUKE_HPP
#define COUPB_DUKE_HPP


//
// Created by yohanan on 26/04/22.
//
#include <iostream>
#include <string>
#include "Player.hpp"
using namespace std;
using namespace coup;


class Duke : public Player{
public:
    Duke(Game &game, string name);
    void block(Player &player);
    void tax();
};


#endif //COUPB_DUKE_HPP
