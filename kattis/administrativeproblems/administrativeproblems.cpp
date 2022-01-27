#include <bits/stdc++.h>

using namespace std;
using ll = int;

struct Car {
    string name;
    ll catalogPrice;
    ll pickupCost;
    ll kmCost;
};

struct SpyLog {
    string car; // name of car in use
    bool consistent = true;
    unsigned long long cost = 0;
};

void solve() {
    ll numCars, numEvents; cin >> numCars >> numEvents;
    map<string, SpyLog> log;

    unordered_map<string,Car> carLog;
    for (int i = 0; i < numCars; i++) {
        string name;
        ll cPrice, pCost, kmCost;
        cin >> name >> cPrice >> pCost >> kmCost;
        carLog[name] = Car{ name, cPrice, pCost, kmCost };
    }

    for (int i = 0; i < numEvents; i++) {
        int eventTime;
        string spyName;
        char type;
        cin >> eventTime >> spyName >> type;
        switch (type) {
            case 'p': { // pickup
                string car; cin >> car;
                SpyLog &sl = log[spyName];
                if (!sl.consistent) break; // don't bother if already inconsistent

                if (!sl.car.empty()) {
                    sl.consistent = false; // trying to use more than one car at a time
                } else {
                    sl.car = car;
                    sl.cost += carLog[car].pickupCost; // add pickup cost
                }
                break;
            }
            case 'r': { // return
                ll distKm; cin >> distKm;
                SpyLog &sl = log[spyName];
                if (!sl.consistent) break;

                if (sl.car.empty()) {
                    sl.consistent = false; // a spy always returns a car they picked up first
                } else {
                    sl.cost += carLog[sl.car].kmCost * distKm; // add distance cost
                    sl.car.clear(); // reset car
                }
                break;
            }
            case 'a': { // accident
                double severity; cin >> severity;
                SpyLog &sl = log[spyName];
                if (!sl.consistent) break;

                if (sl.car.empty()) {
                    sl.consistent = false; // accidents can only happen when spy is using car
                } else {
                    sl.cost += ceil((double) carLog[sl.car].catalogPrice * severity / 100);
                }
                break;
            }
        }
    }

    for (auto &[k, v]: log) {
        if (!v.car.empty()) v.consistent = false; // a spy must return the car he picks up
    }

    for (auto &[k, v]: log) {
        if (v.consistent) {
            cout << k << " " << v.cost << endl;
        } else {
            cout << k << " INCONSISTENT" << endl;
        }
    }
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int t; cin >> t;
    while (t--) solve();
}