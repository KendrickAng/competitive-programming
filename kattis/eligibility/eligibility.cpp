#include <iostream>
#include <string>

int main() {
    int N;
    std::cin >> N;
    std::string name, pss, dob;
    std::string condition;
    int courses;
    for (int i = 0; i < N; i++) {
        std::cin >> name >> pss >> dob >> courses;
        if (std::stoi(pss.substr(0, 4)) >= 2010 || std::stoi(dob.substr(0, 4)) >= 1991) {
            condition = "eligible";
        } else if (courses >= 41) {
            condition = "ineligible";
        } else {
            condition = "coach petitions";
        }
        std::cout << name << " " << condition << std::endl;
    }
}
