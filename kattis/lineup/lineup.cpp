#include <iostream>
#include <string>
#include <vector>
#include <algorithm>

int main() {
    int n;
    std::cin >> n;
    std::vector<std::string> players;
    for (int i = 0; i < n; i++) {
        std::string player;
        std::cin >> player;
        players.push_back(player);
    }
    std::vector<std::string> asc = {players};
    std::vector<std::string> desc = {players};
    std::sort(asc.begin(), asc.end());
    std::sort(desc.rbegin(), desc.rend());
    bool is_asc = true;
    bool is_desc = true;
    for (int i = 0; i < players.size(); i++) {
        if (players[i] != asc[i]) {
            is_asc = false;
        }
        if (players[i] != desc[i]) {
            is_desc = false;
        }
    }
    if (!is_asc && !is_desc) {
        std::cout << "NEITHER" << std::endl;
    } else if (!is_desc) {
        std::cout << "INCREASING\n";
    } else {
        std::cout << "DECREASING\n"; 
    }
}