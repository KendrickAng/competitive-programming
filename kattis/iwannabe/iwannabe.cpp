#include <iostream>
#include <vector>
#include <unordered_set>
#include <algorithm>

struct Pokemon{
    unsigned long idx;
    unsigned long att;
    unsigned long def;
    unsigned long health;
};

int main() {
    int n, k;
    std::unordered_set<int> s{};
    std::cin >> n >> k;
    std::vector<Pokemon> pokemon{};
    for (int i = 0; i < n; i++) {
        unsigned long a, d, h;
        std::cin >> a >> d >> h;
        Pokemon p = {i, a, d, h};
        pokemon.push_back(p);
    }
    std::sort(pokemon.begin(), pokemon.end(), [](auto &lhs, auto &rhs) {
        return lhs.att > rhs.att;
    });
    for (int i = 0; i < k; i++) s.insert(pokemon[i].idx);
    std::sort(pokemon.begin(), pokemon.end(), [](auto &lhs, auto &rhs) {
        return lhs.def > rhs.def;
    });
    for (int i = 0; i < k; i++) s.insert(pokemon[i].idx);
    std::sort(pokemon.begin(), pokemon.end(), [](auto &lhs, auto &rhs) {
        return lhs.health > rhs.health;
    });
    for (int i = 0; i < k; i++) s.insert(pokemon[i].idx);

    std::cout << s.size() << std::endl;
}