// Saimanasa Juluru
// CS2124
// Rec 13
// 1 May 2020

#include <iostream>
#include <fstream>
#include <vector>      // task 1
#include <list>        // task 2
#include <algorithm>   // task 3
#include <string>      // task 21
#include <set>         // task 22
#include <map>         // task 23
using namespace std;

//Task 9
void printList(list<int> someList){
    list<int>::const_iterator regLst;
    for (regLst = someList.begin(); regLst != someList.end(); ++regLst){
        cout << *regLst << " ";
    }
}
//Task 11
auto printList1(list<int> someList) {
    list<int>::const_iterator regLst;
    for (regLst = someList.begin(); regLst != someList.end(); ++regLst) {
        cout << *regLst << " ";
    }
}

//Task 12
list<int>::const_iterator findNum(const list<int> someList, int num){
    list<int>::const_iterator regLst;
    for (regLst = someList.begin(); regLst != someList.end(); regLst++) {
        if (*regLst == num){
            return regLst;
        }
    }
    return someList.end();
}

//Task 13
auto findNum1(const list<int> someList, int num){
    for (auto regLst = someList.begin(); regLst != someList.end(); regLst++) {
        if (*regLst == num){
            return regLst;
        }
    }
    return someList.end();
}

//Task 15
const bool isEven(const int i){
    return !(i % 2);
}

//Task 16
class isEven1{
public:
    bool operator() (int i) const {
        return !(i % 2);
    }
};

//Task 19
list<int>::iterator ourFind(list<int>::iterator begin, list<int>::iterator end, const int& val) {
    cout << "My find function." << endl;
    for (begin; begin != end; ++begin) {
        if (*begin = val) {
            return begin;
        }
    }
}

//Task 20
template <typename T, typename U>
T ourFind1(T begin, T end, U val) {
    cout << "My templated find function." << endl;
    for (begin; begin != end; ++begin) {
        if (*begin = val) {
            return begin;
        }
    }
}


int main() {
    // 1. Create a vector with some values and display using ranged for
    cout << "Task 1:\n";
    vector<int> someVal;
    someVal = {5,4,7,1,3,2,6,8};

    for (int num : someVal){
        cout << num << " ";
    }
    cout << "\n=======\n";

    // 2. Initalize a list as a copy of values from the vector
    cout << "Task 2:\n";
    list<int> newList(someVal.begin(), someVal.end());

    for (int val : newList){
        cout << val << " ";
    }
    cout << "\n=======\n";

    // 3. Sort the original vector.  Display both the vector and the list
    cout << "Task 3:\n";
    cout << "Sorted Vector :D" << endl;
    sort(someVal.begin(), someVal.end());
    for (int num : someVal){
        cout << num << " ";
    }
    cout << endl;
    cout << "Unsorted List :D" << endl;
    for (int val : newList){
        cout << val << " ";
    }
    cout << "\n=======\n";

    // 4. print every other element of the vector.
    cout << "Task 4:\n";
    for (int i = 0; i < someVal.size(); ++++i){
        cout << someVal[i] << " ";
    }

    cout << "\n=======\n";

    // 5. Attempt to print every other element of the list using the
    //    same technique.
    cout << "Task 5:\n";
    /*for (int i = 0; i < newList.size(); ++++i){
        cout << newList[i] << " ";
    }
    */
    cout << "whomp whomp whooooomp :(";
    cout << "\n=======\n";

    //
    // Iterators
    //

    // 6. Repeat task 4 using iterators.  Do not use auto;
    cout << "Task 6:\n";
    vector<int>::iterator frontPtr;
    for (frontPtr = someVal.begin(); frontPtr < someVal.end(); ++++frontPtr){
        cout << *frontPtr << " ";
    }
    cout << "\n=======\n";

    // 7. Repeat the previous task using the list.  Again, do not use auto.
    //    Note that you cannot use the same simple mechanism to bump
    //    the iterator as in task 6.
    cout << "Task 7:\n";
    list<int>::iterator listPtr;
    for (listPtr = newList.begin(); listPtr != newList.end(); ++++listPtr){
        cout << *listPtr << " ";
    }
    cout << "\n=======\n";

    // 8. Sorting a list
    cout << "Task 8:\n";
    newList.sort();
    cout << "sorting demonstrated in task nine hehe :D";
    cout << "\n=======\n";

    // 9. Calling the function to print the list
    cout << "Task 9:\n";
    printList(newList);
    cout << endl;
    cout << "=======\n";

    // 10. Calling the function that prints the list, using ranged-for
    cout << "Task 10:\n";
    for (int val : newList){
        cout << val << " ";
    }
    cout << endl;
    cout << "=======\n";

    //
    // Auto
    //

    // 11. Calling the function that, using auto, prints alterate
    // items in the list
    cout << "Task 11:\n";
    printList1(newList);
    cout << endl;
    cout << "=======\n";

    // 12.  Write a function find that takes a list and value to search for.
    //      What should we return if not found
    cout << "Task 12:\n";
    list<int> task12;
    task12 = {4,5,2,9,17};

    auto val = findNum(task12, 17);
    cout << "Integer found: " << *val << endl;

    cout << "=======\n";

    // 13.  Write a function find that takes a list and value to search for.
    //      What should we return if not found
    cout << "Task 13:\n";
    list<int> task13;
    task13 = {9,1,4,5,33};

    auto in = findNum1(task13, 33);
    cout << "Integer found: " << *in << endl;
    cout << "=======\n";

    //
    // Generic Algorithms
    //

    // 14. Generic algorithms: find
    cout << "Task 14:\n";
    list<int> randomNum;
    randomNum = {11,0,2,2000,12,15,2003};
    list<int>::iterator i = find(randomNum.begin(), randomNum.end(), 15);
    cout << "Integer found: " << *i << endl;

    cout << "=======\n";

    // 15. Generic algorithms: find_if
    cout << "Task 15:\n";
    vector<int> task15;
    task15 = {1,2,4,5,16,11};

    vector<int>::iterator even;

    even = find_if(task15.begin(), task15.end(), isEven);
    if (*even != 0) {
        cout << "The first even value is " << *even << '\n';
    }
    else {
        cout << "No even values found in the vector." << '\n';
    }

    cout << "=======\n";

    // 16. Functor
    cout << "Task 16:\n";
    cout << ":-]\n";
    vector<int> task16;
    task16 = {10,4,5,11,45,72};

    vector<int>::iterator even1;

    even1 = find_if(task16.begin(), task16.end(), isEven1());
    if (*even1 != 0) {
        cout << "The first even value is " << *even1 << '\n';
    }
    else {
        cout << "No even values found in the vector." << '\n';
    }
    cout << "=======\n";

    // 17. Lambda
    cout << "Task 17:\n";

    vector<int> vec = {6,1,9,10};
    vector<int>:: iterator p = find_if(vec.begin(), vec.end(), [](int i)
    {
        return !(i % 2);
    });
    cout << ":-]" << endl;
    cout << "The first even value is " << *p << endl;

    cout << "=======\n";

    // 18. Generic algorithms: copy to an array
    cout << "Task 18:\n";
    int* arr = new int[4];
    copy(newList.begin(), newList.end(), arr);
    for (vector<int>::iterator iter = vec.begin(); iter != vec.end(); ++iter){
        cout << *iter << " ";
    }
    cout << endl;

    int *value = find(arr, arr+4, 9);
    if (value == arr + 4){
        cout << "Value not found." << endl;
    }
    else {
        cout << "Value found: " <<  *value << endl;
    }
    delete [] arr;
    cout << "=======\n";

    //
    // Templated Functions
    //

    // 19. Implement find as a function for lists
    cout << "Task 19:\n";
    list<int> task19;
    task19 = {5,1,9,10};

    list<int>::iterator beginning = task19.begin();
    list<int>::iterator ending = task19.end();

    cout << *ourFind(beginning, ending, 1) << endl;

    cout << "=======\n";

    // 20. Implement find as a templated function
    cout << "Task 20:\n";
    vector<int> task20;
    task20 = {6,7,8,14,5,17};

    vector<int>::iterator first = task20.begin();
    vector<int>::iterator last = task20.end();

    cout << *ourFind1(first, last, 5) << endl;
    cout << "=======\n";

    //
    // Associative collections
    //

    // 21. Using a vector of strings, print a line showing the number
    //     of distinct words and the words themselves.
    cout << "Task 21:\n";
    vector<string> words;

    ifstream ifs("pooh-nopunc.txt");
    if (!ifs){
        cerr << "Couldn't open file." << endl;
        exit(1);
    }

    string token;
    while (ifs>>token){
        if (find(words.begin(), words.end(), token) == words.end()){
            words.push_back(token);
        }
    }
    cout << words.size();

    cout << "\n=======\n";
    ifs.clear();
    ifs.seekg(0);

    // 22. Repeating previous step, but using the set
    cout << "Task 22:\n";

    set<string> setwords;

    while(ifs>>token){
        setwords.insert(token);
    }
    cout << setwords.size();
    cout << endl;

    cout << "=======\n";
    ifs.clear();
    ifs.seekg(0);

    // 23. Word co-occurence using map
    cout << "Task 23:\n";

    map<string, vector<int>> wordMap;
    int pos = 0;
    while (ifs>>token){
        wordMap[token].push_back(pos);
        pos += 1;
    }
    cout << wordMap.size();

    for (const auto& x : wordMap){
        cout << x.first << " ";
        for(const auto& pos : x.second){
            cout << pos << " ";
        }
        cout << endl;
    }
    ifs.close();
    cout << endl;
    cout << "=======\n";
}