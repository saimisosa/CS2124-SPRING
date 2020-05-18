//Saimanasa Juluru
//CS-2124
//Section C
//29 January 2020

#include <iostream>
#include <string>
#include <fstream>
#include <vector>
using namespace std;

char rotatedChar(char& letter, int key);
void decryptString(string& sample, int key);

int main() {
    int key;
    ifstream cipher;
    vector<string> fileContent;
    string line;

    cipher.open("encrypted.txt");

    if (!cipher) {
        cerr << "Could not open the file.\n";
        exit(1);
    }

    cipher >> key; // obtains key and stores it in int key variable

    while(getline(cipher, line)){ // reads each line in file
        if (line.size()>0){
            fileContent.push_back(line); // pushes it into empty vector called fileContent
        }
    }

    for (string& sentence : fileContent) { // for each line in fileContent
        decryptString(sentence, key); // decrypt it
    }

    for (int vecLength = fileContent.size(); vecLength > 0; --vecLength){ // traverse vector backwards
        cout << fileContent[vecLength-1] << endl; // prints out each line separately, including last index
    }

    cipher.close();

}

char rotatedChar(char& letter, int key) {
    if(letter >= 'a' && letter <= 'z'){
        letter = letter - key; // left and/or backwards rotation
        if(letter < 'a'){
            letter = letter + 'z' - 'a' + 1; // case for when the letter is at the beginning
        }
        else if(letter > 'z'){
            letter = letter - (26- (key-2)); // case for when the char is at the end
        }
    }
    else if(letter >= 'A' && letter <= 'Z'){ // ignores uppercase letters
        return letter;
    }
    else if(letter >= '!' && letter <= '~'){ // ignores punctuation
        return letter;
    }
    return letter;
}

void decryptString(string& sample, int key) {
    for (size_t i = 0; i < sample.size(); ++i){ /*for every character in string*/
        rotatedChar(sample[i], key); /*implement rotatedChar*/
    }
}