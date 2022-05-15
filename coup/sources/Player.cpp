//
// Created by yohanan on 26/04/22.
//

#include "Player.hpp"
using namespace std;
using namespace coup;
const int seven = 7;
const int nine = 9;

Player::Player(Game &game1, string &name1, string role) : game(game1), name(name1) , money(0), online(true), play(""){
    this->myRole = move(role);
    this->game.addPlayer(*this);
}

void Player::income() {
    this->game.checks(*this);
    this->game.running = true;
    this->money ++;
    this->game.incMoves();
    this->play = "income";
}
void Player::foreign_aid(){
    this->game.checks(*this);
    if (this->coins() > nine ){
        throw invalid_argument ("you will pass 10 coins");}
    this->money +=2;
    this->game.incMoves();
    this->play = "foreign_aid";

}
void Player::coup(Player &player){
    this->game.checkwithoutCoup(*this);
    if (this->coins() < seven ){
        throw invalid_argument ("you need more coins!!");}
    if (!player.online){
        throw invalid_argument (player.name+" is dead...");}
    this->game.kick(player);
    this->money-=seven;
    this->coupName = player.name;
    this->play = "PlayerCoup";
}

string Player::role() const{
    return this->myRole;
}
int Player::coins() const{
    return this->money ;
}
void Player::dies() {
    this->online = false;
}

