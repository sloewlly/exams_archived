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

class Date {
    private:
    int day;
    int month;
    int year;
    public:
    Date(int day, int month, int year) : day(day), month(month), year(year) {}
    
    void describe() {
        if (isValid(day, month, year)) {
            std::cout << "Day: " << day << " Month: " << month << " Year: " << year << std::endl;
        }
        else { throw std::runtime_error("Invalid date!"); }
    }
};

class Book {
    private:
    std::string name;
    std::string author;
    Date* date;
    public:
    Book(std::string name, std::string author, Date* date) : name(name), author(author), date(date) {}
    
    void describe() {
        std::cout << "Book name: " << name << std::endl;
        std::cout << "Author name: " << author << std::endl;
        date->describe();
    }
};

int main() {
    Date publicationDate(1, 4, 2005);
    Book book("Why I don't belong to Apple's ecosystem and you should too!", "Linus Torvalds", &publicationDate);
    book.describe();

    return 0;
}
