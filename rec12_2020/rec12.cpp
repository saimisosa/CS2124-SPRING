// Saimanasa Juluru
// CS2124
// Rec 12
// 24 April 2020

#include <iostream>
#include <cstdlib>
using namespace std;

class List {
    struct Node;
public:
    List(): lstsize(0), header(new Node(0)), trailer(new Node(0, nullptr, header)){
        header->next = trailer;
    }
    size_t size() const {
        return lstsize;
    }
    void push_back(int data) {
        lstsize++;
        Node* node = new Node(data, trailer, trailer->prior);
        trailer->prior->next = node;
        trailer->prior = node;
    }
    void pop_back() {
        if (lstsize == 0) {
            return;
        }
        else if (lstsize == 1) {
            lstsize--;
            Node* temp = trailer->prior;
            temp->prior = header;
            header->next = trailer;
            delete temp;
        }
        else {
            lstsize--;
            Node* temp = trailer->prior;
            trailer->prior->prior->next = trailer;
            trailer->prior = trailer->prior->prior;
            delete temp;
        }
    }
    void push_front(int data) {
        lstsize++;
        Node* node = new Node(data, header->next, header);
        header->next->prior = node;
        header->next = node;
    }
    void pop_front() {
        if (lstsize == 0) {
            return;
        }
        else if (lstsize == 1) {
            lstsize--;
            Node* temp = header->next;
            header->next = trailer;
            trailer->prior = header;
            delete temp;
        }
        else {
            lstsize--;
            Node* temp = header->next;
            header->next->next->prior = header;
            header->next = header->next->next;
            delete temp;
        }
    }
    int front() const {
        return header->next->data;
    }
    int& front() {
        return header->next->data;
    }
    int back() const {
        return trailer->prior->data;
    }
    int& back() {
        return trailer->prior->data;
    }
    void clear() {
        Node* kill = header->next;
        while (kill != trailer) {
            header->next = header->next->next;
            delete kill;
            kill = header->next;
        }
        header->next = trailer;
        trailer->prior = header;
        lstsize = 0;
    }

    friend ostream& operator << (ostream& os, const List& lst) {
        Node* iter = lst.header->next;
        while (iter != lst.trailer) {
            os << iter->data << " ";
            iter = iter->next;
        }
        os << endl;
        return os;
    }
    int& operator[] (size_t entry) {
        Node* track = header->next;
        for (size_t i = 0; i < entry; ++i) {
            track = track->next;
        }
        return track->data;
    }
    int operator[] (size_t entry) const {
        Node* track = header->next;
        for (size_t i = 0; i < entry; ++i) {
            track = track->next;
        }
        return track->data;
    }
    class iterator {
        friend List;
        friend bool operator==(iterator rhs, iterator lhs) {
            if (rhs.ptr == lhs.ptr) {
                return true;
            }
            return false;
        }
        friend bool operator!=(iterator rhs, iterator lhs) {
            return !(rhs.ptr == lhs.ptr);
        }
    public:
        iterator(Node* ptr): ptr(ptr){}
        iterator& operator++() {
            ptr = ptr->next;
            return *this;
        }
        iterator& operator--() {
            ptr = ptr->prior;
            return *this;
        }

        int operator*() {
            return ptr->data;
        }
    private:
        Node* ptr;
    };
    iterator begin() const {
        iterator p(header->next);
        return p;
    }
    iterator end() const {
        iterator p(trailer);
        return p;
    }
    iterator begin() {
        iterator p(header->next);
        return p;
    }
    iterator end() {
        iterator p(trailer);
        return p;
    }
    iterator insert(iterator entry, int data) {
        Node* node = new Node(data, entry.ptr, entry.ptr->prior);
        entry.ptr->prior->next = node;
        entry.ptr->prior = node;
        entry.ptr = node;
        lstsize++;
        return entry;
    }
    iterator erase(iterator entry) {
        Node* kill = entry.ptr;
        entry.ptr->prior->next = entry.ptr->next;
        entry.ptr->next->prior = entry.ptr->prior;
        entry.ptr = entry.ptr->next;
        lstsize--;
        delete kill;
        return entry;
    }
private:
    struct Node {
        Node(int data, Node* next = nullptr, Node* prior = nullptr) : data(data), next(next), prior(prior) {}
        int data;
        Node* next;
        Node * prior;
    };
    size_t lstsize;
    Node* header;
    Node* trailer;
};


// Task 1
void printListInfo(const List& myList) {
    cout << "size: " << myList.size()
         << ", front: " << myList.front()
         << ", back(): " << myList.back()
         << ", list: " << myList << endl;
}

// The following should not compile. Check that it does not.
//void changeFrontAndBackConst(const List& theList){
//     theList.front() = 17;
//     theList.back() = 42;
// }

void changeFrontAndBack(List& theList) {
    theList.front() = 17;
    theList.back() = 42;
}

// Task 4
void printListSlow(const List& myList) {
    for (size_t i = 0; i < myList.size(); ++i) {
        cout << myList[i] << ' ';
    }
    cout << endl;
}

// Task 8
void doNothing(List aList) {
    cout << "In doNothing\n";
    printListInfo(aList);
    cout << endl;
    cout << "Leaving doNothing\n";
}

int main() {

    // Task 1
    cout << "\n------Task One------\n";
    List myList;
    cout << "Fill empty list with push_back: i*i for i from 0 to 9\n";
    for (int i = 0; i < 10; ++i) {
        cout << "myList.push_back(" << i*i << ");\n";
        myList.push_back(i*i);
        printListInfo(myList);
    }
    cout << "===================\n";

    cout << "Modify the first and last items, and display the results\n";
    changeFrontAndBack(myList);
    printListInfo(myList);
    cout << "===================\n";

    cout << "Remove the items with pop_back\n";
    while (myList.size()) {
        printListInfo(myList);
        myList.pop_back();
    }
    cout << "===================\n";

    // Task 2
    cout << "\n------Task Two------\n";
    cout << "Fill empty list with push_front: i*i for i from 0 to 9\n";
    for (int i = 0; i < 10; ++i) {
        cout << "myList2.push_front(" << i*i << ");\n";
        myList.push_front(i*i);
        printListInfo(myList);
    }
    cout << "===================\n";
    cout << "Remove the items with pop_front\n";
    while (myList.size()) {
        printListInfo(myList);
        myList.pop_front();
    }
    cout << "===================\n";

    // Task 3
    cout << "\n------Task Three------\n";
    cout << "Fill empty list with push_back: i*i for i from 0 to 9\n";
    for (int i = 0; i < 10; ++i) {
        myList.push_back(i*i);
    }
    printListInfo(myList);
    cout << "Now clear\n";
    myList.clear();
    cout << "Size: " << myList.size() << ", list: " << myList << endl;
    cout << "===================\n";

    // Task 4
    cout << "\n------Task Four------\n";
    cout << "Fill empty list with push_back: i*i for i from 0 to 9\n";
    for (int i = 0; i < 10; ++i)  myList.push_back(i*i);
    cout << "Display elements with op[]\n";
    for (size_t i = 0; i < myList.size(); ++i) cout << myList[i] << ' ';
    cout << endl;
    cout << "Add one to each element with op[]\n";
    for (size_t i = 0; i < myList.size(); ++i) myList[i] += 1;
    cout << "And print it out again with op[]\n";
    for (size_t i = 0; i < myList.size(); ++i) cout << myList[i] << ' ';
    cout << endl;
    cout << "Now calling a function, printListSlow, to do the same thing\n";
    printListSlow(myList);
    cout << "Finally, for this task, using the index operator to modify\n"
         << "the data in the third item in the list\n"
         << "and then using printListSlow to display it again\n";
    myList[2] = 42;
    printListSlow(myList);


    // Task 5
    cout << "\n------Task Five------\n";
    cout << "Fill empty list with push_back: i*i for i from 0 to 9\n";
    myList.clear();
    for (int i = 0; i < 10; ++i)  myList.push_back(i*i);
    printListInfo(myList);
    cout << "Now display the elements in a ranged for\n";
    for (int x : myList) cout << x << ' ';
    cout << endl;
    cout << "And again using the iterator type directly:\n";
    // Note you can choose to nest the iterator class or not, your choice.
    //for (iterator iter = myList.begin(); iter != myList.end(); ++iter) {
    for (List::iterator iter = myList.begin(); iter != myList.end(); ++iter) {
        cout << *iter << ' ';
    }
    cout << endl;
    cout << "WOW!!! (I thought it was cool.)\n";

    // Task 6
    cout << "\n------Task Six------\n";
    cout << "Filling an empty list with insert at end: i*i for i from 0 to 9\n";
    myList.clear();
    for (int i = 0; i < 10; ++i) myList.insert(myList.end(), i*i);
    printListInfo(myList);
    cout << "Filling an empty list with insert at begin(): "
         << "i*i for i from 0 to 9\n";
    myList.clear();
    for (int i = 0; i < 10; ++i) myList.insert(myList.begin(), i*i);
    printListInfo(myList);
    // ***Need test for insert other than begin/end***
    cout << "===================\n";

    // Task 7
    cout << "\n------Task Seven------\n";
    cout << "Filling an empty list with insert at end: i*i for i from 0 to 9\n";
    myList.clear();
    for (int i = 0; i < 10; ++i) myList.insert(myList.end(), i*i);
    cout << "Erasing the elements in the list, starting from the beginning\n";
    while (myList.size()) {
        printListInfo(myList);
        myList.erase(myList.begin());
    }
    // ***Need test for erase other than begin/end***
    cout << "===================\n";

    // Task 8
    cout << "\n------Task Eight------\n";
    cout << "Copy control\n";
    cout << "Filling an empty list with insert at end: i*i for i from 0 to 9\n";
    myList.clear();
    for (int i = 0; i < 10; ++i) myList.insert(myList.end(), i*i);
    printListInfo(myList);
    cout << "Calling doNothing(myList)\n";
    doNothing(myList);
    cout << "Back from doNothing(myList)\n";
    printListInfo(myList);

    cout << "Filling listTwo with insert at begin: i*i for i from 0 to 9\n";
    List listTwo;
    for (int i = 0; i < 10; ++i) listTwo.insert(listTwo.begin(), i*i);
    printListInfo(listTwo);
    cout << "listTwo = myList\n";
    listTwo = myList;
    cout << "myList: ";
    printListInfo(myList);
    cout << "listTwo: ";
    printListInfo(listTwo);
    cout << "===================\n";
}

