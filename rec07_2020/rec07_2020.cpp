/*
  Saimanasa Juluru
  CS2124
  Rec 07
  Initial main file for rec07 using cyclical association
  13 March 2020
 */

#include <iostream>
#include <string>
#include <vector>
using namespace std;

class Student;

class Course {
    friend ostream& operator<<(ostream& os, const Course& rhs);
public:
    // Course methods needed by Registrar
    Course(const string& courseName);
    const string& getName() const;
    bool addStudent(Student*);
    void removeStudentsFromCourse();

private:
    string name;
    vector<Student*> students;
};

class Student {
    friend ostream& operator<<(ostream& os, const Student& rhs);
public:
    // Student methods needed by Registrar
    Student(const string& name);
    const string& getName() const;
    bool addCourse(Course*);

    // Student method needed by Course
    void removedFromCourse(Course*);

private:
    string name;
    vector<Course*> courses;
};

class Registrar {
    friend ostream& operator<<(ostream& os, const Registrar& rhs);
public:
    Registrar();
    bool addCourse(const string&);
    bool addStudent(const string&);
    bool enrollStudentInCourse(const string& studentName,
                               const string& courseName);
    bool cancelCourse(const string& courseName);
    void purge();

private:
    size_t findStudent(const string&) const;
    size_t findCourse(const string&) const;

    vector<Course*> courses;
    vector<Student*> students;
};

int main() {

    Registrar registrar;

    cout << "No courses or students added yet\n";
    cout << registrar << endl;

    cout << "AddCourse CS101.001\n";
    registrar.addCourse("CS101.001");
    cout << registrar << endl;

    cout << "AddStudent FritzTheCat\n";
    registrar.addStudent("FritzTheCat");
    cout << registrar << endl;

    cout << "AddCourse CS102.001\n";
    registrar.addCourse("CS102.001");
    cout << registrar << endl;

    cout << "EnrollStudentInCourse FritzTheCat CS102.001\n";
    registrar.enrollStudentInCourse("FritzTheCat", "CS102.001");
    cout << "EnrollStudentInCourse FritzTheCat CS101.001\n";
    registrar.enrollStudentInCourse("FritzTheCat", "CS101.001");
    cout << registrar << endl;

    cout << "EnrollStudentInCourse Bullwinkle CS101.001\n";
    cout << "Should fail, i.e. do nothing, "
         << "since Bullwinkle is not a student.\n";
    registrar.enrollStudentInCourse("Bullwinkle", "CS101.001");
    cout << registrar << endl;

    cout << "CancelCourse CS102.001\n";
    registrar.cancelCourse("CS102.001");
    cout << registrar << endl;

    /*
    // [OPTIONAL - do later if time]
    cout << "ChangeStudentName FritzTheCat MightyMouse\n";
    registrar.changeStudentName("FritzTheCat", "MightyMouse");
    cout << registrar << endl;

    cout << "DropStudentFromCourse MightyMouse CS101.001\n";
    registrar.dropStudentFromCourse("MightyMouse", "CS101.001");
    cout << registrar << endl;

    cout << "RemoveStudent FritzTheCat\n";
    registrar.removeStudent("FritzTheCat");
    cout << registrar << endl;
    */

    cout << "Purge for start of next semester\n";
    registrar.purge();
    cout << registrar << endl;
}
ostream& operator<<(ostream& os, const Course& rhs) {
    os << rhs.name << " : ";
    if (rhs.students.size() == 0) {
        os << "No Students";
    } else {
        for (Student* per : rhs.students) {
            os << per->getName();
        }
    }
    return os;
}
size_t Registrar::findStudent(const string& studentName) const {
    for (size_t i = 0; i < students.size(); i++) {
        if (students[i]->getName() == studentName) {
            return i;
        }
    }
    return students.size();
}
size_t Registrar::findCourse(const string& courseName) const {
    for (size_t i = 0; i < courses.size(); i++) {
        if (courses[i]->getName() == courseName) {
            return i;
        }
    }
    return courses.size();
}
Course::Course(const string& courseName) : name(courseName) {}

const string& Course::getName() const { return name; }

bool Course::addStudent(Student* studentName){
    for (Student* s : students) {
        if (s == studentName) {
            return false;
        }
    }
    students.push_back(studentName);
    return true;
}
void Course::removeStudentsFromCourse(){
    for (Student *s: students) {
        s->removedFromCourse(this);
    }
    students.clear();
}

ostream& operator<<(ostream& os, const Student& rhs) {
    os << rhs.name << " : ";
    if (rhs.courses.size() == 0) {
        os << "No courses.";
    } else {
        for (Course* cour : rhs.courses) {
            os << cour->getName() << " ";
        }
    }
    return os;
}

Student::Student(const string& name) : name(name){}

const string& Student::getName() const { return name; }

bool Student::addCourse(Course* courseName){
    for (Course* c : courses) {
        if (c == courseName) {
            return false;
        }
    }
    courses.push_back(courseName);
    return true;
}

void Student::removedFromCourse(Course* courseName){
    size_t courseind = courses.size();

    for (size_t i = 0; i < courses.size(); i++) {
        if ((courses[i]) == courseName) {
            courseind = i;
        }
    }
    while (courseind < courses.size()){
        courses[courseind] = courses[courseind+1];
        courseind +=1;
    }
    courses.pop_back();
}

ostream& operator<<(ostream& os, const Registrar& rhs) {
    os << "Registrar's Report" << endl;
    os << "Courses: " << endl;
    for (Course *cour : rhs.courses) {
        os << *cour << endl;
    }
    os << "Students: " << endl;
    for (Student *per : rhs.students) {
        os << *per << endl;
    }
    os << endl;
    return os;
}
Registrar::Registrar() {}

bool Registrar::addCourse(const string& courseName){
    if (courses.size() + 1 == Registrar::findCourse(courseName)) {
        return false;
    }
    Course* newCour = new Course(courseName);
    courses.push_back(newCour);
    return true;
}

bool Registrar::addStudent(const string& studentName){
    if (students.size() + 1 == findStudent(studentName)) {
        return false;
    }
    Student* newStud = new Student(studentName);
    students.push_back(newStud);
    return true;
}


bool Registrar::enrollStudentInCourse(const string& studentName, const string& courseName){
    size_t coursenum = findCourse(courseName);
    size_t studnum = findStudent(studentName);
    if ((courses.size() == coursenum) || (students.size() == studnum)) {
        return false;
    }

    courses[coursenum]->addStudent(students[studnum]);
    students[studnum]->addCourse(courses[coursenum]);
    return true;
}

bool Registrar::cancelCourse(const string& courseName){
    size_t courseind = findCourse(courseName);
    if (courses.size() == courseind) {
        return false;
    }
    courses[courseind]->removeStudentsFromCourse();
    delete courses[courseind];
    while (courseind < courses.size()){
        courses[courseind] = courses[courseind + 1];
        courseind+=1;
    }
    courses.pop_back();
    return true;
}

void Registrar::purge() {
    for (Student* stud : students) {
        delete stud;
        stud = nullptr;
    }
    for (Course* cour : courses) {
        delete cour;
        cour = nullptr;
    }
    students.clear();
    courses.clear();
}
