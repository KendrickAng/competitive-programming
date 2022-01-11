#include <iostream>
#include <vector>

using namespace std;

struct flight{
    int u;
    int v;
    int capacity;
};

int main() {
    int k; // number of airports
    int n; // number of days of the flight departure window
    int m; // number of flights in the window
    cin >> k >> n >> m;
    
    // arrivals on each day
    vector<vector<pair<int,int>>> arrivals(n, vector<pair<int,int>>{});
    // people at each airport
    vector<int> people(k, 0);
    // flights on each day
    vector<vector<flight>> flights(n, vector<flight>{});

    // read flights
    for (int i = 0; i < m; i++) {
        int u; // flight start point
        int v; // flight end point
        int d; // day flight flies
        int z; // capacity of the flight
        // at most one flight in each direction between two airports on one day
        cin >> u >> v >> d >> z;
        u--; v--; d--;
        flights[d].push_back({ u, v, z });
    }

    // read arrivals
    for (int i = 0; i < k*n; i++) {
        int a; // airport
        int b; // day
        int c; // number of customers leaving airport a on day b
        cin >> a >> b >> c;
        a--; b--;
        arrivals[b].push_back(make_pair(a,c));
    }

    // simulate
    bool optimal = true; 
    for (int day = 0; day < n; day++) {
        // simulate airport arrivals on particular day
        for (auto [airport, customers]: arrivals[day]) {
            people[airport] += customers;
        }

        // simulate optimal world
        for (auto [u, v, cap]: flights[day]) {
            people[u] -= cap;
            if (people[u] < 0) {
                optimal = false;
                break;
            }
        }
        if (!optimal) break;

        // simulate arrivals for same-day airport arrivals
        for (auto [u, v, cap]: flights[day]) {
            people[v] += cap;
        }
    }

    if (optimal) {
        cout << "optimal" << endl;
    } else {
        cout << "suboptimal" << endl;
    }
}