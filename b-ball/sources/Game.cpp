#include "Game.hpp"
#include <random>

using namespace ball;
using namespace std;
random_device rd;
mt19937 gen(rd());
const int fiftytive = 55;
const int fifty = 50;
const int hundred = 100;
const int ten = 10;

    Game::Game(Team &home, Team &away) {
        this->home = &home;
        this->away = &away;
        setPoints();
    }
    void Game::setPoints() const {
        uniform_int_distribution<> distr(fiftytive, hundred);
        this->home->points = (distr(gen)) + (int)this->home->skill*ten;
        this->home->totalPointsWon += this->home->points - (int)this->home->skill*ten;
        uniform_int_distribution<> distr1(fifty, hundred);
        this->away->points = distr(gen) + (int)this->away->skill*ten;
        this->away->totalPointsWon += this->away->points - (int)this->away->skill*ten;
        this->home->totalPointsLoss += this->away->points - (int)this->away->skill*ten;
        this->away->totalPointsLoss += this->home->points - (int)this->home->skill*ten;
    }

    void Game::setWinner() const{
        if (this->home->points > this->away->points){
            this->home->winns++;
            this->home->inArow++;
            this->away->inArowLoss++;
            if(this->home->inArowFinall<this->home->inArow){
                this->home->inArowFinall = this->home->inArow;
            }
            if(this->home->inArowLossFinnal<this->home->inArowLoss){
                this->home->inArowLossFinnal = this->home->inArowLoss;
            }
            this->away->inArow = 0;
            this->home->inArowLoss = 0;
        } else{
            this->away->winns++;
            this->away->inArow++;
            this->home->inArowLoss++;
            if(this->away->inArowFinall<this->away->inArow){
            this->away->inArowFinall = this->away->inArow;
        }
            if(this->away->inArowLossFinnal<this->away->inArowLoss){
                this->away->inArowLossFinnal = this->away->inArowLoss;
            }
        this->home->inArow = 0;
            this->away->inArowLoss = 0;
        }
    }

