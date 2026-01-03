#include "Map.h"

Map::Map(Player* play) :player(play){
    map = {
        {},
        {2},
        {1, 3, 4 , 7},
        {2},
        {2, 5},
        {4, 6},
        {5},
        {2, 8},
        {7, 9, 10},
        {8, 11},
        {8},
        {9}
    };

    currentRoom=1;

    Consumable* c = new Consumable("Humanity", 60, false);
    Room1 = new Room<Consumable*>("Altarul Firelink", "Un loc linistit.", c, player);

    Enemy* e = new Enemy("Hollow Soldier", 50, 7);
    Room2 = new Room<Enemy*>("Orasul Ruinat", "Case distruse.", e, player);

    Enemy* e3 = new Boss("Demon Taur", 130, 20, "Smash");
    Room3 = new Room<Enemy*>("Podul Mare", "Un pod lung.", e3, player);

    Consumable* c4 = new Consumable("Firebomb", 50, true);
    Room4 = new Room<Consumable*>("Cimitirul", "Morminte vechi.", c4, player);

    Enemy* e5 = new Enemy("Balder Knight", 60, 20);
    Room5 = new Room<Enemy*>("Biserica", "Sunet de clopot.", e5, player);

    Enemy* e6 = new Boss("Gargoyle", 100, 10, "Flame Breath");
    Room6 = new Room<Enemy*>("Acoperis", "Cerul e aproape.", e6, player);

    Weapon* c7 = new Weapon("Uchikatana", 100);
    NPC* n7 = new NPC("Andre", "Fierar", "Nu te lasa ucis.", c7);
    Room7 = new Room<NPC*>("Atelier", "Sunet de ciocan.", n7, player);

    Enemy* e8 = new Enemy("Serpent Man", 70, 25);
    Room8 = new Room<Enemy*>("Fortareata Sen", "Capcane.", e8, player);

    Consumable* c9 = new Consumable("Divine Blessing", 120, false);
    Room9 = new Room<Consumable*>("Balcon", "Priveliste.", c9, player);

    Enemy* e10 = new Boss("Silver Knight", 90, 30, "Lightning");
    Room10 = new Room<Enemy*>("Anor Londo", "Orasul Zeilor.", e10, player);

    KeyItem* c11 = new KeyItem("Cheia Bisericii", "Cheia ce deschide usa inspre biserica");
    NPC* n11 = new NPC("Solaire", "Cavalerul Soarelui", "Praise the Sun!", c11);
    Room11 = new Room<NPC*>("Altarul Soarelui", "Statuie veche.", n11, player);
}

void Map::processCurrentRoom(bool &respawnNeeded) {
    switch(currentRoom) {
        case 1: Room1->visit(respawnNeeded); break;
        case 2: Room2->visit(respawnNeeded); break;
        case 3: Room3->visit(respawnNeeded); break;
        case 4: Room4->visit(respawnNeeded); break;
        case 5: Room5->visit(respawnNeeded); break;
        case 6: Room6->visit(respawnNeeded); break;
        case 7: Room7->visit(respawnNeeded); break;
        case 8: Room8->visit(respawnNeeded); break;
        case 9: Room9->visit(respawnNeeded); break;
        case 10: Room10->visit(respawnNeeded); break;
        case 11: Room11->visit(respawnNeeded); break;
    }
}

void Map::respawnAll() {
    if(Room2->getInside()) Room2->getInside()->respawn();
    if(Room5->getInside()) Room5->getInside()->respawn();
    if(Room8->getInside()) Room8->getInside()->respawn();
}

void Map::move() {
    cout<<"                                             Harta tinutului"<<endl<<endl;
    cout<<"                                            Altarul Firelink (1)"<<endl;
    cout<<"                                                    ||"<<endl;
    cout<<"  Biserica parasita(5)   ===   Cimitirul(4)   ===   Orasul ruinat(2)   ===   Podul mare(3)"<<endl;
    cout<<"          ||                                        ||"<<endl;
    cout<<"  Acoperisul Bisericii(6)                       Atelierul fierarului(7)  "<<endl;
    cout<<"                                                    ||"<<endl;
    cout<<"                                                Fortareata(8)  ===   Anor londo(10)"<<endl;
    cout<<"                                                    ||"<<endl;
    cout<<"                                                Balconul Fortaretei(9)"<<endl;
    cout<<"                                                    ||"<<endl;
    cout<<"                                                Altarul soarelui(11)"<<endl;
    cout<<"\nTu esti acum in camera: " << currentRoom << endl;

    vector<int> targets = map[currentRoom];
    cout << "\nIncotro mergi? (Variante: ";
    for(int t : targets) cout << t << " ";
    cout << "): ";

    int choice;
    cin >> choice;

    bool ok = false;
    for(int t : targets) if(t == choice) ok = true;

    if(ok) {
        if(choice == 5) {
            if(player->hasKey("Cheia Bisericii")) {
                cout << "Ai folosit Cheia Bisericii. Usa se deschide.\n";
                currentRoom = choice;
            } else {
                cout << "Usa este incuiata. Ai nevoie de o cheie.\n";
            }
        } else {
            currentRoom = choice;
        }
    } else {
        cout << "Nu poti ajunge acolo direct.\n";
    }
}

void Map::showMap() {
    cout << "Esti in Camera " << currentRoom << endl;
}



Map::~Map() {
    delete Room1; delete Room2; delete Room3;
    delete Room4; delete Room5; delete Room6;
    delete Room7; delete Room8; delete Room9;
    delete Room10; delete Room11;
}