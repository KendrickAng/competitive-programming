#include <iostream>
#include <vector>
#include <algorithm>

int main() {
    std::vector<int> numbers{};
    int n;
    std::cin >> n;
    for (int i = 0; i < n; i++) {
        int num; std::cin >> num;
        numbers.push_back(num);
    }
    // solve
    std::sort(numbers.begin(), numbers.end());
    int start = 0;
    int end = 0;
    for (int i = 1; i < numbers.size(); i++) {
        int num = numbers[i];
        if (num - 1 != numbers[end]) {
            if (numbers[start] == numbers[end]) {
                std::cout << numbers[start];
            }
            else if (end-start == 1) {
                std::cout << numbers[start] << " " << numbers[end];
            } else {
                std::cout << numbers[start] << "-" << numbers[end];
            }
            if (i != numbers.size() - 1) 
                std::cout << " ";
            start = i;
            end = i;
        }
        else {
            end = i;
        }
    } 
    // print remainig, if any
    if (start != numbers.size()) {
        std::cout << " ";
        if (numbers[start] == numbers[end]) {
            std::cout << numbers[start];
        }
        else if (end-start == 1) {
            std::cout << numbers[start] << " " << numbers[end];
        } else {
            std::cout << numbers[start] << "-" << numbers[end];
        }
    }
}