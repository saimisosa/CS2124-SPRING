/*
 * Saimanasa Juluru
 * CS2124
 * Recitation 6
 * 6 March 2020

  Focus: Dynamic arrays and copy control
 */

#include <string>
#include <iostream>
using namespace std;

class Position {
    friend ostream& operator<<(ostream& os, const Position& rhs) {
        os << '[' << rhs.title << ',' << rhs.salary << ']';
        return os;
    }
public:
    Position(const string& aTitle, double aSalary)
            : title(aTitle), salary(aSalary) {}
    const string& getTitle() const { return title; }
    double getSalary() const { return salary; }
    void changeSalaryTo(double d) { salary = d; }
private:
    string title;
    double salary;
}; // class Position

class Entry {
    friend ostream& operator<<(ostream& os, const Entry& rhs) {
        os << rhs.name << ' ' << rhs.room
           << ' ' << rhs.phone << ", " << *rhs.pos;
        return os;
    }
public:
    Entry(const string& name, unsigned room, unsigned phone, Position& position)
            : name(name), room(room), phone(phone), pos(&position) {
    }
    const string& getName() const { return name; }
    unsigned getPhone() const { return phone; }
private:
    string name;
    unsigned room;
    unsigned phone;
    Position* pos;
}; // class Entry

class Directory {
    // Overload output operator
    friend ostream& operator<<(ostream& os, const Directory& theDirectory) {
        if (theDirectory.size == 0) {
            os << "There are no entries in this directory.";
            return os;
        }
        os << "There is/are " << theDirectory.size << " item(s) in this directory. They are: ";
        for (size_t index = 0; index < theDirectory.size; ++index) {
            os << *theDirectory.entries[index] << endl;
        }
        return os;
    }
public:
    // Of course the first function you need to write for this (or
    // any) class is...
    // ???
    // ...
    // constructor
    Directory() {
        size = 0;
        capacity = 1;
        entries = new Entry*[capacity];
    }
    // destructor
    ~Directory() {
        cout << "Calling destructor..." << endl;
        for (size_t index = 0; index < size; index++) {
            delete entries[index];
        }
        delete [] entries;
    }
    // copy constructor
    Directory(const Directory& rhs) {
        cout << "Calling copy constructor..." << endl;
        size = rhs.size;
        capacity = rhs.size;
        entries = new Entry*[capacity];

        // fill the dynamic array with the entries from the rhs
        for (size_t index = 0; index < rhs.size; index++) {
            entries[index] = new Entry(*rhs.entries[index]);
        }

        // if rhs is larger than the size/capacity of the object on the left
        // set the rest of the objects after the cut off to nullptr
        // to prevent memory leaks
        for (size_t index = size; index < rhs.capacity; index++) {
            entries[index] = nullptr;
        }
    }

    // Assignment operator
    Directory& operator=(const Directory& rhs) {
        if (this != &rhs) {
            cout << "Calling assignment operator..." << endl;
            // free up space
            for (size_t index = 0; index < size; index++) {
                delete entries[index];
            }
            delete [] entries;
            // allocate and copy
            size = rhs.size;
            capacity = rhs.size;
            entries = new Entry*[capacity];

            // fill the dynamic array with the entries from the rhs
            for (size_t index = 0; index < rhs.size; index++) {
                entries[index] = new Entry(*rhs.entries[index]);
            }

            // if rhs is larger than the size/capacity of the object on the left
            // set the rest of the objects after the cut off to nullptr
            // to prevent memory leaks
            for (size_t index = size; index < rhs.capacity; index++) {
                entries[index] = nullptr;
            }
        }
        // return yourself
        return *this;
    }
    unsigned operator[](const string& name) const {
        for (size_t i = 0; i < size; ++i){
            if (entries[i]->getName() == name){
                return entries[i]->getPhone();
            }
        }
        return 0;
    }

    // We'll get you started with the add method, but obviously you
    // have a lot of work to do here.
    void add(const string& name, unsigned room, unsigned ph, Position& pos) {
        if (size == capacity) {
            // something is missing!!!  Add it!
            Entry** oldEntries = entries;
            entries = new Entry*[2*capacity];
            for (size_t index = 0; index < capacity; index++) {
                entries[index] = oldEntries[index];
            }
            delete [] oldEntries;
            capacity *= 2;
        } // if
        entries[size] = new Entry(name, room, ph, pos);
        ++size;
    } // add

private:
    Entry** entries;
    size_t size;
    size_t capacity;
}; // class Directory

void doNothing(Directory dir) { cout << dir << endl; }

int main() {

    // Note that the Postion objects are NOT on the heap.
    Position boss("Boss", 3141.59);
    Position pointyHair("Pointy Hair", 271.83);
    Position techie("Techie", 14142.13);
    Position peon("Peonissimo", 34.79);

    // Create a Directory
    Directory d;
    d.add("Marilyn", 123, 4567, boss);
    cout << d << endl;

    Directory d2 = d;	// What function is being used??
    d2.add("Gallagher", 111, 2222, techie);
    d2.add("Carmack", 314, 1592, techie);
    cout << d << endl;

    cout << "Calling doNothing\n";
    doNothing(d2);
    cout << "Back from doNothing\n";

    Directory d3;
    d3 = d2;

    // Should display 1592
    cout << d2["Carmack"] << endl;

} // main

