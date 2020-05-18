//
// Created by Saimanasa Juluru on 4/15/20.
//

#ifndef HW7_2020_NOBLE_H
#define HW7_2020_NOBLE_H


#include <string>
#include <vector>
#include <iostream>


namespace WarriorCraft{
    class Protector;
    class Noble {
    public:
        Noble(const std::string &nobleName, float strength);

        std::string getName() const;
        virtual void loseStrength(float strength) = 0;
        virtual void battle(Noble& enemy);
        virtual void battleCry() = 0;

    protected:
        std::string nobleName;
        float strengthStat;
        bool isDead;

    };

    class PersonWithStrengthToFight : public Noble {
    public:
        PersonWithStrengthToFight(const std::string name, const float strength);

        virtual void loseStrength(float strength);
        void battleCry();
    };

    class Lord : public Noble {
    public:
        Lord(const std::string& name);

        void hires(Protector& soldier);
        virtual void loseStrength(float strength);
        void battleCry();

    private:
        std::vector<Protector*> army;
    };
}

#endif //HW7_2020_NOBLE_H
