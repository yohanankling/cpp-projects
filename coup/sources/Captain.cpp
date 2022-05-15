//
// Created by yohanan on 26/04/22.
//

#include "Captain.hpp"
using namespace std;
using namespace coup;

Captain::Captain(Game &game, string name) : Player (game, name, "Captain"), stoleFrom(nullptr){
}
void Captain::steal(Player &player) {
    this->game.checks(*this);
    this->play = "steal";
    if (player.money == 1){
        player.money = 0;
        this->money+=1;
    }
    else if (player.money > 1){
        this->money+=2;
        player.money -= 2;
    }
    this->game.incMoves();
    this->stoleFrom = &player;
}
void Captain::block(Player &player) {
    if(player.myRole != "Ambassador"){
        throw invalid_argument("cant block this action");
    }
}