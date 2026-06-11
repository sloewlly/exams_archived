#include <iostream>
#include <string>

class Employee {
    private:
    int id;
    std::string name;
    std::string gender;
    std::string department_id;
    public:
    Employee (int id, std::string name, std::string gender, std::string department_id) : id(id), name(name), gender(gender), department_id(department_id) {}
    int getID() { return id; }
    std::string getName() { return name; }
    std::string getGender() { return gender; }
    std::string getDepartmentID() { return department_id; }
    void printInfo() {
        std::cout << "Employee ID: " << id << std::endl;
        std::cout << "Employee Name: " << name << std::endl;
        std::cout << "Gender: " << gender << std::endl;
        std::cout << "Department ID: " << department_id << std::endl;
    }
};

class Manager : public Employee {
    public:
    Manager (int id, std::string name, std::string gender, std::string department_id) : Employee (id, name, gender, department_id) {}
};

int main() {
    Employee myEmployee(101, "Laurey McCormack", "Female", "SC105");
    Manager myManager(505, "Jacques LeMann", "Male", "SD710");

    std::cout << "Employee(s):" << std::endl;
    myEmployee.printInfo();
    std::cout << "Manager(s):" << std::endl;
    myManager.printInfo();

    return 0;
}