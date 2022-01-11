#include <iostream>
#include <unordered_map>
#include <string>

int main() {
    std::unordered_map<std::string, std::string> dict{};
    std::string line;
    std::getline(std::cin, line);
    // read words
    while (line != "") {
        std::string delimiter = " ";
        std::string a = line.substr(0, line.find(delimiter));
        std::string b = line.substr(line.find(delimiter)+1);
        dict[b] = a;
        std::getline(std::cin, line);
    }
    // translate words
    while (std::getline(std::cin, line)) {
        if (dict.find(line) != dict.end()) {
            std::cout << dict[line] << std::endl;
        }
        else {
            std::cout << "eh" << std::endl;
        }
    }
}