//
// Created by Saimanasa Juluru on 3/13/20.
//

#ifndef REC07_SEPCOMP_REGISTRAR_H
#define REC07_SEPCOMP_REGISTRAR_H
#include <vector>
#include <string>
#include <iostream>


using namespace std;
namespace BrooklynPoly {
    class Student;
    class Course;
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
}



#endif //REC07_SEPCOMP_REGISTRAR_H
