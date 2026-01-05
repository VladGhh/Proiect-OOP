#include <iostream>
#include "Player.h"
#include "Map.h"
#include "Leaderboard.h"
using namespace std;

int main() {


    Player* p = new Player("");
    Map gameMap(p);
    cin>>*p;
    Leaderboard leaderboard;
    leaderboard.populate();
    while(p->isAlive() && Boss::getCount() > 0) {
        gameMap.showMap();

        bool respawnTrigger = false;
        gameMap.processCurrentRoom(respawnTrigger);

        if(respawnTrigger) {
            gameMap.respawnAll();
        }

        if(!p->isAlive()) {
            cout << "AI MURIT.\n";
            Person* pr = new Person(gameMap.getScore(),p->getName(),false);
            leaderboard.addPerson(pr);
            leaderboard.showLeaderboard();
            break;
        }

        if(Boss::getCount() == 0) {
            cout << "VICTORIE! TOTI BOSSII AU FOST INVINS!\n";
            Person* pr = new Person(gameMap.getScore(),p->getName(),true);
            leaderboard.addPerson(pr);
            leaderboard.showLeaderboard();
            break;
        }

        gameMap.move();
    }

    delete p;
    return 0;
}