//
// Created by yohanan on 26/04/22.
//
#include <algorithm>
#include "Game.hpp"
const int five = 5;
const int ten = 10;
using namespace coup;
    Game::Game(): moves(0), running(false){
    }

    Game::~Game() {}

    string Game::turn() {
        return this->gameParticipant.at(uint(this->moves)).name;
    }

    vector<string> Game::players() {
        vector <string> activeParticipant;
        for (Player &p : this->gameParticipant) {
            if (p.online){
                activeParticipant.push_back(p.name);
            }
        }
        return activeParticipant;
    }

    void Game::checks(Player &player){
        if (this->gameParticipant.size() == 1){
            throw invalid_argument ("wait for other players to join..");}
        if (this->turn() != player.name){
            throw invalid_argument ("wait for your turn..");}
        if (player.money == ten){
            throw invalid_argument ("you have to make a coup!");}
    }
    void Game::checkwithoutCoup(Player &player){
        if (this->gameParticipant.size() == 1){
            throw invalid_argument ("wait for other players to join..");}
        if (this->turn() != player.name){
            throw invalid_argument ("wait for your turn..");}
    }

    string Game::winner() {
        if(!this->running){
            throw invalid_argument ("game not running..");
        }
        if(this->players().size() != 1){
            throw invalid_argument ("game still running..");
        }
        return this->players().at(0);
    }

    void Game::addPlayer(Player &player) {
        if (this->running){
            throw invalid_argument("game is running...");
        }
        if (this->gameParticipant.size() > five ){
            throw invalid_argument("max of 6 participant...");
        }
        this->gameParticipant.push_back(player);
    }

    void Game::kick(Player &player) {
        for (Player &p : this->gameParticipant) {
            if (p.name == player.name){
                if (!p.online){
                    throw invalid_argument("is dead...");
                }
                p.online = false;
                this->incMoves();
                break;
            }
        }
    }

    void Game::incMoves(){
        for (uint i = this->moves+1; i < this->gameParticipant.size() + this->moves; ++i) {
            if (this->gameParticipant.at(i % this->gameParticipant.size()).online) {
                this->moves = i % this->gameParticipant.size();
                break;
            }
        }
    }