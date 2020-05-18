//
// Created by Saimanasa Juluru on 4/15/20.
//

#include "Protector.h"
#include "Noble.h"

namespace WarriorCraft{
    Noble::Noble(const std::string &name, float strength = 0) : nobleName(name), strengthStat(strength), isDead(false) {}
    std::string Noble::getName() const { return nobleName; }
    void Noble::battle(Noble& enemy) {
        std::cout << nobleName << " battles " << enemy.nobleName << std::endl;
        battleCry();
        enemy.battleCry();
        float nobleStrength = strengthStat;
        float enemyStrength = enemy.strengthStat;
        if (strengthStat == enemy.strengthStat) {
            //if they're both already dead
            if (isDead && enemy.isDead) {
                std::cout << "Oh, NO! They're both dead! Yuck!\n";
            }
                //else if they have the same strength - mutal destruction
            else {
                this->loseStrength(enemyStrength);
                enemy.loseStrength(nobleStrength);
                isDead = true;
                enemy.isDead = true;
                std::cout << "Mutual Anniilation: " << nobleName << " and " << enemy.nobleName << " die at each other's hands\n";
            }
        }
        else if (strengthStat > enemy.strengthStat) { //if noble wins against enemy
            battleCry();
            enemy.battleCry();
            //check if enemy is already dead
            if (enemy.isDead) {
                std::cout << "He's dead, " << nobleName << std::endl;
            }
            else {
                battleCry();
                enemy.battleCry();
                this->loseStrength(enemyStrength);
                enemy.loseStrength(nobleStrength);
                enemy.isDead = true;
                std::cout << nobleName << " defeats " << enemy.nobleName << std::endl;
            }
        }
        else if (enemy.strengthStat > strengthStat) { //enemy wins against noble
            if (isDead) { //noble already dead
                enemy.battleCry();
                std::cout << "He's dead, " << enemy.nobleName << std::endl;
            }
            else {
                this->loseStrength(enemyStrength);
                enemy.loseStrength(nobleStrength);
                isDead = true;
                std::cout << enemy.nobleName << " defeats " << nobleName << std::endl;
                battleCry();
                enemy.battleCry();
            }
        }
    }
    PersonWithStrengthToFight::PersonWithStrengthToFight(const std::string name, float strength) : Noble(name, strength) {}
    void PersonWithStrengthToFight::loseStrength(float strength) {
        strengthStat -= strength;
        if (strengthStat < 0) { strengthStat = 0; }
    }

    Lord::Lord(const std::string& name) : Noble(name) {}
    void Lord::hires(Protector& soldier) {
        //if noble isn't dead yet and protector isn't hired yet
        if (!isDead && soldier.getNobleBoss() == nullptr) {
            army.push_back(&soldier); //add soldier to army
            strengthStat += soldier.getStrength(); //update strength of army
            soldier.setNobleBoss(this); //soldier's boss is now noble
        }
    }
    void Lord::battleCry(){
        for (Protector* ppl: army){
            ppl->battlecry();
        }
    }
    void PersonWithStrengthToFight::battleCry(){
        std::cout << "UGH!" <<std::endl;
    }
    void Lord::loseStrength(float strength) {
        if (strength == strengthStat) { //mutual annihilation
            for (size_t i = 0; i < army.size(); ++i) {
                army[i]->setStrength(0);
                army[i] = nullptr;
            }
            strengthStat = 0;
        }
        else if (strengthStat > strength) { //noble wins against enemy
            float damage = strength / strengthStat;
            strengthStat = 0; //recalculate new army strength
            for (size_t i = 0; i < army.size(); ++i) {
                float newStrength = army[i]->getStrength() * (1-damage); //calculating new strength of warrior
                army[i]->setStrength(newStrength);
                //adding new strength;
                strengthStat += army[i]->getStrength();
            }
        }
        else if (strength > strengthStat) { //enemy wins against noble
            for (size_t i = 0; i < army.size(); ++i) {
                army[i]->setStrength(0);
                army[i] = nullptr;
            }
            strengthStat = 0;
        }
    }
};