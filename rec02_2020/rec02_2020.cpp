// Saimanasa Juluru
// CS2124
// Section C
// 7 February 2020
/* Recitation 2: Reading in a file of hydrocarbons and sorting them.
 * The following program reads in a file of chemicals by their name
 * and chemical compound and outputs them in increasing order of Carbons
 * and Hydrogens, as well as grouping their various chemical names with each other. */

#include <iostream>
#include <vector>
#include <fstream>
#include <string>
using namespace std;

struct chemInfo {
    vector<string> chemNames;
    int numofCarbon;
    int numofHydrogen;
};
// function prototypes
void openFile(ifstream& inputFile);
void fillVector(ifstream& file, vector<chemInfo>& theFormulas);
void addFormula(string& name, int numC, int numH, vector<chemInfo>& theFormulas);
size_t dupFormula(int numC, int numH, const vector<chemInfo>& theFormulas);
void sortFormulas(vector<chemInfo>& hydroCarbons);
void displayContents(const vector<chemInfo>& hydrocarbonList);

int main() {
    ifstream chemicalFile;
    openFile(chemicalFile);

    vector<chemInfo> fullHydroCarbons;

    fillVector(chemicalFile, fullHydroCarbons);
    chemicalFile.close();

    sortFormulas(fullHydroCarbons);
    displayContents(fullHydroCarbons);

    return 0;
}
// opens the file with the input stream passed in
// takes in the file name as well so that it can overwrite it in the function
void openFile(ifstream& inputFile) {
    string fileName;
    cout << "Enter a valid filename: " << endl;
    cin >> fileName;
    inputFile.open(fileName);

    while (!inputFile) {
        inputFile.clear();
        cout << "Could not open the file. Please enter a new name. ";
        cin >> fileName;
        inputFile.open(fileName);
    }
}
// reads in the various elements within the file in order in which they appear
// calls the addformula function so that it can verify the location of the compounds and names
void fillVector(ifstream& inputFile, vector<chemInfo>& theFormulas) {
    string names;
    char carbon, hydrogen;
    int numC, numH;

    while (inputFile >> names >> carbon >> numC >> hydrogen >> numH) {
        addFormula(names, numC, numH, theFormulas);
    }
}

// pushes the name of the compound, as well as the compound itself, into their respective vectors
void addFormula(string& name, int numC, int numH, vector<chemInfo>& theFormulas) {
    size_t location;
    location = dupFormula(numC, numH, theFormulas);
    chemInfo newHydrocarbon; // empty hydrocarbon to push into vector

    if (location == theFormulas.size()) { // if there are no duplicates, push back name and compound
        newHydrocarbon.chemNames.push_back(name);
        newHydrocarbon.numofCarbon = numC;
        newHydrocarbon.numofHydrogen = numH;
        theFormulas.push_back(newHydrocarbon);
    } else { // if there are duplicates, only push back the name
        theFormulas[location].chemNames.push_back(name);
    }
}

// a helper function to determine if there are any duplicates within the vector of compounds
// returns the size of the vector if it doesnt exist
// else, it returns the index
size_t dupFormula(int numC, int numH, const vector<chemInfo>& theFormulas) {
    for (size_t elem = 0; elem < theFormulas.size(); ++elem) {
        if (theFormulas[elem].numofCarbon == numC && theFormulas[elem].numofHydrogen == numH) {
            return elem;
        }
    }
    return theFormulas.size();
}

// bubble sort to organize the chemical compounds based on increasing number of carbons
// the number of Hs will also be organized in increasing order if the Cs are also increasing
void sortFormulas(vector<chemInfo>& hydrocarbons) {
    for (size_t size = 0; size < hydrocarbons.size(); ++size) {
        for (size_t rest = 0; rest < hydrocarbons.size() - 1; ++rest) {
            // if the first hydrocarbon has more Cs than the second....
            if (hydrocarbons[rest].numofCarbon > hydrocarbons[rest + 1].numofCarbon) {
                swap(hydrocarbons[rest], hydrocarbons[rest + 1]);
            // if the Cs are equal and the Hs in the first are greater than the second....
            } else if (hydrocarbons[rest].numofCarbon == hydrocarbons[rest + 1].numofCarbon &&
                     hydrocarbons[rest].numofHydrogen > hydrocarbons[rest + 1].numofHydrogen) {
                swap(hydrocarbons[rest], hydrocarbons[rest + 1]);
            }
        }
    }
}
// function to display the contents of the vector
void displayContents(const vector<chemInfo>& hydrocarbonList) {
    // ranged for to display all the contents of the vector
    for (const chemInfo& element : hydrocarbonList) {
        cout << 'C' << element.numofCarbon <<
             'H' << element.numofHydrogen << ' ';
        // ranged for to print out the names of the contents (if more than one)
        for (const string& chemName : element.chemNames) {
            cout << chemName << ' ';
        }
        cout << endl;
    }
}