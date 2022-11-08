#include <iostream>
#include "sources/Schedule.cpp"
#include "sources/Game.cpp"
#include "sources/Leauge.cpp"
#include "sources/Team.cpp"
using namespace std;
using namespace ball;
int main() {
Leauge leauge;
    Schedule schedule(&leauge);
    schedule.exec();
    vector<Team*> t = schedule.leauge.teams;
    cout << "---------------------conclusion!!!---------------" << endl;
    t = schedule.leauge.teams;
    for (Team *team :t) {
        team->printScore();
    }
    cout << "----------------------top-3-----------------------" << endl;
    vector<string> str = schedule.winningTeams(3);
    for (string top:str) {
    cout << top << endl;
    }
    cout << "-------------------in a rows-----------------------" << endl;
    cout << "best wins in a row" << schedule.getRowWinns() << endl;
    cout << "worst losses in a row" << schedule.getRowLoses() << endl;
    cout << "-------------scored more that get scored-----------" << endl;
    cout << schedule.greaterScoreThanLoss() << endl;
    cout << "-------------------edge details--------------------" << endl;
    cout << schedule.edgeTeamsDetails() << endl;
    cout << "------------total points to seasons----------------" << endl;
    cout << schedule.total() << endl;
    cout << "-----------see you in the next league!-------------" << endl;
    cout << "bye-bye (:" << endl;

    return 0;
}
