//Saimanasa Juluru
//Recitation 5
//Section C
//28 February 2020

#include <iostream>
#include <string>
#include <vector>
using namespace std;

class LabwWorker;
class Section {
    friend ostream& operator<<(ostream& os, const Section& section) {
        os << "Section: " << section.secName << " TimeSlot: " << section.timeSlot << " Students: ";
        if (section.grades.size() == 0) { os << "None" << endl; }
        else {
            for (StudentRecords* student : section.grades) {
                os << endl << *student;
            }
        }
        return os;
    }
    class TimeSlot {
        friend ostream& operator<<(ostream& os, const TimeSlot& time) {
            os << "[Day: " << time.day << " Start Time: " << time.TStime << time.timeOfDay << "]";
            return os;
        }
    private:
        string day;
        int TStime;
        string timeOfDay;
    public:
        TimeSlot(const string& day, int time) : day(day), TStime(time), timeOfDay("am") {
            if (time > 12) {
                TStime -= 12;
                timeOfDay = "pm";
            }
        };
    };
    class StudentRecords {
        friend ostream& operator<<(ostream& os, const StudentRecords& student) {
            os << "Name: " << student.name << ", Grades: ";
            for (int grade : student.gradebook) {
                os << grade << " ";
            }
            return os;
        }
    public:
        StudentRecords(const string& name) : name(name), gradebook(14,-1) {};
        const string& getName() const {
            return name;
        }
        void changeGrade(int val, int week) {
            gradebook[week - 1] = val;
        }
    private:
        string name;
        vector<int> gradebook;
    };
public:
    Section(const string& secName, const string& day, int time) : secName(secName), timeSlot(day,time) {};
    ~Section() {
        cout << "Section " << secName << " is being deleted." << endl;
        for (StudentRecords* student : grades) {
            cout << "Deleting " << student->getName() << endl;
            delete student;
            student = nullptr;
        }
        grades.clear();
    }
    Section(const Section& rhs): timeSlot(rhs.timeSlot), secName(rhs.secName) {
        cout << "Calling the copy constructor..." << endl;
        for (StudentRecords* student : rhs.grades) {
            StudentRecords* newStudent = new StudentRecords(*student);
            grades.emplace_back(newStudent);
        }
    }

    void setGrade(const string& studentName, int grade, int position){
        for (StudentRecords* student : grades){
            if (student->getName() == studentName){
                student->changeGrade(grade, position);
            }
        }
    }
    void addStudent(const string& studentName){
        grades.emplace_back(new StudentRecords(studentName));
    }
private:
    string secName;
    TimeSlot timeSlot;
    vector<StudentRecords*> grades;
};

class LabWorker {
    friend ostream& operator<<(ostream& os, const LabWorker& employee) {
        if (employee.toTeach == nullptr) {
            os << employee.name << " does not have a lab section.";
        } else {
            os << employee.name << " has section " << *employee.toTeach;
        }
        return os;
    }
public:
    LabWorker(const string& name) : name(name), toTeach(nullptr){}

    void addSection(Section& toAdd) {
        toTeach = &toAdd;
    }
    void addGrade(const string& studentName, int grade, int position) {
        toTeach->setGrade(studentName, grade, position);
    }
private:
    string name;
    Section* toTeach;
};

void doNothing(Section sec) { cout << sec << endl; }

int main() {

    cout << "Test 1: Defining a section\n";
    Section secA2("A2", "Tuesday", 16);
    cout << secA2 << endl;
//
    cout << "\nTest 2: Adding students to a section\n";
    secA2.addStudent("John");
    secA2.addStudent("George");
    secA2.addStudent("Paul");
    secA2.addStudent("Ringo");
    cout << secA2 << endl;
//
    cout << "\nTest 3: Defining a lab worker.\n";
    LabWorker moe( "Moe" );
    cout << moe << endl;
//
    cout << "\nTest 4: Adding a section to a lab worker.\n";
    moe.addSection( secA2 );
    cout << moe << endl;
//
    cout << "\nTest 5: Adding a second section and lab worker.\n";
    LabWorker jane( "Jane" );
    Section secB3( "B3", "Thursday", 11 );
    secB3.addStudent("Thorin");
    secB3.addStudent("Dwalin");
    secB3.addStudent("Balin");
    secB3.addStudent("Kili");
    secB3.addStudent("Fili");
    secB3.addStudent("Dori");
    secB3.addStudent("Nori");
    secB3.addStudent("Ori");
    secB3.addStudent("Oin");
    secB3.addStudent("Gloin");
    secB3.addStudent("Bifur");
    secB3.addStudent("Bofur");
    secB3.addStudent("Bombur");
    jane.addSection( secB3 );
    cout << jane << endl;
//
    cout << "\nTest 6: Adding some grades for week one\n";
    moe.addGrade("John", 17, 1);
    moe.addGrade("Paul", 19, 1);
    moe.addGrade("George", 16, 1);
    moe.addGrade("Ringo", 7, 1);
    cout << moe << endl;
//
    cout << "\nTest 7: Adding some grades for week three (skipping week 2)\n";
    moe.addGrade("John", 15, 3);
    moe.addGrade("Paul", 20, 3);
    moe.addGrade("Ringo", 0, 3);
    moe.addGrade("George", 16, 3);
    cout << moe << endl;
//
    cout << "\nTest 8: We're done (almost)! \nWhat should happen to all "
         << "those students (or rather their records?)\n";
//
//    //All their records should disappear
//
    cout << "\nTest 9: Oh, IF you have covered copy constructors in lecture, "
         << "then make sure the following call works:\n";
    doNothing(secA2);
    cout << "Back from doNothing\n\n";

} // main

