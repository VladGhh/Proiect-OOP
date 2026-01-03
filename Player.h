//
// Created by Vlad on 02.01.2026.
//

#ifndef PROIECT_OOP_PLAYER_H
#define PROIECT_OOP_PLAYER_H
#include "Entity.h"
#include "GameUtils.h"


class Player :public Character{
private:
    Inventory<Item *> backpack;
    Weapon* equippedWeapon;
public:
    Player(std::string name);
    ~Player();

    void addItem(Item* it);
    void useItem(int index,Character* target);
    void attack(Character *target) override;
    bool hasKey(const std::string& keyName);
    void showInventory();
    void restAtBonfire();
};



#endif //PROIECT_OOP_PLAYER_H