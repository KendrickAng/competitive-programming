#include <iostream>
#include <vector>
#include <unordered_set>

std::vector<std::string> split(std::string s, std::string delimiter) {
    size_t last = 0;
    size_t next = 0; 
    std::vector<std::string> ret{};
    while ((next = s.find(delimiter, last)) != std::string::npos) {   
	    ret.push_back(s.substr(last, next-last));
	    last = next + 1; 
    } 
    ret.push_back(s.substr(last));
    return ret;
}

int main() {
    int t;
    std::cin >> t;
    std::string noise, line;
    std::getline(std::cin , noise);
    std::unordered_set<std::string> mem{};
    for (int i = 0; i < t; i++) {
        std::getline(std::cin , noise);
        std::vector<std::string> noises = split(noise, " ");
        std::getline(std::cin, line);
        while(line != "what does the fox say?") {
            mem.insert(split(line, " ")[2]);
            std::getline(std::cin, line);
        }
        bool first = true;
        for (auto s: noises) {
            if (!mem.count(s)) {
                if (first) {
                    first = false;
                } else {
                    std::cout << " ";
                }
                std::cout << s;
            }
        }
        std::cout << std::endl;
    }
}