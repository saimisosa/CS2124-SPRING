// Saimanasa Juluru
// CS2124
// Section C
// 24 Feb. 2020
// HW4: In which Nobles hire/fire warriors as part of their army and duel. 
#include <iostream>
#include <vector>
#include <string>
using namespace std;


class Warrior {
private:
    bool isHired = false;
    double strength = 0;
    string name;
public:
    Warrior(string warriorName, double strength) : name(warriorName), strength(strength){}
    friend ostream& operator << (ostream& os, const Warrior& warrior){
        os << "Warrior: " << warrior.name << " Strength: " << warrior.strength << endl;
        return os;
    }

    const double getStrength() const { return strength; }
    const string getName () const { return name; }
    const void displayWarrior() const { cout << name << " : " << strength << endl; }
    const bool getHireStatus() const { return isHired; }

    void setStrength(double ratio) {
        if (ratio == 0) { strength = 0; }
        else { strength -= (ratio * strength); }
    }
    void setHire(bool statusUpdate) { isHired = statusUpdate; }
};
class Noble {

private:
    bool isAlive = true;
    string name;
    vector <Warrior*> army; // vector of Warrior pointers named "army"
    double totalStrength = 0; // total strength of the army, also no negative values allowed

public:
    Noble(string nobleName): name(nobleName), totalStrength(0){}

    friend ostream& operator << (ostream& os, const Noble& noble) { // ostream operator for noble
        os << noble.name << " has an army of " << noble.army.size() << endl;
        for (const Warrior* warrior : noble.army){
            warrior->displayWarrior();
        }
        return os;
    }
    // hire function
    bool hire(Warrior& warriorName){
        if (warriorName.getHireStatus()) {
            cout << "This warrior is already hired!" << endl;
            return false;
        }
        else if (!isAlive) {
            cout << "The noble you're trying to get to hire people is dead, dude." << endl;
            return false;
        }
        warriorName.setHire(true);
        army.push_back(&warriorName); // pushes the address of the warrior onto vector
        totalStrength += warriorName.getStrength(); // adds the strength of each warrior to the total strength
        return true;

    }
    // battle function
    void battle(Noble& nobleName){

        cout << name << " battles " << nobleName.name <<endl;

        // condition for when noble 1's army is stronger than noble 2's
        if (totalStrength > nobleName.totalStrength){
            // if noble 2 is already dead
            if (nobleName.totalStrength == 0){
                cout << "He's dead, " << name << endl;
               nobleName.isAlive = false;
            }
                /* normal condition, aka when one defeats the other
                * in the case where neither are initially dead or equally matched*/
            else {
                cout << name << " defeats " << nobleName.name << endl;

                double ratio = nobleName.totalStrength / totalStrength; // ratio to recalculate army strength
                totalStrength = 0;
                nobleName.totalStrength = 0;
                nobleName.isAlive = false;

                for (Warrior* warrior : nobleName.army){ // loops through army vector
                    warrior->setStrength(0); // sets strength with ratio 0
                }
                for (Warrior* warrior : army){
                    warrior->setStrength(ratio); // sets strength with ratio calculated above
                    totalStrength += warrior->getStrength(); // recalculates total strength

                }
            }
        }
            // condition for if noble 2's army strength is greater than noble 1's
        else if (totalStrength < nobleName.totalStrength){

            // condition for if one is already dead
            if (totalStrength == 0){
                cout << "He's dead " << nobleName.name << endl;
                isAlive = false;
            }
                /* normal condition, aka when one defeats the other
                 * in the case where neither are initially dead or equally matched*/
            else {
                cout << nobleName.name << " defeats " << name << endl;

                double ratio =  nobleName.totalStrength / totalStrength; // ratio to recalculate army strength

                totalStrength = 0;
                nobleName.totalStrength = 0;
                isAlive = false;

                for (Warrior* warrior : army){ // loops through army vector
                    warrior->setStrength(0); // sets the strength with ratio 0
                }
                for (Warrior* warrior : nobleName.army){
                    warrior->setStrength(ratio); // sets strength with ratio calculated above
                    totalStrength += warrior->getStrength(); // recalculates the total strength
                }
            }
        }
            // condition for when they're both already dead
        else if (totalStrength == 0 && nobleName.totalStrength == 0){
            cout << "Oh no they're both dead! yuck!" << endl;
            isAlive = false;
            nobleName.isAlive = false;
        }
            // condition for when both have equal strength
        else if (totalStrength == nobleName.totalStrength){
            cout << "Mutual annihilation: " << name << " and " << nobleName.name << " die at each other's hands" << endl;

            totalStrength = 0; // sets first noble's total strength to 0
            nobleName.totalStrength = 0; // set's second noble's total strength to 0
            isAlive = false;
            nobleName.isAlive = false;

            for (Warrior* warrior : army) {
                warrior->setStrength(0); // sets noble 1's army to strength 0
            }
            for (Warrior* warrior : nobleName.army) {
                warrior->setStrength(0); // sets noble 2's army to strength 0
            }
        }
    }

    // firing function
    bool fire(Warrior& warrior) {
        if (!isAlive) {
            return false;
        }
        cout << "You don't work for me anymore " << warrior.getName() << "! -- " << name << "." << endl;
        totalStrength = 0;

        for (size_t i=0; i< army.size(); ++i){ // loops through array of Warrior pointers
            if (&warrior== army[i]){ // if the address of Warrior to be fired is found
                army[i]=army[army.size()-1]; // resize vector
                army.pop_back(); // remove Warrior
                warrior.setHire(false);
            }
        }
        for (size_t i = 0; i < army.size(); ++i){ // loops through army vector
            totalStrength += army[i]->getStrength(); // recalculates total army strength after firing
        }
        return true;
    }
};
int main() {
    Noble art("King Arthur");
    Noble lance("Lancelot du Lac");
    Noble jim("Jim");
    Noble linus("Linus Torvalds");
    Noble billie("Bill Gates");

    Warrior cheetah("Tarzan", 10);
    Warrior wizard("Merlin", 15);
    Warrior theGovernator("Conan", 12);
    Warrior nimoy("Spock", 15);
    Warrior lawless("Xena", 20);
    Warrior mrGreen("Hulk", 8);
    Warrior dylan("Hercules", 3);

    jim.hire(nimoy);
    lance.hire(theGovernator);
    art.hire(wizard);
    lance.hire(dylan);
    linus.hire(lawless);
    billie.hire(mrGreen);
    art.hire(cheetah);

    cout << "==========\n"
         << "Status before all battles, etc.\n";
    cout << jim << endl;
    cout << lance << endl;
    cout << art << endl;
    cout << linus << endl;
    cout << billie << endl;
    cout << "==========\n";

    art.fire(cheetah);
    cout << art << endl;

    art.battle(lance);
    jim.battle(lance);
    linus.battle(billie);
    billie.battle(lance);

    cout << "==========\n"
         << "Status after all battles, etc.\n";
    cout << jim << endl;
    cout << lance << endl;
    cout << art << endl;
    cout << linus << endl;
    cout << billie << endl;
    cout << "==========\n";
}
