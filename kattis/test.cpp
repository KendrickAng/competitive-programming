#include <iostream>
#include <unordered_map>
#include <string>

using namespace std;

int main() {
    struct Hash {
        hash<int> hasher;
        size_t seed = 0;
        size_t operator()(pair<int,int> p) {
            seed ^= hasher(p.first);
            return seed;
        }
    };
    unordered_map<pair<int,int>, int, Hash> map;
}
