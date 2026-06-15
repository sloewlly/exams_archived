    #include <iostream>
    #include <vector>
    #include <string>
    #include <algorithm>
    #include <stdexcept>

    class Person {
        protected:
        std::string name;
        int yearofBirth;
        std::string commonField;    
        public:
        Person(std::string name, int yearofBirth, std::string commonField) : name(name), yearofBirth(yearofBirth), commonField(commonField) {}
        virtual ~Person() = default;
        int getbirthYear() const { return yearofBirth; }
        virtual void describe() const {}
        virtual bool isDoctor() const { return false; }
        virtual bool isTeacher() const { return false; }
    };

    class Student : public Person {
        public:
        Student(std::string name, int yearofBirth, std::string grade) : Person(name, yearofBirth, grade) {}
        void isValid() {
            int value = std::stoi(commonField);
            if (value < 1 || value > 13){
                throw std::runtime_error("Invalid Grade!");          
            }
        }

        bool isDoctor() const override { return false; }
        bool isTeacher() const override { return false; }
        void describe() const override{
            std::cout << "Name: " << name << std::endl; 
            std::cout << "Year of Birth: " << yearofBirth << std::endl;
            std::cout << "Grade: " << commonField << std::endl;
        }
    };

    class Teacher : public Person {
        public:
        Teacher(std::string name, int yearofBirth, std::string subject) : Person(name, yearofBirth, subject) {}
        bool isDoctor() const override { return false; }
        bool isTeacher() const override { return true; }
        void describe() const override{
            std::cout << "Name: " << name << std::endl; 
            std::cout << "Year of Birth: " << yearofBirth << std::endl;
            std::cout << "Subject: " << commonField << std::endl;
        }
    };

    class Doctor : public Person {
        public:
        Doctor(std::string name, int yearofBirth, std::string specialist) : Person(name, yearofBirth, specialist) {}
        bool isDoctor() const override { return true; }
        bool isTeacher() const override { return false; }
        void describe() const override {
            std::cout << "Name: " << name << std::endl; 
            std::cout << "Year of Birth: " << yearofBirth << std::endl;
            std::cout << "Specialist: " << commonField << std::endl;
        }
    };

    class Ward {
        private:
        std::string name;
        std::vector<Person*> list;
        public:
        Ward(std::string name) : name(name) {}
        void addPerson(Person* person) {
            list.push_back(person);
        }
        void describe() {
            std::cout << "Ward's name: " << name << std::endl;
            for (const auto& person : list) {
                person->describe();
            }
        } 
        int countDoctors() {
            int totalDoctors = 0;
            for (const auto& person : list) {
                if (person->isDoctor()) { totalDoctors += 1; }
            }
            return totalDoctors;
        }
        void sortAge() {
            std::sort(list.begin(), list.end(), [](Person* a, Person* b) {
                return a->getbirthYear() > b->getbirthYear(); 
            });
        }

        int aveTeacherYearOfBirth() {
            int totalTeachers = 0;
            int totalbirthYears = 0;
            for (const auto& person : list) {
                if (person->isTeacher()) {
                    totalTeachers += 1;
                    totalbirthYears += (person->getbirthYear());
                }
            }
            if (totalTeachers == 0) return 0;
            return totalbirthYears / totalTeachers;
        }  
    };

int main() {
    Student studentA("John Doe", 2008, "12");
    Teacher teacherA("Jane Doe", 1970, "Mathematics");
    Doctor doctorA("Joseph McCoy", 1950, "Psychologist");
    Teacher teacherB("Andrew Johnson", 1990, "German");
    Doctor doctorB("Julia Bergvall", 1999, "Astronomer");
    Ward ward("WardA");
    ward.addPerson(&studentA);
    ward.addPerson(&teacherA);
    ward.addPerson(&doctorA);
    ward.addPerson(&teacherB);
    ward.addPerson(&doctorB);
    ward.describe();

    int numberofDoctors = ward.countDoctors();
    std::cout << "Number of doctors: " << numberofDoctors << std::endl;

    ward.sortAge();
    ward.describe();

    int aveTeacherYearOfBirth = ward.aveTeacherYearOfBirth();

    std::cout << "Average year of birth (Teachers): " << aveTeacherYearOfBirth << std::endl;
}