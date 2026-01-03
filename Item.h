//
// Created by Vlad on 01.01.2026.
//

#ifndef PROIECT_OOP_ITEM_H
#define PROIECT_OOP_ITEM_H
#include<iostream>
#include<string>
using namespace std;
class Player;
class Entity;

//clasa item
class Item {
protected:
    string name;
public:
    Item(string name);
    virtual ~Item();
    string getName() const;
    virtual void use() const = 0;
    virtual void display() const = 0;
};

//clasa cheie
class KeyItem:public Item {
private:
    char* description;
public:
    KeyItem(string name, const char* desc); // Modified to const char*
    ~KeyItem();
    KeyItem& operator=(const KeyItem& other);
    void use() const override;
    void display() const override;
};

//clasa arma
class Weapon: public Item {
protected:
    int damage;
public:
    Weapon(string name,int d);
    virtual int getDamage() const;
    void use() const override;
    void display() const override;
};

//clasa arma magica
class MagicWeapon: public Weapon {
private:
    int magicBonus;
public:
    MagicWeapon(string name,int d,int bonus);
    int getDamage() const override;
    void use() const override;
    void display() const override;
};

//clasa consumabile
class Consumable:public Item {
private:
    int power;
    bool isOffensive;
public:
    Consumable(string name,int power,bool offensive);
    int getPower() const;
    bool getIsOffensive() const;
    void use() const override;
    void display() const override;
};

#endif //PROIECT_OOP_ITEM_H