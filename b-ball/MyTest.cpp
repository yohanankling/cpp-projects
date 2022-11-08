//
// Created by yohanan on 02/06/22.
//
#include <stdexcept>
#include "doctest.h"
#include "sources/Schedule.cpp"
#include "sources/Game.cpp"
#include "sources/Leauge.cpp"
#include "sources/Team.cpp"
using namespace ball;
using namespace std;

TEST_CASE("good case") {
    // test for a league
    Leauge leauge;
    Schedule schedule(&leauge);
    CHECK_NOTHROW(schedule.exec());
        vector<Team*> t = schedule.leauge.teams;
        CHECK_EQ(t.size(),20);
        vector<string> str = schedule.winningTeams(3);
        CHECK_EQ(str.size(),3);
        CHECK_NOTHROW(schedule.getRowWinns());
        CHECK_NOTHROW(schedule.getRowLoses());
        CHECK_NOTHROW(schedule.greaterScoreThanLoss());
        CHECK_NOTHROW(schedule.edgeTeamsDetails());
        CHECK_NOTHROW(schedule.total());
 }

TEST_CASE("good case2") {
    // test for a league
    vector<Team * >teams;
    string name = "yohanan";
    Team team (name, 0.1);
    teams.push_back(&team);
    Leauge leauge(teams);
    Schedule schedule(&leauge);
            CHECK_NOTHROW(schedule.exec());
    vector<Team*> t = schedule.leauge.teams;
            CHECK_EQ(t.size(),20);
    vector<string> str = schedule.winningTeams(3);
            CHECK_EQ(str.size(),3);
            CHECK_NOTHROW(schedule.getRowWinns());
            CHECK_NOTHROW(schedule.getRowLoses());
            CHECK_NOTHROW(schedule.greaterScoreThanLoss());
            CHECK_NOTHROW(schedule.edgeTeamsDetails());
            CHECK_NOTHROW(schedule.total());
}

TEST_CASE("bad case") {
    // test for a league
    Leauge leauge;
    Schedule schedule(&leauge);
    string name = "yohanan";
    Team team (name, 0.1);
    CHECK_THROWS(leauge.addTeam((team)));
    CHECK_THROWS(schedule.winningTeams(21));
}
