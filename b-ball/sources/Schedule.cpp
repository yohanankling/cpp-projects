#include "Schedule.hpp"
#include "Game.hpp"
#include "Leauge.hpp"
#include <algorithm>
using namespace ball;
const int ninety = 19;
const int thertyeight = 38;


Schedule::Schedule(Leauge *leauge) {
    this->leauge = *leauge;
    for (uint i = 1; i < leauge->teams.size(); ++i) {
        this->teams.push_back(leauge->teams.at(i));
    }
}

void Schedule::exec() {
    for (uint i = 0; i < this->leauge.teams.size(); ++i) {
        for (uint j = i; j < this->teams.size(); ++j) {
            if(this->leauge.teams.at(i)->name == this->teams.at(i)->name){
                continue;
            }
            Game *game = new Game(*this->leauge.teams.at(i), *this->teams.at(j));
            game->setPoints();
            game->setWinner();
            Game *game1 = new Game(*this->teams.at(j), *this->leauge.teams.at(i));
            game1->setPoints();
            game1->setWinner();
        }
    }
}
struct winnsSort
{
    inline bool operator() (Team *team1, const Team *team2)
    {
        if (team1->winns == team2->winns){
            return (team1->totalPointsWon-team1->totalPointsLoss < team2->totalPointsWon-team2->totalPointsLoss);
        }
        return team1->winns > team2->winns;
    }
};

void Schedule::sortLeauge() {
    sort(this->leauge.teams.begin(), this->leauge.teams.end(), winnsSort());
}

vector<string> Schedule::winningTeams(int num){
    if (num > ninety){
        throw invalid_argument("20 teams max..");
    }
    this->sortLeauge();
    vector<string> ans;
    for (uint i = 0; i < num; ++i) {
        ans.push_back(this->leauge.teams.at(i)->name);
    }
    return ans;
}

int Schedule::getRowWinns(){
    int ans = 0;
    for (Team *team :this->leauge.teams) {
        if(ans < team->inArowFinall){
            ans = team->inArowFinall;
        }
    }
    return ans;
    }

int Schedule::getRowLoses(){
    int ans = 0;
    for (Team *team :this->leauge.teams) {
        if(ans < team->inArowLossFinnal){
            ans = team->inArowLossFinnal;
        }
    }
    return ans;
}

int Schedule::greaterScoreThanLoss(){
    int ans = 0;
    for (Team *team :this->leauge.teams) {
        if(team->totalPointsWon > team->totalPointsLoss){
            ans++;
        }
    }
    return ans;
}

string Schedule::edgeTeamsDetails(){
    this->sortLeauge();
    Team *team = this->leauge.teams.front();
    string ans = "best team: " +
            team->name + " games stat: \n      won: " + to_string(team->winns) +
                 "      loss: " + to_string(thertyeight - team->winns) +
                 "      scored: " + to_string(team->totalPointsWon) +
                 "      got scored: " + to_string(team->totalPointsLoss);
    team = this->leauge.teams.back();
    ans +=  "\nworst team: " +
            team->name + " games stat: \n      won: " + to_string(team->winns) +
            "      loss: " + to_string(thertyeight - team->winns) +
            "      scored: " + to_string(team->totalPointsWon) +
            "      got scored: " + to_string(team->totalPointsLoss);
    return ans;
}

string Schedule::total() {
    string ans;
    int totalScored = 0;
    for (Team *team: this->leauge.teams) {
        totalScored += team->totalPointsWon;
    }
    ans += "total points that scored this seasons: " +
           to_string(totalScored);
    return ans;
}