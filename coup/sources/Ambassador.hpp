#ifndef COUPB_AMBASSADOR_HPP
#define COUPB_AMBASSADOR_HPP
#include <iostream>
#include <string>
#include "Player.hpp"
#include "Captain.hpp"
using namespace std;
using namespace coup;

class Ambassador: public Player{
public:
    Ambassador(Game &game, string name);
    void transfer (Player &player1, Player &player2);
    void block (Captain &player);
};

#endif //COUPB_AMBASSADOR_HPP
