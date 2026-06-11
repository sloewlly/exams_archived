#include <iostream>
#include <string>
#include <vector>
#include <algorithm>

class Member {
    protected:
    std::string name;
    int birthYear;
    std::string commonField;
    public:
    Member() {
        name = "John Doe";
        birthYear =  1970;
        commonField = "Unknown";
    }

    Member(std::string name, int birthYear, std::string commonField) : name(name), birthYear(birthYear), commonField(commonField) {}
    virtual bool isCoordinator () { return false; }
    int getBirthYear() { return birthYear; }
    virtual void describe() {}
    virtual ~Member() = default;
};

class Participant : public Member {
    public:
    Participant(std::string name, int birthYear, std::string field) : Member(name, birthYear, field) {}
    void describe() override {
        std::cout << "Name: " << name << std::endl;
        std::cout << "Birth Year: " << birthYear << std::endl;
        std::cout << "Field: " << commonField << std::endl;
    }
    bool isCoordinator() override { return false; }
};

class Mentor : public Member {
    public:
    Mentor(std::string name, int birthYear, std::string subject) : Member(name, birthYear, subject) {}
    void describe() override {
        std::cout << "Name: " << name << std::endl;
        std::cout << "Birth Year: " << birthYear << std::endl;
        std::cout << "Subject: " << commonField << std::endl;
    }
    bool isCoordinator() override { return false; }
};

class Coordinator : public Member {
    public:
    Coordinator(std::string name, int birthYear, std::string division) : Member(name, birthYear, division) {}
    void describe() override {
        std::cout << "Name: " << name << std::endl;
        std::cout << "Birth Year: " << birthYear << std::endl;
        std::cout << "Division: " << commonField << std::endl;
    }
    bool isCoordinator() override { return true; }
};

class Society {
    private:
    std::string name;
    std::vector<Member*> memberList;
    public:
    Society(std::string societyName) : name(societyName) {}
    std::string getName() { return name; }
    void addMember(Member* member){
        memberList.push_back(member);
    }
    void describe () {
        std::cout << "Society name: " << name << std::endl;
        for (const auto& member :  memberList){
            member->describe(); 
        }
    }

    int countCoordinator() {
        int count = 0;
        for (const auto& member :  memberList){
            if (member->isCoordinator()) { count += 1; } 
        }
        return count;
    }

    std::vector<int> sorthBirthYear() {
        std::vector<int> years;
        for (const auto& member : memberList) {
            years.push_back(member->getBirthYear());
        }
        std::sort(years.begin(), years.end());
        return years;
    }

    int aveMentorYearOfBirth() {
        int totalYearSum = 0;
        int mentorCount = 0;

        for (const auto& member : memberList) {
            if (dynamic_cast<Mentor*>(member) != nullptr) {
                totalYearSum += member->getBirthYear();
                mentorCount += 1;
            }
        }

        if (mentorCount == 0) {
            return 0.0; 
        }
        return static_cast<int>(totalYearSum) / mentorCount;
    }
};

int main() {
    Participant participant("Alice", 1995, "Art");
    participant.describe();
    Mentor mentor1("Bob", 1980, "Math");
    mentor1.describe();
    Mentor mentor2("Carol", 1970, "Science");
    mentor2.describe();
    Coordinator coordinator1("David", 1985, "Events");
    Coordinator coordinator2("Thomas", 1980, "Logistics");
    Society society("society1");
    society.addMember(&mentor1);
    society.addMember(&mentor2);
    society.addMember (&coordinator1);
    society.addMember (&coordinator2);

    society.describe ();
    int numberOfCoordinators = society.countCoordinator();
    std::cout << "numberOfCoordinators: " << numberOfCoordinators << std::endl;
    society.describe ();

    std::cout << "Average year of birth (Mentors): " << society.aveMentorYearOfBirth() << std::endl;
    return 0;
}