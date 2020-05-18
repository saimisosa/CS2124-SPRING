//
// Created by Saimanasa Juluru on 4/15/20.
//

#include "Protector.h"
#include "Noble.h"

namespace WarriorCraft{
    Protector::Protector(const std::string name, float strength) : protectorName(name), protectorStrength(strength), nobleBoss(nullptr) {}
    Noble* Protector::getNobleBoss() const { return nobleBoss; }
    void Protector::setStrength(float strength) { protectorStrength = strength; }
    float Protector::getStrength() const { return protectorStrength; }
    void Protector::setNobleBoss(Noble* boss) { nobleBoss = boss; }

    Wizard::Wizard(const std::string name, float strength) : Protector(name, strength) {}
    void Wizard::battlecry()  const { std::cout << "POOF!\n"; }

    Warrior::Warrior(const std::string name, float strength) : Protector(name, strength) {}

    Archer::Archer(const std::string name, float strength) : Warrior(name, strength) {}
    void Archer::battlecry() const {
        std::cout << "TWANG! " << protectorName << " says: Take that in the name of my lord, " << nobleBoss->getName() << std::endl;
    }

    Swordsman::Swordsman(const std::string name, float strength) : Warrior(name, strength) {}
    void Swordsman::battlecry() const {
        std::cout << "CLANG! " << protectorName << " says: Take that in the name of my lord, " << nobleBoss->getName() << std::endl;
    }
}
