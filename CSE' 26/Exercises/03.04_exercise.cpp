#include <iostream>
#include <string>

class Course {
    private:
    std::string courseCode;
    std::string title;
    std::string description;
    int creditsH;
    public:
    Course(std::string courseCode, std::string title, std::string description, int creditsH) : courseCode(courseCode), title(title), description(description), creditsH(creditsH) {}
    void getCoursedetails() {
        std::cout << "Course ID: " << courseCode << " | Course title: " << title << " | Course description: " << description << " | Credits: " << creditsH << std::endl;
    }
    void updateCourse(std::string u_description) {
        description = u_description;
    }
};

int main() {
    Course myCourse("CSE101", "Introduction to Programming-2", "This course will help you to master C++ programming", 48);
    myCourse.getCoursedetails();
    myCourse.updateCourse("This course will actually help you to master Java, my mistakes!");
    myCourse.getCoursedetails();
    return 0;
}