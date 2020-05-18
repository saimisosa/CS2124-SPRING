//
// Created by Saimanasa Juluru on 3/13/20.
//

#include "Course.h"
#include "Student.h"
#include "Registrar.h"


using namespace std;
namespace BrooklynPoly {
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
        while (courseind < courses.size()-1){
            courses[courseind] = courses[courseind+1];
            courseind +=1;
        }
        courses.pop_back();
    }
}
