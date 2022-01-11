#include <iostream>
#include <string>
#include <unordered_set>
#include <cctype>

int main() {
    int n;
    std::cin >> n;
    std::string s = "";
    std::string db = "abcdefghijklmnopqrstuvwxyz";
    std::getline(std::cin, s);
    for (int i = 0; i < n; i++) {
        std::unordered_set<char> mySet{};
        std::string output = "";
        bool isPangram = true;
        std::getline(std::cin, s);
        
        // to lower case
        for (int j = 0; j < s.length(); j++) {
            mySet.insert((char) std::tolower(s[j]));
        }
        // check
        for (char c: db) {
            if (mySet.find(c) == mySet.end()) { // word not found
                isPangram = false;
                output.push_back(c);
            }
        }
        // output answer
        if (isPangram) {
            std::cout << "pangram" << std::endl;
        } else {
            std::cout << "missing " + output << std::endl;
        }
    }
}