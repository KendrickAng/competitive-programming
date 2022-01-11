#include <iostream>
#include <unordered_set>
#include <string>

int main() {
    int t;
    std::cin >> t;
    for (int i = 0; i < t; i++) {
        int n;
        std::string place;
        std::unordered_set<std::string> places;
        std::cin >> n;
        getline(std::cin, place); // get rid of newline
        for (int j = 0; j < n; j++) {
            getline(std::cin, place);
            places.insert(place);
        }
        std::cout << places.size() << std::endl;
    }
}