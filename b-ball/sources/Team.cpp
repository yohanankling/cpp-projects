#include "Team.hpp"
using namespace std;
using namespace ball;
Team::Team(string &name, double skill){
    this->name = name;
    this->skill = skill;
}

void Team::print() const{
    cout << this->name << ": skill: " << this->skill << ": wins: " << this->winns << endl;
}

void Team::printScore() const{
    cout << this->name << ": " << this->winns << " wins" << endl;
}
