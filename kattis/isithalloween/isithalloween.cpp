#include <iostream>

int main() {
    std::string date;
    std::getline(std::cin, date);
    if (date == "OCT 31" || date == "DEC 25") {
        std::cout << "yup" << std::endl;
    } else {
        std::cout << "nope" << std::endl;
    }
}
