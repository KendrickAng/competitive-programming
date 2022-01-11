#include <iostream>
#include <ctime>
#include <string>
#include <vector>

int main() {
    std::vector<std::string> v = {"Saturday", "Sunday", "Monday", "Tuesday", "Wednesday", "Thursday", "Friday"};
    std::tm time{};
    std::cin >> time.tm_mday;
    std::cin >> time.tm_mon;
    time.tm_mon --;
    time.tm_year = 2009;
    std::mktime(&time);
    std::cout << v[time.tm_wday] << std::endl;
}