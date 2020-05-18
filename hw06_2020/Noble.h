//
// Created by Saimanasa Juluru on 3/30/20.
//

#ifndef HOW06_2020_NOBLE_H
#define HOW06_2020_NOBLE_H


#include <string>
#include <vector>
#include <iostream>

namespace WarriorCraft{
    class Warrior;
    class Noble {
    public:
        Noble(const std::string &nobleName);

        std::string getName() const;
        std::vector<Warrior*> getWarriors() const;
        bool aliveNow();

        void setAlive(bool thing);
        void hire(Warrior& warriorName);
        void battle(Noble& nobleName);
        void fire(Warrior& warriorName);
        void removeWarrior(std::string runaway);

    private:
        std::string name;
        std::vector <Warrior*> army;
        double totalStrength;
        bool isAlive = true;

    };
    std::ostream& operator<<(std::ostream& os, Noble& noble);
}


#endif //HOW06_2020_NOBLE_H
