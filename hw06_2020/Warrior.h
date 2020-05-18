//
// Created by Saimanasa Juluru on 3/30/20.
//

#ifndef HOW06_2020_WARRIOR_H
#define HOW06_2020_WARRIOR_H


#include <string>
#include <iostream>
namespace WarriorCraft
{
    class Noble;
    class Warrior {
    public:
        Warrior(const std::string& warriorName, double power2);

        const std::string getName() const;
        const double getStrength() const;

        void setStrength(float ratio);
        void displayWarrior() const;
        void setEmployer(Noble*& n);
        void runaway();

    private:
        std::string name;
        double power;
        Noble* boss;

    };
}


#endif //HOW06_2020_WARRIOR_H
