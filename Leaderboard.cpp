//
// Created by Vlad on 05.01.2026.
//

#include "Leaderboard.h"

#include <algorithm>

bool Person::getDidWin() const {
    return didWin;
}

int Person::getScore() const {
    return score;
}
string Person::getName() const {
    return name;
}

std::ostream& operator<<(std::ostream& os, const Person& person) {
    os << person.getName()<<" "<<person.getScore()<<" suflete"<<endl;
    return os;
}

Leaderboard::Leaderboard() {
}

Leaderboard::~Leaderboard() {
    for (int i = 0; i < winBoard.size(); i++)
        delete winBoard[i];
    for (int i = 0; i < loseBoard.size(); i++)
        delete loseBoard[i];
}

void Leaderboard::addPerson(Person *person) {
    if (person->getDidWin()) {
        winBoard.push_back(person);
        sort(winBoard.begin(), winBoard.end(),
             [](const Person *A, const Person *B) { return A->getScore() > B->getScore(); });
    } else {
        loseBoard.push_back(person);
        sort(loseBoard.begin(), loseBoard.end(),
             [](const Person *A, const Person *B) { return A->getScore() > B->getScore(); });
    }
}

void Leaderboard::showLeaderboard() {
    cout<<"Eroii care au distrus intunericul"<<endl;
    for (int i = 0; i < winBoard.size(); i++) {
        cout<<" "<<i+1<<". "<<*winBoard[i];
    }
    cout<<"Cei ce n au reusit si au devenit Hollow"<<endl;
    for (int i = 0; i < loseBoard.size(); i++) {
        cout<<" "<<i+1<<". "<<*loseBoard[i];
    }
}
void Leaderboard::populate() {
    Person *p1=new Person(300,"Dani Danutul",false);
    this->addPerson(p1);
    Person *p2=new Person(13370,"Marian Camatarul",true);
    this->addPerson(p2);
    Person *p3=new Person(1390,"Marcel Omul Padurii",false);
    this->addPerson(p3);
    Person *p4=new Person(9900,"Maria",true);
    this->addPerson(p4);
    Person *p5=new Person(1230,"Ana Banana",false);
    this->addPerson(p5);
    Person *p6=new Person(2380,"Costel Smacherel",false);
    this->addPerson(p6);

}
