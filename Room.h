#ifndef PROIECT_OOP_ROOM_H
#define PROIECT_OOP_ROOM_H

#include <iostream>
#include <vector>
#include <string>
#include <type_traits>
#include "Entity.h"
#include "Player.h"
#include "Item.h"
#include "GameUtils.h"

using namespace std;
class Player;

template<class T>
class Room {
private:
    string name, description;
    T inside;
    Player *player;
    bool visited;

public:
    Room(string name, string desc, T inside ,Player *player) : name(name), description(desc), visited(false), player(player) ,inside(inside){
    };
    string getName() { return name; }
    void setVisited() { visited = true; }
    T getInside() { return inside; }

    void visit(bool &triggerRespawn);
    ~Room();
};

template<class T>
Room<T>::~Room() {
    if (inside != nullptr) {
        delete inside;
        inside = nullptr;
    }
}

template<class T>
void Room<T>::visit(bool &triggerRespawn) {
    cout << "Bun venit in " << name << "!" << endl << description << endl;

    // enemy
    if constexpr (std::is_convertible_v<T, Enemy*>) {
        if (inside && inside->isAlive()) {
            cout << "Ai grija! esti atacat de " << inside->getName() << "!!!" << endl;

            while (inside->isAlive() && player->getHp() > 0) {
                cout << "\n   HP Tau: " << player->getHp() << " | Inamic: " << inside->getHp() << "\n";
                cout << "   1. Ataca cu arma  2. Foloseste ceva din inventar \n   > ";
                int op;
                if(!(cin >> op)){ cin.clear(); cin.ignore(1000, '\n'); continue; }

                if (op == 1) {
                    player->attack(inside);
                    if (inside->isAlive())
                        inside->attack(player);
                } else if (op == 2) {
                    cout << "(-1 daca nu ai gasit nimic util)\n";
                    player->showInventory();
                    cout << "Ce folosesti?(index): ";
                    int idx;
                    cin >> idx;

                    if (idx == -1) continue; // Logica ta cu -1

                    try {
                        player->useItem(idx, inside);
                        if (inside->isAlive()) inside->attack(player);
                    } catch (const GameException &ex) {
                        cout << "   [EROARE] " << ex.what() << endl;
                    } catch (...) {
                        cout << "   [EROARE] Actiune invalida.\n";
                    }
                } else {
                    cout << "Mai scrie o data ca n-am inteles\n";
                }
            }

            if (!inside->isAlive()) {
                cout << "E pustiu, inamicii sunt invinsi\n";
                if (Boss* b = dynamic_cast<Boss*>(inside)) {
                    Boss::decreaseCount();
                    cout << "Un boss a cazut! Au mai ramas: " << Boss::getCount() << "\n";
                }
            }
        } else {
            cout << "E pustiu, inamicii sunt invinsi\n";
        }
    }
    //Consumable
    else if constexpr (std::is_convertible_v<T, Consumable*>) {
        if (!visited && inside != nullptr) {
            cout << "Ai gasit un cufar!Oare ce se afla in el?\n";
            cout << "Ai obtinut: " << inside->getName() << "!\n";
            player->addItem(inside);
            inside = nullptr;
        }

        cout <<"Este un bonfire in camera, te poti aseza sa iti umpli din nou potiunile, dar ai grija, inamicii ucisi (nu Bossi) se vor intoarce la viata!\n";
        bool inputValid = false;
        while (!inputValid) {
            cout << "Te asezi la bonfire? (y/n): ";
            char op;
            cin >> op;
            if (op == 'y' || op == 'Y') {
                cout << "Te-ai odihnit. HP si potinile refacute.\n";
                player->restAtBonfire();
                triggerRespawn = true;
                inputValid = true;
            }
            else if (op == 'n' || op == 'N') {
                cout << "Ai decis sa nu te odihnesti.\n";
                inputValid = true;
            }
            else {
                cout << "Mai scrie o data ca n-am inteles\n";
            }
        }
    }
    // Npc
    else if constexpr (std::is_convertible_v<T, NPC*>) {
        if (inside) {
            if (!visited) {
                inside->describe();
                inside->interact(player);
            } else {
                cout << inside->getName() << " e acolo ca de obicei,saluti politicos.\n";
            }
        }
    }
    setVisited();
}

#endif //PROIECT_OOP_ROOM_H