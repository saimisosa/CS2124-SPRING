//
// Created by Saimanasa Juluru on 4/15/20.
//

#ifndef HW7_2020_PROTECTOR_H
#define HW7_2020_PROTECTOR_H


#include <string>
#include <vector>
#include <iostream>

namespace WarriorCraft{
    class Noble;
    class Protector {
    public:
        Protector(const std::string name, float strength);
        Noble* getNobleBoss() const;
        virtual void setStrength(float strength);
        virtual void battlecry() const = 0;
        float getStrength() const;
        void setNobleBoss(Noble* boss);
    protected:
        std::string protectorName;
        float protectorStrength;
        Noble* nobleBoss;
    };

    class Wizard : public Protector {
    public:
        Wizard(const std::string name, float strength);
        void battlecry() const;
    };

    class Warrior : public Protector {
    public:
        Warrior(const std::string name, float strength);
        virtual void battlecry() const = 0;
    };

    class Archer : public Warrior {
    public:
        Archer(const std::string name, float strength);
        void battlecry() const;
    };

    class Swordsman : public Warrior {
    public:
        Swordsman(const std::string name, float strength);
        void battlecry() const;
    };
}

#endif //HW7_2020_PROTECTOR_H
