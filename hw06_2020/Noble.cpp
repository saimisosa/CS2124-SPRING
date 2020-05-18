//
// Created by Saimanasa Juluru on 3/30/20.
//

#include "Noble.h"
#include "Warrior.h"
#include <iostream>
#include <string>
#include <vector>

using namespace std;

namespace WarriorCraft
{
    Noble::Noble(const string& name) : name(name) {}

    string Noble::getName() const { return name; }

    vector<Warrior*> Noble::getWarriors() const { return army; }

    bool Noble::aliveNow() { return isAlive; }
    void Noble::hire(Warrior& combatant)
    {
        army.push_back(&combatant);
        Noble* boss = this;
        combatant.setEmployer(boss);
    }

    void Noble::fire(Warrior& combatant)
    {
        int warriorIdx = 0;
        for (size_t i = 0; i < army.size(); i++)
        {
            if (combatant.getName() == army[i]->getName())
            {
                warriorIdx = i;
            }
        }

        if (warriorIdx >= 0)
        {
            cout << combatant.getName() << ", you're fired! -- " << name << endl;
            army[warriorIdx] = army[army.size() - 1];
            army.pop_back(); //remove warrior
        }
    }


    void Noble::setAlive(bool thing) { isAlive = thing; }

    void Noble::battle(Noble& otherNoble)
    {
        cout << name << " battles " << otherNoble.getName() << endl;

        if (isAlive == true && otherNoble.aliveNow() == true)
        {
            double totalStrOfThisNoble = 0;
            double totalStrOfOtherNoble = 0;
            double ratio;

            for (size_t i = 0; i < army.size(); i++)
            {
                totalStrOfThisNoble += army[i]->getStrength(); //find sum of str of warriors for first noble
            }

            for (size_t i = 0; i < otherNoble.getWarriors().size(); i++)
            {
                totalStrOfOtherNoble += otherNoble.getWarriors()[i]->getStrength(); //find sum of str of warriors for other noble
            }

            if (totalStrOfThisNoble > totalStrOfOtherNoble)
            {
                ratio = totalStrOfOtherNoble / totalStrOfThisNoble;
                for (size_t i = 0; i < army.size(); i++)
                {
                    army[i]->setStrength((army[i]->getStrength() - (army[i]->getStrength() * ratio))); //this noble's soldiers lose a portion of their strength
                }
                for (size_t i = 0; i < otherNoble.getWarriors().size(); i++)
                {
                    otherNoble.getWarriors()[i]->setStrength(0); // all warriors for other noble has 0 str now
                }

                otherNoble.setAlive(false);
                cout << name << " defeats " << otherNoble.getName() << endl;
            }
            else if (totalStrOfOtherNoble > totalStrOfThisNoble)
            {
                ratio = totalStrOfThisNoble / totalStrOfOtherNoble;
                for (size_t i = 0; i < otherNoble.getWarriors().size(); i++)
                {
                    otherNoble.getWarriors()[i]->setStrength((otherNoble.getWarriors()[i]->getStrength() - (otherNoble.getWarriors()[i]->getStrength() * ratio))); //other noble's soldiers lose a portion of their strength
                }

                for (size_t i = 0; i < army.size(); i++)
                {
                    army[i]->setStrength(0); // all warriors for this noble has 0 str now
                }

                isAlive = false;
                cout << otherNoble.getName() << " defeats " << name << endl;
            }
            else if (totalStrOfThisNoble == totalStrOfOtherNoble)
            {
                for (size_t i = 0; i < army.size(); i++)
                {
                    army[i]->setStrength(0);
                }

                for (size_t i = 0; i < otherNoble.getWarriors().size(); i++)
                {
                    otherNoble.getWarriors()[i]->setStrength(0);
                }
                otherNoble.setAlive(false);
                isAlive = false;
                cout << "Mutual Annihilation: " << name << " and " << otherNoble.getName() << " die at each other's hands" << endl;
            }

        }
        else if (isAlive == false && otherNoble.aliveNow() == false)
        {
            cout << "Oh, NO! They're both dead! Yuck!" << endl;
        }
        else if (isAlive == false && otherNoble.aliveNow() == true)
        {
            cout << "He's dead " << otherNoble.getName() << endl;
        }
        else if (isAlive == true && otherNoble.aliveNow() == false)
        {
            cout << "He's dead " << name << endl;
        }
    }

//
    void Noble::removeWarrior(string runaway)
    {
        for (size_t i = 0; i < army.size(); i++)
        {
            if (army[i]->getName() == runaway)
            {
                army[i] = army[army.size() - 1];
                army.pop_back(); //remove warrior
            }
        }

    }

    ostream& operator<<(ostream& os, Noble& noble)
    {
        cout << noble.getName() << " has an army of " << noble.getWarriors().size() << endl;
        for (size_t i = 0; i < noble.getWarriors().size(); i++)
        {
            cout << "	";
            noble.getWarriors()[i]->displayWarrior();
        }
        return os;
    }
}
