#include <iostream>
#include <string>
#include <vector>

class Student {
    private:
    std::string name;
    std::string address;
    int intake;
    std::string email;
    std::string cellphone;
    std::string courseName;
    int hour;
    public:
    Student(const std::string& name, const std::string& address, int intake, const std::string& email, const std::string& cellphone, const std::string& courseName, int hour) : name(name), address(address), intake(intake), email(email), cellphone(cellphone), courseName(courseName), hour(hour) {}
    void printDetails() const {
        std::cout << "Name: " << name 
                  << " | Course: " << courseName 
                  << " | Hours: " << hour << "\n";
    }
};

class System {
    private:
    std::vector<Student*> studentList; 
    public:
    System(const std::vector<Student*>& initStudent) : studentList(initStudent) {}
    
    ~System() {
        for (Student* studentPtr : studentList) {
            delete studentPtr; 
        }
        studentList.clear(); 
    }
    
    void countingList() {
        int counting = 0;
        for (const auto& student : studentList) {
            counting++;
        }
        std::cout << "The number of student taking courses are: " << counting << " students" << std::endl;
    }
    
    void addStudent(Student* newStudent) {
        studentList.push_back(newStudent);
    }
    
    void displayStudents() const {
        if (studentList.empty()) {
            std::cout << "No students currently in the system.\n";
            return;
        }

        std::cout << "--- Current Enrolled Students ---\n";
        
        for (const Student* studentPtr : studentList) {
            studentPtr->printDetails(); 
        }
        
        std::cout << "---------------------------------\n";
    }
};

int main() {
    System mySystem({});
    
    Student* student1 = new Student("Bjorn Andersson", "2294 Warner St.", 2021, "bjorn.a@proton.me", "555-0001", "Discrete Mathematics", 18);
    Student* student2 = new Student("Svenja Klueger", "73 Prospect Valley Rd.", 2025, "s.klueger@email.com", "555-0002", "Programming with Java", 21);

    mySystem.addStudent(student1);
    mySystem.addStudent(student2);

    mySystem.countingList();
    mySystem.displayStudents();
    
    return 0;
}