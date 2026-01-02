//
// Created by Vlad on 01.01.2026.
//

#ifndef PROIECT_OOP_GAMEUTILS_H
#define PROIECT_OOP_GAMEUTILS_H


#include <vector>
#include <string>
#include <exception>
#include <iostream>


//exceptiile
class GameException : public std::exception {
protected:
    std::string msg;
public:
    GameException(std::string msg) : msg(msg) {}
    GameException():msg("Eroare"){}
    virtual const char *what() const noexcept override { return msg.c_str(); }
};

class InvalidItemException : public GameException {
public:
    InvalidItemException() : GameException("Eroare:Item invalid") {
    }
};

class InvalidChoice: public GameException {
public:
    InvalidChoice(): GameException("Nu poti folosi acest obiect in lupta") {
    }
};


//clasa template inventar
template <class T>
class Inventory {
private:
    std::vector<T> items;
    std::vector<int>counts;
public:
    void add(const T& item) {
        for (int i = 0; i < items.size(); ++i) {
            if (items[i]->getName() == item->getName()) {
                counts[i]++;
                delete item;
                return;
            }
        }
        //daca nu e deja in inventar
        items.push_back(item);
        counts.push_back(1);

    }
    void remove(int index) {
        if (index>=0 && index < items.size()) {
            delete items[index];
            items.erase(items.begin()+index);
            counts.erase(counts.begin()+index);
        }
    }
    T& get(int index) {
        if (index<0 || index >= items.size()){throw InvalidItemException();}
        return items[index];
    }

    int getCount(int index) {
        if (index<0 || index >= items.size()){throw InvalidItemException();}
        return counts[index];
    }

    void decreaseCount(int index) {
        if (index<0 || index >= items.size()){throw InvalidItemException();}
        counts[index]--;
        if (counts[index]==0)
            remove(index);
    }
    int size() const {return items.size();}
    bool empty() const {return items.empty();}
};

#endif //PROIECT_OOP_GAMEUTILS_H
