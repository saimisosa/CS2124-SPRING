//Saimanasa Juluru
//CS2124
//Section C
//2 March 2020
/*A modification of the previous Warriors & Nobles classes, we have now made is that we're reading into a file
 * of commands. There is a vector of Nobles pointers as well as a vector of Warriors pointers. Also, the warriors
 * need to know if they're hired / fired as well. */

#include <iostream>
#include <vector>
#include <string>
#include <fstream>
using namespace std;

class Warrior {
public:
    Warrior(const string& warriorName, double power2): name(warriorName), power(power2){}

    friend ostream& operator << (ostream& os, const Warrior& warrior) {
        os << warrior.name << " : " << warrior.power << endl;
        return os;
    }

    double getStrength() const { return power; } // returns power
    string getName() const { return name; } // returns name
    bool getJobStatus() const {return isHired;} // returns job status

    void setStrength(float ratio) { power = ratio; } // sets strength
    void displayWarrior() { cout << name << " : " << power <<endl; } // displays warrior : power
    void setJobStatus(bool hired) { isHired = hired; } // sets job status to hired or unhired


private:
    string name; // name of warior
    double power; // double makes sure there are no negative values being entered
    bool isHired = true; // by default, they are not hired
};

class Noble {

private:
    string name;
    vector <Warrior*> army; // vector of Warrior pointers named "army"
    double totalStrength; // total strength of the army, also no negative values allowed
    bool isAlive = true; // by default, noble is alive


public:
    Noble(const string& nobleName): name(nobleName), totalStrength(0){}

    friend ostream& operator << (ostream& os, const Noble& noble) {
        os << noble.name << " has an army of " << noble.army.size() << endl;
        for (Warrior* warrior : noble.army){
            warrior->displayWarrior();
        }
        return os;
    }

    string getName() const {return name;} // returns name
    vector<Warrior*> getWarriors() const { return army; } // returns army
    bool aliveNow() const { return isAlive; } // returns whether they're alive or dead

    void setAlive(bool thing) { isAlive = thing; } // changes the "alive" status


    // hire function
    void hire(Warrior& warriorName){
        if (warriorName.getJobStatus()){ // if the warrior is unhirired
            army.push_back(&warriorName); // pushes the address of the warrior onto vector
            totalStrength += warriorName.getStrength(); // adds the strength of each warrior to the total strength
            warriorName.setJobStatus(false); // sets hire status to false
        }
        else {
            cout << warriorName.getName() << " is already hired!" << endl; // if they're already hired, print this
        }

    }
    // battle function
    void battle(Noble& nobleName){

        cout << name << " battles " << nobleName.name <<endl;

        if (isAlive && nobleName.aliveNow()) {
            double totalStrOfThisNoble = 0;
            double totalStrOfOtherNoble = 0;
            double ratio;

            for (Warrior* warrior : army) {
                totalStrOfThisNoble += warrior->getStrength(); //find sum of str of warriors for first noble
            }

            for (size_t i = 0; i < nobleName.getWarriors().size(); i++) {
                totalStrOfOtherNoble += nobleName.getWarriors()[i]->getStrength(); //find sum of str of warriors for other noble
            }

            if (totalStrOfThisNoble > totalStrOfOtherNoble) {
                ratio = totalStrOfOtherNoble / totalStrOfThisNoble;
                for (size_t i = 0; i < army.size(); i++) {
                    army[i]->setStrength((army[i]->getStrength() - (army[i]->getStrength() * ratio))); //this noble's soldiers lose a portion of their strength
                }
                for (size_t i = 0; i < nobleName.getWarriors().size(); i++) {
                    nobleName.getWarriors()[i]->setStrength(0); // all warriors for other noble has 0 str now
                }

                nobleName.setAlive(false);
                cout << name << " defeats " << nobleName.getName() << endl;
            }
            else if (totalStrOfOtherNoble > totalStrOfThisNoble) {
                ratio = totalStrOfThisNoble / totalStrOfOtherNoble;
                for (size_t i = 0; i < nobleName.getWarriors().size(); i++) {
                    nobleName.getWarriors()[i]->setStrength((nobleName.getWarriors()[i]->getStrength() - (nobleName.getWarriors()[i]->getStrength() * ratio))); //other noble's soldiers lose a portion of their strength
                }

                for (size_t i = 0; i < army.size(); i++) {
                    army[i]->setStrength(0); // all warriors for this noble has 0 str now
                }

                isAlive = false;
                cout << nobleName.getName() << " defeats " << name << endl;
            }
            else if (totalStrOfThisNoble == totalStrOfOtherNoble) {
                for (size_t i = 0; i < army.size(); i++) {
                    army[i]->setStrength(0);
                }

                for (size_t i = 0; i < nobleName.getWarriors().size(); i++) {
                    nobleName.getWarriors()[i]->setStrength(0);
                }
                nobleName.setAlive(false);
                isAlive = false;
                cout << "Mutual Annihilation: " << name << " and " << nobleName.getName() << " die at each other's hands" << endl;
            }

        }
        else if (!isAlive && !nobleName.aliveNow()) {
            cout << "Oh, NO! They're both dead! Yuck!" << endl;
        }
        else if (!isAlive && nobleName.aliveNow()) {
            cout << "He's dead, " << nobleName.getName() << "." << endl;
        }
        else if (isAlive && !nobleName.aliveNow()) {
            cout << "He's dead " << name << endl;
        }
    }

    // firing function
    void fire(Warrior& warrior){
        cout << "You don't work for me anymore " << warrior.getName() << "! -- " << name << "." << endl;
        totalStrength = 0;

        for (size_t i=0; i< army.size(); ++i){ // loops through array of Warrior pointers
            if (&warrior== army[i]){ // if the address of Warrior to be fired is found
                army[i]=army[army.size()-1]; // resize vector
                army.pop_back(); // remove Warrior
                warrior.setJobStatus(true);
            }
        }
        for (size_t i = 0; i < army.size(); ++i){ // loops through army vector
            totalStrength += army[i]->getStrength(); // recalculates total army strength after firing
        }
    }
};


int main() {
    ifstream warriorstream("nobleWarriors.txt");
    if (!warriorstream) {
        cerr << "does not exist\n";
    }
    vector<Noble*> nobles;
    vector<Warrior*> warriors;
    string commandGiven;
    while (warriorstream >> commandGiven) {
        if (commandGiven == "Noble") {
            string name;
            bool isThere = false;

            warriorstream >> name;

            for (size_t i = 0; i < nobles.size(); i++) {
                if (name == nobles[i]->getName()) {
                    cout << "Noble Already Exists" << endl;
                    isThere = true;
                }
            }
            if (!isThere) {
                nobles.push_back(new Noble(name));
            }
        }
        else if (commandGiven == "Warrior") {
            string name;
            int str;
            bool isThere = false;

            warriorstream >> name >> str;

            for (size_t i = 0; i < warriors.size(); i++) {
                if (name == warriors[i]->getName()) {
                    cout << "Warrior Already Exists" << endl;
                    isThere = true;
                }
            }
            if (!isThere) {
                warriors.push_back(new Warrior(name, str));
            }
        }
        else if (commandGiven == "Hire") {
            string nobleName;
            string warriorName;
            bool nobleBorn = false;
            bool warriorBorn = false;
            int indexOfNoble;
            int indexOfWarrior;

            warriorstream >> nobleName >> warriorName;

            for (size_t i = 0; i < nobles.size(); i++) {
                if (nobleName == nobles[i]->getName()) {
                    indexOfNoble = i;
                    nobleBorn = true;
                }
            }
            if (!nobleBorn) {
                cout << "Noble Does Not Exist" << endl;
            }

            for (size_t i = 0; i < warriors.size(); i++) {
                if (warriorName == warriors[i]->getName()) {
                    indexOfWarrior = i;
                    warriorBorn = true;
                }
            }
            if (!warriorBorn) {
                cout << "Warrior Does Not Exist" << endl;
            }
            if (nobleBorn && warriorBorn) {
                nobles[indexOfNoble]->hire(*warriors[indexOfWarrior]);
            }
        }
        else if (commandGiven == "Status") {
            cout << "Status" << endl << "======="<<endl << "Nobles: " <<endl;
            for (Noble* n : nobles) {
                cout << *n << endl;
            }

            if (nobles.size() == 0) {
                cout << "NONE" << endl;
            }

            cout << "Unemployed Warriors:" << endl;
            for (size_t i = 0; i < warriors.size(); i++) {
                if (warriors[i]->getJobStatus()) {
                    cout << *warriors[i] << endl;
                }
            }
            if (warriors.size() == 0) {
                cout << "NONE" << endl;
            }
        }
        else if (commandGiven == "Fire") {
            string nobleName;
            string warriorName;
            int indexOfNoble = 0;
            int indexOfWarrior = 0;

            warriorstream >> nobleName >> warriorName;

            for (size_t i = 0; i < nobles.size(); i++) {
                if (nobleName == nobles[i]->getName()) {
                    indexOfNoble = i;
                }
            }
            for (size_t i = 0; i < warriors.size(); i++) {
                if (warriorName == warriors[i]->getName()) {
                    indexOfWarrior = i;
                }
            }
            nobles[indexOfNoble]->fire(*warriors[indexOfWarrior]);
        }
        else if (commandGiven == "Battle") {
            string nobleOne;
            string otherNoble;
            int indexOfOne = 0;
            int indexOfOther = 0;

            warriorstream >> nobleOne >> otherNoble;

            for (size_t i = 0; i < nobles.size(); i++) {
                if (nobleOne == nobles[i]->getName()) {
                    indexOfOne = i;
                }
            }
            for (size_t i = 0; i < nobles.size(); i++) {
                if (otherNoble == nobles[i]->getName()) {
                    indexOfOther = i;
                }
            }
            nobles[indexOfOne]->battle(*nobles[indexOfOther]);
        }
        else if (commandGiven == "Clear") {
            for (size_t i = 0; i < nobles.size(); i++){
                delete nobles[i];
            }
            for (size_t i = 0; i < nobles.size(); i++) {
                delete warriors[i];
            }
            nobles.clear();
            warriors.clear();
        }
    }
}
