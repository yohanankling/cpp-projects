//
// Created by yohanan on 26/04/22.
//
#include "Assassin.hpp"
const int six = 6;
const int seven = 7;
using namespace std;
using namespace coup;

Assassin::Assassin(Game &game, string name) : Player (game, name, "Assassin"){
}
void Assassin::coup(Player &player) {
    if (this->coins() < 3 ){
        throw invalid_argument ("you need more coins!!");}
    this->game.checks(*this);
    this->game.kick(player);
    if (this->coins() > six ) {
        this->money-=seven;
        this->lastcoup = player.name;
    }
    else {
    this->money-=3;
    this->lastcoup = player.name;
    this->play = "AssasinCoup";}

}