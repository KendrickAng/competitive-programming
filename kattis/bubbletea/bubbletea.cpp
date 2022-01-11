#include <iostream>
#include <vector>
#include <algorithm>

int main() {
    std::vector<int> teas;
    std::vector<int> toppings;
    std::vector<int> prices;
    // 1-indexing
    teas.push_back(-1);
    toppings.push_back(-1);
    int n;
    // read tea prices
    std::cin >> n;
    for (int i = 0; i < n; i++) {
        int tmp = 0;
        std::cin >> tmp;
        teas.push_back(tmp);
    }
    // read topping prices
    int m;
    std::cin >> m;
    for (int i = 0; i < m; i++) {
        int tmp = 0;
        std::cin >> tmp;
        toppings.push_back(tmp);
    }
    // populate prices
    for (int i = 1; i <= n; i++) {
        int combinations = 0;
        std::cin >> combinations;
        for (int j = 0; j < combinations; j++) {
            int topping_idx = 0;
            std::cin >> topping_idx;
            prices.push_back(teas[i] + toppings[topping_idx]);
        }
    }
    std::sort(prices.begin(), prices.end());
    long money;
    std::cin >> money;
    std::cout << (money - prices[0]) / prices[0] << std::endl;
}