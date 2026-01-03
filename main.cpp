#include <iostream>
#include "Player.h"
#include "Map.h"

using namespace std;

int main() {
    cout << "Dati un nume eroului: ";
    string name;
    cin >> name;

    Player* p = new Player(name);
    Map gameMap(p);

    while(p->isAlive() && Boss::getCount() > 0) {
        gameMap.showMap();

        bool respawnTrigger = false;
        gameMap.processCurrentRoom(respawnTrigger);

        if(respawnTrigger) {
            gameMap.respawnAll();
        }

        if(!p->isAlive()) {
            cout << "AI MURIT.\n";
            break;
        }

        if(Boss::getCount() == 0) {
            cout << "VICTORIE! TOTI BOSSII AU FOST INVINS!\n";
            break;
        }

        gameMap.move();
    }

    delete p;
    return 0;
}