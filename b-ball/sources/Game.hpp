#pragma once
#ifndef GAME_H
#define GAME_H
#include <iostream>
#include "Team.hpp"
using namespace std;
namespace ball {
    class Game {
    public:
        Team *home;
        Team *away;
        Game (Team &home, Team &away);
        Game() = default;
        ~Game() = default;
        Game (Game& game) = default;
        Game (Game&& game) = default;
        Game & operator= (Game && ) = default;
        Game& operator = (const Game& game) = default;
        void setPoints() const;
        void setWinner() const;
    };
}


#endif //GAME_H

