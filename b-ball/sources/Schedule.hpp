#pragma once
#ifndef Schedule_HPP
#define Schedule_HPP
#include <iostream>
#include <string>
#include <vector>
#include "Leauge.hpp"
using namespace std;
namespace ball {
    class Schedule {
    public:
        Schedule(Leauge *leauge);
        Leauge leauge;
        vector<Team *> teams;
        void exec();
        void sortLeauge();
        vector<string> winningTeams(int num);
        int getRowWinns();
        int getRowLoses();
        int greaterScoreThanLoss();
        string edgeTeamsDetails();
        string total();
        Schedule (Schedule& Schedule) = default;
        Schedule (Schedule&& Schedule) = default;
        Schedule & operator= (Schedule && ) = default;
        Schedule& operator = (const Schedule& Schedule) = default;
        ~Schedule() = default;
    };
}
#endif //Schedule_HPP
