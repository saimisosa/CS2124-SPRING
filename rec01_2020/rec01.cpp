#include <iostream>
#include <fstream>
#include <vector>
using namespace std;

// Saimanasa Juluru
// Lab 1
// CS2124
// Section GLab

// question 13
void displayVector(const vector<int>& someVec) {
    for (int someInts : someVec) {
        cout << someInts << " ";
    }
    cout << endl;
}
// question 14
void doubleVector1(vector<int>& otherVec) {
    for (size_t i = 0; i < otherVec.size(); ++i) {
        otherVec[i] *= 2;
    }
}
// question 15
void doubleVector2(vector<int>& otherVec) {
    for (int& element : otherVec) {
        element *= 2;
    }
}

int main() {
    // question 1
    // main returns an integer, but in this case, it doesnt need to do anything
    // only include <iostream> is needed
    // as we're using the cout and endl methods
    std::cout << "Hello, World!" << std::endl;

    // question 2
    cout << "Hello, World!" << endl;

    // question 3
    int x;
    cout << x << endl;
    // this is a problem because x was uninitialized, so anything could be printed
    // my ide prints out the number one, but it could be different on any other system

    // question 4
    int y = 17;
    int z = 2000000017;
    double pie =  3.14159;

    cout << "Y size: " << sizeof(y) << endl;
    cout << "Z size: " << sizeof(z) << endl;
    cout << "Pie size: " << sizeof(pie) << endl;

    // pie takes up the most space, as it is a double.

    // question 5
    // x = "felix";
    // incompatible types - x is an int and you're trying to assign
    // a string to it

    // question 6
    if (y >= 10 && y <= 20) {
        cout << "Yes, Y is in between 10 and 20." << endl;
    } else {
        cout << "No, Y is not in between 10 and 20." << endl;
    }

    // question 7
    // for loop
    cout << "for loop: " << endl;
    for (int i = 10; i <= 20; i++) {
        cout << i << " ";
    }
    cout << endl;

    // while loop
    cout << "while loop: " << endl;
    int number = 10;
    while (number <= 20) {
        cout << number << " ";
        number++;
    }
    cout << endl;
    // do-while loop
    cout << "do-while: " << endl;
    int otherNum = 10;
    do {
        cout << otherNum << " ";
        otherNum++;
    }
    while (otherNum <= 20);
    cout << endl;

    // question 8
    ifstream testFile;
    do {
        string fileName;
        cout << "Enter a filename. " << endl;
        cin >> fileName;
        testFile.open(fileName);
    } while (!testFile);

    // question 9
    string word;
    while (testFile >> word){ // whitespace delimited character
        cout << word << endl;
    }
    testFile.close();

    // question 10
    vector<int> sampleVector;
    for (int j = 10; j <= 100; ++j) {
        if (j % 2 == 0) {
            sampleVector.push_back(j);
        }
    }

    // question 11

    // indices
    cout << "Indexed for loop: " << endl;
    for (size_t k = 0; k < sampleVector.size() ; ++k) {
        cout << sampleVector[k] << " ";
    }
    cout << endl;
    // ranged for
    cout << "Ranged for: " << endl;
    for (int evenNum : sampleVector) {
        cout << evenNum << " ";
    }
    cout << endl;
    // in reverse
    cout << "In reverse: " << endl;
    for (size_t l = sampleVector.size(); l > 0 ; l--) {
        cout << sampleVector[l-1] << " ";
    }
    cout << endl;

    // question 12
    vector<int> primeNums{1,2,3,5,7,11,13,17,19};
    cout << "vector of prime ints less than 20: " << endl;
    for (int primes : primeNums) {
        cout << primes << " ";
    }
    cout << endl;

    // question 13
    cout << "using the displayVector function on my vector of prime numbers: " << endl;
    displayVector(primeNums);
    cout << "using the displayVector function on my other vector: " << endl;
    displayVector(sampleVector);

    // question 14
    cout << "testing out the doubling function with the traditional for loop: " << endl;
    vector<int> smallVec{1,2,3,4,5,6,7,8};
    doubleVector1(smallVec);
    displayVector(smallVec);


    // question 15
    cout << "testing out the doubling function with the ranged for loop: " << endl;
    vector<int> otherSmallVec{4,5,6,7,8,9};
    doubleVector2(otherSmallVec);
    displayVector(otherSmallVec);
}
