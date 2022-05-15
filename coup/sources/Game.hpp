//
// Created by yohanan on 26/04/22.
//
#ifndef GAME_H
#define GAME_H
#include <iostream>
#include "Player.hpp"
#include <string>
#include <vector>
using namespace std;
namespace coup {
    class Player;
    class Game {
    public:
        Game();
        ~Game();
        uint moves;
        bool running;
        vector <Player> gameParticipant;
        string turn();
        vector<string> players();
        string winner();
        void addPlayer(Player &player);
        void checks(Player &player);
        void checkwithoutCoup(Player &player);
        void kick(Player &player);
        void incMoves();
    };
}


#endif //COUPB_GAME_HPP

