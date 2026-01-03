#ifndef PROIECT_OOP_ENTITY_H
#define PROIECT_OOP_ENTITY_H
#include<string>
#include<vector>
#include<iostream>
#include "Item.h"
using namespace std;
class Player;

class Entity {
protected:
    string name;
public:
    Entity(string name);
    virtual ~Entity();
    string getName() const;
};

class Character:public Entity {
protected:
    int hp,maxHp;
public:
    Character(string name,int maxHp);
    virtual void takeDamage(int dmg);
    bool isAlive() const;
    int getHp() const;
    void heal(int amount);
    void fullHeal();
    virtual void attack(Character* target)=0;
};

class Enemy:public Character {
protected:
    int baseDamage;
public:
    Enemy(string name,int maxHp,int dmg);
    void attack(Character* target) override;
    void respawn();
};

class Boss:public Enemy {
private:
    static int bossCount;
    string specialAbility;
public:
    Boss(string name,int maxHp,int dmg,string ability);
    void attack(Character* target) override;
    static int getCount();
    static void decreaseCount();
};

class NPC:public Entity {
private:
    string description;
    string dialogue;
    Item* giftItem;
    bool itemGiven;
public:
    NPC(string name,string desc,string dialogue,Item* gift=nullptr);
    ~NPC();
    void describe();
    void interact(Player* p);
};

#endif //PROIECT_OOP_ENTITY_H