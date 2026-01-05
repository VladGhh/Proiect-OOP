//
// Created by Vlad on 05.01.2026.
//

#ifndef PROIECT_OOP_LEADERBOARD_H
#define PROIECT_OOP_LEADERBOARD_H
#include<string>
#include<vector>
#include<iostream>
using namespace std;

class Person {
private:
    int score;
    string name;
    bool didWin;
public:

    Person(int score, const string &name, bool didWin)
        : score(score),
          name(name),
          didWin(didWin) {
    }
    bool getDidWin() const;
    int getScore() const;
    string getName() const;

    friend ostream& operator<<(std::ostream& os, const Person& person) ;
};


class Leaderboard {
private:
    vector<Person*> loseBoard;
    vector<Person*> winBoard;
public:
   Leaderboard();
    ~Leaderboard();
    void addPerson(Person* person);
    void showLeaderboard();
    void populate();
};


#endif //PROIECT_OOP_LEADERBOARD_H