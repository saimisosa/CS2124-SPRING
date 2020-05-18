//
// Created by Saimanasa Juluru on 3/13/20.
//

#ifndef REC07_SEPCOMP_STUDENT_H
#define REC07_SEPCOMP_STUDENT_H
#include <vector>
#include <string>
#include <iostream>

using namespace std;
namespace BrooklynPoly {
    class Course;
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
}



#endif //REC07_SEPCOMP_STUDENT_H
