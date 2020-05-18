//
// Created by Saimanasa Juluru on 3/13/20.
//
#include "Course.h"
#include "Student.h"
#include "Registrar.h"

using namespace std;
namespace BrooklynPoly {
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
        while (courseind < courses.size()-1){
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
}

