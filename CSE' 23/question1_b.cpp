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
    Course course;
    public:
    Student(std::string name, int id, Course course) : name(name), studentID(id), course(course) {}
    void describe() {
        std::cout << "Student name: " << name << std::endl;
        std::cout << "Student ID: " << studentID << std::endl;
        course.describe();
    }
};

int main() {
    Course myCourse(101, "Programming - 2");
    Student myStudent("Elijah McCowatt", 17246, myCourse);

    myStudent.describe();
}