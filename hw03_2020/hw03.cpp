//Saimanasa Juluru
//CS2124
//Section A
//18 February 2020
/*This is a modification of the previous Warriors simulation. Instead of having a struct
 * with only the Warriors name and strength, we now have a weapon name.*/

#include <iostream>
#include <string>
#include <vector>
#include <fstream>
using namespace std;
class Warrior {
private:
    class Weapon {
    private:
        string name;
        int strength;
    public:
        Weapon(const string& weaponName, int weaponStrength) : name(weaponName), strength(weaponStrength) {}
        friend ostream& operator << (ostream& os, const Weapon& weapon) {
            os << "weapon: " << weapon.name <<", " << weapon.strength;
            return os;
        }
        void setStrength(int newStrength) { strength = newStrength; }
        const int getStrength() const { return strength; }
    };
    string name;
    Weapon weapon;

public:
    //name of warrior and name of weapon are not going to chance, hence the 'const'
    //passed by reference to ensure no copies are being made
    Warrior(const string& warriorName, const string& weaponName, int strength) : name(warriorName), weapon(weaponName, strength){}
    //output operator
    friend ostream& operator << (ostream& os, const Warrior& warrior) {
        os << "Warrior: " << warrior.name << ", " << warrior.weapon << endl;
        return os;
    }
    //returns the name of the warrior
    const string getName() const { return name;}

    void battle(Warrior& opponent) {
        cout << name << " battles " << opponent.name << endl;
        if (weapon.getStrength() != 0 && opponent.weapon.getStrength() == 0) {
            cout << "He's Dead, " << name << endl;

        } else if (opponent.weapon.getStrength() != 0 && weapon.getStrength() == 0) {
            cout << "He's Dead, " << opponent.getName() << endl;

        } else if (weapon.getStrength() > opponent.weapon.getStrength()) {
            int newStrength = weapon.getStrength() - opponent.weapon.getStrength();
            weapon.setStrength(newStrength);
            opponent.weapon.setStrength(0);

            cout << name << " defeats " << opponent.name << endl;

        } else if (opponent.weapon.getStrength() > weapon.getStrength()) {
            int newStrength = opponent.weapon.getStrength() - weapon.getStrength();
            opponent.weapon.setStrength(newStrength);
            weapon.setStrength(0);
            cout << opponent.name << " defeats " << name << endl;

        } else {
            if (weapon.getStrength() == 0 && opponent.weapon.getStrength() == 0) {
                cout << "Oh, NO! They're both dead! Yuck!" << endl;
            } else {
                weapon.setStrength(0);
                opponent.weapon.setStrength(0);
                cout << "Mutual Annihilation: " << name << " and " << opponent.name
                     << " die at each other's hands" << endl;
            }
        }
    }

};
void displayStatus(const vector<Warrior>& warriors);//displays the warriors' current stats
int findWarrior(const vector<Warrior>& warriors, string name);//finds the index of a warrior if it exists
void start_program(ifstream& input);//runs program

int main() {
    ifstream input("battle.txt");
    start_program(input);
    input.close();
}

void start_program(ifstream& input) {
    string token;
    vector<Warrior> warriors;
    //check if file exists
    if (!input) {
        cerr << "failed to open file";
        exit(1);
    }
    while (input >> token) {
        if (token == "Warrior") { //create new Warrior
            string name;
            string weaponName;
            int strength;
            input >> name;
            input >> weaponName;
            input >> strength;
            warriors.emplace_back(name, weaponName, strength);
        }
        else if (token == "Battle") { //battle two warriors and update stats
            string warrior_1, warrior_2;
            input >> warrior_1;
            input >> warrior_2;
            size_t index1 = findWarrior(warriors, warrior_1);
            size_t index2 = findWarrior(warriors, warrior_2);
            if (index1 != warriors.size() && index2 != warriors.size()) {
                warriors[index1].battle(warriors[index2]);
            } else {
                cout << "Warrior does not exist\n";
            }

        } else {//display stats
            displayStatus(warriors);
        }
    }
}


int findWarrior(const vector<Warrior>& warriors, string name) {
    //check if warrior exists in warriors vector
    for (size_t i = 0; i < warriors.size(); i++) {
        if (warriors[i].getName() == name) {
            return i;
        }
    }
    //return size if warrior not found
    return warriors.size();
}

void displayStatus(const vector<Warrior>& warriors) {
    cout << "There are: " << warriors.size() << " warriors" << endl;
    //for each warrior print Name and Strength
    for (const Warrior& warrior : warriors) {
        cout << warrior;
    }
}


