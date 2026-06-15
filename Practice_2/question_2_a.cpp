#include <iostream>
#include <string>

bool leapYear(int y){
    if (y % 400 == 0) { return true; }
    else if (y % 100 == 0) { return false; }
    else if (y % 4 == 0) { return true; }
    else { return false; }   
}

bool isValid(int d, int m, int y) {
    if (m < 1 || m > 12) { return false; }
    int daysInMonth[] = { 31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31 };
    if (m == 2 && leapYear(y)) { daysInMonth[1] = 29; }
    if (d < 1 || d > daysInMonth[m - 1]) { return false; }
    return true;
}

class Book {
    private:
    std::string name;
    std::string author;
    int day;
    int month;
    int year;
    public:
    Book(std::string name, std::string author, int day, int month, int year) : name(name), author(author), day(day), month(month), year(year) {}
    
    void describe() {
        if (isValid(day, month, day)) {
            std::cout << "Book name: " << name << std::endl;
            std::cout << "Author name: " << author << std::endl;
            std::cout << "Day: " << day << " Month: " << month << " Year: " << year << std::endl;
        }
        else { throw std::runtime_error("Invalid date!"); }
    }
};

int main() {
    Book book("Why I don't belong to Apple's ecosystem and you should too!", "Linus Torvalds", 01, 04, 2005);
    book.describe();

    return 0;
}
