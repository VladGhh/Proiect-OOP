//
// Created by Vlad on 02.01.2026.
//

#include "Player.h"
#include "GameUtils.h"

using namespace std;

Player::Player(std::string name) : Character(name, 120), equippedWeapon(nullptr) {
    //iteme de start
    backpack.add(new Weapon("Sabie tocita", 12));
    backpack.add(new Consumable("Licoare ajutatoare", 60, false));
    backpack.add(new Consumable("Firebomb", 60, true));
    equippedWeapon = dynamic_cast<Weapon *>(backpack.get(0));
}

Player::~Player() {
    for (int i = 0; i < backpack.size(); i++)
        delete backpack.get(i);
};

void Player::addItem(Item *it) {
    backpack.add(it);
}

void Player::useItem(int index, Character *enemy) {
    try {
        Item *item = backpack.get(index);
        if (Weapon *w = dynamic_cast<Weapon *>(item)) {
            equippedWeapon = w;
            w->use();
        } else if (Consumable *c = dynamic_cast<Consumable *>(item)) {
            if (c->getIsOffensive()) {
                //cutite,bombe
                if (enemy && enemy->isAlive()) {
                    c->use();
                    enemy->takeDamage(c->getPower());
                    cout << " -> Inamicul a primit " << c->getPower() << " damage!\n";
                    backpack.decreaseCount(index);
                } else {
                    cout << "Nici un personaj ostil in zona\n";
                }
            } else {
                //heal
                c->use();
                heal(c->getPower());
                cout << "   -> HP Refacut: " << hp << "/" << maxHp << "\n";
                backpack.decreaseCount(index);
            }
        } else throw InvalidChoice();
    } catch (const InvalidChoice &e) {
        cout << e.what() << "\n";
    } catch (const InvalidItemException &e) {
        cout << e.what() << "\n";
    } catch (const GameException &e) {
        cout << e.what() << "\n";
    }
}

void Player::attack(Character *target) {
    int dmg = equippedWeapon->getDamage();
    cout << " Lovesti cu " << equippedWeapon->getName() << "!\n";
    target->takeDamage(dmg);
}

bool Player::hasKey(const std::string &keyName) {
    for (int i = 0; i < backpack.size(); ++i) {
        if (backpack.get(i)->getName() == keyName) {
            return true;
        }
    }
    return false;
}

void Player::showInventory() {
    cout << "\n   INVENTAR\n";
    for (int i = 0; i < backpack.size(); ++i) {
        cout << " " << i << ". ";
        backpack.get(i)->display();
        if (backpack.get(i) == equippedWeapon)
            cout << " [ECHIPAT]";
        if (Consumable *c = dynamic_cast<Consumable *>(backpack.get(i)))
            cout << " [ " << backpack.getCount(i) << " ] ";
        cout << "\n";
    }
}
