//
// Created by yohanan on 26/04/22.
//
#ifndef PLAYER_H
#define PLAYER_H
#include "Game.hpp"
#include <iostream>
#include <string>
using namespace std;
namespace coup {
    class Game;

    class Player {
    public:
        Game &game;
        Player(Game &game1, string &name1, string role);
        string myRole;
        string name;
        string play;
        string coupName;
        bool online;
        int money;
        void income();
        void dies();
        void foreign_aid();
        void coup(Player &player);
        string role() const;
        int coins() const;
    };
}
#endif //COUPB_PLAYER_HPP
