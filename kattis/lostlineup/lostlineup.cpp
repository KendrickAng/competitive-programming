#include <iostream>
#include <vector>

int main() {
    int n, curr;
    std::cin >> n;
    std::vector<int> line(n);
    line[0] = 1; // jimmmy goes here
    for (int i = 0; i < line.size(); i++) {
        std::cin >> curr;
        line[curr+1] = i+1;
    }
    for (int i = 0; i < line.size(); i++) {
        std::cout << line[i];
        if (i < line.size() - 1) {
            std::cout << std::endl;
        }
    }
}