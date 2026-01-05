#ifndef PROIECT_OOP_MAP_H
#define PROIECT_OOP_MAP_H
#include <vector>
#include <iostream>
#include "Room.h"
#include "Player.h"

using namespace std;
class Player;

class Map {
private:
    int currentRoom;
    int score;
    vector<vector<int>> map;

    // Pointeri expliciti
    Room<Enemy*> *Room2, *Room3, *Room5, *Room6, *Room8, *Room10;
    Room<NPC*> *Room7, *Room11;
    Room<Consumable*> *Room1, *Room4, *Room9;

    Player* player;
public:
    Map(Player* play);
    ~Map();


    void showMap();
    void processCurrentRoom(bool &respawnNeeded);
    void move();
    void respawnAll();
    int getScore();
};

#endif //PROIECT_OOP_MAP_H