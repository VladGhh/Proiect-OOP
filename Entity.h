//
// Created by Vlad on 01.01.2026.
//

#ifndef PROIECT_OOP_ENTITY_H
#define PROIECT_OOP_ENTITY_H
#include<string>
#include<vector>
#include "Item.h"
using namespace std;
class Player;



//clasa entitate
class Entity {
protected:
    string name;
public:
    Entity(string name);
    virtual ~Entity();
    string getName() const;
};



//clasa personaj
class Character:public Entity {
protected:
    int hp,maxHp;
public:
    Character(string name,int maxHp);
    virtual void takeDamage(int dmg);
    bool isAlive() const;
    int getHp() const;
    void heal(int amount);
    virtual void attack(Character* target)=0;
};



//clasa inamic
class Enemy:public Character {
protected:
    int baseDamage;
public:
    Enemy(string name,int maxHp,int dmg);
    void attack(Character* target) override;
};



//clasa Boss
class Boss:public Enemy {
private:
    static int bossCount;
    string specialAbility;
public:
    Boss(string name,int maxHp,int dmg,string ability);
    void attack(Character* target) override;
    static int getCount();
};



//clasa npc
class NPC:public Entity {
private:
    string description;
    string dialogue;
    Item* giftItem;
    bool itemGiven;
public:
    NPC(string name,string desc,Item* gift=nullptr);
    ~NPC();
    void describe();
    void interact(Player* p);
};

#endif //PROIECT_OOP_ENTITY_H