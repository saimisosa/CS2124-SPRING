//
// Created by Saimanasa Juluru on 3/30/20.
//

#include "Warrior.h"
#include "Noble.h"
#include <string>
#include <iostream>

using namespace std;
namespace WarriorCraft {
    Warrior::Warrior(const string& warriorName, double power2): name(warriorName), power(power2), boss(nullptr){}

    const double Warrior::getStrength() const { return power; } // returns power
    const string Warrior::getName() const { return name; } // returns name

    void Warrior::setStrength(float ratio) { power = ratio; } // sets strength
    void Warrior::displayWarrior() const { cout << name << " : " << power <<endl; } // displays warrior : power
    void Warrior::setEmployer(WarriorCraft::Noble *&n) { boss = n; } // sets boss
    void Warrior::runaway(){
        boss->removeWarrior(name);
        cout << name << " flees in terror, abandoning his lord, " << boss->getName() <<endl;
        boss = nullptr;
    }
}