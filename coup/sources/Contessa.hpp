
#ifndef COUPB_CONTESSA_HPP
#define COUPB_CONTESSA_HPP


//
// Created by yohanan on 26/04/22.
//
#include <iostream>
#include <string>
#include "Player.hpp"
#include "Assassin.hpp"
using namespace std;
using namespace coup;


class Contessa : public Player{
public:
    Contessa(Game &game, string name);
    void block(Assassin &player);
};


#endif //COUPB_CONTESSA_HPP
