// Saimanasa Juluru
// CS2124
// Section C
// 12 February 2020
/*This code reads in a file, warriors.txt, and executes the commands
 * detailed in each line. It reads in the warriors, has them battle,
 * and displays their ending stats. */

#include <iostream>
#include <string>
#include <vector>
#include <fstream>
using namespace std;

struct Warrior {
    string warriorName;
    int weaponStrength;
};

void battle(Warrior& warrior_1, Warrior& warrior_2); //starts battle between two warriors
void displayStatus(const vector<Warrior>& warriors); //displays warriors' current stats
int findWarrior(const vector<Warrior>& warriors, const string& name); //finds the index of a warrior if it exists
void runProgram(ifstream& input); //runs program

int main() {
    ifstream input("warriors.txt");
    runProgram(input);
    input.close();
}

void runProgram(ifstream& input) {
    string token;
    vector<Warrior> warriors;
    if (!input) {
        cerr << "failed to open file";
        exit(1);
    }
    while (input >> token) {
        if (token == "Warrior") { //create new Warrior
            string name;
            int strength;
            input >> name;
            input >> strength;

            Warrior person; //creates new warrior object
            person.warriorName = name; //manually sets name
            person.weaponStrength = strength; //manually sets strength
            warriors.emplace_back(person); //pushes this struct into the vector
        } else if (token == "Battle") { //battle two warriors and update stats
            string warriorOne, warriorTwo;
            input >> warriorOne;
            input >> warriorTwo;
            battle(warriors[findWarrior(warriors, warriorOne)],
                   warriors[findWarrior(warriors, warriorTwo)]);
        } else { //display stats
            displayStatus(warriors);
        }
    }
}


int findWarrior(const vector<Warrior>& warriors, const string& name) {
    //check if warrior exists in the vector
    for (size_t i = 0; i < warriors.size(); i++) {
        if (warriors[i].warriorName == name) {
            return i;
        }
    }
    //return size if warrior not found
    return warriors.size();
}

void displayStatus(const vector<Warrior>& warriors) {
    cout << "There are " << warriors.size() << " warriors." << endl;
    //for each warrior, print Name and Strength
    for (const Warrior& warrior : warriors) {
        cout << "Warrior: " << warrior.warriorName << ", " << "Strength: " << warrior.weaponStrength << endl;
    }

}

void battle(Warrior& warriorOne, Warrior& warriorTwo) {
    cout << warriorOne.warriorName << " battles " << warriorTwo.warriorName << endl;
    if (warriorOne.weaponStrength != 0 && warriorTwo.weaponStrength == 0) {
        cout << "He's dead, " << warriorOne.warriorName << endl;
    } else if (warriorTwo.weaponStrength != 0 && warriorOne.weaponStrength == 0) {
        cout << "He's dead, " << warriorOne.warriorName << endl;

    } else if (warriorOne.weaponStrength > warriorTwo.weaponStrength) { //if 1st warrior wins subtract strength from him
        int newStrength = warriorOne.weaponStrength - warriorTwo.weaponStrength;
        warriorOne.weaponStrength = newStrength;
        warriorTwo.weaponStrength = 0;
        cout << warriorOne.warriorName << " defeats " << warriorTwo.warriorName << endl;

    } else if (warriorTwo.weaponStrength > warriorOne.weaponStrength) {  //if warrior 2 wins subtract strength from him
        int newStrength = warriorTwo.weaponStrength - warriorOne.weaponStrength;
        warriorTwo.weaponStrength = newStrength;
        warriorOne.weaponStrength = 0;
        cout << warriorTwo.warriorName << " defeats " << warriorOne.warriorName << endl;

    } else { // if they have the same strength
        if (warriorOne.weaponStrength == 0 && warriorTwo.weaponStrength == 0) { //both already 0 strength
            cout << "Oh, NO! They're both dead! Yuck!" << endl;
        } else { // same but not 0 strength
            warriorOne.weaponStrength = 0;
            warriorTwo.weaponStrength = 0;
            cout << "Mutual Annihilation: " << warriorOne.warriorName << " and "
            << warriorTwo.warriorName << " die at each other's hands." << endl;
        }
    }
}
