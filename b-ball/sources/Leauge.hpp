#pragma once
#ifndef Leauge_HPP
#define Leauge_HPP
#include <iostream>
#include <vector>
#include "Team.hpp"
using namespace std;
namespace ball {
    class Leauge {
    public:
        vector<Team*> teams;
        Leauge();
        Leauge(const vector<Team*>& teams);
        static Team* generateTeam();
        Leauge (Leauge& Leauge) = default;
        Leauge (Leauge&& Leauge) = default;
        Leauge & operator= (Leauge && ) = default;
        Leauge& operator = (const Leauge& Leauge) = default;
        ~Leauge() = default;
        void addTeam (Team &team);
    };
}
#endif //Leauge_HPP
