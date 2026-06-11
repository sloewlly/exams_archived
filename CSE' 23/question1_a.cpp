#include <iostream>
#include <string>

class Course {
    private:
    int CourseCode;
    std::string CourseName;
    public:
    Course(int courseCode, std::string courseName) : CourseCode(courseCode), CourseName(courseName) {}
    void describe() {
        std::cout << "Course code: " << CourseCode << std::endl;
        std::cout << "Course name: " << CourseName << std::endl;
    }
};
class Student {
    private:
    std::string name;
    int studentID;
    Course* course;
    public:
    Student(std::string name, int id, int courseCode, std::string courseName) {
        this->name = name;
        this->studentID = id;
        this->course = new Course(courseCode, courseName);
    }

    ~ Student() {
        delete course;
    }

    void describe() {
        std::cout << "Student name: " << name << std::endl;
        std::cout << "Student ID: " << studentID << std::endl;
        course->describe();
    }
};

int main() {
    Student myStudent("Elijah McCowatt", 17246, 101, "Programming - 2");
    myStudent.describe();
}