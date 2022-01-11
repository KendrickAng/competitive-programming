#include <iostream>
#include <queue>
#include <functional>
#include <string>
#include <sstream>

using namespace std;

string tmp;

int main() {
    int t; cin >> t;
    for (int i = 0; i < t; i++) {
        int n; cin >> n;
        getline(cin, tmp);

        priority_queue<pair<int, int>> buys;
        priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>> sells;

        int bid = -1;
        int ask = -1;
        int stock = -1;

        for (int j = 0; j < n; j++) {
            int quantity, price;
            string line, order;
            getline(cin, line);
            istringstream iss(line);
            iss >> order >> quantity >> tmp >> tmp >> price;

            // place the order
            if (order == "buy") {
                buys.push({price, quantity});
            }
            if (order == "sell") {
                sells.push({price, quantity});
            }

            // handle all possible deals
            while (!buys.empty() && !sells.empty() && buys.top().first >= sells.top().first) {
                int buyPrice, buyQty, sellPrice, sellQty;
                buyPrice = buys.top().first;
                buyQty = buys.top().second;
                sellPrice = sells.top().first;
                sellQty = sells.top().second;
                stock = sellPrice;
                buys.pop();
                sells.pop();
                if (buyQty > sellQty) {
                    buys.push({buyPrice, buyQty-sellQty});
                }
                else if (buyQty < sellQty) {
                    sells.push({sellPrice, sellQty-buyQty});
                }
                else {
                    // do nothing
                }
            }

            if (!buys.empty()) {
                bid = buys.top().first;
            } else {
                bid = -1;
            }
            if (!sells.empty()) {
                ask = sells.top().first;
            } else {
                ask = -1;
            }

            cout << (ask == -1 ? "-" : to_string(ask)) << " " << (bid == -1 ? "-" : to_string(bid)) << " " << (stock == -1 ? "-" : to_string(stock)) << endl;
        }
    }
}