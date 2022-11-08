#pragma once
#ifndef Team_H
#define Team_H
#include <iostream>
#include <string>
using namespace std;
namespace ball {
    class Team {
    public:
        Team(string &name, double skill);
        Team() = default;
        ~Team() = default;
        Team (Team& team) = default;
        Team (Team&& team) = default;
        Team & operator= (Team && ) = default;
        Team& operator = (const Team& team) = default;
        string name;
        double skill{};
        int points = 0;
        int winns = 0;
        int inArow = 0;
        int inArowLoss = 0;
        int inArowLossFinnal = 0;
        int inArowFinall = 0;
        int totalPointsWon = 0;
        int totalPointsLoss = 0;
        void print() const;
        void printScore() const;
    };
}
#endif //Team_H

