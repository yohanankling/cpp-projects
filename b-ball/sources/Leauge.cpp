#include "Leauge.hpp"
using namespace ball;
#include <random>
random_device rand2;
mt19937 gen2(rand2());
const int sixtytive = 65;
const int ninety1 = 90;
const int twenty = 20;

uniform_int_distribution<> distr(sixtytive, ninety1);

Leauge::Leauge() {
    while (this->teams.size()<twenty){
        Team *team = generateTeam();
        this->addTeam(*team);
    }
}

Leauge::Leauge(const vector<Team *>& teams) {
    if(teams.size()>twenty){
        throw invalid_argument("20 teams max..");
    }
    this->teams = teams;
    while (this->teams.size()<twenty){
        Team *team = generateTeam();
        this->addTeam(*team);
    }
}

Team* Leauge::generateTeam(){
    string name;
    char ch = 'a';
    for (int i = 0; i < 4; ++i) {
        ch = (char)distr(gen2) ;
        name +=ch;
    }
    float skill = static_cast <float> (rand()) / static_cast <float> (RAND_MAX);
    Team *team = new Team(name, skill);
    return team;
}

void Leauge::addTeam(Team &team) {
    for (Team *team1 : this->teams) {
        if (team1->name == team.name){
            return;}
    }
    this->teams.push_back(&team);
}


