#include <iostream>
#include <string>

class Time {
    private:
    int second;
    int minute;
    int hour;
    public:
    Time() = default;
    Time(int h, int m, int s) : hour(h), minute(m), second(s) { if ((hour > 23) || (minute > 59) || (second > 59)) { throw std::runtime_error("Invalid values!"); }}
    Time operator+(const Time& other) {
        int sum_sec = this->second + other.second;
        int sum_min = this->minute + other.minute;
        int sum_hour = this->hour + other.hour;

        if ((sum_sec) >= 60) {
            sum_min += sum_sec / 60;
            sum_sec = sum_sec % 60;
        }
        if ((sum_min) >= 60) {
            sum_hour += sum_min / 60;
            sum_min = sum_min % 60;
        }
        if ((sum_hour) >= 24) {
            sum_hour = sum_hour % 24;
        }
        return (Time(sum_hour, sum_min, sum_sec));
    }

    void operator=(const Time& other){
        if (this != &other){
            this->hour = other.hour;
            this->minute = other.minute;
            this->second = other.second;
        }
    }
    
    bool operator>(const Time& other){
        if (hour != other.hour) { return (hour > other.hour); } if (minute != other.minute) { return (minute > other.minute); } return (second > other.second);
    }

    void display() {
        std::cout << "Time: " << hour << ":" << minute << ":" << second << std::endl;
    }
};
int main() { 
    Time myTime(5, 12, 59);
    Time myotherTime(19, 17, 1);
    Time mytotalTime;
    myTime.display();
    myotherTime.display();
    mytotalTime = myTime + myotherTime;
    mytotalTime.display();
    myTime = myotherTime;
    mytotalTime = myTime + myotherTime;
    mytotalTime.display();

    std::cout << "Is the first time larger than the second time? " << (mytotalTime > myTime) << std::endl;
    return 0;
 }