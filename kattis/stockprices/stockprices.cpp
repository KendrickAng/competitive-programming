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
                if (!sells.empty() && sells.top().first <= price) {
                    int sellQty = sells.top().second;
                    int sellPrice = sells.top().first;
                    stock = sellPrice;
                    if (quantity > sellQty) {
                        buys.push({price, quantity-sellQty});
                        sells.pop();
                    }
                    else if (quantity < sellQty) {
                        sells.pop();
                        sells.push({sellPrice, sellQty-quantity});
                    }
                    else {
                        sells.pop();
                    }
                } else {
                    cout << "pushing" << endl;
                    buys.push({price, quantity});
                }
            }
            else if (order == "sell") {
                if (!buys.empty() && buys.top().first >= price) {
                    int buyQty = buys.top().second;
                    int buyPrice = buys.top().first;
                    stock = price;
                    if (quantity > buyQty) {
                        buys.pop();
                        sells.push({price, quantity-buyQty});
                    }
                    else if (quantity < buyQty) {
                        buys.pop();
                        buys.push({buyPrice, buyQty-quantity});
                    }
                    else {
                        buys.pop();
                    }
                } else {
                    sells.push({price, quantity});
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