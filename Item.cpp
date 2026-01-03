//
// Created by Vlad on 01.01.2026.
//

#include "Item.h"
#include <cstring>
using namespace std;

//implementare item
Item::Item(string name):name(name){}
Item::~Item(){}
string Item::getName() const {return name;}

//implementare cheie
KeyItem::KeyItem(string name, const char* desc):Item(name) {
    description=new char[strlen(desc)+1];
    strcpy(description,desc);
}
KeyItem::~KeyItem(){delete[] description;}
KeyItem& KeyItem::operator=(const KeyItem& other) {
if (this!=&other) {
    delete[] description;
    Item::operator=(other);
    description=new char[strlen(other.description)+1];
    strcpy(description,other.description);
}
    return *this;
}
void KeyItem::use() const{ cout<<" [CHEIE] Cheia se foloseste automat la usa.\n";}
void KeyItem::display() const{ cout<< name<<"("<<description<<")";}

//implementare arme
Weapon::Weapon(string name, int d):Item(name),damage(d) {}
void Weapon::use() const{ cout<<" [ECHIPAT] Ai scos arma "<<name<<".\n";}
void Weapon::display() const{ cout<< name<<"[DMG: "<<damage<<"]";}
int Weapon::getDamage() const {return damage;}

//implementare arme magice
MagicWeapon::MagicWeapon(string name, int d, int bonus): Weapon(name,d),magicBonus(bonus){}
void MagicWeapon::display() const { cout<< name<<"[DMG: "<<damage<<" physical damage + "<<magicBonus<<" magical damage]";}
void MagicWeapon::use() const{ cout<<" [ECHIPAT] Arma ta magica straluceste "<<name<<".\n";}
int MagicWeapon::getDamage() const {  return magicBonus+damage;}

//implementare consumabile
Consumable::Consumable(string name, int power, bool offensive):Item(name),power(power),isOffensive(offensive){}
void Consumable::use() const {
    if (isOffensive) {cout<<" [ATAC] Arunci cu "<<name<<" !\n";}
    else {cout<<" [VINDECARE] Consumi "<<name<<" .\n";}
}
void Consumable::display() const {
    cout<<name;
    if (isOffensive) {cout<<" [DMG: "<<power<<" ]";}
    else {cout<<" [Vindeca: "<<power<<" HP]";}
}
int Consumable::getPower() const {return power;}
bool Consumable::getIsOffensive() const {return isOffensive;}